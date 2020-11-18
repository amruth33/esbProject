#include <stdio.h>
#include "esb.h"
#include <string.h>
#include <libxml/parser.h>
#include <libxml/tree.h>
#include <mysql/mysql.h>
#include <stdlib.h>
#define MAX_STRING 1000


/* parse_bmd_xml function takes the file path as an argument and it parses the xml file and stores the content of the file in structure*/
bmd parse_bmd_xml(char* bmd_file_path) {
    bmd b;
    bmd_envelop envl;
   //printf("%s\n",bmd_file_path);
    
    xmlDoc         *document=NULL; //declaring pointers to document and nodes of xml doc
    
    xmlNode        *root=NULL, *first_child=NULL, *node=NULL,*temp=NULL; // pointers to root element,first child of an elements and one temporary pointer

    if((document = xmlReadFile(bmd_file_path, NULL, 0))==NULL){            //reading xml file and error checking, document pointer should point at xml document
        printf("Could not parse the file\n");
        exit(1);
    }
    temp = xmlDocGetRootElement(document);          // access the root element of the bmd file
    root=xmlFirstElementChild(temp);                
   
    first_child = root->children;       // first child of the root element

    for (node = first_child; node; node = node->next) {   //storing the content of each node into structure

        if(node->type==1)
        {
            if((strcmp(((char *) node->name),"MessageID")==0)) 
            {
                b.envelop.messageId=(char *) xmlNodeGetContent(node);             
                
            }
            else if((strcmp(((char *) node->name),"MessageType"))==0)
            {
                b.envelop.messageType=(char *)xmlNodeGetContent(node);

            }

            else if(strcmp(((char *) node->name), "Sender")==0)
            {
                b.envelop.sender=(char *)xmlNodeGetContent(node);

            }

            else if((strcmp(((char *) node->name),"Destination"))==0)
            {
                b.envelop.destination=(char *)xmlNodeGetContent(node);

            }

            else if((strcmp(((char *) node->name),"CreationDateTime"))==0)
            {
                b.envelop.creationDateTime=(char *)xmlNodeGetContent(node);
                
            }

            else  if((strcmp(((char *) node->name),"Signature"))==0)
            {
                b.envelop.signature=(char *)xmlNodeGetContent(node);
               
            }

            else if((strcmp(((char *) node->name),"ReferenceID"))==0)
            {
                b.envelop.referenceId=(char *)xmlNodeGetContent(node);
              
            }
        }
    }


    root=xmlLastElementChild(temp);
    first_child = root;
    for (node = first_child; node; node = node->next) {

        if(node->type==1)
        {
            if ((strcmp(((char *) node->name),"Payload"))==0)
            {
                b.payload=(char *) xmlNodeGetContent(node);
                
            }
       }
    }
    return b;  // returns structure which stores the content of the xml file
}





/* this function is to check if the xml file is valid or not, it takes struct as an argument*/
check_t is_bmd_valid(bmd b)
{
    int valid = -1; // 1 => vaild, -1 => invalid
    
   //checking if any mandatory value is not null, it null then invalid bmd 
   if(*b.envelop.messageId == 0){
        
        printf("messageId is missing\n");
        valid=-1;
    
    }
   if(*b.envelop.messageType == 0){
    
       printf("messageType is missing\n");
       valid=-1;
   
   }
   if(*b.envelop.sender == 0){
   
       printf("sender is missing\n");
       valid=-1;
   
   }
   if(*b.envelop.destination == 0){
   
       printf("destination is missing\n");
       valid=-1;
   
   }
   if(*b.envelop.creationDateTime == 0){
   
       printf("creationDateTime is missing\n");
       valid=-1;
   
   }
   if(*b.envelop.signature == 0){
   
       printf("signature is missing\n");
       valid=-1;
   
   }
   if(*b.envelop.referenceId == 0){
   
       printf("referenceId is missing\n");
       valid=-1;
   
   }

    
    //checking if there are active routes in routes table   
    //connecting with the database
  
    static char *host ="localhost";
    static char *user = "root";
    static char *password = "my sql";
    static char *dbname ="esb";
    static char *unix_socket = NULL;
    unsigned int flag =0;
	
    // CREATING CONNECTION HANDERLER (con) :
    MYSQL *conn;
    MYSQL_RES *res,*resTransform,*resTransport;
    MYSQL_ROW *row,*rowTransform,*rowTransport;
    
    conn = mysql_init(NULL);
   
    if (!mysql_real_connect(conn, host, user, password, dbname, 0, NULL, 0)) {
       
        printf("Failed to connect MySQL Server %s. Error: %s\n", host, mysql_error(conn));
        exit(1);
       
    }
   
    printf("\nConnected to database\n\n");
   
    if(mysql_query(conn,"SELECT sender,destination,message_type,route_id FROM routes"))
    {

        fprintf(stderr, "%s\n", mysql_error(conn));
        mysql_close(conn);

    }
    
    res=mysql_store_result(conn);                 //storing the results
    int num_fields = mysql_num_fields(res);       //number of records
    printf("num_fields=%d\n",num_fields);
    char * record;
    
    while(row = mysql_fetch_row(res)){
    
        for(int i=0;i<num_fields;i++){
    
            if(!(strcmp(b.envelop.sender,row[i])) && !(strcmp(b.envelop.destination,row[i+1])) && !(strcmp(b.envelop.messageType,row[i+2])))  //checking for active records in the routes table
            {
                printf("\nrecord found in the routes table\n\n");
                record=row[i+3];
                printf("route id is : %s\n",record);
                valid=1;
                break;
    
            }
        }  
    }
   
    //storing the transport and transform key and values in the structure
    check_t check;           //declaring the structure, definition is in esb.h
    if(valid==1){
        char query[2000];
        sprintf(query,"SELECT config_key, config_value FROM transport_config where route_id='%s'",record);
        
        if(mysql_query(conn,query)){
        
            fprintf(stderr, "%s\n", mysql_error(conn));   
        
        }
        resTransport=mysql_store_result(conn);
        rowTransport=mysql_fetch_row(resTransport);
        
        if(((rowTransport[0]!=NULL) && (rowTransport[1]!=NULL))){
        
            printf("\ntransport_key: %s\ttransport_value: %s\n\n",rowTransport[0],rowTransport[1]);
            check.transport_key=rowTransport[0];
            check.transport_value=rowTransport[1];
            valid=1;
        
        }
        else{
        
            valid=0;
        
        }
    
    }
    if(valid==1){
        char query1[2000];
        sprintf(query1,"SELECT config_key, config_value FROM transform_config where route_id='%s'",record);
        if(mysql_query(conn,query1)){
        
            fprintf(stderr, "%s\n", mysql_error(conn));   
        
        }
        resTransform=mysql_store_result(conn);
        rowTransform=mysql_fetch_row(resTransform);
       
        if(((rowTransform[0]!=NULL) && (rowTransform[1]!=NULL))){
        
            printf("\ntransform_key: %s\ttransform_value: %s\n\n",rowTransform[0],rowTransform[1]);
            check.transform_key=rowTransform[0];
            check.transform_value=rowTransform[1];
            valid=1;
       
        }
        else{
       
            valid=0;
       
        }
    
    }
    //free the pointers
    mysql_free_result(resTransport);
    mysql_free_result(resTransform);
    mysql_free_result(res);
    mysql_close(conn);
    //storing the validation status in the struct
    check.valid_status=valid;
    return check;
}

/* this function is to store the data of bmd file into esb request table once it is validated */
int queue_the_request(bmd b,char* bmd_file_path)
{   
    /*tranform creationDateTime into datetime format to insert it into esb_request table*/
    int n=strlen(b.envelop.creationDateTime);
    
    for(int k=0;k<n;k++){                
    
        if(b.envelop.creationDateTime[k]=='T'){
              b.envelop.creationDateTime[k]=' ';
    
         }
    }
    b.envelop.creationDateTime=strtok(b.envelop.creationDateTime,"+");
    printf("\nCreationDateTime is  %s\n\n",b.envelop.creationDateTime );
    
    int success = 1; // 1 => OK, -1 => Error cases
   
    char * initial_status="AVAILABLE"; 
    MYSQL *con;
    MYSQL_RES *res;
    MYSQL_ROW *row;
    
    static char *host ="localhost";
    static char *user = "root";
    static char *password = "my sql";
    static char *dbname ="esb";
    static char *unix_socket = NULL;
    unsigned int flag =0;
	
    //CREATING CONNECTION HANDERLER (con) :
   
    con = mysql_init(NULL);

    if (con == NULL)
    {
       
        fprintf(stderr, "%s\n", mysql_error(con));
        exit(1);
    
    }

    // MAKING CONNECTION BETWEEN C AND MYSQL SERVER USING LOCALHOST :

    if (mysql_real_connect(con, host, user, password,
                           dbname, 0, unix_socket, flag) == NULL)
    {
        fprintf(stderr, "%s\n", mysql_error(con));
        mysql_close(con);
        exit(1);

    }

    //storing the data into esb_request table
    char  query[MAX_STRING]={0};
    
    snprintf(query,MAX_STRING,"INSERT INTO esb_request(message_id,message_type,sender_id,dest_id,received_on,reference_id,data_location,status)  VALUES('%s','%s','%s','%s','%s','%s','%s','%s')",b.envelop.messageId,b.envelop.messageType,b.envelop.sender,b.envelop.destination,b.envelop.creationDateTime,b.envelop.referenceId,bmd_file_path,initial_status);
    
    if (mysql_query(con,(query))){
    
        fprintf(stderr, "%s\n", mysql_error(con));
        mysql_close(con);
        exit(1);
    
    }
    
    res = mysql_use_result(con);
    mysql_free_result(res);
    mysql_close(con);          //closing the connection after inserting the data
    return success;
}

/**
 * This is the main entry point into the ESB. 
 * It will start processing of a BMD received at the HTTP endpoint.
 */
check_t process_esb_request(char* bmd_file_path) {
    int status = 1; // 1 => OK, -ve => Errors
    printf("\nHandling the BMD %s\n\n", bmd_file_path);
    
   // Step 1:parsing the xml file
   bmd b = parse_bmd_xml(bmd_file_path);
   printf("\nparsing is done\n\n");

    // Step 2:validation of bmd file
   check_t check=is_bmd_valid(b); 
    
   if (check.valid_status==-1)
    {
        printf("\nBMD is invalid!\n\n");
        status = -2;
    }
    else
    {
        // Step 3:storing the data into esb_request table
        status = queue_the_request(b,bmd_file_path);
        if(status==1)
        {  
               printf("\ncontent of bmd is stored in esb_request table\n\n");
        }
    }
    
    return check;
}

