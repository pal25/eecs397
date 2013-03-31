#ifndef _DICT_H
#define _DICT_H

#include "list.h"

typedef struct {
  char *key;
  char *value;
  struct list_head list;
}dict_entry;

dict_entry *alloc_dict(void);
void free_dict(dict_entry *d);
int add_kv(dict_entry *d,  char *key,  char *value);
void remove_kv(dict_entry *d,  char *key);
int lookup_kv(dict_entry *d,  char *key, char *value);

#endif
