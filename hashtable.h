/*//////////////////////////////////////////////////////////////////////
Nome: Henrique Suzuki                 NUSP: 10297626
Nome: Rubens Gomes Neto               NUSP:  9318484
//////////////////////////////////////////////////////////////////////*/

//#include guards
#ifndef hashtable_h
#define hashtable_h

#include "advlib.h"

typedef struct simbolo {
	Elemento ele;
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

Boolean ht_insere(TabSim tab, char *key, Elemento ele);

Elemento ht_busca(TabSim tab, char *key);

Boolean ht_retira(TabSim tab, char *key);

#endif /* hashtable_h */
