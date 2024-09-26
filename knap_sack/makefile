CC = gcc
CFLAGS = -Wall -Wextra -std=c99
TARGET = main

all: main test

main: main.o lib.o
	$(CC) $(CFLAGS) -o main main.o lib.o

main.o: main.c
	$(CC) $(CFLAGS) -c main.c

test: test.o lib.o
	$(CC) $(CFLAGS) -o test test.o lib.o

test.o:
	$(CC) $(CFLAGS) -c test.c

lib.o: lib.c
	$(CC) $(CFLAGS) -c lib.c

clean:
	rm -f main test *.o

.PHONY: all clean
