	Nome: Henrique Suzuki                 NUSP: 10297626
	Nome: Rubens Gomes Neto               NUSP: 9318484

#Relatório Projeto Tecprog 2018 "Aventura"

	Primeira Fase
	
	Instrunções:
	Pra compilar o programa coloque todos os arquivos em um diretório e utilze o make.
	Depois execute o teste.
	O programa teste.c testa todas as funções do hashtable.c e do linkedlist.c.
	
	Detalhes da implementação:
	Os objetos e elementos tem somente informações mínimas para teste nessa fase, mais serão implementadas no futuro.
	A hash function implementada na Hash Table(ht) soma todos os caracteres da key (como numeros inteiros do ASCII)
	e pega o resto da divisão dessa soma com o tamanho da ht. Caso aconteça uma colisão ele segue adiante no vetor.
	Portanto um item ao ser retirado da ht é substituido por um DUMMY, assim é possivel buscar todos os items.
	A lista ligada funciona de forma padrão, com inserção no inicio da lista.
	
	Dificuldades encontradas:
