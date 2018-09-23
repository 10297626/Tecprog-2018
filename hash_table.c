/*//////////////////////////////////////////////////////////////////////
Nome: Alessandro Bezerra da Silva     NUSP: 10284351
Nome: Henrique Suzuki                 NUSP: 10297626
Nome: Rubens Gomes Neto               NUSP: 9318484
//////////////////////////////////////////////////////////////////////*/

#include <stdlib.h>
#include <string.h>
#include "hash_table.h"
#include "advlib.h"

tabsim cria(int tam){
  tabsim *tab=malloc(sizeof(tabsim));
  tabsim->tab=malloc(sizeof(simbolo * ) * tam)
	for( i = 0; i < tam; i++ ) {
		tabsim->tab[i] = NULL;
	}
  tabsim->size=tam;
  return tabsim;
}
