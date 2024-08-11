#include <stdio.h>

int maximum(int a, int b);

int main() {
    int a;
    int b;
    char c;
    if ((scanf("%d %d%c", &a, &b, &c) != 3) || (c != '\n')) {
        printf("n/a\n");
    } else {
        int res = maximum(a, b);
        printf("%d\n", res);
    }
    return 0;
}

int maximum(int a, int b) {
    int res;
    if (a > b) {
        res = a;
    } else if (b > a) {
        res = b;
    }
    return res;
}