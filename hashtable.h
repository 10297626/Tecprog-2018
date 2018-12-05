/*//////////////////////////////////////////////////////////////////////
Nome: Henrique Suzuki                 NUSP: 10297626
Nome: Rubens Gomes Neto               NUSP:  9318484
//////////////////////////////////////////////////////////////////////*/

//#include guards
#ifndef hashtable_h
#define hashtable_h

#include "base.h"

typedef void* TipoDaTab;

// definicao de simbolo
typedef struct simbolo {
	char *key;
	int tipo;
	TipoDaTab info;
} simbolo;
typedef simbolo* Simbolo;

// definicao da tabela de simbolos, com um vetor simbolos de tamanho size
typedef struct tabsim {
	int size;
	int count;
	Simbolo* simbolos;
} tabsim;
typedef tabsim* TabSim;

TabSim ht_cria(int tam);
void ht_destroi(TabSim tab);
Boolean ht_insere(TabSim tab, char *key, TipoDaTab info);
TipoDaTab ht_busca(TabSim tab, char *key);
Boolean ht_retira(TabSim tab, char *key, int (*COMPARE)(void*, void*));

#endif /* hashtable_h */
