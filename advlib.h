/*//////////////////////////////////////////////////////////////////////
Nome: Henrique Suzuki                 NUSP: 10297626
Nome: Rubens Gomes Neto               NUSP: 9318484
//////////////////////////////////////////////////////////////////////*/

//#include guards
#ifndef advlib_h
#define advlib_h

//Booleanos
typedef enum {
False, True
} Boolean;
//Elemento
typedef struct elemento{
	char *nome; //nome do objeto
//	char *artigos[4][10]; // artigos
	char *curta[40]; //descrição curta
	char *longa[100]; //descrição longa para quando examinar o objeto
	Boolean ativo; //indica se elemento existe no jogo
	Boolean visivel; //indicador de visibilidade
	Boolean conhecido; //indicador de conhecimento do jogador
//	Lista conteudo; //itens dentro do elemento
//	Lista acoes; // lista de acoes
}elemento;
typedef elemento* Elemento;

//Objeto
typedef struct objeto{
	Elemento ele;
//	char *adjetivos[][];//adjetivos 
	int invisivel;// quando 1 o objeto é invisivel
}objeto;

//Lugares

typedef struct saida{
	char *destino[100];// referencia key do hashtable do destino dessa saida
	int fechada;// quando 1 a sáida esta fechada
}saida;

typedef struct lugar {
	Elemento ele;
	saida *saida;// saida do lugar
}lugar;

//imcompletos
//
//typedef struct{
//}verbo;//verbos

//typedef struct{
//}aventureiro;//o aventureiro

void exam(objeto o);// função para examinar o objeto
void catch(objeto o);//função para pegar o objeto
void drop(objeto o); // função para soltar o objeto caso ele esteja no invetário


#endif /* advlib_h */
