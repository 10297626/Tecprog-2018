# pro terminal 
# gcc advlib.h  hash_table.h hash_table.c linked_list.h linked_list.c teste.c -o teste
CC=gcc
CFLAGS=-I.

teste: teste.o hash_table.o linked_list.o  
	$(CC) -o teste teste.o hash_table.o linked_list.o  


