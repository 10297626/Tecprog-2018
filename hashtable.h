/*//////////////////////////////////////////////////////////////////////
Nome: Henrique Suzuki                 NUSP: 10297626
Nome: Rubens Gomes Neto               NUSP:  9318484
//////////////////////////////////////////////////////////////////////*/

//#include guards
#ifndef hashtable_h
#define hashtable_h

#include "base.h"
#include "linkedlist.h"

typedef void* TipoDaTab;

// definicao de simbolo
/*typedef struct simbolo {
	char *key;
	//int tipo;
	Lista l;
} simbolo;
typedef simbolo* Simbolo;*/

// definicao da tabela de simbolos, com um vetor simbolos de tamanho size
typedef struct tabsim {
	int size;
	int count;
	Lista* simbolos;
} tabsim;
typedef tabsim* TabSim;

TabSim ht_cria(int);
void ht_destroi(TabSim);
Node ht_busca(TabSim, char*);
TabSim ht_insere(TabSim, char*, int, void*);
TabSim ht_retira(TabSim, char*);

#endif /* hashtable_h */
