# pro terminal 
# gcc teste.c hashtable.c hashtable.h linked_list.c linked_list.h advlib.h -o teste
CC=gcc
CFLAGS=-I.

teste: teste.o hashtable.o linked_list.o  
     $(CC) -o teste teste.o hashtable.o linked_list.o  


