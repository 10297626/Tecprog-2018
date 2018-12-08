/*//////////////////////////////////////////////////////////////////////
Nome: Henrique Suzuki                 NUSP: 10297626
Nome: Rubens Gomes Neto               NUSP:  9318484
//////////////////////////////////////////////////////////////////////*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedlist.h"

/**
 * Cria uma lista ligada
 * @return l
 */
Lista l_cria() {
	Lista l = malloc(sizeof(lista));
	l->head = (Node) 0;
	l->count = 0;
	return l;
}

/**
 * Destroi a lista ligada, liberando o espaço alocado pela lista e seus nodes
 * @param l lista a ser destruida
 */
void l_destroi(Lista l) {
	Node atual = l->head;
	Node prox;
	while(atual != (Node) 0) {
		prox = atual->next;
		free(atual->name);
		free(atual);
		atual = prox;
	}
	free(l);
}

/**
 * Insere novo item na frente da lista
 * @param  l   lista a receber o item
 * @param  val item a ser adicionado
 * @return     retorna a lista atualizada
 */
Lista l_insere(Lista list, char* name, int tipo, void* val) {
	Lista l;
	if(list == (Lista) 0)
		l = l_cria();
	else
		l = list;
	Node new = malloc(sizeof(node));
	new->name = malloc(strlen(name)+1);
	strcpy(new->name, name);
	new->tipo = tipo;
	new->value = val;
	new->next = l->head;
	l->head = new;
	l->count++;
	return l;
}

/**
 * Busca linearmente um item na lista e retorna o elemento
 * @param  l          lista para busca
 * @param  n          item a ser encontrado na lista
 * @param  (*COMPARE) funcao usada para comparar os itens da lista
 * @return            retorna o Node encontrado , ou NULL caso não encontre
 */
Node l_busca(Lista l, char* name) {
	if(l == (Lista) 0)
		return 0;
	Node atual = l->head;
	while(atual != (Node) 0) {
		if(strcmp(atual->name, name) == 0) {
			return atual;
		}
		atual = atual->next;
	}
	return 0;
}

/**
 * Retira um item da lista ligada
 * @param  l          lista de onde tirar o elemento
 * @param  val        elemento a ser retirado
 * @param  (*COMPARE) funcao usada para comparar os itens da lista
 * @return            retorna a lista atualizada
 */
Lista l_retira(Lista l, char* name) {
	Node atual = l->head;
	Node anterior = atual;
	while(atual != (Node) 0) {
		if(strcmp(atual->name, name) == 0) {
			if(atual == l->head) {//se for o primeiro da lista
				l->head = atual->next;
				free(atual);
			} else { // caso esteja no meio da lista
				anterior->next = atual->next;
				free(atual);
			}
			return l;
		}
		anterior = atual;
		atual = atual->next;
	}
	return l;
}

/**
 * Imprime conteudos da lista
 * @param l lista a ser impressa
 */
void printList(Lista l) {
	if(l == (Lista) 0)
		return;
	Node atual;
	for (atual = l->head; atual != (Node) 0; atual = (Node) atual->next)
		printf("\t%s\n", atual->name);
}
