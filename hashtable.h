/*//////////////////////////////////////////////////////////////////////
Nome: Henrique Suzuki                 NUSP: 10297626
Nome: Rubens Gomes Neto               NUSP:  9318484
//////////////////////////////////////////////////////////////////////*/

//#include guards
#ifndef hashtable_h
#define hashtable_h

//#include "advlib.h"

typedef void* TipoDaTab;

typedef struct simbolo {
	TipoDaTab ele;
	char *key;
} simbolo;
typedef simbolo* Simbolo;

typedef struct tabsim {
	int size;
	int count;
	Simbolo* simbolos;
} tabsim;
typedef tabsim* TabSim;

TabSim ht_cria(int tam);

void ht_destroi(TabSim tab);

int ht_insere(TabSim tab, char *key, TipoDaTab ele);

TipoDaTab ht_busca(TabSim tab, char *key);

int ht_retira(TabSim tab, char *key);

#endif /* hashtable_h */
