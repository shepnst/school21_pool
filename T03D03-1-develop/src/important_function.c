#include <math.h>
#include <stdio.h>
float func(float x);
// y = 7e-3 * x^4 + ((22.8 * x^⅓ - 1e3) * x + 3) / (x * x / 2) - x * (10 + x)^(2/x) - 1.01.

int main() {
    float x;
    if (scanf("%f", &x) != 1) {
        printf("n/a\n");
    } else if (x == 0) {
        printf("n/a\n");
    } else {
        float res = func(x);
        printf("%.1f\n", res);
    }
    return 0;
}

float func(float x) {
    float res = 7 * pow(10, -3) * pow(x, 4) +
                ((22.8 * pow(x, 1 / 3) - 1 * pow(10, 3)) * x + 3) / (x * x / 2) - x * pow(10 + x, 2 / x) -
                1.01;
    return res;
}