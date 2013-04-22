#include <zmq.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <time.h>
#include "helper.h"

//  Receive 0MQ string from socket and convert into C string
//  Caller must free returned string. Returns NULL if the context
//  is being terminated.
char* s_recv (void* socket) {
    zmq_msg_t* msg = (zmq_msg_t*)malloc(sizeof(zmq_msg_t));
    checked_msg_init(msg);

    if(zmq_recv(socket, msg, 0) == -1) {
	exit(EXIT_FAILURE);
    }
    
    char* msg_data = strdup((char*)zmq_msg_data(msg));
    zmq_msg_close(msg);
    return msg_data;
}

//  Convert C string to 0MQ string and send to socket
int s_send (void* socket, char* buffer) {
    zmq_msg_t* msg = (zmq_msg_t*)malloc(sizeof(zmq_msg_t));
    checked_msg_init(msg);
    checked_msg_data(msg, buffer);
    
    int size = zmq_send (socket, msg, 0);
    return size;
}

void checked_msg_init(zmq_msg_t* msg)
{
    if(zmq_msg_init(msg) == -1) {
	perror("Error initing zmq_msg");
	exit(EXIT_FAILURE);
    }

    return;
}

void checked_msg_data(zmq_msg_t* msg, char* buffer)
{
    if(zmq_msg_init_size(msg, strlen(buffer)) == -1) {
	    perror("Error setting zmq_msg data");
	    exit(EXIT_FAILURE);
    }

    memcpy(zmq_msg_data(msg), buffer, strlen(buffer));
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



