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
	Lista atributos;
} Objeto;

//Lugares

/*typedef struct saidas {
	//objeto *obj; // caracteristicas de objetos
	char *destino; // referencia key do hashtable do destino dessa saida [100]
	Boolean fechada; // quando True a sáida esta fechada
} saidas;*/

// struct contendo os atributos, especificos de lugares
typedef struct {
	//Elemento ele;
	// [0]: Norte
	// [1]: Leste
	// [2]: Sul
	// [3]: Oeste
	// [4]: Sobe
	// [5]: Desce
	struct elemento* saida[6];// saidas do lugar
} Lugar;

typedef union {
	Lugar* L;
	Objeto* O;
} Spec;

//Elemento
typedef struct elemento {
	int x;
	char *nome; //nome do objeto
	char *artigos[4]; // artigos
	char *curta; //descrição curta [40]
	char *longa; //descrição longa para quando examinar o objeto [100]
	Boolean ativo; //indica se elemento existe no jogo
	Boolean visivel; //indicador de visibilidade
	Boolean conhecido; //indicador de conhecimento do jogador
	Lista contem; //itens dentro do elemento
	Lista acao; // lista de acoes
	//Lista animacao;
	Spec* detalhe;
} Elemento;
//typedef elemento* Elemento;

Elemento* cria_ele();

//imcompletos
//
//typedef struct {
//} verbo; //verbos

//typedef struct {} aventureiro; //o aventureiro

Boolean examinar(Elemento* e1, Elemento* e2); // função para examinar o objeto
Boolean pegar(Elemento* e1, Elemento* e2); //função para pegar o objeto
Boolean largar(Elemento* e1, Elemento* e2); // função para soltar o objeto caso ele esteja no invetário


#endif /* advlib_h */
