#include <stdio.h>
#include <stdlib.h>

int input(int **matrix, int *n, int *m);
void output(int **matrix, int *n, int *m);
int sum(int matrix_first, int n_first, int m_first, int matrix_second, int n_second, int m_second,
        int **matrix_result, int *n_result, int *m_result);
int transpose(int **matrix, int n, int m);
int mul(int matrix_first, int n_first, int m_first, int matrix_second, int n_second, int m_second,
        int **matrix_result, int *n_result, int *m_result);

int main() {
    int operation;
    int flag = 1;
    char c;
    if (scanf("%d%c", &operation, &c) != 2 || c != '\n') {
        flag = 0;
        printf("n/a");
    }
    if (flag != 0 && operation == 3) {
        int n, m;
        int **matrix;
        if (input(matrix, &n, &m)) {
            transpose(matrix, m, n);
        }
    } else if (flag != 0) {
        int n, m;
        int **matrix;
        if (input(matrix, &n, &m)) {
            int **data;
            int a, b;
            if (input(data, &a, &b)) {
                int **result;
                if (n == 1 && n == a && m == b) {
                    sum(matrix, m, n, data, b, a, result, &m, &n);
                } else if (operation == 2 && m == a) {
                    mul(matrix, n, m, data, b, a, result, &m, &n);
                } else {
                    printf("n/a");
                }
            }
        }
    } else {
        printf("n/a");
    }
    return 0;
}

int input(int **matrix, int *n, int *m) {
    int flag = 0;
    char c;
    if (scanf("%d%c", n, &c) == 2 && (c == '\n' || c == ' ')) {
        if (scanf("%d%c", m, &c) == 2 && (c == '\n' || c == ' ')) {
            flag = 1;
        }
    }
    if (flag != 0) {
        const int M = *n, N = *m;

        matrix = malloc(M * sizeof(int *));
        for (int i = 0; i < M; i++) {
            matrix[i] = malloc(N * sizeof(int));
        }
        int value;
        char c;
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                int res = scanf("%d%c", &value, &c);
                if (res == 2 && (c == '\n' || c == ' ')) {
                    matrix[i][j] = value;
                } else {
                    printf("n/a");
                    flag = 0;
                    break;
                }
            }
        }
    }
    return flag;
}
void output(int **array, int *n, int *m) {
    const int M = *m, N = *n;
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
int sum(int matrix_first, int n_first, int m_first, int matrix_second, int n_second, int m_second,
        int **matrix_result, int *n_result, int *m_result) {
    for (int i = 0; i < m_first; i++) {
        for (int j = 0; j < n_first; j++) {
            matrix_result[i][j] = matrix_first[i][j] + matrix_second[i][j];
        }
    }
    output(matrix_result, m_result, n_result);
    n_second++;
    m_second++;
    return 0;
}
int mul(int matrix_first, int n_first, int m_first, int matrix_second, int n_second, int m_second,
        int **matrix_result, int *n_result, int *m_result) {
    for (int i = 0; i < m_first; i++) {
        for (int j = 0; j < n_second; j++) {
            for (int k = 0; k < n_first; k++) {
                matrix_result[i][j] += matrix_first[i][k] * matrix_second[k][j];
            }
        }
    }
    output(matrix_result, m_result, n_result);
    m_second++;
    return 0;
}
int transpose(int **matrix, int n, int m) {
    int result[m][n];
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            result[i][j] = matrix[i][j];
        }
    }
    output(result, &m, &n);
    return 0;
}