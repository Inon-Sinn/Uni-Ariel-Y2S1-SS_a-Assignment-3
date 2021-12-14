CC=gcc
AR=ar
FLAGS= -Wall -g


all: stringProg

stringProg: main.o algo.o
	$(CC) $(FLAGS) -o stringProg main.o algo.o

algo.o: algo.c algo.h
	$(CC) $(FLAGS) -c algo.c

main.o: main.c algo.h
	$(CC) $(FLAGS) -c main.c

clean:
	rm -f *.o stringProg