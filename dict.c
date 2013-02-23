#include <string.h>
#include "dict.h"

// initialize the dict provided for use
void init_dict(dict_t *d)
{
    int i;

    for(i=0; i < MAX_ENTRIES; i++) {
        memset(d->entries[i].key, '\0', KEY_LENGTH);
        memset(d->entries[i].value, '\0', VALUE_LENGTH);
    }
}

int add_kv(dict_t *d, const char *key, const char *value)
{
    if(strlen(key) > KEY_LENGTH || strlen(value) > VALUE_LENGTH)
	return 0;
    
    for(int i=0;i<MAX_ENTRIES;i++) {
	if(!strncmp(key, d->entries[i].key, strlen(key))) {
	    strncpy(d->entries[i].value, value, strlen(value));
	    return 1;
	} else if(strlen(d->entries[i].key) == 0) {
	    strncpy(d->entries[i].value, value, strlen(value));
	    strncpy(d->entries[i].key, key, strlen(key));
	    return 1;
	}
    }
    return 0;
}

void remove_kv(dict_t *d, const char *key)
{
    for(int i=0;i<MAX_ENTRIES;i++) {
	if(!strncmp(key, d->entries[i].key, strlen(key))) {
	    memset(d->entries[i].key, '\0', KEY_LENGTH);
	    memset(d->entries[i].value, '\0', VALUE_LENGTH);
	}
    }
}

int lookup_kv(dict_t *d, const char *key, char *value)
{
    if(strlen(key) > KEY_LENGTH)
	return 0;
    
    for(int i=0;i<MAX_ENTRIES;i++) {
	if(!strncmp(key, (*d).entries[i].key, strlen(key))) {
	    strncpy(value, (*d).entries[i].value, VALUE_LENGTH);
	    return 1;
	}
    }

    return 0;
}

