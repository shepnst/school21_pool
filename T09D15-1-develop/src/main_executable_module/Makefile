CC=gcc
CFLAGS=-c -Wall -Werror -Wextra

all: Quest_3

Quest_3: main_executable_module.o decision.o data_stat.o data_io.o data_process.o
	$(CC) $(FLAGS) main_executable_module.o decision.o data_stat.o data_io.o data_process.o -o ../../build/Quest_3

main_executable_module.o: main_executable_module.c
	$(CC) $(FLAGS) -c main_executable_module.c -o main_executable_module.o

data_io.o: ../data_libs/data_io.c
	$(CC) $(FLAGS) -c ../data_libs/data_io.c -o data_io.o

data_stat.o: ../data_libs/data_stat.c
	$(CC) $(FLAGS) -c ../data_libs/data_stat.c -o data_stat.o

data_process.o: ../data_module/data_process.c
	$(CC) $(FLAGS) -c ../data_module/data_process.c -o data_process.o

decision.o: ../yet_another_decision_module/decision.c 
	$(CC) $(FLAGS) -c ../yet_another_decision_module/decision.c -o decision.o 


clean:
	rm *.o

rebuild:
	make clean
	make all

data_stat.a: ../data_libs/data_stat.c
	ar rcs data_stat.a data_stat.o

build_with_static: main_executable_module.o decision.o data_stat.o data_io.o data_process.o
	$(CC) $(FLAGS) data_stat.a main_executable_module.o decision.o data_stat.o data_io.o data_process.o -o ../build/Quest_5

data_process.so: data_process.o
	$(CC) $(FLAGS) ../data_module/data_process.c
	$(CC) -shared data_stat.o data_process.o -o libdata_process.o

build_with_dynamic: main_executable_module.o data_io.o data_stat.o decision.o data_process.so
	$(CC) main_executable_module.o data_io.o data_stat.o decision.o libdata_process.so -o ../../build/Quest_6
	mv libdata_process.so ../../build

