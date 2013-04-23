#include <zmq.h>
#include <jansson.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <time.h>
#include "helper.h"

//  Receive 0MQ string from socket and convert into C string
//  Caller must free returned string. Returns NULL if the context
//  is being terminated.
void s_recv (void* socket, char* payload) {
    zmq_msg_t* msg = (zmq_msg_t*)malloc(sizeof(zmq_msg_t));
    checked_msg_init(msg);

    if(zmq_recv(socket, msg, 0) == -1) {
	exit(EXIT_FAILURE);
    }
    strcpy(payload, zmq_msg_data(msg));
    return;
}

//  Convert C string to 0MQ string and send to socket
int s_send (void* socket, json_t* payload) {
    zmq_msg_t* msg = (zmq_msg_t*)malloc(sizeof(zmq_msg_t));
    checked_msg_init(msg);
    
    char* data = json_dumps(payload, 0);
    checked_msg_data(msg, data);
    free(data);
    
    int size = zmq_send (socket, msg, 0);
    return size;
}

// Check for errors in initing the data struct
void checked_msg_init(zmq_msg_t* msg)
{
    if(zmq_msg_init(msg) == -1) {
	perror("Error initing zmq_msg");
	exit(EXIT_FAILURE);
    }

    return;
}

// Check for erros in setting up messages
void checked_msg_data(zmq_msg_t* msg, char* payload)
{
    if(zmq_msg_init_size(msg, sizeof(char)*strlen(payload)) == -1) {
	    perror("Error setting zmq_msg data");
	    exit(EXIT_FAILURE);
    }
    
    strcpy(zmq_msg_data(msg), payload);

    printf("zmq_msg_data: %s\n",  (char*)zmq_msg_data(msg));
    return;
}
 
//  Sleep for a number of milliseconds
void s_sleep (int msecs)
{
    struct timespec t;
    t.tv_sec  =  msecs / 1000;
    t.tv_nsec = (msecs % 1000) * 1000000;
    nanosleep (&t, NULL);
}


