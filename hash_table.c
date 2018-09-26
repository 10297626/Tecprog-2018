/*//////////////////////////////////////////////////////////////////////
Nome: Alessandro Bezerra da Silva     NUSP: 10284351
Nome: Henrique Suzuki                 NUSP: 10297626
Nome: Rubens Gomes Neto               NUSP: 9318484
//////////////////////////////////////////////////////////////////////*/

#include "stdlib.h"
#include "string.h"
#include "hash_table.h"
#include "advlib.h"

tabsim ht_cria(int tam){
 	tabsim *tab=malloc(sizeof(tabsim));
 	tab=malloc(sizeof(simbolo * ) * tam)
		
	for( i = 0; i < tam; i++ ) {
		tab[i] = NULL;
	}
	
 	tab->size=tam;
 	return tab;
}

void ht_destroi(tabsim tab){
	free(tab);
}

int hashCode(char *key, int tam) {
	//soma todos os ascii de cada caractere da key
	int x = strlen(key)-1;
	int asc=0;
	
	while (x>=0){
		asc+= (int) key[x];
		x+= -1;			
	}
	
	return asc % tam;
}

int ht_insere(tabsim tab, char *n,elemento *val){
	// retorna 0 caso não tenha sucesso
	// retorna 1 caso tenha sucesso
	
	simbolo *sim1 = malloc(sizeof(simbolo));
	sim1->ele=val;
	sim1->key=n;
	
	int hi=hashcode(n,tab->size);//manda o codigo ascII do n;
	int lim=hi;//pra saber se deu uma volta completa
	
	while(tab[hi]!=NULL){//até achar um espaço vazio
		//vai pra proxima 
		hi+=1;
		//volta ao inicio caso passe
		hi%=tab->tam;
		//se der uma volta completa e não achar espaço
		if (hi==lim){
			return 0;
		}	
	}
	//insere o item na hashtable
	tab[hi] = sim1;
	return 1;
}

elemento ht_busca(tabsim t, char *n){
	int hi=hashcode(n);
	int lim=hi;
	//se mexe até um vazio, caso encontre isso quer dizer que o item não esta na hash table
	while(tab[hi]!=NULL){
		
		if(tab[hi]->key==n){
			//encontrou
			return tab[hi];
		}
		
		//vai pra proxima 
		hi+=1;
		//volta ao inicio caso passe
		hi%=tab->tam;
		//se der uma volta completa e não achar o item
		if (hi==lim){
			return null;
		}	
	}
	return null;
}

int ht_retira(tabsim t, char*n){
	// retorna 0 caso não tenha sucesso
	// retorna 1 caso tenha sucesso
	
	int hi=hashcode(n);
	int lim=hi;
	//se mexe até um vazio, caso encontre isso quer dizer que o item não esta na hash table
	while(tab[hi]!=NULL){
		
		if(tab[hi]->key==n){
			tab[hi]=NULL;
			return 1;
		}
		
		//vai pra proxima 
		hi+=1;
		//volta ao inicio caso passe
		hi%=tab->tam;
		
		//se der uma volta completa e não achar o item
		if (hi==lim){
			return 0;
		}	
	}
	return 0;
}


