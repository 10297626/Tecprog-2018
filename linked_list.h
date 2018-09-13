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

lista cria();

void destroi(lista l);

lista insere(lista l, elemento *val, char *n);

elemento busca(lista l, char *n);

elemento retira(lista l, elemento  *val);


  
  
