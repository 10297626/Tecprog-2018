/*//////////////////////////////////////////////////////////////////////
Nome: Henrique Suzuki                 NUSP: 10297626
Nome: Rubens Gomes Neto               NUSP:  9318484
//////////////////////////////////////////////////////////////////////*/

//#include guards
#include <stdlib.h>
#include <stdio.h>
#include "base.h"
#include "linkedlist.h"
#include "hashtable.h"
#include "advlib.h"

Elemento* cria_ele() {
	Elemento* ele = malloc(sizeof(Elemento));
	ele->nome = NULL;
	ele->curta = NULL;
	ele->longa = NULL;
	ele->ativo = False;
	//ele->visivel = False;
	ele->conhecido = False;
	ele->contem = ht_cria(10);
	//ele->acao = l_cria();
	//ele->detalhe = malloc(sizeof(Spec));
	//ele->detalhe->L = malloc(sizeof(Lugar));
	return ele;
}

/**
 * descreve o elemento para o jogador
 * @param  e1 elemento a ser descrito
 * @param  e2 deve ser NULL
 * @return    retorna 1 se obteve sucesso, 0 caso contrario
 */
Boolean examinar(Elemento* e1, Elemento* e2) { // função para examinar o objeto
	if(e1 == NULL || e2 != NULL)
		return False; //apenas 1 elemento pode ser analisado por vez

	if(!(e1->conhecido)) {
		printf("%s\n", e1->longa);
		e1->conhecido = 1;
	} else
		printf("%s\n", e1->curta);

	return True;
};

/* Macros para testar propriedades comuns */
#define Ativo(x) (x)->detalhe.obj.ativo
#define Visivel(x) (x)->detalhe.obj.visivel
#define conhecido(x) (x)->conhecido

/**
 * Move um item do mundo para o inventário
 * @param  e1 elemento a ser tranferido
 * @param  e2 NULL
 * @return    status de sucesso
 */
Boolean pegar(Elemento* e1, Elemento* e2) { //função para pegar o objeto

	return False;
};

/**
 * Remove um item do inventário e o coloca no mundo
 * @param  e1 objeto a ser largado
 * @param  e2 NULL
 * @return    status de sucesso
 */
Boolean largar(Elemento* e1, Elemento* e2) { // função para soltar o objeto caso ele esteja no inventário
	return False;
};
