/*//////////////////////////////////////////////////////////////////////
Nome: Henrique Suzuki                 NUSP: 10297626
Nome: Rubens Gomes Neto               NUSP:  9318484
//////////////////////////////////////////////////////////////////////*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
//#include "base.h"
#include "linkedlist.h"
#include "hashtable.h"


/**
 * Cria uma nova entrada para a hash table, associando a key ao cojunto de dados info
 * @param  info conjunto de dados a ser adicionado na tabela
 * @param  key  chave usada para encontrar os dados
 * @return      retorna o endereço do simbolo criado
 */
/*static Simbolo ht_novosim(void* info, char *key) {
	Simbolo i = malloc(sizeof(simbolo));
	i->key = key;
	i->info = info;
	return i;
}*/

/**
 * Cria uma tabela de simbolos do tamanho especificado para guardar os dados
 * @param  tam tamanho da tabela a ser criada
 * @return     retorna o endereço da tabela de simbolos criada
 */
TabSim ht_cria(int tam) {
	TabSim tab = malloc(sizeof(tabsim));
	tab->size = tam;
	tab->count = 0;
	tab->simbolos = malloc(tam*sizeof(Lista));//calloc((size_t)tab->size, sizeof(Lista));
	return tab;
}

/**
 * Deleta o simbolo
 * @param sim simbolo a ser deletado
 */
/*static void ht_delsim(Simbolo sim) {
	free(sim->info);
	sim->info = NULL;
	free(sim->key);
	sim->key = NULL;
	free(sim);
	sim = NULL;
}*/

/**
 * Apaga todos os simbolos e a tabela liberando o espaço da memoria
 * @param tab tabela a ser apagada
 */
void ht_destroi(TabSim tab) {
	int i;
	for(i = 0; i < tab->size; i++) {
		Lista l = tab->simbolos[i];
		if(l != (Lista) 0)
			l_destroi(l);
	}
	free(tab->simbolos);
	free(tab);
}

/**
 * Calcula o codigo hash e retorna o indice para tentar primeiro
 * @param  key chave dos dados
 * @param  tam tamanho da tabela de simbolos
 * @return     indice a ser checado como a primeira tentativa para os dados
 */
static int hashcode(char *key, int tam) {
	//soma todos os ascii de cada caractere da key
	char c = *key;
	int asc = 0;
	while(c != 0) {
		asc += (int) c;
		c = *key++;
	}
	//retorna o resultado da divisão inteira da soma pelo tamanho da hash table
	return asc % tam;
}

/**
 * Encontra o indice dos dados associados a key
 * @param  tab tabela de dados
 * @param  key chave associada
 * @return     retorna o conjunto de dados
 */
Node ht_busca(TabSim tab, char *key) {
	if(tab == (TabSim) 0 || tab->size == 0)
		return 0;
	printf("testando1\n");

	int hi = hashcode(key, tab->size);
	printf("testando2\n");

	//busca o item, testando a lista
	if(tab->simbolos[hi] != (Lista) 0) {
		if(tab->simbolos[hi]->count == 1 && strcmp(tab->simbolos[hi]->head->name, key) == 0) {
			printf("encontrou1: ");
			printf("%s\n", tab->simbolos[hi]->head->name);
			return tab->simbolos[hi]->head;
		}
		Node val;
		if((val = l_busca(tab->simbolos[hi], key))){
			printf("encontrou2: %s\n", val->name);
			return val; //encontrou
		}
	}
	printf("testando3\n");

	return 0;
}

/**
 * Insere um novo conjunto de dados a tabela de simbolos
 * @param  tab  tabela de simbolos
 * @param  key  chave associada
 * @param  value conjunto de dados
 * @return      retorna True se obter sucesso, e False caso contrário
 */
TabSim ht_insere(TabSim symTable, char *key, int tipo, void* value) {
	TabSim tab;
	if(symTable == (TabSim) 0)
		tab = ht_cria(10);
	else
		tab = symTable;

	//manda o codigo ASCII do n;
	int hi = hashcode(key, tab->size);

	if(tab->simbolos[hi] == (Lista) 0) {
		Lista l = l_cria();
		l = l_insere(l, key, tipo, value);
		tab->simbolos[hi] = l;
		tab->count++;
		return tab;
	}
	if(!ht_busca(tab, key)) {
		tab->simbolos[hi] = l_insere(tab->simbolos[hi], key, tipo, value);
		tab->count++;
		return tab;
	}
	return tab;
}

/**
 * Retira um simbolo da tabela de dados associado a key
 * @param  tab tabela de simbolos
 * @param  key chave associada
 * @return     retorna 1 se obter sucesso, e 0 caso contrário
 */
TabSim ht_retira(TabSim tab, char *key) {
	int hi = hashcode(key, tab->size);
	//Node val;
	if(tab->simbolos[hi] != (Lista) 0){
		tab->simbolos[hi] = l_retira(tab->simbolos[hi], key);
		tab->count--;
		return tab;
	}
	return tab;
}

/**
 * Imprime tabela
 * @param tab tabela hash
 */
void printHT(TabSim tab) {
	int i;
	for(i=0; i<tab->size; i++)
		if(tab->simbolos[i] != (Lista) 0)
			printList(tab->simbolos[i]);
}
