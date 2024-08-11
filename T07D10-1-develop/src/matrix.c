#include <stdio.h>
#include <stdlib.h>
#define MMAX 100
#define NMAX 100
int input(int *a, int n);
// void output(int *a, int len_arr);
int input_menu(int *num);
int input_m_n(int *m, int *n);
void create_dyn1(int m, int n);
void create_dyn2(int m, int n);
void create_dyn3(int m, int n);
void create_static(int m, int n);

int main() {
    int num;
    int flag = input_menu(&num);
    int m, n;
    if (flag) {
        int flag_m_n = input_m_n(&m, &n);
        if (flag_m_n) {
            if (n == 1 && (m > MMAX || n > NMAX)) {
                printf("n/a");
            } else if (n == 1 && (m <= MMAX && n <= NMAX)) {
                create_static(m, n);
            } else if (n == 2) {
                create_dyn1(m, n);
            } else if (n == 3) {
                create_dyn2(m, n);
            } else if (n == 4) {
                create_dyn3(m, n);
            }

        } else {
            printf("n/a");
        }

    } else {
        printf("n/a");
    }

    return 0;
}
int input_menu(int *num) {
    char c;
    int res1 = scanf("%d%c", num, &c);
    int flag = 1;
    if ((res1 != 2) || (c != '\n')) {
        flag = 0;
    }
    if (*num <= 0) {
        flag = 0;
    }
    return flag;
}

void create_dyn1(int n, int m) {
    const int M = m, N = n;
    int **array = malloc(M * N * sizeof(int) + M * sizeof(int *));
    int *ptr = (int *)(array + M);
    int value;
    char c;
    int flag = 1;
    for (int i = 0; i < M; i++) {
        array[i] = ptr + N * i;
    }
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            int res1 = scanf("%d%c", &value, &c);
            if ((res1 == 2) || (c == ' ')) {
                array[i][j] = value;
            } else {
                flag = 0;
                break;
            }
        }
    }
    if (flag != 0) {
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                if (j != N - 1) {
                    printf("%d ", array[i][j]);
                } else {
                    printf("%d", array[i][j]);
                }
            }
            if (i != M - 1) {
                printf("\n");
            }
        }
    }
    free(array);
}

void create_dyn2(int m, int n) {
    const int M = m, N = n;
    int flag = 1;
    int value;
    char c;
    int **array = malloc(M * sizeof(int *));
    for (int i = 0; i < M; i++) {
        array[i] = malloc(N * sizeof(int));
    }
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            int res1 = scanf("%d%c", &value, &c);
            if ((res1 == 2) || (c == ' ')) {
                array[i][j] = value;
            } else {
                flag = 0;
                break;
            }
        }
    }
    if (flag != 0) {
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                if (j != N - 1) {
                    printf("%d ", array[i][j]);
                } else {
                    printf("%d", array[i][j]);
                }
            }
            if (i != M - 1) {
                printf("\n");
            }
        }
        for (int i = 0; i < M; i++) {
            free(array[i]);
        }
    }
    free(array);
}

void create_dyn3(int m, int n) {
    const int M = m, N = n;
    int value;
    char c;
    int flag = 1;
    int **array = malloc(M * sizeof(int *));
    int *values_array = malloc(M * N * sizeof(int));
    for (int i = 0; i < M; i++) {
        array[i] = values_array + N * i;
    }
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            int res1 = scanf("%d%c", &value, &c);
            if ((res1 == 2) || (c == ' ')) {
                array[i][j] = value;
            } else {
                flag = 0;
                break;
            }
        }
    }
    if (flag != 0) {
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                if (j != N - 1) {
                    printf("%d ", array[i][j]);
                } else {
                    printf("%d", array[i][j]);
                }
            }
            if (i != M - 1) {
                printf("\n");
            }
        }
    }
    free(values_array);
    free(array);
}

int input_m_n(int *m, int *n) {
    char c;
    int res1 = scanf("%d %d%c", m, n, &c);
    int flag = 1;
    if ((res1 != 3) || (c != '\n')) {
        flag = 0;
    }
    if (*n <= 0 || *m <= 0) {
        flag = 0;
    }
    return flag;
}

void create_static(int m, int n) {
    const int M = m, N = n;
    int array[n * m];
    int value;
    char c;
    int flag = 1;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            int res1 = scanf("%d%c", &value, &c);
            if ((res1 == 2) || (c == ' ')) {
                array[i * n + j] = value;
            } else {
                flag = 0;
                break;
            }
        }
    }
    if (flag != 0) {
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                if (j != N - 1) {
                    printf("%d ", array[i * n + j]);
                } else {
                    printf("%d", array[i * n + j]);
                }
            }
            if (i != M - 1) {
                printf("\n");
            }
        }
    }
}