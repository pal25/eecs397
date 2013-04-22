#include <stdlib.h>
#include <stdio.h>
#include "helper.h"

int main(int argc, char** argv)
{
    void* context = zmq_init(2);
    void* publisher = zmq_socket(context, ZMQ_PUB);

    char addr[32];
    sprintf(addr, "tcp://*:%d", PORT_NUM);

    int rc = zmq_bind(publisher, addr);
    if(rc != 0)
	exit(EXIT_FAILURE);

    int running = 1;
    while(running) {
	int count = 0;
	char buffer[256];
	sprintf(buffer, "%d", count);
	s_send(publisher, buffer);
    }

    zmq_close(publisher);
    zmq_term(context);
    return 0;
}


