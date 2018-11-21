/*//////////////////////////////////////////////////////////////////////
Nome: Henrique Suzuki                 NUSP: 10297626
Nome: Rubens Gomes Neto               NUSP:  9318484
//////////////////////////////////////////////////////////////////////*/

#include <stdlib.h>
#include <stdio.h>
//#include <string.h>
#include "base.h"
#include "hashtable.h"

static simbolo HT_DUMMY = {NULL, NULL};

/**
 * Cria uma nova entrada para a hash table, associando a key ao cojunto de dados info
 * @param  info conjunto de dados a ser adicionado na tabela
 * @param  key  chave usada para encontrar os dados
 * @return      retorna o endereço do simbolo criado
 */
static Simbolo ht_novosim(TipoDaTab info, char *key) {
	Simbolo i = malloc(sizeof(simbolo));
	i->key = key;
	i->info = info;
	return i;
}

/**
 * Cria uma tabela de simbolos do tamanho especificado para guardar os dados
 * @param  tam tamanho da tabela a ser criada
 * @return     retorna o endereço da tabela de simbolos criada
 */
TabSim ht_cria(int tam) {
	TabSim tab = malloc(sizeof(tabsim));
	tab->size = tam;
	tab->count = 0;
	tab->simbolos = calloc((size_t)tab->size, sizeof(Simbolo));
	return tab;
}

/**
 * Deleta o simbolo
 * @param sim simbolo a ser deletado
 */
static void ht_delsim(Simbolo sim) {
	free(sim->info);
	sim->info = NULL;
	free(sim->key);
	sim->key = NULL;
	free(sim);
	sim = NULL;
}

/**
 * Apaga todos os simbolos e a tabela liberando o espaço da memoria
 * @param tab tabela a ser apagada
 */
void ht_destroi(TabSim tab) {
	for(int i = 0; i < tab->size; i++) {
		Simbolo sim = tab->simbolos[i];
		if(sim != NULL)
			ht_delsim(sim);
	}
	free(tab->simbolos);
	tab->simbolos = NULL;
	free(tab);
	tab = NULL;
}

/**
 * Calcula o codigo hash e retorna o indice para tentar primeiro
 * @param  key chave dos dados
 * @param  tam tamanho da tabela de simbolos
 * @return     indice a ser checado como a primeira tentativa para os dados
 */
static int hashcode(char *key, int tam) {
	//soma todos os ascii de cada caractere da key
	//int x = strlen(key)-1;
	char c = *key;
	int asc = 0;
	while(c != 0) {
		asc += (int)c;
		c = *key++;
	}
	//retorna o resultado da divisão inteira da soma pelo tamanho da hash table
	return asc % tam;
}

/**
 * Insere um novo conjunto de dados a tabela de simbolos
 * @param  tab  tabela de simbolos
 * @param  key  chave associada
 * @param  info conjunto de dados
 * @return      retorna True se obter sucesso, e False caso contrário
 */
Boolean ht_insere(TabSim tab, char *key, TipoDaTab info) {
	//printf("ht_insere\n");

	// retorna False caso não tenha sucesso
	// retorna True caso tenha sucesso
	//printf("passagem 01\n");

	//nao ha espaco na tabela
	if(tab->size == tab->count)
		return False;

	Simbolo sim1 = ht_novosim(info, key);
	//printf("passagem 02\n");

	int hi = hashcode(key, tab->size);//manda o codigo ascII do n;
	int lim = hi;//pra saber se deu uma volta completa
	//printf("passagem 03\n");

	// esse código resolve a possibilidade de colisões na hash table
	// a partir do hashcode verificar os seguintes items da tabela e se vazios preenche com o simbolo;
	//int cont = 0;
	while(tab->simbolos[hi] != NULL && tab->simbolos[hi] != &HT_DUMMY) {//até achar um espaço vazio
		//vai pra proxima
		//printf("while %02d\n", cont);
		//cont++;

		hi += 1;
		//volta ao inicio caso passe
		hi %= tab->size;
		//se der uma volta completa e não achar espaço
		if(hi == lim) {
			return False;
		}
	}
	//insere o item na hashtable
	tab->simbolos[hi] = sim1;
	tab->count += 1;
	return True;
}

/**
 * Encontra o indice dos dados associados a key
 * @param  tab tabela de dados
 * @param  key chave associada
 * @return     retorna o conjunto de dados
 */
TipoDaTab ht_busca(TabSim tab, char *key) {
	//printf("ht_busca\n");

	//printf("passagem 01\n");

	int hi = hashcode(key, tab->size);
	int lim = hi;
	//printf("passagem 02 - hi: %d; lim: %d\n", hi, lim);
	//int cont = 0;

	//se mexe até um vazio, caso encontre isso quer dizer que o item não esta na hash table
	while(tab->simbolos[hi] != NULL) {
		//printf("while %02d\n", cont);
		//cont++;

		if(tab->simbolos[hi]->key == key && tab->simbolos[hi] != &HT_DUMMY)
			return tab->simbolos[hi]->info; //encontrou

		//vai pra proxima
		hi += 1;
		//volta ao inicio caso passe
		hi %= tab->size;
		//se der uma volta completa e não achar o item
		if(hi == lim)
			return NULL;
	}
	return NULL;
}

/**
 * Retira um simbolo da tabela de dados associado a key
 * @param  tab tabela de simbolos
 * @param  key chave associada
 * @return     retorna 1 se obter sucesso, e 0 caso contrário
 */
Boolean ht_retira(TabSim tab, char *key, int (*COMPARE)(void*, void*)) {
	//printf("ht_retira\n");

	// retorna False caso não tenha sucesso
	// retorna True caso tenha sucesso
	//printf("passagem 01\n");
	int hi = hashcode(key, tab->size);
	int lim = hi;
	//printf("passagem 02 - hi: %d; lim: %d\n", hi, lim);
	//int cont = 0;
	//se mexe até um vazio, caso encontre isso quer dizer que o item não esta na hash table
	while(tab->simbolos[hi] != NULL) {
		//printf("while %02d\n", cont);
		//cont++;
		//printf("%s\n", tab->simbolos[hi]->key);
		Simbolo item = tab->simbolos[hi];
		//printf("passagem 03\n");
		if((item != &HT_DUMMY) && (COMPARE(item->key, key) == 0)) {
			//printf("passagem 04 if - key: %s\n", key);
			ht_delsim(item);
			//printf("passagem 05 delsim\n");

			tab->simbolos[hi] = &HT_DUMMY;
			tab->count--;
			return True;
		}
		//vai pra proxima
		hi += 1;
		//volta ao inicio caso passe
		hi %= tab->size;
		//se der uma volta completa e não achar o item
		if(hi == lim)
			return False;
	}
	return False;
}
