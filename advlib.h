/*//////////////////////////////////////////////////////////////////////
Nome: Henrique Suzuki                 NUSP: 10297626
Nome: Rubens Gomes Neto               NUSP:  9318484
//////////////////////////////////////////////////////////////////////*/

//#include guards
#ifndef advlib_h
#define advlib_h

#include "base.h"
#include "linkedlist.h"
#include "hashtable.h"

// struct contendo os atributos, especificos de objetos
typedef struct {
	//Elemento ele;
	Boolean ativo;
	Boolean visivel;
} Objeto;

//Lugares

// struct contendo os atributos, especificos de lugares
typedef struct {
	//Elemento ele;
	// [0]: Norte
	// [1]: Sul
	// [2]: Leste
	// [3]: Oeste
	// [4]: Sobe
	// [5]: Desce
	struct elemento* saidas[6];// saidas do lugar
} Lugar;



//Elemento
typedef struct elemento {
	char *nome; //nome do objeto
	//char *artigos[4]; // artigos
	char *curta; //descrição curta [40]
	char *longa; //descrição longa para quando examinar o objeto [100]
	Boolean ativo; //indica se elemento existe no jogo
	//Boolean visivel; //indicador de visibilidade
	Boolean conhecido; //indicador de conhecimento do jogador
	TabSim contem; //itens dentro do elemento
	int tipo;
	//TabSim acao; // lista de acoes
	//Lista animacao;
	union {
		Lugar lug;
		Objeto obj;
	} detalhe;
} Elemento;
//typedef elemento* Elemento;

Elemento* cria_ele();

//imcompletos
//
//typedef struct {
//} verbo; //verbos

//typedef struct {} aventureiro; //o aventureiro
typedef void (*Fptr)(Elemento *, Elemento *);

Boolean examinar(Elemento *, Elemento *); // função para examinar o objeto
Boolean pegar(Elemento *, Elemento *); //função para pegar o objeto
Boolean largar(Elemento *, Elemento *); // função para soltar o objeto caso ele esteja no invetário


#endif /* advlib_h */
