
/*//////////////////////////////////////////////////////////////////////
Nome: Henrique Suzuki                 NUSP: 10297626
Nome:                                 NUSP:         
Nome:                                 NUSP:         
//////////////////////////////////////////////////////////////////////*/

//Elemento
typedef struct{
  char name[20];//nome do objeto
  char articles[4][10];// artigos 
  char desclong[100];//descrição longa para quando examinar o objeto
  char desc[40];// descrição curta
}element

//Objeto
typedef struct {
  element ele;
  char adj[];//adjetivos
  int invis;// quando 1 o objeto é invisivel
}object;

void exam(object o);// função para examinar o objeto

void catch(object o);//função para pegar o objeto

void drop(object o); // função para soltar o objeto caso ele esteja no invetário

//Lugares
typedef struct {
  elemente ele;
  exit ex;// saida do lugar
}place;

typedef struct{
  char destiny[100];// referencia ao destino dessa saida
  int closed;// quando 1 a sáida esta fechada
}exit

//imcompletos
typedef struct{
}verb;//verbos

typedef struct{
}adventurer;//o aventureiro


