/*  =====================================================================
    helper.h

    Heavily modified code from the zmq_guide
    =====================================================================
*/

#ifndef __HELPER_H_INCLUDED__
#define __HELPER_H_INCLUDED__

#include <zmq.h>
#include <jansson.h>

#define PORT_NUM 30123

void s_recv (void* socket, char* payload);
int s_send (void* socket, json_t* payload);
void checked_msg_init(zmq_msg_t* msg);
void checked_msg_data(zmq_msg_t* msg, char* payload);
void s_sleep (int msecs);

#endif  //  __HELPER_H_INCLUDED__
