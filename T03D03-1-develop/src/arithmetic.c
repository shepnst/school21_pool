#include <stdio.h>

int sum(int a, int b);
int diff(int a, int b);
int multi(int a, int b);
int div(int a, int b);

int main() {
    int a;
    int b;
    char c;
    int s, m, y, d;
    if (scanf("%d %d%c", &a, &b, &c) != 3 || c != '\n') {
        printf("n/a\n");
    } else {
        s = sum(a, b);
        m = diff(a, b);
        y = multi(a, b);
        d = div(a, b);
        if (b != 0) {
            printf("%d %d %d %d\n", s, m, y, d);
        } else if (b == 0) {
            char r[] = "n/a\n";
            printf("%d %d %d %s\n", s, m, y, r);
        }
    }
    return 0;
}

int sum(int a, int b) { return a + b; }
int diff(int a, int b) { return a - b; }
int multi(int a, int b) { return a * b; }
int div(int a, int b) {
    if (b != 0) return a / b;
    return 0;
}
