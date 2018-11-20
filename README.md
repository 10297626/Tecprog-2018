	Nome: Henrique Suzuki                 NUSP: 10297626
	Nome: Rubens Gomes Neto               NUSP: 9318484

#Relatório Projeto Tecprog 2018 "Aventura"

	Primeira Fase

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

	Dificuldades encontradas:
	Acredito que pode ser benfico adicionar um novo arquivo .c e .h com algumas das estruturas mais basicas, tipo booleans. Mas seria mais pra facilidade de leitura do codigo, mas pode ser usada pra criar estruturas pra serem usadas pela linkedlist e hashtable.
	Seria bom alterar o hashtable no sentido da lista pra remover a dependencia em string.h, pensei em alterar a implementação para resolver as colisoes com listas, mas a implementacao atual é o suficiente
