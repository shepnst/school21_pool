FLAG = -Wall -Werror -Wextra -std=c11

all: graph

graph: string_stack.o double_stack.o logic.o string_functions.o graph.o
	gcc -o ../build/graph graph.o double_stack.o string_stack.o logic.o string_functions.o

graph.o: graph.c
	gcc $(FLAG) -c graph.c -o graph.o

logic.o: logic.c
	gcc $(FLAG) -c logic.c -o logic.o

string_functions.o: string_functions.c
	gcc $(FLAG) -c string_functions.c -o string_functions.o

double_stack.o: double_stack.c
	gcc $(FLAG) -c double_stack.c -o double_stack.o

string_stack.o: string_stack.c
	gcc $(FLAG) -c string_stack.c -o string_stack.o

clean:
	rm -rf *.o ../build/graph

rebuild: clean all