#include "advlib.h"

typedef struct{
  elemento ele;
  struct node next;
}node;

typedef struct{
  node head;
  int count;
  char *nome;
}lista

lista cria();

void destroi(lista l);

lista insere(lista l, elemento *val);

elemento busca(lista l, char *n);

elemento retira(lista l, elemento  *val);


  
  
