
Nome: Alessandro Bezerra da Silva     NUSP: 10284351
Nome: Henrique Suzuki                 NUSP: 10297626
Nome: Rubens Gomes Neto               NUSP: 9318484

Relatório Projeto Tecprog 2018 "Aventura"

	Primeira Fase
	
	Instrunções:
	Pra compilar o programa coloque todos os arquivos .c e .h em um diretório e no terminal execute:
	gcc teste.c hash_table.c linked_list.c -o teste
	e depois execute o teste.
	O programa teste.c testa todas as funções do hash_table.c e do linked_list.c.
	
	Detalhes da implementação:
	Os objetos e elementos tem somente informações mínimas para teste nessa fase, mais serão implementadas no futuro.
	A hash function implementada na Hash Table(ht) soma todos os caracteres da key (como numeros inteiros do ASCII)
	e pega o resto da divisão dessa soma com o tamanho da ht. Caso aconteça uma colisão ele segue adiante na matriz.
	Portanto um item ao ser retirado da ht é substituido por um DUMMY, assim é possivel buscar todos os items.
	A lista ligada funciona de forma padrão.
	
	Dificuldades encontradas:
	-Char*, char array e strings são confusas, a solução foi fazer com que uma char array receba uma string e um char* receba o endereço da char array;
	-Dificuldades com ponteiros, já que é a primeira que o grupo programa em C. Mas achamos que conseguimos entender o suficiente.
	-Makefile ainda não funciona.
