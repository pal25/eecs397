#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main (int argc, char** argv)
{
    char* echo[argc];
    int echoCount = 0;

    int suppress = 0;
    int repeat = 1;
    
    while(--argc) {
	switch(**(++argv)) {
    	case('-'):
	    if(!strncmp(*argv, "-n", strlen(*argv))) {
		suppress = 1;
	    } else if(!strncmp(*argv, "-r", strlen(*argv))) {
		repeat = atoi(*(++argv));
		argc = argc - 1;
	    }
	    break;
	default:
	    echo[echoCount++] = *argv;
	    break;
	}
    }

    for(int i=0;i<echoCount;i++) {
	for(int j=0;j<repeat;j++) {
	    printf("%s", echo[i]);
	    if(!suppress)
		printf("\n");
	}
    }
    return 0;
}
