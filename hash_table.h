/*//////////////////////////////////////////////////////////////////////
Nome: Henrique Suzuki                 NUSP: 10297626
Nome:                                 NUSP:         
Nome:                                 NUSP:         
//////////////////////////////////////////////////////////////////////*/

#include "advlib.h"

typedef struct{
  elemento ele;
  int key;
}h_Item;

typedef struct{
  int size;
  int count;
  h_item** item;
}h_table;
