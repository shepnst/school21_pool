#include <stdio.h>
#define NMAX 10
int input(int *a);
void sort(int *a);
void output(int *a, int len_arr);

int main() {
    int data[NMAX];
    int flag = input(data);
    if (flag) {
        sort(data);
        output(data, NMAX);
    }
    return 0;
}

int input(int *a) {
    int flag = 1;
    char c;
    if (flag) {
        for (int *p = a; p - a < NMAX; p++) {
            int res = scanf("%d%c", p, &c);
            if (((res != 2) || (c != ' ')) && p - a != NMAX - 1) {
                flag = 0;
            } else if (((res != 2) || (c != '\n')) && p - a == NMAX - 1) {
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

void output(int *a, int len_arr) {
    for (int *p = a; p - a < len_arr; p++) {
        if (p - a != len_arr - 1) {
            printf("%d ", *p);
        } else {
            printf("%d", *p);
        }
    }
}

void sort(int *a) {
    for (int p = 0; p < 10; p++) {
        for (int b = 0; b < 10; b++) {
            int temp;
            if (a[b] > a[b + 1]) {
                temp = a[b];
                a[b] = a[b + 1];
                a[b + 1] = temp;
            }
        }
    }
}