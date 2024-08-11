#include <stdio.h>

float circle(float x, float y);

int main() {
    float x, y;
    float d = 25.0;
    if (scanf("%f %f", &x, &y) != 2) {
        printf("n/a\n");
    } else {
        float res = circle(x, y);
        if (res < d) {
            printf("GOTCHA\n");
        } else {
            printf("MISS\n");
        }
    }
    return 0;
}

float circle(float x, float y) { return x * x + y * y; }