/*//////////////////////////////////////////////////////////////////////
Nome: Alessandro Bezerra da Silva     NUSP: 10284351
Nome: Henrique Suzuki                 NUSP: 10297626
Nome: Rubens Gomes Neto               NUSP: 9318484
//////////////////////////////////////////////////////////////////////*/

//#include guards
#ifndef linkedlist_h
#define linkedlist_h

#include "advlib.h"

typedef struct node{
  elemento *ele;
  struct node *next;
}node;

typedef struct lista{
  node *head;
  int count;
}lista;

lista* l_cria();

void l_destroi(lista *l);

lista* l_insere(lista *l, elemento *ele);

elemento* l_busca(lista *l, char *nome);

elemento* l_retira(lista *l, elemento  *val);

#endif /* linkedlist_h */
  
  
