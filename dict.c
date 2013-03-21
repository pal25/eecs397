#include <string.h>
#include <stdlib.h>
#include "dict.h"

// initialize the dict provided for use
void init_dict(dict_t *d)
{
    // allocate an "array" of keyvaluepair_t structures
    d->entries = (keyvaluepair_t *)calloc(MAX_ENTRIES, sizeof(keyvaluepair_t));

    int i;
    for(i=0; i<MAX_ENTRIES; i++) {
	d->entries[i].key = NULL;
	d->entries[i].value = NULL;
    }
}

void free_dict(dict_t *d)
{
    int i;
    // free each keyvaluepair_t's members that are non-NULL
    for(i=0; i<MAX_ENTRIES; i++) {
	if(d->entries[i].key != NULL) {
	    free(d->entries[i].key);
	    d->entries[i].key = NULL;
	    free(d->entries[i].value);
	    d->entries[i].value = NULL;
	}
    }

    free(d->entries);
}

int add_kv(dict_t *d, const char *key, const char *value)
{
    int i;
    for(i=0; i<MAX_ENTRIES; i++) {
        if(d->entries[i].key != NULL && strncmp(d->entries[i].key, key, strlen(key)) == 0) {
	    strcpy(d->entries[i].value, value);
	    return 1;
	}
    }

    for(i=0; i<MAX_ENTRIES; i++) {
	if(d->entries[i].key == NULL) {
	    d->entries[i].key = calloc(KEY_LENGTH, sizeof(char));
	    strcpy(d->entries[i].key, key);
	    d->entries[i].value = calloc(VALUE_LENGTH, sizeof(char));
	    strcpy(d->entries[i].value, value);
	    return 1;
	}
    }
    return 0;
}

void remove_kv(dict_t *d, const char *key)
{
    int i;    
    for(i=0; i<MAX_ENTRIES; i++) {
	if(d->entries[i].key != NULL && strncmp(d->entries[i].key, key, strlen(key)) == 0) {
	    free(d->entries[i].key);
	    d->entries[i].key = NULL;
	    free(d->entries[i].value);
	    d->entries[i].value = NULL;
	}
    }
}
    
int lookup_kv(dict_t *d, const char *key, char *value)
{
    int i;
    for(i=0; i<MAX_ENTRIES; i++) {
	if(d->entries[i].key != NULL && strncmp(d->entries[i].key, key, strlen(key)) == 0) {
	    strcpy(value, d->entries[i].value);
	    return 1;
	}
    }
    return 0;
}

