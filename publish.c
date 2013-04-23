#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "helper.h"

int main(int argc, char** argv)
{
    void* context = zmq_init(2);
    void* publisher = zmq_socket(context, ZMQ_PUB);

    char addr[32];
    sprintf(addr, "tcp://*:%d", PORT_NUM);

    if(zmq_bind(publisher, addr) == -1) {
	perror("Failed to bind publisher");
	exit(EXIT_FAILURE);
    } else {
	printf("Bound to %s\n", addr);
    }

    srand(time(NULL));

    int running = 1;
    while(running) {
	json_t* payload = json_object();
	payload = json_object();
	json_object_set_new(payload, "Timestamp", json_integer((int) time(NULL)));
	json_object_set_new(payload, "Value A", json_real((float) (2*(random()/(float)RAND_MAX)-1)));
	s_send(publisher, payload);
	s_sleep(2000);
    }
    
    zmq_close(publisher);
    zmq_term(context);
    return 0;
}


