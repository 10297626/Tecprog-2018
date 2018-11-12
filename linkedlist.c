/*//////////////////////////////////////////////////////////////////////
Nome: Henrique Suzuki                 NUSP: 10297626
Nome: Rubens Gomes Neto               NUSP:  9318484
//////////////////////////////////////////////////////////////////////*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "linkedlist.h"
#include "advlib.h"

/**
 * Cria uma lista ligada
 * @return 1
 */
Lista l_cria() {
	Lista l = malloc(sizeof(lista));
	l->count = 0;
	l->head = NULL;
	return l;
}

/**
 * Destroi a lista ligada, liberando o espaço alocado pela lista e seus nodes
 * @param l lista a ser destruida
 */
void l_destroi(Lista l) {
	Node atual = l->head;
	Node prox = l->head->next;
	while(prox != NULL) {
		/*atual->ele = NULL;
		atual->next = NULL;*/
		free(atual);
		atual = prox;
		prox = prox->next;
	}
	free(atual);
	free(l);
	l = NULL;
}

/**
 * Insere novo item na frente da lista
 * @param  l   lista a receber o item
 * @param  val item a ser adicionado
 * @return     retorna a lista atualizada
 */
Lista l_insere(Lista l, Elemento val) {
	Node new = malloc(sizeof(node));
	new->ele = val;
	new->next = l->head;
	l->head = new;
	l->count++;
	return l;
}

/**
 * Busca linearmente um item na lista e retorna o elemento
 * @param  l lista para busca
 * @param  n item a ser encontrado na lista
 * @return   retorna o Elemento encontrado , ou NULL caso não encontre
 */
Elemento l_busca(Lista l, char *n) {
	Node atual = l->head;

	while(atual != NULL) {
		//char *na = atual->ele->nome;
		if(strcmp(atual->ele->nome, n) == 0) {
			return atual->ele;
		}
		atual = atual->next;
	}
	return NULL;      
}

/**
 * Retira um item da lista ligada
 * @param  l   lista de onde tirar o elemento
 * @param  val elemento a ser retirado
 * @return     [description]
 */
Elemento l_retira(Lista l, Elemento val) {
	Node atual = l->head;
	Node anterior = atual;
	while(atual != NULL) {
		if(strcmp(atual->ele->nome, val->nome) == 0) {
			if(atual == l->head) {//se for o primeiro da lista
				l->head = atual->next;
				atual->next = NULL;
			} else { // caso esteja no meio da lista
				anterior->next = atual->next;
				atual->next = NULL;
			}
			return atual->ele;
		}
		anterior = atual;
		atual = atual->next;
	}
	return NULL;
}
