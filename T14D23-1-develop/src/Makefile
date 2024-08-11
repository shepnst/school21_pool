CC=gcc
CFLAGS= -Wall -Werror -Wextra -std=c11

all: state_search

state_search: state_search.o
	$(CC) $(CFLAGS) state_search.o -o ../build/state_search

state_search.o: state_search.c
	$(CC) $(CFLAGS) -c state_search.c -o state_search.o

clean:
	rm -f *.o

rebuild:
	make clean
	make all
