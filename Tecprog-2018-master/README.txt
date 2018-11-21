
Nome: Henrique Suzuki                 NUSP: 10297626
Nome: Rubens Gomes Neto               NUSP: 9318484

Relatório Projeto Tecprog 2018 "Aventura" , Escape the Room

	Segunda Fase
	
	Instrunções:
	Pra compilar o programa coloque todos os arquivos .c e .h em um diretório e no terminal execute:
	gcc jogo.c hash_table.c linked_list.c -o jogo
	e depois execute o jogo.
	O programa começa no lugar inicial e roda pelas salas mostrando as descrições. Ainda nao é possível jogar.
	
	Detalhes da implementação:
	Adicionamos as informações para os elementos além de dividi-los em lugares e objetos, achamos melhor ter a seguinte implementação:
	-Os elementos tem as informações comuns aos lugares e objetos.
	-os Objetos então seriam uma struct que contém um elemento mais uma lista de atributos que ainda vai ser implementada
	-os lugares ebtão seriam uma struct que contém um elemento mais a lista de saídas, como houve dificuldade na hora de usar o hash table, criamos
	campos com ponteiros  leste, oeste, norte e sul.
	A estória é bem simples, seguindo o estilo dos jogos escape the room, o personagem principal acorda em uma casa sem memória da noite anterior
	e nota que está trancado dentro dela, precisando resolver puzzles para poder destrancar a porta principal e fugir.
	
	
	Dificuldades encontradas:
	-Char*, char array e strings são confusas, a solução foi fazer com que uma char array receba uma string e um char* receba o endereço da char array;
	-Makefile ainda não funciona.
	-As listas de saida e contém ainda estão vazias
	-Não conseguimos usar a tabela de simbolo ainda.
	-faltam os objetos e as suas interações para resolver puzzles
	-os Textos e as descrições não funcionam por algum motivo. Talvez problemas com memoria.
	-outro dificuldade encontrada foi de organização, tivemos dificuldade de organizar um cronograma e de organizar a programação para que o projeto
	consiga avançar, tendo momentos onde o mesmo código foi feito duas vezes.
	
	
	
	
