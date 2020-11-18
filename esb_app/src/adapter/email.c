#include <stdio.h>
#include <string.h>

/*install and configure ssmtp in ubuntu to send the mail using ssmtp*/
 
int send_mail(char *to,char *text)
{
    /*open and read file and store the content of the file in a string that needs to be send on email*/
    FILE * fp,*f;
    fp=fopen(text,"r");
    int c;
    int i=0;
    while((c=fgetc(fp))!= EOF){    //determine the size of buffer 
	i++;              
    }
    fclose(fp); //close the local file
    f=fopen(text,"r");
    char buff[i];
    int j=0;
    while((c=fgetc(fp))!= EOF){
	buff[j]=c;  
	j++;
    }
    char * const str=buff;  //storing the content of the file in the string
    fclose(f);   //close the local file
       
    printf("buffer content is:%s\n",str);
    
    char cmd[1000];      //to hold the command
    int n=strlen(str);   //length of the string which needs to be send on email
    char dataFile[n];     //declaring the char array to store the string

    FILE * fl = fopen(dataFile,"w"); // open it for writing.
    
    fprintf(fl,"From: team dove\r\n");   //sender's name
    fprintf(fl,"Subject: Payload of json file\r\n");  //subject of mail to be send
    fprintf(fl,"\r\n");                               //blank line to separate the header and body
    fprintf(fl,"%s\n",str);        // write body to it.
    
    fclose(fl);             // close it.
    
    sprintf(cmd,"ssmtp %s < %s",to,dataFile);  
    system(cmd);     // execute it.

    return 1;        
}

