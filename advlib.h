
/*//////////////////////////////////////////////////////////////////////
Nome: Henrique Suzuki                 NUSP: 10297626
Nome:                                 NUSP:         
Nome:                                 NUSP:         
//////////////////////////////////////////////////////////////////////*/

//Elemento
typedef struct{
  char nome[20];//nome do objeto
  char artigo[4][10];// artigos 
  char desclong[100];//descrição longa para quando examinar o objeto
  char desc[40];// descrição curta
}elemento

//Objeto
typedef struct {
  elemento ele;
  char adj[];//adjetivos por enquanto array, mas é pra ser uma lista
  int invis;// quando 1 o objeto é invisivel
}objeto;

void exam(objeto o);// função para examinar o objeto

void catch(objeto o);//função para pegar o objeto

void drop(objeto o); // função para soltar o objeto caso ele esteja no invetário

//Lugares
typedef struct {
  elemento ele;
  saida ex;// saida do lugar
}lugar;

typedef struct{
  char destino[100];// referencia key do hashtable do destino dessa saida
  int closed;// quando 1 a sáida esta fechada
}saida

//imcompletos
typedef struct{
}verbo;//verbos

typedef struct{
}aventureiro;//o aventureiro


