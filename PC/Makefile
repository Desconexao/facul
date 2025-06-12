all: maketestelib.o maketeste.o
	gcc maketestelib.o maketeste.o -o maketeste

maketestelib.o: maketestelib.c
	gcc -c maketestelib.c

maketeste.o: maketeste.c
	gcc -c maketeste.c

limpa:
	rm -f *.o

