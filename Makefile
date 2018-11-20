#############################################################
#Nome: Henrique Suzuki                 NUSP: 10297626		#
#Nome: Rubens Gomes Neto               NUSP:  9318484		#
#############################################################
#$(info $(SHELL))
CC = gcc
CFLAGS = -Wall

jogo: advlib.o hashtable.o linkedlist.o jogo.o
	$(CC) $(CFLAGS) -o $@ $^

teste: advlib.o hashtable.o linkedlist.o teste.o
	$(CC) $(CFLAGS) -o $@ $^

advlib.o: advlib.c advlib.h linkedlist.h hashtable.h
	$(CC) $(CFLAGS) -c $<

hashtable.o: hashtable.c hashtable.h
	$(CC) $(CFLAGS) -c $<

linkedlist.o: linkedlist.c linkedlist.h
	$(CC) $(CFLAGS) -c $<

teste.o: teste.c hashtable.h linkedlist.h advlib.h
	$(CC) $(CFLAGS) -c $<

jogo.o: jogo.c hashtable.h linkedlist.h advlib.h
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f *.o *~ jogo
