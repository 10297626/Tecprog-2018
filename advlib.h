/*//////////////////////////////////////////////////////////////////////
Nome: Henrique Suzuki                 NUSP: 10297626
Nome: Rubens Gomes Neto               NUSP:  9318484
//////////////////////////////////////////////////////////////////////*/

//#include guards
#ifndef advlib_h
#define advlib_h

#include "linkedlist.h"
#include "hashtable.h"
/*
//Booleanos
typedef enum {
	False, True
} Boolean;
*/
typedef union {
	char* valor1;
	int valor2;
} StrInt;

//Objeto
typedef struct objeto {
	//Elemento ele;
	Lista atributos; //adjetivos 
} Objeto;

//Lugares

/*typedef struct saidas {
	//objeto *obj; // caracteristicas de objetos
	char *destino; // referencia key do hashtable do destino dessa saida [100]
	Boolean fechada; // quando True a sáida esta fechada
} saidas;*/

typedef struct lugar {
	//Elemento ele;
	void* saida[6];// saidas do lugar
} Lugar;

typedef union {
	Lugar L;
	Objeto O;
} Spec;

//Elemento
typedef struct elemento {
	char *nome; //nome do objeto
	char *artigos[4]; // artigos
	char *curta; //descrição curta [40]
	char *longa; //descrição longa para quando examinar o objeto [100]
	int ativo; //indica se elemento existe no jogo
	int visivel; //indicador de visibilidade
	int conhecido; //indicador de conhecimento do jogador
	//Lista contem; //itens dentro do elemento
	//Lista acao; // lista de acoes
	//Lista animacao;
	Spec detalhe;
} Elemento;
//typedef elemento* Elemento;

Elemento* cria_ele();

//imcompletos
//
//typedef struct {
//} verbo; //verbos

//typedef struct {} aventureiro; //o aventureiro

int examinar(Elemento* e1, Elemento* e2); // função para examinar o objeto
int pegar(Elemento* e1, Elemento* e2); //função para pegar o objeto
int largar(Elemento* e1, Elemento* e2); // função para soltar o objeto caso ele esteja no invetário


#endif /* advlib_h */
