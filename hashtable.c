/*//////////////////////////////////////////////////////////////////////
Nome: Henrique Suzuki                 NUSP: 10297626
Nome: Rubens Gomes Neto               NUSP:  9318484
//////////////////////////////////////////////////////////////////////*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "hashtable.h"
#include "advlib.h"

static simbolo HT_DUMMY = {NULL, NULL};


//NO FUTURO COPIE KEY E ELE PARA FAZER SENTIDO ESSE MALLOC, MSM COISA PRA LISTA
static Simbolo ht_novosim(Elemento ele, char *key){
	Simbolo i = malloc(sizeof(simbolo));
	i->key = key;
	i->ele = ele;
	return i;
}

TabSim ht_cria(int tam){
	TabSim tab = malloc(sizeof(tabsim));
	tab->size = tam;
	tab->count = 0;
	tab->simbolos = calloc((size_t)tab->size,sizeof(Simbolo));
	return tab;
}

static void ht_delsim(Simbolo sim){
	free(sim->ele);
	sim->ele = NULL;
	free(sim->key);
	sim->key = NULL;
	free(sim);
	sim = NULL;
}

void ht_destroi(TabSim tab){
	for(int i = 0; i < tab->size; i++){

		Simbolo sim = tab->simbolos[i];
		if (sim != NULL){
			ht_delsim(sim);
		} 
	}
	free(tab->simbolos);
	tab->simbolos = NULL;
	free(tab);
	tab = NULL;
}

static int hashcode(char *key, int tam) {
	//soma todos os ascii de cada caractere da key
	int x = strlen(key)-1;
	int asc = 0;
	
	while (x >= 0){
		asc += (int)key[x];
		x -= 1;
	}
	
	//retorna o resultado da divisão inteira da soma pelo tamanho da hash table
	return asc % tam;
}

Boolean ht_insere(TabSim tab, char *key, Elemento ele){
	// retorna False caso não tenha sucesso
	// retorna True caso tenha sucesso
	
	Simbolo sim1 = ht_novosim(ele, key);
	
	int hi = hashcode(key, tab->size);//manda o codigo ascII do n;
	int lim = hi;//pra saber se deu uma volta completa
	
	// esse código resolve a possibilidade de colisões na hash table
	// a partir do hashcode verificar os seguintes items da tabela e se vazios preenche com o simbolo;
	while(tab->simbolos[hi] != NULL && tab->simbolos[hi] != &HT_DUMMY){//até achar um espaço vazio
		//vai pra proxima 
		hi += 1;
		//volta ao inicio caso passe
		hi %= tab->size;
		//se der uma volta completa e não achar espaço
		if (hi == lim){
			return False;
		}
	}
	//insere o item na hashtable
	tab->simbolos[hi] = sim1;
	tab->count += 1;
	return True;
}

Elemento ht_busca(TabSim tab, char *key){
	int hi = hashcode(key, tab->size);
	int lim = hi;
	//se mexe até um vazio, caso encontre isso quer dizer que o item não esta na hash table
	while(tab->simbolos[hi] != NULL ){
		
		if(tab->simbolos[hi]->key == key && tab->simbolos[hi] != &HT_DUMMY){
			//encontrou
			return tab->simbolos[hi]->ele;
		}
		
		//vai pra proxima 
		hi += 1;
		//volta ao inicio caso passe
		hi %= tab->size;
		//se der uma volta completa e não achar o item
		if (hi == lim){
			return NULL;
		}
	}
	return NULL;
}



Boolean ht_retira(TabSim tab, char *key){
	// retorna False caso não tenha sucesso
	// retorna True caso tenha sucesso
	
	int hi = hashcode(key, tab->size);
	int lim = hi;
	//se mexe até um vazio, caso encontre isso quer dizer que o item não esta na hash table
	while(tab->simbolos[hi] != NULL){
		Simbolo item = tab->simbolos[hi];
		if(item != &HT_DUMMY){
			if(strcmp(item->key, key) == 0){
				ht_delsim(item);
				tab->simbolos[hi] = &HT_DUMMY;
				tab->count--;
				return True;
			}
		}
		
		//vai pra proxima 
		hi += 1;
		//volta ao inicio caso passe
		hi %= tab->size;
		
		//se der uma volta completa e não achar o item
		if (hi == lim){
			return False;
		}
	}
	return False;
}