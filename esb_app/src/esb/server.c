#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdbool.h>
#include <pthread.h>
#include <sys/un.h>
#include <stddef.h>
#include "esb.h"
#include "server.h"
#include "../adapter/transform.h"
#include "../adapter/ftp.h"
#include "../adapter/email.h"
#include "../adapter/http.h"
#include "../adapter/csv.h"

bool create_worker_thread(int fd);
void log_msg(const char *msg, bool terminate) {
    printf("%s\n", msg);
    if (terminate) exit(-1); /* failure */
}

/*  Create a named (AF_LOCAL) socket at a given file path.is_client whether to create a client socket or server socket and returns Socket descriptor*/
int make_named_socket(const char *socket_file, bool is_client) {
    printf("Creating AF_LOCAL socket at path %s\n", socket_file);
    if (!is_client && access(socket_file, F_OK) != -1) {
        log_msg("An old socket file exists, removing it.", false);
        if (unlink(socket_file) != 0) {
            log_msg("Failed to remove the existing socket file.", true);
        }
    }
    struct sockaddr_un name;
    /* Create the socket. */
    int sock_fd = socket(AF_LOCAL, SOCK_STREAM, 0);
    if (sock_fd < 0) {
        log_msg("Failed to create socket.", true);
    }

    /* Bind a name to the socket. */
    name.sun_family = AF_LOCAL;
    strncpy (name.sun_path, socket_file, sizeof(name.sun_path));
    name.sun_path[sizeof(name.sun_path) - 1] = '\0';

    /* The size of the address is
       the offset of the start of the socket_file,
       plus its length (not including the terminating null byte).
       Alternatively you can just do:
       size = SUN_LEN (&name);
   */
    size_t size = (offsetof(struct sockaddr_un, sun_path) +
                   strlen(name.sun_path));
    if (is_client) {
        if (connect(sock_fd, (struct sockaddr *) &name, size) < 0) {
            log_msg("connect failed", 1);
        }
    } else {
        if (bind(sock_fd, (struct sockaddr *) &name, size) < 0) {
            log_msg("bind failed", 1);
        }
    }
    return sock_fd;
}

void thread_function(int sock_fd) {
    log_msg("SERVER: thread_function: starting", false);
    char buffer[5000];
    memset(buffer, '\0', sizeof(buffer));
    
    int count = read(sock_fd, buffer, sizeof(buffer));
    if (count > 0) {
        printf("SERVER: Received from client: %s\n", buffer);
        write(sock_fd, buffer, sizeof(buffer)); /* echo as confirmation */
    }
    
    //modifying the path of the file, to correctly track the bmd file
    char data[100];
    strcpy(data,"../."); 
    strcat(data,buffer); //data contains the modified bmd path
    
    /* processing the esb request, parsing the bmd file, validating the mandatory values, and stroing it in database*/
    check_t check= process_esb_request(data);

    if(check.valid_status==1){ 
        printf("\nsuccessfully processed esb request\n\n");
    }
    else{
        printf("\ncould not processed esb request\n\n");
        close(sock_fd); /* break connection */
        log_msg("SERVER: thread_function: Done. Worker thread terminating.", false);
        pthread_exit(NULL);
    }
    
    //storing the values from the structure to the strings
    char *transport_key = malloc(strlen(check.transport_key)+1);
    strcpy(transport_key,check.transport_key);
    char *transport_value = malloc(strlen(check.transport_value)+1);
    strcpy(transport_value,check.transport_value);
    char *transform_value = malloc(strlen(check.transform_value)+1);
    strcpy(transform_value,check.transform_value);
    char *transform_key = malloc(strlen(check.transform_key)+1);
    strcpy(transform_key,check.transform_key);
    
    //transformation of xml to json and xml to csv
    char * payload_data_file;
    if(!strcmp(transform_value,"json") && (!strcmp(transform_key,"Json_file"))){
        payload_data_file=transformToJson(data);
    }
    else if((!strcmp(transform_value,"csv")) && (!strcmp(transform_key,"Csv_file"))) {
        //transform xml to csv
        bmd b1 = parse_bmd_xml(data);
        char * str1 = b1.payload;
        int csv_transform = payload_csv(str1);
        if(csv_transform==1)
        printf("File succesfully transormed to CSV format\n\n");
    }
    
    if(payload_data_file!=NULL){
        printf("\nxml file is transformed into json\n\n");
    }
    
    //send the payload part over http server
    if(!strcmp(transport_value,"HTTP")){
        int http_status=http(transport_key,payload_data_file);
        if(http_status==1){
            printf("\nfile is sent to the HTTP server\n\n");
        }
        else{
            printf("\nfile is not being sent on HTTP server\n\n");
       }
    }

     if((!strcmp(transport_value,"FTP")) && (!strcmp(transform_value,"csv"))){
        int ftp_status=ftp(transport_key,"payload.csv");
        if(ftp_status==1){
            printf("\nfile is sent to the FTP server\n\n");
        }
        else{
            printf("\nfile is not being sent on FTP server\n\n");
       }
    }
    
    //send the payload part over ftp server 
    if((!strcmp(transport_value,"FTP")) && (!strcmp(transform_value,"json"))){
        int ftp_status=ftp(transport_key,payload_data_file);
        if(ftp_status==1){
            printf("\nfile is sent to the FTP server\n\n");
        }
        else{
            printf("\nfile is not being sent on FTP server\n\n");
       }
    }
    
    //send the payload over email in a string format
    if(!strcmp(transport_value,"EMAIL")){
        printf("reciepient of email is %s\n",transport_key);
        int email_status=send_mail(transport_key,payload_data_file);
        if(email_status==1){
            printf("\nemail is sent to destination\n\n");
        }
        else{
            printf("\nfile is not being sent on email\n\n");
       }
    }
    
    close(sock_fd); /* break connection */
    log_msg("SERVER: thread_function: Done. Worker thread terminating.", false);
    pthread_exit(NULL); // Must be the last statement
}

/**
 * This function launches a new worker thread.
 * sock_fd
 * return Return true if thread is successfully created, otherwise false.
 */
bool create_worker_thread(int sock_fd) {
    log_msg("SERVER: Creating a worker thread.", false);
    pthread_t thr_id;
    int rc = pthread_create(&thr_id,
            /* Attributes of the new thread, if any. */
                            NULL,
            /* Pointer to the function which will be
             * executed in new thread. */
                            thread_function,
            /* Argument to be passed to the above
             * thread function. */
                            (void *) sock_fd);
    if (rc) {
        log_msg("SERVER: Failed to create thread.", false);
        return false;
    }
    return true;
}

/**
 * Sends a message to the server socket.
 *  msg Message to send
 *  socket_file Path of the server socket on localhost.
 */
_Noreturn void start_server_socket(char *socket_file, int max_connects) {
    int sock_fd = make_named_socket(socket_file, false);

    /* listen for clients, up to MaxConnects */
    if (listen(sock_fd, max_connects) < 0) {
        log_msg("Listen call on the socket failed. Terminating.", true); /* terminate */
    }
    log_msg("Listening for client connections...\n", false);
    /* Listens indefinitely */
    while (1) {
        struct sockaddr_in caddr; /* client address */
        int len = sizeof(caddr);  /* address length could change */

        printf("Waiting for incoming connections...\n");
        int client_fd = accept(sock_fd, (struct sockaddr *) &caddr, &len);  /* accept blocks */
        

        if (client_fd < 0) {
            log_msg("accept() failed. Continuing to next.", 0); /* don't terminate, though there's a problem */
            continue;
        }
        /* Start a worker thread to handle the received connection. */
        if (!create_worker_thread(client_fd)) {
            log_msg("Failed to create worker thread. Continuing to next.", 0);
            continue;
        }

    }  /* while(1) */
}


int main() {
  
        start_server_socket("./my_sock", 10);
    
}


