
/*//////////////////////////////////////////////////////////////////////
Nome: Henrique Suzuki                 NUSP: 10297626
Nome: Rubens Gomes Neto               NUSP: 9318484
//////////////////////////////////////////////////////////////////////*/

//#include guards
#ifndef advlib_h
#define advlib_h




//Elemento
typedef struct elemento{
	char *nome;//nome do objeto
	char *curta;// descrição curta
	char *longa;//descrição longa para quando examinar o objeto
	int active;//nome em ingles pq em portugues dava 'expected expression before int'
	int invis;//nome em ingles pq em portugues dava 'expected expression before int'
	int known;//nome em ingles pq em portugues dava 'expected expression before int'
	struct lista *contem; //itens dentro do elemento
	//Lista acao; // lista de acoes
	//Lista animacao;

}elemento;

//Objeto
typedef struct objeto{
	elemento *ele;
	//Lista atributos; //Atributos do objeto como energia
}objeto;

void exam(objeto o);// função para examinar o objeto

void catch(objeto o);//função para pegar o objeto

void drop(objeto o); // função para soltar o objeto caso ele esteja no invetário

//Lugares

typedef struct saida{
	char *destino;// referencia key do hashtable do destino dessa saida
	int fechada;// quando 1 a sáida esta fechad
}saida;


typedef struct lugar {
	elemento *ele;
	struct lugar* leste;
	struct lugar* oeste;
	struct lugar* norte;
	struct lugar* sul;
	//struct lista *saida;// saidas do lugar
}lugar;

//imcompletos
//
//typedef struct{
//}verbo;//verbos

//typedef struct{
//}aventureiro;//o aventureiro

#endif /* advlib_h */
