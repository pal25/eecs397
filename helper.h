/*  =====================================================================
    helper.h

    Heavily modified code from the zmq_guide
    =====================================================================
*/

#ifndef __HELPER_H_INCLUDED__
#define __HELPER_H_INCLUDED__

#include <zmq.h>

#define PORT_NUM 30123

char* s_recv (void* socket);
int s_send (void* socket, char* buffer);
void checked_msg_init(zmq_msg_t* msg);
void checked_msg_data(zmq_msg_t* msg, char* buffer);
void s_sleep (int msecs);

#endif  //  __HELPER_H_INCLUDED__
