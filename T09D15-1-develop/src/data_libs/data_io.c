#include "data_io.h"

#include <stdio.h>
int input(double *data, int *n) {
    int flag = 1;
    if (flag) {
        for (int i = 0; i < *n; i++) {
            int res = scanf("%lf", &data[i]);
            if ((res != 1) && i != *n - 1) {
                flag = 0;
            } else if (((res != 1)) && i == *n - 1) {
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
void output(double *data, int n) {
    for (int i = 0; i < n; i++) {
        if (i != n - 1) {
            printf("%.2lf ", data[i]);
        } else {
            printf("%.2lf", data[i]);
        }
    }
}