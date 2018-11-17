/*//////////////////////////////////////////////////////////////////////
Nome: Henrique Suzuki                 NUSP: 10297626
Nome: Rubens Gomes Neto               NUSP:  9318484
//////////////////////////////////////////////////////////////////////*/

//#include guards
#ifndef linkedlist_h
#define linkedlist_h

#include "advlib.h"

typedef Elemento TipoDaLista;

typedef struct node {
	TipoDaLista info;
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

Lista l_insere(Lista l, TipoDaLista val);

TipoDaLista l_busca(Lista l, char *n);

TipoDaLista l_retira(Lista l, TipoDaLista  val);

#endif /* linkedlist_h */
