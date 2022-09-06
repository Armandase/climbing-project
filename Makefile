CFLAGS=-lSDL2 -lSDL2_ttf 

all: main.o
	g++ main.o -o exec $(CFLAGS)

main.o: main.c
	g++ -c main.c -o main.o

clean:
	rm -rf *.o
