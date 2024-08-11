#include <math.h>
#include <stdio.h>

double ver_an(double pi);
double lem_ber(double pi);
double gip(double pi);

int main() {
    double pi = -3.14159265358979323846;
    double pi_step = (pi * 2) / 41;
    for (int i = 0; i < 42; i++) {
        if (i>0){
            pi -= pi_step;
        }
        double ans1 = ver_an(pi);
        double ans2 = lem_ber(pi);
        double ans3 = gip(pi);
        if (ans2 != ans2) {
            printf("%.7lf | %.7lf | - | %.7lf\n", pi, ans1, ans3);
        } else {
            printf("%.7lf | %.7lf | %.7lf | %.7lf\n", pi, ans1, ans2, ans3);
        }
    }
    return 0;
}

double ver_an(double pi) { return 1 / (1 + pow(pi, 2)); }

double lem_ber(double pi) { return sqrt(sqrt(1 + 4 * pow(pi, 2)) - pow(pi, 2) - 1); }

double gip(double pi) { return 1 / pow(pi, 2); }