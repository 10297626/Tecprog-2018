/*//////////////////////////////////////////////////////////////////////
Nome: Alessandro Bezerra da Silva     NUSP: 10284351
Nome: Henrique Suzuki                 NUSP: 10297626
Nome: Rubens Gomes Neto               NUSP: 9318484
//////////////////////////////////////////////////////////////////////*/

#include "advlib.h"

typedef struct node{
  elemento ele;
  struct node next;
  char *nome;
}node;

typedef struct lista{
  node head;
  node last;
  int count;
}lista;

lista l_cria();

void l_destroi(lista l);

lista l_insere(lista l, elemento *val, char *n);

elemento l_busca(lista l, char *n);

elemento l_retira(lista l, elemento  *val);


  
  
