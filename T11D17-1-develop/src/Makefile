CC=gcc
CFLAGS=-c -Wall -Werror -Wextra



door_struct: dmanager_module.o
	$(CC) $(FLAGS) dmanager_module.o -o ../build/Quest_1

list_test: list_test.o list.o 
	$(CC) $(FLAGS) list_test.o list.o -o ../build/Quest_2

list_test.o: list_test.c
	$(CC) $(FLAGS) -c list_test.c -o list_test.o
	
list.o: list.c
	$(CC) $(FLAGS) -c list.c -o list.o


dmanager_module.o: dmanager_module.c
	$(CC) $(FLAGS) -c dmanager_module.c -o dmanager_module.o

clean:
	rm -f *.o

rebuild:
	make clean
	make all
