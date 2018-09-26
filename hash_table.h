/*//////////////////////////////////////////////////////////////////////
Nome: Henrique Suzuki                 NUSP: 10297626
Nome:                                 NUSP:         
Nome:                                 NUSP:         
//////////////////////////////////////////////////////////////////////*/

#include "advlib.h"

typedef struct{
  elemento ele;
  char* key;
}simbolo;

typedef struct{
  int size;
  simbolo **tab;
}tabsim;

tabsim ht_cria(int tam);

void ht_destroi(tabsim t);

int ht_insere(tabsim t, char *n,elemento *val);

elemento ht_busca(tabsim t, char *n);

int ht_retira(tabsim t, char*n);

