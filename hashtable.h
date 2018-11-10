/*//////////////////////////////////////////////////////////////////////
Nome: Henrique Suzuki                 NUSP: 10297626
Nome: Rubens Gomes Neto               NUSP: 9318484
//////////////////////////////////////////////////////////////////////*/

//#include guards
#ifndef hashtable_h
#define hashtable_h

#include "advlib.h"



typedef struct simbolo{
	Elemento ele;
	char *key;
}simbolo;
typedef simbolo* Simbolo;

typedef struct tabsim{
	int size;
	int count;
	Simbolo* simbolos;
}tabsim;
typedef tabsim* TabSimb;

TabSimb ht_cria(int tam);

void ht_destroi(TabSimb tab);

int ht_insere(TabSimb tab, char *key, Elemento ele);

Elemento ht_busca(TabSimb tab, char *key);

int ht_retira(TabSimb tab, char*key);

#endif /* hashtable_h */
