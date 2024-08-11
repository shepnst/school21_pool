#include <math.h>
#include <stdio.h>

int fibonachi(int x);

int main() {
    int n;
    if (scanf("%d", &n) != 1) {
        printf("n/a\n");
    } else {
        if (n <= 0) {
            printf("n/a\n");
        } else {
            printf("%d\n", fibonachi(n));
        }
    }

    return 0;
}

int fibonachi(int n) {
    if (n == 2 || n == 1) {
        return 1;
    } else {
        return fibonachi(n - 1) + fibonachi(n - 2);
    }
}