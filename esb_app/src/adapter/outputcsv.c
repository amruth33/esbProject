#include<stdio.h>
#include<stdlib.h>
#include "csv.h"

int payload_csv(char * data)
{
    FILE * fp;
    //char * msg = "HDFCNO8979";
    fp = fopen("payload.csv","w+");
    if(fp==NULL)
    {
        printf("File cannot ne opened...\n");
    }
    fprintf(fp,"Payload\n");
    fprintf(fp,"%s\n",data);
    fclose(fp);
    return 1;
}