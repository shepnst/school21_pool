CC=gcc
CFLAGS=-c -Wall -Werror -Wextra

all: strlen_tests strcmp_tests strcpy_tests strcat_tests



strlen_tests: s21_string_test_strlen.o s21_string.o
	$(CC) $(FLAGS) s21_string_test_strlen.o s21_string.o -o ../build/Quest_1

strcmp_tests: s21_string_test_strcmp.o s21_string.o
	$(CC) $(FLAGS) s21_string_test_strcmp.o s21_string.o -o ../build/Quest_2

strcpy_tests: s21_string_test_strcpy.o s21_string.o
	$(CC) $(FLAGS) s21_string_test_strcpy.o s21_string.o -o ../build/Quest_3

strcat_tests: s21_string_test_strcat.o s21_string.o
	$(CC) $(FLAGS) s21_string_test_strcat.o s21_string.o -o ../build/Quest_4

s21_string_test_strlen.o: s21_string_test.c 
	$(CC) $(FLAGS) -D S21_STRLEN_TEST -c s21_string_test.c -o s21_string_test_strlen.o

s21_string_test_strcmp.o: s21_string_test.c 
	$(CC) $(FLAGS) -D S21_STRCMP_TEST -c s21_string_test.c -o s21_string_test_strcmp.o

s21_string_test_strcpy.o: s21_string_test.c 
	$(CC) $(FLAGS) -D S21_STRCPY_TEST -c s21_string_test.c -o s21_string_test_strcpy.o

s21_string_test_strcat.o: s21_string_test.c 
	$(CC) $(FLAGS) -D S21_STRCAT_TEST -c s21_string_test.c -o s21_string_test_strcat.o

s21_string.o: s21_string.c 
	$(CC) $(FLAGS) -c s21_string.c -o s21_string.o

clean:
	rm *.o

rebuild:
	make clean
	make all
