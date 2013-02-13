#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "my_string.h"

#define TEST_STRING_LENGTH 100

int test_strlen();
int test_strncat();
int test_strncpy();
int test_strstr();

int main(int argc, char** argv) {

    int failure = 0;
    
    if(test_strlen() != 0)
	failure = 1;
    if(test_strncat() != 0)
	failure = 1;
    if(test_strncpy() != 0)
	failure = 1;
    if(test_strstr() != 0)
	failure = 1;

    if (failure)
	return 1;
    
    return 0;
}

int test_strlen()
{
    char s1[TEST_STRING_LENGTH];

    int failure = 0;

    s1[0] = '\0';
    if(strlen(s1) != my_strlen(s1)) {
	failure = 1;
	printf("Failed Test strlen(%s): Good: %d Bad: %d\n", s1, (int)strlen(s1), (int)my_strlen(s1));
    }


    memcpy(s1, "This is a test", strlen("This is a test"));
    if(strlen(s1) != my_strlen(s1)) {
	failure = 1;
	printf("Failed Test strlen(%s): Good: %d Bad: %d\n", s1, (int)strlen(s1), (int)my_strlen(s1));
    }

    
    if(failure)
	return 1;

    return 0;
}

int test_strncat()
{
    char s1[TEST_STRING_LENGTH];
    char s2[TEST_STRING_LENGTH];
    char *result1, *result2;

    int failure = 0;

    memset(s1, 0, TEST_STRING_LENGTH);
    memset(s2, 0, TEST_STRING_LENGTH);

    result1 = strncat(s1, "", TEST_STRING_LENGTH);
    memset(s1, 0, TEST_STRING_LENGTH);
    result2 = my_strncat(s1, "", TEST_STRING_LENGTH);

    if( result1 != result2 ) {
        printf("strncat() != my_strncat()\n");
        failure = 1;
    }

    memset(s1, 0, TEST_STRING_LENGTH);
    memset(s2, 0, TEST_STRING_LENGTH);

    strncat(s1, "hello, ", TEST_STRING_LENGTH);
    strncat(s1, "world", TEST_STRING_LENGTH - strlen(s1));
    my_strncat(s2, "hello, ", TEST_STRING_LENGTH);
    my_strncat(s2, "world", TEST_STRING_LENGTH - strlen(s1));
   
    if( 0 != strcmp(s1, s2) ) {
        printf("results of strncat() and my_strncat() with multiple calls different\n");
        failure = 1;
    } 

    memset(s1, 0, TEST_STRING_LENGTH);
    memset(s2, 0, TEST_STRING_LENGTH);

    strncat(s1, "hello, ", 3);
    my_strncat(s2, "hello, ", 3);

    if( 0 != strcmp(s1, s2) ) {
        printf("results of strncat() \"%s\" and my_strncat() \"%s\"with limited copy different\n", s1, s2);
        failure = 1;
    } 

    if( failure ) {
	return 1;
    } 

    return 0;
}


int test_strncpy()
{
    char s1[TEST_STRING_LENGTH];
    char s2[TEST_STRING_LENGTH];
    char src[TEST_STRING_LENGTH];
    char *result1, *result2;

    int failure = 0;

    memset(s1, 0, TEST_STRING_LENGTH);
    memset(s2, 0, TEST_STRING_LENGTH);

    strcpy(src, "");
    result1 = strncpy(s1, src, TEST_STRING_LENGTH);
    strcpy(src, "");
    result2 = my_strncpy(s1, src, TEST_STRING_LENGTH);

    if( result1 != result2 ) {
        printf(
            "strncpy(\"%s\", \"%s\", %d) returned %p != my_strncpy(\"%s\", \"%s\", %d) returned %p\n",
            s1, src, TEST_STRING_LENGTH, result1, s2, src, TEST_STRING_LENGTH,
            result2);
        failure = 1;
    }

    strcpy(src, "ab");
    memset(s1, 0, TEST_STRING_LENGTH);
    result2 = my_strncpy(s1, src, TEST_STRING_LENGTH);

    if( !strcmp(s2, "ab") ) {
        printf("failed to copy \"%s\"\n", "ab");
        failure = 1;
    }

    strcpy(src, "abcdefghijklmnopqrstuvwxyz");
    memset(s1, 0, TEST_STRING_LENGTH);
    result2 = my_strncpy(s1, src, 3);
    s1[3] = '\0';

    if( !strcmp(s2, "abc") ) {
        printf("failed to copy \"%s\" with short\n", "abc");
        failure = 1;
    }


   
    if( failure ) {
	return 1;
    } 

    return 0;
}

int test_strstr()
{
    char s1[TEST_STRING_LENGTH];
    char s2[TEST_STRING_LENGTH];
    char *result1, *result2;

    int failure = 0;

    memset(s1, 0, TEST_STRING_LENGTH);
    memset(s2, 0, TEST_STRING_LENGTH);

    result1 = strstr(s1, "");
    result2 = my_strstr(s1, "");

    if ( result1 != result2 ) {
        printf("strstr() did not match return value for my_strstr()\n");
        failure = 1;
    }

    strcpy(s1, "abcdefghijklmnopqrstuvwxyz");
    result1 = my_strstr(s1, "lmno");

    if( 0 != strcmp(strstr(s1, "lmno"), result1) ) {
        printf("failed to find substring with strstr expected \"%s\" not \"%s\"\n", strstr(s1, "lmno"), result1);
        failure = 1;
    }
   
    strcpy(s1, "abcdefghijklmnopqrstuvwxyz");
    result1 = my_strstr(s1, "LMNO");

    if( NULL != result1 ) {
        printf("my_strstr() should have returned null but returned \"%s\" (%p) instead\n", result1, result1);
        failure = 1;
    }
   
    if( failure ) {
	return 1;
    } 

    return 0;
}
