#include <stdio.h>
#include <string.h>
#include <time.h>
#include "helper.h"

int main(int argc, char** argv)
{
    void* context = zmq_init(2);
    void* subscriber = zmq_socket(context, ZMQ_SUB);
    
    char addr[32];
    sprintf(addr, "tcp://eecs397.bitbacker.com:%d", PORT_NUM);

    if(zmq_connect(subscriber, addr) == -1) {
	perror("Failed to connect sub");
	exit(EXIT_FAILURE);
    } else {
	printf("Connected to %s\n", addr);
    }

    if(zmq_setsockopt(subscriber, ZMQ_SUBSCRIBE, NULL, 0) == -1) {
	perror("Failed to sub all");
	exit(EXIT_FAILURE);
    }

    while(1) {
	char payload[256];
	s_recv(subscriber, payload);

	json_t* data = json_loadb(payload, strlen(payload), 0, NULL);
	time_t time = (time_t) json_number_value(json_object_get(data, "Timestamp"));
	float reading = (float) json_real_value(json_object_get(data, "Value A"));

	char buffer[256];
	sprintf(buffer, "%E %s", reading, ctime(&time));
	printf("%s", buffer);
	json_decref(data);
    }

    zmq_close(subscriber);
    zmq_term(context);
    return 0;
}


