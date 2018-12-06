	Nome: Henrique Suzuki                 NUSP: 10297626
	Nome: Rubens Gomes Neto               NUSP: 9318484

#Relatório Projeto Tecprog 2018 "Aventura"

	Terceira Fase

	Instrunções:
	Pra compilar o programa coloque todos os arquivos em um diretório e utilze o make.
	Depois execute o teste.
	O programa teste.c testa todas as funções do hashtable.c e do linkedlist.c.

	Detalhes da implementação:
	O advlib implementa o tipo Elemento com uma union de detalhe que contem as structs especificas para objetos e lugares.
	A hash function implementada na Hash Table(ht) somando todos os caracteres da key (como numeros inteiros do ASCII) e pega o resto da divisão dessa soma com o tamanho da ht. Caso aconteça uma colisão ele segue adiante no vetor.
	Portanto um item ao ser retirado da ht é substituido por um DUMMY, assim é possivel buscar todos os items.
	A lista ligada funciona de forma padrão, com inserção no inicio da lista.
	As listas e tabelas
	As funções de ação foram adaptadas para seguir o formato geral de
	'''
		int (*FUNC)(Elemento* e1, Elemento* e2);
	'''
	as acoes serao implementadas com listas que chamam a funcao necessaria, que serao checadas hierarquicamentes, entre objeto, sala, e geral.

	Dificuldades encontradas:
	inicializacao nao e' automatica e faltaram acoes.
	faltaram a criacao de objetos, mas as bibliotecas basicas deveriam suportar
