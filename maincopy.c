#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 1024

char* getfilename()
{
    char buffer[BUFFER_SIZE]; 
    sprintf(buffer, "s", __FILENAME__);

    char* filename = strstr(buffer, ".");
    memcpy(filename, "\0", strlen(filename));

    return buffer;
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
    char buffer;
    int i = 0;
    while((buffer = getc(old[i++])) != EOF)
	putc(buffer, new);

    fclose(old);
    fclose(new);
}

int main(int argc, char** argv)
{
    char* filename = getfilename();

    char buffer[BUFFER_SIZE];
    sprintf(buffer, "%s.c", filename);
    FILE* old = checked_fopen(filename, "r");

    char buffer[BUFFER_SIZE];
    sprintf(buffer, "%sN.c", filename);
    FILE* new = checked_fopen(filename, "w");

    write_new(old, new);
    
    return 0;
}
