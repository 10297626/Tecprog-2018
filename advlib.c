/*//////////////////////////////////////////////////////////////////////
Nome: Henrique Suzuki                 NUSP: 10297626
Nome: Rubens Gomes Neto               NUSP: 9318484
//////////////////////////////////////////////////////////////////////*/

//#include guards
#include <stdlib.h>
#include <stdio.h>

//Elemento
typedef struct elemento{
	char *nome;//nome do objeto
//	char *artigos[4][10];// artigos 
//	char *longa[100];//descrição longa para quando examinar o objeto
//	char *curta[40];// descrição curta
}elemento;

//Objeto
typedef struct objeto{
	elemento *ele;
//	char *adjetivos[][];//adjetivos 
	int invisivel;// quando 1 o objeto é invisivel
}objeto;

void exam(objeto o);// função para examinar o objeto

void catch(objeto o);//função para pegar o objeto

void drop(objeto o); // função para soltar o objeto caso ele esteja no invetário

//Lugares

typedef struct saida{
	char *destino[100];// referencia key do hashtable do destino dessa saida
	int fechada;// quando 1 a sáida esta fechada
}saida;

typedef struct lugar {
	elemento *ele;
	saida *saida;// saida do lugar
}lugar;

//imcompletos
//
//typedef struct{
//}verbo;//verbos

//typedef struct{
//}aventureiro;//o aventureiro

/*int main(){
	return(0);
}*/