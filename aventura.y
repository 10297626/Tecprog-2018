/* Calculadora infixa */

%{
	#include <stdio.h>
	#include "linkedlist.h"
	#include "hashtable.h"
	#include "advlib.h"

	int yylex();
	int yyerror(char *);

	/* Macro para simplificar a escrita das chamadas de função */
	#define F(x) (*(Fptr)(x->value))

	/* Identifica qual a versão correta do verbo chamado */
	Node AcertaF(Node f, Node o1) {
		Node s;

		/* Verifica se existe uma versão especial no local atual (Posic) */
		if ((s = ht_busca(Posic->contem, f->name))) {
			printf("testandoS: ");
			printf("%s\n", s->name);
			return s;
		}


		/* Verifica se o primeiro objeto tem uma versão especial */
		if (o1) {
			Elemento *o = o1->value;
			if ((s = ht_busca(o->contem, f->name)))
				return s;
		}
		printf("testando\n");

		return f;
	}
%}

/* Declaracoes */
%union {
	Node tptr;
	char *str;
	int direc;
}

%token <tptr> VERBO OBJ LUGAR

/* DESC representa uma palavra desconhecida */
%token <str> DESC
%token  NORTE SUL LESTE OESTE CIMA BAIXO VAPARA EOL FIM INVENT

%type <direc> dir
%type <tptr> obj

%defines

%%
/* Gramatica */


input: EOL { printf("Zzzz...\n"); }
	| cmd
	| VAPARA dir {
			if ($2 >= 0 && $2 < 6 && Posic->detalhe.lug.Saidas[$2]) {
				if(!Ativo(Posic->detalhe.lug.Saidas[$2])) {
					printf("Você ainda não consegue entrar em %s\n", Posic->detalhe.lug.Saidas[$2]->nome);
				} else {
					Posic = Posic->detalhe.lug.Saidas[$2];
					printf("Você foi para %s\n", Posic->nome);
					examinar(NULL,NULL);
				}
			}
			else puts("Não há passagem....");
		} eol

	| dir {
			/* movimentação  */
			if ($1 >= 0 && $1 < 6 && Posic->detalhe.lug.Saidas[$1]) {
				if(!Ativo(Posic->detalhe.lug.Saidas[$1])){
					printf("Você ainda não consegue entrar em %s\n", Posic->detalhe.lug.Saidas[$1]->nome);
				} else {
					Posic = Posic->detalhe.lug.Saidas[$1];
					printf("Você foi para %s\n", Posic->nome);
					examinar(Posic,NULL);
				}
			}
			else puts("Não há passagem....");
		} eol

	| INVENT {
			/* listagem do inventário */
			if (inventario->count > 0) {
				puts("Você tem:");
				printHT(inventario);
			}
			else puts("Você está sem nada no momento...");
		} eol

	| FIM  { return 0;}
	| DESC { puts("Não tem registro, Will Robinson.");}
	| error eol;
;

cmd: VERBO {
			/* Intransitivo */
			printf("testandoVerb1\n");

			F(AcertaF($1,NULL))(NULL,NULL);
		} eol

	| VERBO obj {
			/* Transitivo direto */
			printf("testandoVerb2\n");

			F(AcertaF($1,$2))($2->value,NULL);
		} eol

	| VERBO obj obj {
			/* Bitransitivo */
			printf("testandoVerb3\n");

			F(AcertaF($1,$2))($2->value,$3->value);
		} eol

	| VERBO DESC {
			printf("%s??\n", $2);
		} eol

	| VERBO obj DESC {
			printf("não sei o que é isso: %s\n",  $3);
		} eol

	| VERBO DESC DESC {
			printf("Pare de jogar e vá descansar um pouco\n"
				"Fazer isso com %s e %s, que coisa\n", $2,$3);
		} eol
;

obj: OBJ    { $$ = $1;}
	| LUGAR { $$ = $1;}

dir: NORTE	 { puts("norte"); $$=0;}
	| SUL	 { puts("sul");   $$=1;}
	| LESTE  { puts("leste"); $$=2;}
	| OESTE  { puts("oeste"); $$=3;}
	| CIMA	 { puts("cima");  $$=4;}
	| BAIXO  { puts("baixo"); $$=5;}
	| DESC   { puts("... (onde é isso?)"); $$=-1;}
;

eol: EOL {return 1;}
%%

int yyerror(char *s) {
	puts("Não entendi...");
	return 0;
}
