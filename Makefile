#############################################################
#Nome: Henrique Suzuki                 NUSP: 10297626		#
#Nome: Rubens Gomes Neto               NUSP:  9318484		#
#############################################################
#$(info $(SHELL))
LOADLIBES= -lfl -lreadline
CC = gcc
CFLAGS = -Wall -g

%.c: %.y
	bison $<
	mv $*.tab.c $*.c

aventura: jogo.o advlib.o aventura.o aventuraL.o hashtable.o linkedlist.o base.o

aventura.c : aventura.y

aventuraL.o: aventuraL.l aventura.c

clean:
	rm -f *.o *~ jogo teste
