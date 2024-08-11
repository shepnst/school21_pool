CC=gcc
CFLAGS= -Wall -Werror -Wextra -std=c11

print_module: main_module_entry_point.o print_module.o
	$(CC) $(CFLAGS) main_module_entry_point.o print_module.o -o ../build/Quest_1

bst_create_test: bst_create_test.o bst.o
	$(CC) $(CFLAGS) bst_create_test.o bst.o -o ../build/Quest_2

bst_insert_test: bst_insert_test.o bst.o 
	$(CC) $(CFLAGS) bst.o bst_insert_test.o -o ../build/Quest_4 
	

main_module_entry_point.o: main_module_entry_point.c print_module.h
	$(CC) $(FLAGS) -c main_module_entry_point.c -o main_module_entry_point.o

print_module.o: print_module.c 
	$(CC) $(FLAGS) -c print_module.c -o print_module.o

bst_create_test.o: bst_create_test.c bst.c bst.h
	$(CC) $(FLAGS) -c  bst_create_test.c -o  bst_create_test.o

bst_insert_test.o: bst_insert_test.c  
	$(CC) $(CFLAGS) -c bst_insert_test.c -o bst_insert_test.o
	

bst.o: bst.c
	$(CC) $(FLAGS) -c bst.c -o bst.o


clean:
	rm -f *.o

rebuild:
	make clean
	make all