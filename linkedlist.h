/*//////////////////////////////////////////////////////////////////////
Nome: Henrique Suzuki                 NUSP: 10297626
Nome: Rubens Gomes Neto               NUSP: 9318484
//////////////////////////////////////////////////////////////////////*/

//#include guards
#ifndef linkedlist_h
#define linkedlist_h

#include "advlib.h"

typedef struct node {
	Elemento ele;
	struct node *next;
} node;
typedef node* Node;

typedef struct lista {
	Node head;
	int count;
} lista;
typedef lista* Lista;

Lista l_cria();

void l_destroi(Lista l);

Lista l_insere(Lista l, Elemento ele);

Elemento l_busca(Lista l, char *nome);

Elemento l_retira(Lista l, Elemento  val);

#endif /* linkedlist_h */
