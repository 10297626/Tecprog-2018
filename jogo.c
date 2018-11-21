/*//////////////////////////////////////////////////////////////////////
Nome: Henrique Suzuki                 NUSP: 10297626
Nome: Rubens Gomes Neto               NUSP: 9318484
//////////////////////////////////////////////////////////////////////*/

#include <stdio.h>
#include <stdlib.h>
#include "base.h"
#include "advlib.h"
#include "hashtable.h"
#include "linkedlist.h"

/*
elemento* cria_ele(){
	elemento *ele= malloc(sizeof(elemento));
	ele->nome=NULL;
	ele->curta=NULL;
	ele->longa=NULL;
	ele->active=1;
	ele->invis=0;
	ele->known=0;
	ele->contem= l_cria();
	return ele;
}


objeto* cria_obj(){
	objeto *obj= malloc(sizeof(objeto));
	obj->ele=cria_ele();
	return obj;
}

lugar* cria_lugar(){
	lugar *lug=malloc(sizeof(lugar));
	lug->ele=cria_ele();
	//lug->saida=l_cria();
	lug->leste=NULL;
	lug->oeste=NULL;
	lug->norte=NULL;
	lug->sul=NULL;
	return lug;

}
*/

Elemento* inicial(){

	Elemento* sala = cria_ele();
	sala->nome = "Sala\0";
	sala->longa = "Voce esta em uma sala. Um sofa branco esta encostado no lado leste da sala, na frente dele uma  mesa de centro. Ao oeste da sala uma mesa de tv com gavetas, ao sul uma mesa de jantar com duas cadeiras.Pro Sul tem a cozinha, ao leste o quarto e ao norte uma janela emparedada.\0";
	sala->curta = "Voce esta em uma sala de estar. Pro sul tem a cozinha e pro leste o quarto. \0";

	Elemento* cozinha = cria_ele();
	cozinha->nome = "Cozinha \0";
	cozinha->longa = "Voce esta em uma cozinha. Um Balcao branco cobre toda a parede oeste, encostado no balcao tem um fogao branco, em cima do balcao tem uma pia, ao sul uma geladeira. Encostado na parede tem um armario. Pro norte tem a sala de estar e pro leste tem a entrada.\0";
	cozinha->curta = "Voce esta em uma cozinha. Pro norte tem a sala de estar e pro leste tem a entrada. \0";

	Elemento* banheiro = cria_ele();
	banheiro->nome = "Banheiro \0";
	banheiro->longa = "Voce esta em um banheiro. Uma banheira esta encostada na parede. Ao sul tem uma privada e uma pia, em cima da pia um espelho. Pro norte tem o quarto e pra oeste a Entrada.\0";
	banheiro->curta = "Voce esta em um banheiro.Pro norte tem o quarto e pra oeste a Entrada.\0";

	Elemento* quarto = cria_ele();
	quarto->nome = "Quarto\0";
	quarto->longa = "Voce esta em um quarto. Uma cama esta encostada na parede ao leste, do lado dela um criado mudo. Na parede oeste tem um grande armario de duas portas. Ao norte tem uma janela emparedada. Pro sudeste tem o banheiro, pro sudoeste o closet e pra oeste tem a sala de estar.\0";
	quarto->curta = "Voce esta em um quarto.Pro sudeste tem o banheiro, pro sudoeste o closet e pra oeste tem a sala de estar.\0";

	Elemento* closet= cria_ele();
	closet->nome = "Closet\0";
	closet->longa = "Voce esta em um closet. Tem um cofre eletronico nele. Pro norte tem o quarto.\0";
	closet->curta = "Voce esta em um closet. Pro norte tem o quarto.\0";
	closet->conhecido = True;

	Elemento* entrada= cria_ele();
	entrada->nome = "Entrada \0";
	entrada->longa = "Voce esta na Entrada. No Sul tem uma grande porta de ferro trancada, voce sente um vento saindo de debaixo da porta, provavelmente ela abre pro mundo. Pra leste tem o banheiro e pra oeste tem a cozinha.\0";
	entrada->curta = "Voce esta na Entrada. Pra leste tem o banheiro e pra oeste tem a cozinha.\0";


	//saidas :::
	//sala
	sala->detalhe->L->saida[1] = quarto;
	sala->detalhe->L->saida[2]=cozinha;

	//cozinha
	cozinha->detalhe->L->saida[1]=entrada;
	cozinha->detalhe->L->saida[0]=sala;

	//entrada
	entrada->detalhe->L->saida[1]=banheiro;
	entrada->detalhe->L->saida[3]=cozinha;

	//banheiro
	banheiro->detalhe->L->saida[0]=quarto;
	banheiro->detalhe->L->saida[3]=entrada;

	//quarto
	quarto->detalhe->L->saida[3]=sala;
	quarto->detalhe->L->saida[2]=banheiro;

	//closet
	closet->detalhe->L->saida[0]=quarto;


	return closet;
}


int main(){
	Elemento* current = inicial();
	printf("%s \n  %s \n Voce vai para o norte \n",current->nome, current->longa);

	current=current->detalhe->L->saida[0];
	printf("%s \n  %s \n Voce vai para o oeste \n",current->nome, current->longa);

	current=current->detalhe->L->saida[3];
	printf("%s \n  %s \n Voce vai para o sul \n",current->nome, current->longa);

	current=current->detalhe->L->saida[2];
	printf("%s \n  %s \n Voce vai para o leste \n",current->nome, current->longa);

	current=current->detalhe->L->saida[1];
	printf("%s \n  %s \n Voce vai para o leste \n",current->nome, current->longa);

	current=current->detalhe->L->saida[1];
	printf("%s \n  %s \n Voce vai para o norte \n",current->nome, current->longa);

	current=current->detalhe->L->saida[0];
	printf("%s \n  %s \n",current->nome, current->longa);

	return 0;
}

/* ideia de ler um arquivo txt e criar as salas tirando esses textos do código
   FILE * fp;
	char * line = NULL;
	size_t len = 0;
	ssize_t read;
	int x = 0 ;
	int a=0;

	fp = fopen("lugar_desc.txt", "r");
	if (fp == NULL){return 0;}

	while ((read = getline(&line, &len, fp)) != -1) {
		if (line[0]=='_'){
			x+=1;
		}
		switch ( x ){
			case 1 :;


			if (a==0){
				sala->ele->nome = strdup(line);
				a+=1;
			}
			if (a==1){
				sala->ele->longa = strdup(line);
				a+=1;
			}
			if (a==2){
				sala->ele->curta = strdup(line);
				a=0;
			}

			printf("%s \n ", sala->ele->nome);
			break;

			case 2 :
			printf ("Segunda");
			break;

			case 3 :
			printf ("Terça");
			break;

			case 4 :
			printf ("Quarta");
			break;

			case 5 :
			printf ("Quinta");
			break;

			case 6 :
			printf ("Sexta");
			break;

			default :
			printf ("Valor invalido!");
		}

	}
	fclose(fp);

	printf("%s \n ", sala->ele->nome);
	printf("%s \n ", sala->ele->longa);
	printf("%s \n ", sala->ele->curta);
	if (line){ free(line);}

*/
