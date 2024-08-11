CC=gcc
CFLAGS= -Wall -Werror -Wextra -std=c11

all: cipher

cipher: cipher.o
	$(CC) $(CFLAGS) cipher.o -o ../build/cipher

cipher.o: cipher.c
	$(CC) $(CFLAGS) -c cipher.c -o cipher.o

clean:
	rm -f *.o

rebuild:
	make clean
	make all
