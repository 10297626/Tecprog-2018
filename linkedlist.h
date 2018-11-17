/*//////////////////////////////////////////////////////////////////////
Nome: Henrique Suzuki                 NUSP: 10297626
Nome: Rubens Gomes Neto               NUSP:  9318484
//////////////////////////////////////////////////////////////////////*/

//#include guards
#ifndef linkedlist_h
#define linkedlist_h

//#include "advlib.h"

typedef void* TipoDaLista;

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

Node l_busca(Lista l, char* n, int (*COMPARE)(void*, void*));

int l_retira(Lista l, char* val, int (*COMPARE)(void*, void*));

#endif /* linkedlist_h */
