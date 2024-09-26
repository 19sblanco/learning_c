CC = gcc
CFLAGS = -Wall -Wextra -std=c99
TARGET = main

all: $(TARGET)

$(TARGET): main.o lib.o
	$(CC) $CFLAGS -o $(TARGET) main.o lib.o

main.o: main.c
	$(CC) $(CFLAGS) -c main.c

lib.o: lib.c
	$(CC) $(CFLAGS) -c lib.c

clean:
	rm -f $(TARGET) *.o

.PHONY: all clean
