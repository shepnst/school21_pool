#include <math.h>
#include <stdio.h>
int is_prime(int x);
int divisor(int x);

int main() {
    int a;
    if (scanf("%d", &a) != 1) {
        printf("n/a\n");
    } else {
        if (a < 0) {
            a *= -1;
        }
        if (a == 0) {
            printf("n/a\n");
        } else {
            int res=divisor(a);
            printf("%d\n", res);
        }
    }
    return 0;
}

int divisor(int x) {
    for (int i = x; i >= 2; i--) {
        if (is_prime(i)) {
            int ans = x;
            while (ans > 0) {
                ans -= i;
            }
            if (ans == 0) {
                return i;
            }
        }
    }
    return 0;
}

int is_prime(int x) {
    if (x == 2) {
        return 1;
    } else {
        for (int i = 2; i < x; i++) {
            int for_check = x;
            while (for_check > 0) {
                for_check -= i;
            }
            if (for_check == 0) {  // i*times
                return 0;
            }
            //return 1;  // this way the num is prime
        }
    }
    return 1;
}
