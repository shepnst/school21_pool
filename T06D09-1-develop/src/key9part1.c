/*------------------------------------
        Здравствуй, человек!
        Чтобы получить ключ
        поработай с комментариями.
-------------------------------------*/

#include <stdio.h>
#define NMAX 10
int input(int *buffer, int *length);
void output(int *a, int len_arr);
int sum_numbers(int *buffer, int length);
int find_numbers(int *buffer, int length, int number, int *numbers);
int len_of_arr(int *numbers);

/*------------------------------------
        Функция получает массив данных
        через stdin.
        Выдает в stdout особую сумму
        и сформированный массив
        специальных элементов
        (выбранных с помощью найденной суммы):
        это и будет частью ключа
-------------------------------------*/
int main() {
    int n;
    int data[NMAX];
    int ans[NMAX];
    int flag = input(data, &n);
    int summa = sum_numbers(data, n);
    int len = find_numbers(data, n, summa, ans);
    if (flag) {
        if (summa) {
            printf("%d\n", summa);
            find_numbers(data, n, summa, ans);
            output(ans, len);
        } else {
            printf("n/a");
        }
    }
}

int input(int *a, int *n) {
    char c;
    int res1 = scanf("%d%c", n, &c);
    int flag = 1;
    if ((res1 != 2) || (c != '\n')) {
        flag = 0;
    }
    if (*n <= 0 || *n > NMAX) {
        flag = 0;
    }
    if (flag) {
        for (int *p = a; p - a < *n; p++) {
            int res = scanf("%d%c", p, &c);
            if (((res != 2) || (c != ' ')) && p - a != *n - 1) {
                flag = 0;
            } else if (((res != 2) || (c != '\n')) && p - a == *n - 1) {
                flag = 0;
            }
            if (flag == 0) {
                printf("n/a");
                break;
            }
        }
    } else {
        printf("n/a");
    }

    return flag;
}
/*------------------------------------
        Функция должна находить
        сумму четных элементов
        с 0-й позиции.
-------------------------------------*/
int sum_numbers(int *buffer, int length) {
    int sum = 0;

    for (int i = 0; i < length; i++) {
        if (buffer[i] % 2 == 0) {
            sum = sum + buffer[i];
        }
    }
    return sum;
}

/*------------------------------------
        Функция должна находить
        все элементы, на которые нацело
        делится переданное число и
        записывает их в выходной массив.
-------------------------------------*/
int find_numbers(int *buffer, int length, int number, int *numbers) {
    int index = 0;
    int len = 0;
    for (int i = 0; i < length; i++) {
        if (buffer[i] != 0 && number % buffer[i] == 0) {
            numbers[index] = buffer[i];
            index++;
            len++;
        }
    }
    return len;
}

void output(int *a, int len_arr) {
    for (int *p = a; p - a < len_arr; p++) {
        if (p - a != len_arr - 1) {
            printf("%d ", *p);
        } else {
            printf("%d", *p);
        }
    }
}
