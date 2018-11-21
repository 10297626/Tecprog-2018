/*//////////////////////////////////////////////////////////////////////
Nome: Henrique Suzuki                 NUSP: 10297626
Nome: Rubens Gomes Neto               NUSP: 9318484
//////////////////////////////////////////////////////////////////////*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "advlib.h"
#include "hash_table.h"
#include "linked_list.h"

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

lugar* inicial(){
    
    lugar* sala= cria_lugar();
    char sn[] ="Sala";
    char slong[]="Voce esta em uma sala. Um sofa branco esta encostado no lado leste da sala, na frente dele uma  mesa de centro. Ao oeste da sala uma mesa de tv com gavetas, ao sul uma mesa de jantar com duas cadeiras.Pro Sul tem a cozinha, ao leste o quarto e ao norte uma janela emparedada.\0";   
    char sshort[]="Voce esta em uma sala de estar. Pro sul tem a cozinha e pro leste o quarto. \0";   
    char *ptrn=sn;
    sala->ele->nome=ptrn;
    ptrn=slong;
    sala->ele->longa=ptrn;
    ptrn=sshort;
    sala->ele->curta=ptrn;

    lugar* cozinha= cria_lugar();
    char kn[] = "Cozinha \0";
    char klong[]="Voce esta em uma cozinha. Um Balcao branco cobre toda a parede oeste, encostado no balcao tem um fogao branco, em cima do balcao tem uma pia, ao sul uma geladeira. Encostado na parede tem um armario. Pro norte tem a sala de estar e pro leste tem a entrada.\0";   
    char kshort[]="Voce esta em uma cozinha. Pro norte tem a sala de estar e pro leste tem a entrada. \0";   
    char *ptrkn=kn;
    cozinha->ele->nome=ptrkn;
    ptrkn=klong;
    cozinha->ele->longa=ptrkn;
    ptrkn=kshort;
    cozinha->ele->curta=ptrkn;

    lugar* banheiro= cria_lugar();
    char bn[] = "Banheiro \0";
    char blong[]="Voce esta em um banheiro. Uma banheira esta encostada na parede. Ao sul tem uma privada e uma pia, em cima da pia um espelho. Pro norte tem o quarto e pra oeste a Entrada.\0";   
    char bshort[]="Voce esta em um banheiro.Pro norte tem o quarto e pra oeste a Entrada.\0";   
    char *ptrbn=bn;
    banheiro->ele->nome=ptrbn;
    ptrbn=blong;
    banheiro->ele->longa=ptrbn;
    ptrbn=bshort;
    banheiro->ele->curta=ptrbn;

    lugar* quarto= cria_lugar();
    char qn[] = "Quarto\0";
    char qlong[]="Voce esta em um quarto. Uma cama esta encostada na parede ao leste, do lado dela um criado mudo. Na parede oeste tem um grande armario de duas portas. Ao norte tem uma janela emparedada. Pro sudeste tem o banheiro, pro sudoeste o closet e pra oeste tem a sala de estar.\0";   
    char qshort[]="Voce esta em um quarto.Pro sudeste tem o banheiro, pro sudoeste o closet e pra oeste tem a sala de estar.\0";   
    char *ptrqn=qn;
    quarto->ele->nome=ptrqn;
    ptrqn=qlong;
    quarto->ele->longa=ptrqn;
    ptrqn=qshort;
    quarto->ele->curta=ptrqn;

    lugar* closet= cria_lugar();
    char cn[] = "Closet\0";
    char clong[]="Voce esta em um closet. Tem um cofre eletronico nele. Pro norte tem o quarto.\0";   
    char cshort[]="Voce esta em um closet. Pro norte tem o quarto.\0";   
    char *ptrcn=cn;
    closet->ele->nome=ptrcn;
    ptrcn=clong;
    closet->ele->longa=ptrcn;
    ptrcn=cshort;
    closet->ele->curta=ptrcn;
    closet->ele->known=1;

    lugar* entrada= cria_lugar();
    char en[] = "Entrada \0";
    char elong[]="Voce esta na Entrada. No Sul tem uma grande porta de ferro trancada, voce sente um vento saindo de debaixo da porta, provavelmente ela abre pro mundo. Pra leste tem o banheiro e pra oeste tem a cozinha.\0";   
    char eshort[]="Voce esta na Entrada. Pra leste tem o banheiro e pra oeste tem a cozinha.\0";   
    char *ptren=en;
    entrada->ele->nome=ptren;
    ptren=elong;
    entrada->ele->longa=ptren;
    ptren=eshort;
    entrada->ele->curta=ptren;


    //saidas :::
    //sala
    sala->leste=quarto;
    sala->sul=cozinha;

    //cozinha
    cozinha->leste=entrada;
    cozinha->norte=sala;

    //entrada
    entrada->leste=banheiro;
    entrada->oeste=cozinha;

    //banheiro
    banheiro->norte=quarto;
    banheiro->oeste=entrada;

    //quarto
    quarto->oeste=sala;
    quarto->sul=banheiro;

    //closet
    closet->norte=quarto;

    
    return closet;
}


int main(){
    lugar* current = inicial();
    printf("%s \n  %s \n Voce vai para o norte \n",current->ele->nome, current->ele->longa);

    current=current->norte;
    printf("%s \n  %s \n Voce vai para o oeste \n",current->ele->nome, current->ele->longa);
 
    current=current->oeste;
    printf("%s \n  %s \n Voce vai para o sul \n",current->ele->nome, current->ele->longa);

    current=current->sul;
    printf("%s \n  %s \n Voce vai para o leste \n",current->ele->nome, current->ele->longa);

    current=current->leste;
    printf("%s \n  %s \n Voce vai para o leste \n",current->ele->nome, current->ele->longa);

    current=current->leste;
    printf("%s \n  %s \n Voce vai para o norte \n",current->ele->nome, current->ele->longa);

    current=current->norte;
    printf("%s \n  %s \n",current->ele->nome, current->ele->longa);

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