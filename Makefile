# pro terminal 
# gcc  teste.c hash_table.c linked_list.c -o teste 
# depois rode teste\
CC= gcc
CFLAGS= -Wall

teste: hash_table.o linked_list.o advlib.o teste.o
	$(CC) $(CFLAGS) -o $@ $^

hash_table.o: hash_table.c advlib.h hash_table.h
	$(CC) $(CFLAGS) -c $<

linked_list.o: linked_list.c advlib.h linked_list.h
	$(CC) $(CFLAGS) -c $<

advlib.o: advlib.c advlib.h
	$(CC) $(CFLAGS) -c $<

teste.o: teste.c hash_table.h linked_list.h advlib.h
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f *.o *~ teste
