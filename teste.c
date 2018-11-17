/*//////////////////////////////////////////////////////////////////////
Nome: Henrique Suzuki                 NUSP: 10297626
Nome: Rubens Gomes Neto               NUSP: 9318484
//////////////////////////////////////////////////////////////////////*/

#include <stdio.h>
#include <string.h>
#include "advlib.h"
#include "hashtable.h"
#include "linkedlist.h"

int main(){

	//teste de hash table
	//criação da hash table
	TabSim tab = ht_cria(30);
	printf("hash table criada\n");
	//item exemplo
	Elemento* ele = cria_ele();
	char *n = "ola";
	//char *ptrn = n;
	ele->nome = n;
	char *key = "alo";
	//char *ptrkey = key;

	//inserção na hash table
	if(ht_insere(tab, key, ele) == 1) {
		printf("sucesso na insercao da hash table\n");
	}

	//busca na hash table
	if(ht_busca(tab, key) == ele) {
		printf("sucesso na busca da hash table\n");
	}

	//retirada da hash table
	if(ht_retira(tab, key) == 1) {
		printf("sucesso na retirada da hash table \n");
	}
	
	//busca após retirada
	if(ht_busca(tab,key) == NULL) {
		printf("item nao esta na hash table\n");
	}

	//destroi a hash table
	ht_destroi(tab);
	printf("hash table destruida\n\n");

	//teste da lista ligada
	//criando a lista
	Lista l = l_cria();
	printf("lista criada\n");

	//inserindo um elemento
	l = l_insere(l, ele);
	printf("sucesso na insercao da lista\n");
	/*
	//busca na lista
	if (ele == l_busca(l, ele->nome)) {
		printf("sucesso na busca da lista\n");
	}
	
	//retirando um elemento
	if (ele == l_retira(l, ele)) {
		printf("sucesso na retirada da lista\n");
	}
	
	//busca na lista
	if (l_busca(l, "ola") == NULL) {
		printf("item nao esta na lista\n");
	}
	*/
	l_destroi(l);
	printf("lista destruida\n\n");
	
}
