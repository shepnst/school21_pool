#include <stdio.h>
#include <stdlib.h>

#include "../data_libs/data_io.h"
#include "data_process.h"
int main() {
    double *data;
    int n;
    int res1 = scanf("%d", &n);
    int flag = 1;
    if (res1 != 1) {
        flag = 0;
    } else if (n <= 0) {
        flag = 0;
    }
    if (flag) {
        data = (double *)malloc(n * sizeof(double));
        input(data, &n);

        if (normalization(data, n))
            output(data, n);
        else
            printf("ERROR");
    } else {
        printf("ERROR");
    }
    free(data);
    return 0;
}
