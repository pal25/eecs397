#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 1024

void getfilename(char* buffer)
{
    sprintf(buffer, "%s", __FILE__);

    char* filename = strstr(buffer, ".");
    memcpy(filename, "\0", strlen(filename));
}

FILE* checked_fopen(char* filename, char* perm)
{
    FILE* file = fopen(filename, perm);
    if(file == NULL) {
	fprintf(stderr, "Failed to open %s\n", filename);
	exit(1);
    }

    return file;
}

void write_new(FILE* old, FILE* new)
{
    int buffer;
    while((buffer = getc(old)) != EOF)
	putc(buffer, new);

    fclose(old);
    fclose(new);
}

int main(int argc, char** argv)
{
    char filename[BUFFER_SIZE];
    getfilename(filename);

    char buffer[BUFFER_SIZE];
    sprintf(buffer, "%s.c", filename);
    FILE* old = checked_fopen(filename, "r");
    sprintf(buffer, "%sN.c", filename);
    FILE* new = checked_fopen(filename, "w");

    write_new(old, new);
    
    return 0;
}
