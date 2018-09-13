/*//////////////////////////////////////////////////////////////////////
Nome: Henrique Suzuki                 NUSP: 10297626
Nome:                                 NUSP:         
Nome:                                 NUSP:         
//////////////////////////////////////////////////////////////////////*/

#include <stdlib.h>
#include <string.h>
#include "hash_table.h"
#include "advlib.h"

static h_item* new_item(const elemento* ele, const int* key){
  h_item* i = malloc(sizeof(h_item));
  
}
static ht_item* ht_new_item(st char* k, const char* v) {
    ht_item* i = malloc(sizeof(ht_item));
    i->key = strdup(k);
    i->value = strdup(v);
    return i;
}
