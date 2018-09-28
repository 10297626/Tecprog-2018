# pro terminal 
# gcc  teste.c hash_table.c  linked_list.c -o teste 
# depois rode teste
CC=gcc
CFLAGS=-I.

teste: teste.o hash_table.o linked_list.o  
	$(CC) -o teste teste.o hash_table.o linked_list.o  


