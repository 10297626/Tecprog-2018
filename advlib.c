/*//////////////////////////////////////////////////////////////////////
Nome: Henrique Suzuki                 NUSP: 10297626
Nome: Rubens Gomes Neto               NUSP:  9318484
//////////////////////////////////////////////////////////////////////*/

//#include guards
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "base.h"
//#include "linkedlist.h"
#include "hashtable.h"
#include "advlib.h"
#include "aventura.tab.h"

// Variáveis globais
TabSim   sym_table  = (TabSim)     0;
TabSim   inventario = (TabSim)     0;
Elemento *Posic     = (Elemento *) 0;
int      cadeados   =              3;

/*
Elemento* cria_ele() {
	Elemento* ele  = malloc(sizeof(Elemento));
	ele->nome      = NULL;
	ele->curta     = NULL;
	ele->longa     = NULL;
	ele->ativo     = False;
	ele->conhecido = False;
	ele->contem    = ht_cria(10);
	return ele;
}
*/
/* Objetos */
Elemento chave = {"chave","-","-",False,False,NULL,OBJ,.detalhe.obj={False}};
Elemento chave1 = {"chave 1", "Uma chave pesada de ferro com o numero 1 marcado nela.", "Uma chave pesada de ferro, em sua base pode ser visto o número 1 gravado.", True, False, NULL, OBJ, .detalhe.obj={False}};
Elemento chave2 = {"chave 2", "Uma chave pesada de ferro com o numero 2 marcado nela.", "Uma chave pesada de ferro, em sua base pode ser visto o número 2 gravado.", True, False, NULL, OBJ, .detalhe.obj={False}};
Elemento chave3 = {"chave 3", "Uma chave pesada de ferro com o numero 3 marcado nela.", "Uma chave pesada de ferro, em sua base pode ser visto o número 3 gravado.", True, False, NULL, OBJ, .detalhe.obj={False}};
Elemento chaveP = {"chave pequena", "Uma chave pequena.", "Uma chave pequena e brilhante, parece nova.", True, False, NULL, OBJ, .detalhe.obj={False}};
Elemento cartao = {"cartao", "Um cartão", "Um cartão similar aos de quartos de hotéis.", True, False, NULL, OBJ, .detalhe.obj={False}};
Elemento privada = {"privada", "Uma privada normal.", "Uma privada, está limpa mas parece ter algo dentro dela... Uma chave estranha.", True, False, NULL, OBJ, .detalhe.obj={True}};
Elemento banheira = {"banheira", "Uma banheira cheia.", "Uma banheira cheia, mas no fundo você vê um martelo.", True, False, NULL, OBJ, .detalhe.obj={True}};
Elemento pia = {"pia", "Uma pia de banheiro.", "Uma pia de banheiro, de relance algo brilha no ralo, parece uma pequena chave", True, False, NULL, OBJ, .detalhe.obj={True}};
Elemento martelo = {"martelo", "Um martelo comum.", "Um martelo, posso usar ele para abrir a porta.", True, False, NULL, OBJ, .detalhe.obj={False}};
Elemento cama = {"cama", "Uma cama de casal.", "Uma cama de casal comum. Range ao deitar-se.", True, False, NULL, OBJ, .detalhe.obj={True}};
Elemento criadoMudo = {"criado mudo", "Um criado mudo vazio.", "Um criado mudo com sua gaveta parafusada, se eu tivesse alguma ferramenta poderia abri-lo.", True, False, NULL, OBJ, .detalhe.obj={True}};
Elemento sofa = {"sofa", "Um sofá branco rasgado.", "Uma sofá branco, consigo sentir algo dentro dele, se eu tivesse uma faca poderia ver.", True, False, NULL, OBJ, .detalhe.obj={True}};
Elemento mesa = {"mesa", "Uma mesa de centro.", "Uma mesa de centro, ao sentir debaixo dela você descobre uma ferramenta.", True, False, NULL, OBJ, .detalhe.obj={True}};
Elemento ferramenta = {"ferramenta", "Uma chave de fenda comum.", "Uma chave de fenda, útil para tirar parafusos.", True, False, NULL, OBJ, .detalhe.obj={False}};
Elemento geladeira = {"geladeira", "Uma geladeira vazia.", "Uma geladeira desligada, abrindo ela você vê uma faca.", True, False, NULL, OBJ, .detalhe.obj={True}};
Elemento faca = {"faca", "Uma faca.", "Uma faca comum. Muito fria ao toque. Brrr...", True, False, NULL, OBJ, .detalhe.obj={False}};
Elemento fogao = {"fogao", "Um fogão", "Um fogão acorrentado com um cadeado.", True, False, NULL, OBJ, .detalhe.obj={True}};
Elemento cadeado1 = {"cadeado 1", "Um cadeado aberto com o numero 1 talhado.", "Um cadeado com o numero 1 talhado.", True, False, NULL, OBJ, .detalhe.obj={True}};
Elemento cadeado2 = {"cadeado 2", "Um cadeado aberto com o numero 2 talhado.", "Um cadeado com o numero 2 talhado.", True, False, NULL, OBJ, .detalhe.obj={True}};
Elemento cadeado3 = {"cadeado 3", "Um cadeado aberto com o numero 3 talhado.", "Um cadeado com o numero 3 talhado.", True, False, NULL, OBJ, .detalhe.obj={True}};

/* Lugares */
Elemento final = {"final", "Eu consegui fugir da casa.", "Eu consegui fugir da casa.", False, False, NULL, LUGAR, .detalhe.lug.Saidas={NULL, NULL, NULL, NULL, NULL, NULL}};
Elemento entrada = {"entrada", "Eu estou em uma entrada da casa. Pro oeste eu vejo uma porta de ferro trancada pra leste tem a cozinha. Eu consigo ver: ", "Eu estou em uma entrada da casa. Pro oeste eu vejo uma porta de ferro trancada pra leste tem a cozinha. Eu consigo ver: ", True, False, NULL, LUGAR, .detalhe.lug.Saidas={NULL, NULL, NULL, &final, NULL, NULL}};
Elemento cozinha = {"cozinha", "Eu estou em uma cozinha. Pro norte tem a sala de estar e pro oeste tem a entrada. Eu consigo ver: ", "Eu estou em uma cozinha. Pro norte tem a sala de estar e pro oeste tem a entrada. Eu consigo ver: ", False, False, NULL, LUGAR, .detalhe.lug.Saidas={NULL, NULL, NULL, &entrada, NULL, NULL}};
Elemento sala = {"sala", "Estou em uma sala de estar. Pro sul tem a cozinha e pro leste o quarto. Eu consigo ver: ", "Estou em uma sala de estar. Pro sul tem uma porta fechada com um leitor de cartao e pro leste o quarto. Eu consigo ver:", True, False, NULL, LUGAR, .detalhe.lug.Saidas={NULL, &cozinha, NULL, NULL, NULL, NULL}};
Elemento quarto = {"quarto", "Eu estou em um quarto. Pro sul tem o banheiro e pra oeste tem uma sala de estar. Eu consigo ver:", "Eu estou em um quarto. Pro sul tem o banheiro e pra oeste tem uma sala de estar. Eu consigo ver: ", False, False, NULL, LUGAR, .detalhe.lug.Saidas={NULL, NULL, NULL, &sala, NULL, NULL}};
Elemento banheiro = {"banheiro", "Estou em um banheiro. Pro norte tem o quarto. Eu consigo ver:", "Estou em um banheiro.  Pro norte tem uma porta pregada, talvez com alguma ferramenta eu consiga abri-la. Eu consigo ver:", True, False, NULL, LUGAR, .detalhe.lug.Saidas={&quarto, NULL, NULL, NULL, NULL, NULL}};



/* verifica se um objeto está presente */
/* retorna 1 se no local, 2 se no inventário, 0 se não existir */
int presente(char *nome) {
	/* inventário? */
	//printHT(Posic->contem);
	if (ht_busca(inventario, nome))  return 2;
	Node s = ht_busca(Posic->contem, nome);
	//printf("chave: %s\n", nome);
	if (s) return 1;
	return 0;
}

/* Macros para testar propriedades comuns de elementos*/
//#define Ativo(x) (x)->ativo
#define Visivel(x) (x)->detalhe.obj.visivel
#define Conhecido(x) (x)->conhecido

/**
 * descreve o elemento para o jogador
 * @param  e1 elemento a ser descrito
 * @param  e2 deve ser NULL
 * @return    retorna 1 se obteve sucesso, 0 caso contrario
 */
void examinar(Elemento* e1, Elemento* e2) { // função para examinar o objeto
	Node ptr;
	/* o default é descrever o local atual */
	if (e1 == NULL || e1 == Posic) {
		if(!Posic->conhecido) {
			puts(Posic->longa);
			Posic->conhecido = True;
		}
		puts(Posic->curta);
		puts("Aqui tem:");
		int i;
		for(i=0; i<Posic->contem->size; i++) {
			if(Posic->contem->simbolos[i] != (Lista) 0) {
				//ptr = Posic->contem->simbolos[i]->head;
				for(ptr = Posic->contem->simbolos[i]->head; ptr != (Node) 0; ptr = (Node)ptr->next) {
					/* como a lista contém tods os nomes, precisamos filtrar */
					if(ptr->tipo == OBJ) {
						Elemento *oo = (Elemento *)ptr->value;
						if(Visivel(oo)  && Ativo(oo))
							printf("\t%s\n", oo->nome);
					}
				}
			}
		}
		return;
	}
	if (e1->tipo == OBJ)
		if(Ativo(e1) && Visivel(e1)) {
			if(!Conhecido(e1)){
				puts(e1->longa);
				e1->conhecido = True;
			} else {
				puts(e1->curta);
			}
			/* descoberta de objetos escondidos */
			if(e1->contem != (TabSim) 0) {
				int i;
				for(i = 0; i < e1->contem->size; i++) {
					Lista l = e1->contem->simbolos[i];
					if(l != (Lista) 0) {
						Node atual = l->head;
						while(atual != (Node) 0) {
							if(atual->tipo == OBJ) {
								((Elemento*) atual->value)->detalhe.obj.visivel = True;
							}
							atual = atual->next;
						}
					}
				}
			}

		} else puts("Oi?");
	else
		puts("Não tenho como responder neste momento");
}

/**
 * Move um item do mundo para o inventário
 * @param  e1 elemento a ser tranferido
 * @param  e2 NULL
 * @return    status de sucesso
 */
void pegar(Elemento* e1, Elemento* e2) { //função para pegar o objeto
	if (e1->tipo == LUGAR) {
		puts("Não dá para pegar um lugar!");
		return;
	}
	if(Ativo(e1)) {
		if(Visivel(e1)) {
			int r = presente(e1->nome);
			switch (r) {
				case 2:
					printf("Você já está com %s!\n", e1->nome);
					return;
				case 1:
					/* insere no inventário */
					inventario = ht_insere(inventario, e1->nome, OBJ, e1);
					/* retira do local */
					Posic->contem = ht_retira(Posic->contem, e1->nome);
					printf("Peguei %s\n", e1->nome);
					return;
				default:
					printf("Não há %s aqui!\n", e1->nome);
					return;
			}
		}
		printf("Não consigo ver nenhum %s!\n", e1->nome);
	} else
		printf("Não existe %s!!!!\n", e1->nome);
}

/**
 * Remove um item do inventário e o coloca no mundo
 * @param  e1 objeto a ser largado
 * @param  e2 NULL
 * @return    status de sucesso
 */
void largar(Elemento* e1, Elemento* e2) { // função para soltar o objeto caso ele esteja no inventário
	if (e1->tipo == LUGAR) {
		puts("Largue a mão de ser besta!");
		return;
	}
	if (ht_busca(inventario, e1->nome)) {
		/* insere no local */
		Posic->contem = ht_insere(Posic->contem, e1->nome, OBJ, e1);
		/* retira do inventario */
		inventario = ht_retira(inventario, e1->nome);
		printf("Larguei %s\n", e1->nome);
		return;
	} else {
		puts("Tu não ta com isso não parceiro...");
	}
}

/* funcoes extra */
void examinarEspecial(Elemento *e1, Elemento *e2) {
	if(e1)
		if(!Conhecido(e1)){
			puts(e1->longa);
		} else {
			puts(e1->curta);
		}
	else
		if(!Conhecido(Posic)){
			puts(e1->longa);
		} else {
			puts(e1->curta);
		}
}

void usarFerramenta(Elemento *e1, Elemento *e2) {
	if(strcmp(e2->nome, "criado mudo") != 0) {
		puts("não da pra usar isso aqui\n");
		return;
	}
	puts("ao abrir o criado mudo você vê um cartão plástico.\n");
	cartao.detalhe.obj.visivel = True;
	e2->conhecido = True;
}

void usarMartelo(Elemento *e1, Elemento *e2) {
	if(Posic != &banheiro) {
		puts("não da pra usar isso aqui");
		return;
	}
	quarto.ativo = True;
	sala.ativo = True;
	puts("Você abriu a porta! \n");
}

void usarFaca(Elemento *e1, Elemento *e2) {
	if(!e2 || strcmp(e2->nome, "sofa") != 0) {
		puts("não da pra usar isso aqui\n");
		return;
	}
	puts("ao rasgar o sofá uma chave cai aos seus pés\n");
	chave2.detalhe.obj.visivel = True;
	e2->conhecido = True;
}

void usarChave(Elemento *e1, Elemento *e2) {
	if(e1 && e2) {
		int len1 = strlen(e1->nome);
		const char *last1 = &e1->nome[len1-1];
		int len2 = strlen(e2->nome);
		const char *last2 = &e2->nome[len2-1];
		if(strcmp(last1, last2) == 0) {
			puts("Abriu!");
			cadeados--;
			e2->conhecido = True;
		} else {
			puts("essa não é a chave certa");
		}
		if(cadeados == 0) {
			final.ativo = True;
		}
	} else {
		puts("onde?? ");
	}
}

void usarChaveP(Elemento *e1, Elemento *e2) {
	if(strcmp(e2->nome, "fogao") != 0) {
		puts("no no no...\n");
		return;
	}
	puts("você abre o fogão e vê algo dentro.\n");
	fogao.conhecido = True;
	chave3.detalhe.obj.visivel = True;
}

void usarCartao(Elemento *e1, Elemento *e2) {
	if(strcmp(Posic->nome, "sala") != 0) {
		puts("no no no...\n");
		return;
	}
	puts("*bibibip* a porta se abre");
	cozinha.ativo = True;
	entrada.ativo = True;
}

void usar(Elemento *e1, Elemento *e2) {
	printf("no no no...\n");
}



/* Para inicializar as funções, copiei da calculadora */
struct initfunc {
	char *fname;
	Fptr fnct;
};

/* Lista de verbos */
struct initfunc lfunc[] = {
	{"pegue",   pegar},
	{"cate",    pegar},
	{"largue",  largar},
	{"solte",   largar},
	{"jogue",   largar},
	{"examine", examinar},
	{"use", usar},
	{0, 0}
};

/* Para objetos */
struct initobj {
	char *name;
	Elemento *obj;
};

/* Lista de objetos */
struct initobj lobjs[] = {
	{"chave",           &chave},
	{"privada",         &privada},
	{"banheira",        &banheira},
	{"chave 1",         &chave1},
	{"chave de ferro 1",&chave1},
	{"chave 2",         &chave2},
	{"chave de ferro 2",&chave2},
	{"chave 3",         &chave3},
	{"chave de ferro 3",&chave3},
	{"pia",             &pia},
	{"chave pequena",   &chaveP},
	{"sofa",            &sofa},
	{"geladeira",       &geladeira},
	{"faca",            &faca},
	{"fogao",           &fogao},
	{"martelo",         &martelo},
	{"cama",            &cama},
	{"criado mudo",     &criadoMudo},
	{"cartao",          &cartao},
	{"mesa",            &mesa},
	{"mesa de centro",  &mesa},
	{"chave de fenda",  &ferramenta},
	{"ferramenta",      &ferramenta},
	{"cadeado 1",       &cadeado1},
	{"cadeado 2",       &cadeado2},
	{"cadeado 3",       &cadeado3},
	{ 0, 0}
};

/* Para lugares */
struct initlug {
	char *name;
	Elemento *lug;
};

/* Lista de lugares */
struct initlug llugs[] = {
	{"quarto",   &quarto},
	{"sala",     &sala},
	{"cozinha",  &cozinha},
	{"banheiro", &banheiro},
	{"entrada",  &entrada},
	{"final",    &final},
	{ 0, 0}
};

/* Inicializa a tabela de símbolos passada como argumento */
TabSim init_table(TabSim sym_table) {
	int i;//int
	//TabSim ptr = sym_table;		/* cabeça da lista */
	TabSim ptr = ht_cria(30);

	/* Lista de verbos */
	for (i = 0; lfunc[i].fname != 0; i++) {
		/* insere */
		ptr = ht_insere(ptr, lfunc[i].fname, VERBO, lfunc[i].fnct);
		/* completa os dados */
		//ptr->value = lfunc[i].fnct;
	}

	/* Lista de objetos */
	for (i = 0; lobjs[i].name != 0; i++) {
		Elemento * oo = lobjs[i].obj;
		/* insere */
		ptr = ht_insere(ptr, lobjs[i].name, OBJ, oo);
		//ptr = ht_insere(ptr, oo->nome, OBJ, oo);
		oo->contem = NULL;
	}

	/* Lista de lugares */
	for (i = 0; llugs[i].name != 0; i++) {
		/* insere */
		ptr = ht_insere(ptr, llugs[i].name, LUGAR,llugs[i].lug);
	}

	/* Coloca os objetos nos lugares */
	banheiro.contem = ht_insere(banheiro.contem, "privada",       OBJ, &privada);
	privada.contem  = ht_insere(privada.contem,  "chave 1",       OBJ, &chave1);
	banheiro.contem = ht_insere(banheiro.contem, "chave 1",       OBJ, &chave1);
	privada.contem  = ht_insere(privada.contem,  "chave",         OBJ, &chave1);
	//banheiro.contem = ht_insere(banheiro.contem, "chave",       OBJ, &chave1);
	banheiro.contem = ht_insere(banheiro.contem, "banheira",      OBJ, &banheira);
	banheira.contem = ht_insere(banheira.contem, "martelo",       OBJ, &martelo);
	banheiro.contem = ht_insere(banheiro.contem, "martelo",       OBJ, &martelo);
	banheiro.contem = ht_insere(banheiro.contem, "pia",           OBJ, &pia);
	pia.contem      = ht_insere(pia.contem,      "chave pequena", OBJ, &chaveP);
	banheiro.contem = ht_insere(banheiro.contem, "chave pequena", OBJ, &chaveP);
	pia.contem      = ht_insere(pia.contem,      "chave",         OBJ, &chaveP);


	quarto.contem     = ht_insere(quarto.contem,     "cama",        OBJ, &cama);
	quarto.contem     = ht_insere(quarto.contem,     "criado mudo", OBJ, &criadoMudo);
	criadoMudo.contem = ht_insere(criadoMudo.contem, "cartao",      OBJ, &cartao);
	quarto.contem     = ht_insere(quarto.contem,     "cartao",      OBJ, &cartao);

	sala.contem = ht_insere(sala.contem, "sofa",       OBJ, &sofa);
	sofa.contem = ht_insere(sofa.contem, "chave 2",    OBJ, &chave2);
	sala.contem = ht_insere(sala.contem, "chave 2",    OBJ, &chave2);
	sofa.contem = ht_insere(sofa.contem, "chave",      OBJ, &chave2);
	sala.contem = ht_insere(sala.contem, "mesa",       OBJ, &mesa);
	mesa.contem = ht_insere(mesa.contem, "ferramenta", OBJ, &ferramenta);
	sala.contem = ht_insere(sala.contem, "ferramenta", OBJ, &ferramenta);

	cozinha.contem   = ht_insere(cozinha.contem,   "geladeira", OBJ, &geladeira);
	geladeira.contem = ht_insere(geladeira.contem, "faca",      OBJ, &faca);
	cozinha.contem   = ht_insere(cozinha.contem,   "faca",      OBJ, &faca);
	cozinha.contem   = ht_insere(cozinha.contem,   "fogao",     OBJ, &fogao);
	fogao.contem     = ht_insere(fogao.contem,     "chave 3",   OBJ, &chave3);
	cozinha.contem   = ht_insere(cozinha.contem,   "chave 3",   OBJ, &chave3);
	fogao.contem     = ht_insere(fogao.contem,     "chave",     OBJ, &chave3);


	entrada.contem = ht_insere(entrada.contem, "cadeado 1", OBJ, &cadeado1);
	entrada.contem = ht_insere(entrada.contem, "cadeado 2", OBJ, &cadeado2);
	entrada.contem = ht_insere(entrada.contem, "cadeado 3", OBJ, &cadeado3);

	/* saidas */
	entrada.detalhe.lug.Saidas[2] = &cozinha;
	cozinha.detalhe.lug.Saidas[0] = &sala;
	sala.detalhe.lug.Saidas[2]    = &quarto;
	quarto.detalhe.lug.Saidas[2]  = &banheiro;
	final.detalhe.lug.Saidas[2]   = &entrada;

	/* Ajustes finais */
	criadoMudo.contem =    ht_insere(criadoMudo.contem, "examine", VERBO, examinarEspecial);
	sofa.contem       =    ht_insere(sofa.contem,       "examine", VERBO, examinarEspecial);
	cadeado1.contem   =    ht_insere(cadeado1.contem,   "examine", OBJ,   examinarEspecial);
	cadeado2.contem   =    ht_insere(cadeado2.contem,   "examine", OBJ,   examinarEspecial);
	cadeado3.contem   =    ht_insere(cadeado3.contem,   "examine", OBJ,   examinarEspecial);
	ferramenta.contem =    ht_insere(ferramenta.contem, "use",     VERBO, usarFerramenta);
	martelo.contem    =    ht_insere(martelo.contem,    "use",     VERBO, usarMartelo);
	//banheiro.contem   =    ht_insere(banheiro.contem,   "use",     VERBO, usarMartelo);
	faca.contem       =    ht_insere(faca.contem,       "use",     VERBO, usarFaca);
	chaveP.contem     =    ht_insere(chaveP.contem,     "use",     VERBO, usarChaveP);
	chave1.contem     =    ht_insere(chave1.contem,     "use",     VERBO, usarChave);
	chave2.contem     =    ht_insere(chave2.contem,     "use",     VERBO, usarChave);
	chave3.contem     =    ht_insere(chave3.contem,     "use",     VERBO, usarChave);
	cartao.contem     =    ht_insere(cartao.contem,     "use",     VERBO, usarCartao);

	/* posição inicial */
	inventario = ht_cria(10);
	Posic = &banheiro;
	/* retorna a tabela */
	return ptr;
}

