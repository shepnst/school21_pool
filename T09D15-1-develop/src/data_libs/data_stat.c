#include "data_stat.h"

#include <math.h>

double max(double *a, int n) {
    double max = a[0];
    for (int i = 0; i < n; i++) {
        if (a[i] > max) {
            max = a[i];
        }
    }
    return max;
}

double min(double *a, int n) {
    double min = a[0];
    for (int i = 0; i < n; i++) {
        if (a[i] < min) {
            min = a[i];
        }
    }
    return min;
}

double mean(double *a, int n) {
    double res = 0;
    for (int i = 0; i < n; i++) {
        res += a[i];
    }
    return res / n;
}

double variance(double *a, int n) {
    double res2 = 0;
    double sred = mean(a, n);
    double sq = 0;
    for (int i = 0; i < n; i++) {
        sq = pow(a[i] - sred, 2);
        res2 += sq;
    }
    return res2 / n;
}
void sort(double *a, int n) {
    for (int p = 0; p < n; p++) {
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
