#include <stdio.h>
#include <stdlib.h>

#include "../data_libs/data_io.h"
#include "decision.h"
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
        if (make_decision(data, n))
            printf("YES");
        else
            printf("NO");
    } else {
        printf("ERROR");
    }
    free(data);
    return 0;
}
