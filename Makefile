# pro terminal 
# gcc  teste.c hash_table.c linked_list.c -o teste 
# depois rode teste\
CC=gcc
CFLAGS= -Wall

teste: teste.o hash_table.o linked_list.o advlib.o
	gcc $(CFLAGS) -o teste teste.o hash_table.o linked_list.o advlib.o

teste.o: hash_table.h linked_list.h advlib.h

hash_table.o: advlib.h

linked_list.o: advlib.h

advlib.o:

clean:
	rm -f *.o *~ teste
