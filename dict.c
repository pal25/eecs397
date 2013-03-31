#include <stdlib.h>
#include <string.h>
#include "dict.h"

dict_entry* alloc_dict(void)
{
    dict_entry* dict = malloc(sizeof(dict_entry));
    dict->key = NULL;
    dict->value = NULL;
    
    INIT_LIST_HEAD(&(dict->list));
    
    return dict;
}

void free_dict(dict_entry* d)
{
    struct list_head *pos, *temp;
    dict_entry* entry;
    
    list_for_each_safe(pos, temp, &d->list) {
	entry = list_entry(pos, dict_entry, list);
	list_del(pos); // Remove the list
	free(entry->key); // Remove the key
	free(entry->value); // Remove the value
	free(entry); // Remove the containing struct
    }

    free(d); // Remove the head node
}

int add_kv(dict_entry* d, char* key, char* value)
{
    struct list_head *pos, *temp;
    dict_entry* entry;

    list_for_each_safe(pos, temp, &d->list) {
	entry = list_entry(pos, dict_entry, list);
	if(!strcmp(key, entry->key)) {
	    entry->value = realloc(entry->value, strlen(value)+1);
	    strcpy(entry->value, value);
	    return 1;
	}
    }
    
    entry = malloc(sizeof(dict_entry));
    entry->key = calloc(strlen(key)+1, sizeof(char));
    strcpy(entry->key, key);
    entry->value = calloc(strlen(value)+1, sizeof(char));
    strcpy(entry->value, value);

    list_add(&(entry->list), pos);
    
    return 1;
}

void remove_kv(dict_entry* d, char* key)
{
    struct list_head *pos, *temp;
    dict_entry* entry;

    list_for_each_safe(pos, temp, &d->list) {
	entry = list_entry(pos, dict_entry, list);
	if(!strcmp(key, entry->key)) {
	    free(entry->value);
	    free(entry->key);
	    list_del(pos);
	    free(entry);
	    return;
	}
    }
}

int lookup_kv(dict_entry* d, char* key, char* value)
{
    struct list_head *pos, *temp;
    dict_entry* entry;

    list_for_each_safe(pos, temp, &d->list) {
	entry = list_entry(pos, dict_entry, list);
	if(!strcmp(key, entry->key)) {
	    strcpy(value, entry->value);
	    return 1;
	}
    }
    return 0;
}
