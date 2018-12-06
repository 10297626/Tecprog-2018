/*//////////////////////////////////////////////////////////////////////
Nome: Henrique Suzuki                 NUSP: 10297626
Nome: Rubens Gomes Neto               NUSP:  9318484
//////////////////////////////////////////////////////////////////////*/

//#include guards
#include <stdlib.h>
#include <stdio.h>
#include "base.h"
//#include "linkedlist.h"
#include "hashtable.h"
#include "advlib.h"
#include "aventura.tab.h"

// Variáveis globais
TabSim sym_table  = (TabSim)     0;
TabSim inventario = (TabSim)     0;
Elemento *Posic   = (Elemento *) 0;

Elemento* cria_ele() {
	Elemento* ele  = malloc(sizeof(Elemento));
	ele->nome      = NULL;
	ele->curta     = NULL;
	ele->longa     = NULL;
	ele->ativo     = False;
	ele->conhecido = False;
	ele->contem    = ht_cria(10);
	return ele;
}

/* verifica se um objeto está presente */
/* retorna 1 se no local, 2 se no inventário, 0 se não existir */
int presente(char *nome) {
	/* inventário? */
	if (ht_busca(inventario, nome))  return 2;
	if (ht_busca(Posic->cont, nome)) return 1;
	return 0;
}

/* Macros para testar propriedades comuns */
#define Ativo(x) (x)->detalhe.obj.ativo
#define Visivel(x) (x)->detalhe.obj.visivel
#define Conhecido(x) (x)->conhecido

/**
 * descreve o elemento para o jogador
 * @param  e1 elemento a ser descrito
 * @param  e2 deve ser NULL
 * @return    retorna 1 se obteve sucesso, 0 caso contrario
 */
Boolean examinar(Elemento* e1, Elemento* e2) { // função para examinar o objeto
	/*Node ptr;
	if(e1 == NULL || e2 != NULL)
		return False; //apenas 1 elemento pode ser analisado por vez

	if(!(e1->conhecido)) {
		printf("%s\n", e1->longa);
		e1->conhecido = 1;
	} else
		printf("%s\n", e1->curta);

	return True;*/
	Node ptr;

	/* o default é descrever o local atual */
	if (o1 == NULL || o1 == Posic) {
		if(!Posic->conhecido)
			puts(Posic->longa);
		else
			puts(Posic->curta);
		puts("Aqui tem:");
		for(ptr = Posic->cont; ptr != (symrec *) 0;	ptr = (symrec *)ptr->next) {
			/* como a lista contém tods os nomes, precisamos filtrar */
			if(ptr->tipo == OBJ) {
				Elemento *oo = (Elemento *)ptr->value;
				if(Visivel(oo)  && Ativo(oo))
					printf("\t%s\n", oo->nome);
			}
		}
		return;
	}
	if (o1->tipo == OBJ)
		if(Ativo(o1) && Visivel(o1))
			puts(o1->longa);
		else puts("Oi?");
	else
		puts("Não tenho como responder neste momento");
}

/**
 * Move um item do mundo para o inventário
 * @param  e1 elemento a ser tranferido
 * @param  e2 NULL
 * @return    status de sucesso
 */
Boolean pegar(Elemento* e1, Elemento* e2) { //função para pegar o objeto

	return False;
}

/**
 * Remove um item do inventário e o coloca no mundo
 * @param  e1 objeto a ser largado
 * @param  e2 NULL
 * @return    status de sucesso
 */
Boolean largar(Elemento* e1, Elemento* e2) { // função para soltar o objeto caso ele esteja no inventário
	return False;
}
