#include <stdio.h>
#define NMAX 10

int input(int *a, int *n);
void output(int *a, int n);
void squaring(int *a, int n);

int main() {
    int n, data[NMAX];
    int flag = input(data, &n);
    if (flag) {
        squaring(data, n);
        output(data, n);
    } else {
    }

    return 0;
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

void output(int *a, int n) {
    for (int *p = a; p - a < n; p++) {
        printf("%d ", *p);
    }
}

void squaring(int *a, int n) {
    for (int *p = a; p - a < n; p++) {
        *p = (*p) * (*p);
    }
}
