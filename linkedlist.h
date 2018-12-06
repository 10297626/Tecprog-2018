/*//////////////////////////////////////////////////////////////////////
Nome: Henrique Suzuki                 NUSP: 10297626
Nome: Rubens Gomes Neto               NUSP:  9318484
//////////////////////////////////////////////////////////////////////*/

//#include guards
#ifndef linkedlist_h
#define linkedlist_h

//#include "base.h"

//typedef void* TipoDaLista;

// definicao de um no de uma lista
typedef struct node {
	char* name;
	int tipo;
	void* info;
	struct node* next;
} node;
typedef struct node* Node;

// struct que guarda a cabeca da lista, efetivamente guardando o local da lista
typedef struct lista {
	Node head;
	int count;
} lista;
typedef lista* Lista;

Lista l_cria();
void l_destroi(Lista);
Lista l_insere(Lista, char*, int, void*);
Node l_busca(Lista, char*);
Lista l_retira(Lista, char*);
void printList(Lista);

#endif /* linkedlist_h */
