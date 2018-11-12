#########################################################################
#Nome: Henrique Suzuki                 NUSP: 10297626					#
#Nome: Rubens Gomes Neto               NUSP:  9318484					#
#########################################################################
#$(info $(SHELL))
CC = gcc
CFLAGS = -Wall

teste: hashtable.o linkedlist.o advlib.o teste.o
	$(CC) $(CFLAGS) -o $@ $^

hashtable.o: hashtable.c advlib.h hashtable.h
	$(CC) $(CFLAGS) -c $<

linkedlist.o: linkedlist.c advlib.h linkedlist.h
	$(CC) $(CFLAGS) -c $<

advlib.o: advlib.c advlib.h
	$(CC) $(CFLAGS) -c $<

teste.o: teste.c hashtable.h linkedlist.h advlib.h
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f *.o *~ teste
