#include "advlib.h"

typedef struct{
  elemento ele;
  struct node next;
  char *nome;
}node;

typedef struct{
  node head;
  node last;
  int count;
}lista

lista l_cria();

void l_destroi(lista l);

lista l_insere(lista l, elemento *val, char *n);

elemento l_busca(lista l, char *n);

elemento l_retira(lista l, elemento  *val);


  
  
