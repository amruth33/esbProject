#ifndef ESB_H
#define ESB_H

typedef struct {
    char * messageId;
    char * messageType;
    char * sender;
    char * destination;
    char * creationDateTime;
    char * signature;
    char * referenceId;
    char * userProperties;
} bmd_envelop;

typedef struct {
    bmd_envelop envelop;
    char* payload;
} bmd;

typedef struct {
    char * transform_key;
    char * transform_value;
    char * transport_key;
    char * transport_value;
    char * valid_status;
} check_t;
check_t process_esb_request(char* bmd_file_path);
bmd parse_bmd_xml(char* bmd_file_path);

#endif