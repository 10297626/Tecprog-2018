# pro terminal 
# gcc teste.c hash_table.c hash_table.h linked_list.c linked_list.h advlib.h -o teste
CC=gcc
CFLAGS=-I.

teste: teste.o hash_table.o linked_list.o  
	$(CC) -o teste teste.o hash_table.o linked_list.o  


