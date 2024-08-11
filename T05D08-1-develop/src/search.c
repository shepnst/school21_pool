/*
    Search module for the desired value from data array.

    Returned value must be:
        - "even"
        - ">= mean"
        - "<= mean + 3 * sqrt(variance)"
        - "!= 0"

        OR

        0
*/

#include <math.h>
#include <stdio.h>
#define NMAX 30

int input(int *a, int *n);
void output(int *a, int n);
int search(int *a, int n);
int is_prime(int *p);
double mean(int *a, int n);
int if_zero(int *p);
int three_sigm(int *p, int *a, int n);

int main() {
    int n, data[NMAX];
    int flag = input(data, &n);
    if (flag) {
        printf("%d", search(data, n));
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

double mean(int *a, int n) {
    double res = 0;
    for (int *p = a; p - a < n; p++) {
        res += *p;
    }
    return res / n;
}

int is_prime(int *p) {
    int flag = 0;
    if (*p % 2 == 0) {
        flag = 1;
    } else {
        flag = 0;
    }
    return flag;
}

int if_zero(int *p) {
    int flag = 0;
    if (*p == 0) {
        flag = 0;
    } else {
        flag = 1;
    }
    return flag;
}

double variance(int *a, int n) {
    double res2 = 0;
    double sred = mean(a, n);
    double sq = 0;
    for (int *p = a; p - a < n; p++) {
        sq = pow(*p - sred, 2);
        res2 += sq;
    }
    return res2 / n;
}

int three_sigm(int *p, int *a, int n) {
    int flag = 0;
    double varian = variance(a, n);
    double sred = mean(a, n);
    if (*p <= sred + 3 * sqrt(varian)) {
        flag = 1;
    } else {
        flag = 0;
    }
    return flag;
}

int search(int *a, int n) {
    double sred = mean(a, n);
    int resultat = 0;
    for (int *p = a; p - a < n; p++) {
        if ((is_prime(p)) && (if_zero(p)) && (*p >= sred) && (three_sigm(p, a, n))) {
            resultat = *p;
            break;
        }
    }
    return resultat;
}
