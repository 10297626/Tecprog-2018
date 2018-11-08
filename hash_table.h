/*//////////////////////////////////////////////////////////////////////
Nome: Henrique Suzuki                 NUSP: 10297626
Nome: Rubens Gomes Neto               NUSP: 9318484
//////////////////////////////////////////////////////////////////////*/

//#include guards
#ifndef hashtable_h
#define hashtable_h

#include "advlib.h"



typedef struct simbolo{
	elemento *ele;
	char *key;
}simbolo;

typedef struct tabsim{
	int size;
	int count;
	simbolo** simbolos;
}tabsim;

tabsim *ht_cria(int tam);

void ht_destroi(tabsim *tab);

int ht_insere(tabsim *tab, char *key,elemento *ele);

elemento* ht_busca(tabsim *tab, char *key);

int ht_retira(tabsim *tab, char*key);

#endif /* hashtable_h */
