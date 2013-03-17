#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dict.h"

#define ADD_FAIL 1
#define LOOKUP_FAIL 2
#define REMOVE_FAIL 3

int test_add(dict_t* dict, char* key, char* value)
{
    printf("Adding dict[%s] = %s\n", key, value);
    if(!add_kv(dict, key, value)) {
	printf("Failed to add: %s\n", key);
	return 0;
    } else {
	printf("Success!\n\n");
    }
	   
    return 1;
}

int test_lookup(dict_t* dict, char* key, char* real_value)
{
    printf("Looking up dict[%s]\n", key);
    char value[VALUE_LENGTH];
    if(!lookup_kv(dict, key, value)) {
	printf("Failed to lookup dict[%s]\n", key);
	return 0;
    } else {
	printf("Success!\n\n");
    }

    if(strncmp(real_value, value, strlen(value))) {
	printf("Failed to lookup correct value: %s vs. %s\n", value, real_value);
	return 0;
    } 

    return 1;
}

int main(int argc, char** argv)
{
    dict_t test_dict;
    init_dict(&test_dict);

    if(!test_add(&test_dict, "test", "1"))
	exit(ADD_FAIL);
    if(!test_add(&test_dict, "this is a key", "this is a value"))
	exit(ADD_FAIL);

    if(!test_lookup(&test_dict, "test", "1"))
	exit(LOOKUP_FAIL);
    if(!test_lookup(&test_dict, "this is a key", "this is a value"))
	exit(LOOKUP_FAIL);

    printf("Removing dict[%s]\n", "test");
    char value[VALUE_LENGTH];
    remove_kv(&test_dict, "test");
    if(lookup_kv(&test_dict, "test", value)) {
	printf("Failed to remove...\n");
	exit(REMOVE_FAIL);
    } else {
	printf("Success!\n\n");
    }

    if(!test_add(&test_dict, "this is a key", "duplicate"))
	exit(ADD_FAIL);
    remove_kv(&test_dict, "this is a key");
    if(lookup_kv(&test_dict, "this is a key", value)) {
	printf("There were two instances of %s in dict\n", "this is a key");
	exit(REMOVE_FAIL);
    }

    printf("Freeing dict\n");	 
    free_dict(&test_dict);
	
    return 0;
}
