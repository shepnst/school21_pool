#include <math.h>
#include <stdio.h>
#define NMAX 10

int input(int *a, int *n);
void output(int *a, int n);
int max(int *a, int n);
int min(int *a, int n);
double mean(int *a, int n);
double variance(int *a, int n);

void output_result(int max_v, int min_v, double mean_v, double variance_v);

int main() {
    int n, data[NMAX];
    int flag = input(data, &n);
    if (flag) {
        output(data, n);
        output_result(max(data, n), min(data, n), mean(data, n), variance(data, n));
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

int max(int *a, int n) {
    int max = *a;
    for (int *p = a; p - a < n; p++) {
        if (*p > max) {
            max = *p;
        }
    }
    return max;
}

int min(int *a, int n) {
    int min = *a;
    for (int *p = a; p - a < n; p++) {
        if (*p < min) {
            min = *p;
        }
    }
    return min;
}

void output(int *a, int n) {
    for (int *p = a; p - a < n; p++) {
        printf("%d ", *p);
    }
}

double mean(int *a, int n) {
    double res = 0;
    for (int *p = a; p - a < n; p++) {
        res += *p;
    }
    return res / n;
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

void output_result(int max_v, int min_v, double mean_v, double variance_v) {
    printf("\n%d %d %.6lf %.6lf", max_v, min_v, mean_v, variance_v);
}
