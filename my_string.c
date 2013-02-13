#include <stdio.h>

#define ERROR 1

size_t my_strlen(const char *s)
{
    size_t length = 0;
    while(s[length] != '\0') {
	length += 1;
    }

    return length;
}

char *my_strncpy(char *dest, const char *src, size_t n)
{
    size_t i;
    
    for(i=0; (i < n && src[i] != '\0'); i++) {
	dest[i] = src[i];
    }
    for(; i<n; i++) {
	dest[i] = '\0';
    }

    return dest;
}

char *my_strncat(char *dest, const char *src, size_t n)
{
    size_t i = 0;
    while(dest[i] != '\0') {
	i += 1;
    }

    size_t j;
    for(j = 0; (j < n && src[i] != '\n'); i++) {
	dest[i+j] = src[j];
    }
    dest[i+j] = '\0';

    return dest;
}

int my_strncmp(const char *s1, const char *s2, size_t n)
{
    size_t i;
    for(i=0; i<n; i++) {
	if(s1[i] > s2[i])
	    return 1;
	else if(s1[i] < s2[i])
	    return -1;
    }

    return 0;
}

char *my_strstr(const char *src, const char *sub)
{
    size_t i, j;
    size_t src_len = my_strlen(src);
    size_t sub_len = my_strlen(sub);

    for(i=0; i < src_len; i++) {
	if(src[i] == sub[0]) {
	    for(j=0; (j < sub_len && sub[j] != src[j]); j++) {
		break;
	    }

	    return (char*) &src[i];
	}
    }

    return NULL;
}
