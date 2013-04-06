#include <ctype.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "dict.h"

#define BUFFER_SIZE 1024

void strToLower(char* str)
{
    //Credit J.F. Sebastian
    for (; *str; ++str)
	*str = tolower(*str);
}

void filterString(char* str)
{
    char* new;
    for(new=str; *str; ++str) {
	switch(*str) {
	case('!'):
	case('\"'):
	case('#'):
	case('$'):
	case('%'):
	case('&'):
	case('\''):
	case('('):
	case(')'):
	case('*'):
	case('+'):
	case(','):
	case('.'):
	case('/'):
	case(':'):
	case(';'):
	case('<'):
	case('='):
	case('>'):
	case('?'):
	case('@'):
	case('['):
	case('\\'):
	case(']'):
	case('^'):
	case('_'):
	case('`'):
	case('{'):
	case('|'):
	case('}'):
	case('~'):
	case('\n'):
	case('\r'):
	    break;
	default:
	    *(new++) = *str;
	    break;
	}
    }
    *new = '\0';
}

dict_entry* readToDict(FILE* input)
{
    dict_entry* dict = alloc_dict();
    
    char* linebuffer = NULL;
    size_t len = 0;
    
    char newbuffer[BUFFER_SIZE];
    char oldbuffer[BUFFER_SIZE];

    char* token;
    char* delims = " ";
    int in_dict;

    while(getline(&linebuffer, &len, input) != -1) {
	filterString(linebuffer);
	token = strtok(linebuffer, delims);
	while(token != NULL) {
	    strToLower(token);
	    in_dict = lookup_kv(dict, token, oldbuffer);
	    if(!in_dict) {
		sprintf(newbuffer, "%d", 1);
	    } else {
		sprintf(newbuffer, "%d", atoi(oldbuffer)+1);
	    }
	    add_kv(dict, token, newbuffer);
	    token = strtok(NULL, delims);
	}
    }

    fclose(input);
    return dict;
}

int main(int argc, char** argv)
{
    FILE* input;

    if(argc == 1) {
	input = stdin;
    } else if(!(strcmp(argv[1], "-f") == 0)) {
	if((input = fopen(argv[2], "r")) == NULL) {
	    printf("Cannot open file: %s\n", argv[2]);
	    exit(EXIT_FAILURE);
	}
    } else {
	printf("USAGE: ./freq -f filename\n");
	exit(EXIT_FAILURE);
    }

    dict_entry* dict = readToDict(input);
    dict_entry* sorted = sort_dict(dict);
    print_dict(sorted);
    free_dict(dict);
    free_dict(sorted);
}
