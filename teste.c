/*//////////////////////////////////////////////////////////////////////
Nome: Alessandro Bezerra da Silva     NUSP: 10284351
Nome: Henrique Suzuki                 NUSP: 10297626
Nome: Rubens Gomes Neto               NUSP: 9318484
//////////////////////////////////////////////////////////////////////*/

#include <stdio.h>
#include <string.h>
#include "advlib.h"
#include "hash_table.h"
#include "linked_list.h"
int main(){

	//teste de hash table
	//criação da hash table
	tabsim *tab = ht_cria(30);
	
	//item exemplo
	elemento ele;
	char n;
	strncpy(&n,"ola",4);
	ele.nome=&n;
	char key;
	strncpy(&key,"alo",4);

	//inserção na hash table
	if(ht_insere(tab, &key, &ele)==1){
		printf("sucesso na insercao\n");
	}

	//busca na hash table
	if(ht_busca(tab,&key)==&ele){
		printf("sucesso na busca\n");
	}

	//retirada da hash table
	if(ht_retira(tab,&key)==1){
		printf("sucesso na retirada \n");
	}
	
	//busca após retirada
	if(ht_busca(tab,&key)==NULL){
		printf("item nqo esta na hash table\n");
	}

	//destroi a hash table
    ht_destroi(tab);


    //teste da lista ligada
}
