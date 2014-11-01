#ifndef REQUESTHELPERS_H
#define REQUESTHELPERS_H

#include "logHelper.h"
#include <netinet/in.h>

typedef struct {
	int requestSD;
	char * requesstBuffer;
	logger * l;
	struct sockaddr_in client;
	char ** parsedReq;
}request;

void handle_request(request *, char *);

int is_valid_request(char **);

int parse_request(char *, char **);

FILE * open_file(char *, char *, int *);

int read_file(FILE *, char **);

int send_file(request *, char *, char *);

int send_bad_request(request *);

int send_file_not_found(request *);

int send_permission_denied(request *);

int send_internal_service_error(request *);

int send_text(int, char *);

char * get_good_response(int);

int transfer_file(FILE *, int, int);

long get_file_size(FILE *);

#endif