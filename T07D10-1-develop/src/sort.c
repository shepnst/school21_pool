#include <stdio.h>
#include <stdlib.h>
int input(int *a, int n);
void sort(int *a, int n);
void output(int *a, int len_arr);
int input_n(int *n);

int main() {
    int n;
    int flag = input_n(&n);
    if (flag) {
        int *data = (int *)malloc(n * sizeof(int));
        int flag2 = input(data, n);

        if (flag2) {
            sort(data, n);
            output(data, n);
        } else {
            printf("n/a");
        }
        free(data);
    } else {
        printf("n/a");
    }

    return 0;
}

int input_n(int *n) {
    char c;
    int res1 = scanf("%d%c", n, &c);
    int flag = 1;
    if ((res1 != 2) || (c != '\n')) {
        flag = 0;
    }
    if (*n <= 0) {
        flag = 0;
    }
    return flag;
}

int input(int *a, int n) {
    char c;
    int flag = 1;
    for (int *p = a; p - a < n; p++) {
        int res = scanf("%d%c", p, &c);
        if (((res != 2) || (c != ' ')) && p - a != n - 1) {
            flag = 0;
        } else if (((res != 2) || (c != '\n')) && p - a == n - 1) {
            flag = 0;
        }
        if (flag == 0) {
            printf("n/a");
            break;
        }
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

void sort(int *a, int n) {
    for (int p = 0; p < n - 1; p++) {
        for (int b = 0; b < n - 1; b++) {
            int temp;
            if (a[b] > a[b + 1]) {
                temp = a[b];
                a[b] = a[b + 1];
                a[b + 1] = temp;
            }
        }
    }
}