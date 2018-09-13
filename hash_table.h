/*//////////////////////////////////////////////////////////////////////
Nome: Henrique Suzuki                 NUSP: 10297626
Nome:                                 NUSP:         
Nome:                                 NUSP:         
//////////////////////////////////////////////////////////////////////*/

#include "advlib.h"

typedef struct{
  elemento ele;
  char* key;
}simbol;

typedef struct{
  int size;
  int count;
  simbol** item;
}tabsim;

tabsim Cria(int tam);

void destroi(tabsim t);

int insere(tabsim t, char *n,elemento *val);

elemento *busca(tabsim t, char *n);

int retira(tabsim t, char*n);

