#include <stdio.h>
#define NMAX 10
int input(int *a);
void output(int *a, int len_arr);
void quick_sort(int *a, int l, int n);
void merge(int *left, int size1, int *right, int size2, int *b);
void merge_sort(int *b, int size);
int parts(int *a, int n);

int main() {
    int data[NMAX];

    int flag = input(data);
    if (flag) {
        int data2[NMAX];
        for (int i = 0; i < NMAX; i++) {
            data2[i] = data[i];
        }
        quick_sort(data, 0, NMAX - 1);
        output(data, NMAX);
        merge_sort(data2, NMAX);
        printf("\n");
        output(data2, NMAX);
    }
    return 0;
}

int input(int *a) {
    int flag = 1;
    char c;
    if (flag) {
        for (int *p = a; p - a < NMAX; p++) {
            int res = scanf("%d%c", p, &c);
            if (((res != 2) || (c != ' ')) && p - a != NMAX - 1) {
                flag = 0;
            } else if (((res != 2) || (c != '\n')) && p - a == NMAX - 1) {
                flag = 0;
            }
            if (flag == 0) {
                printf("n/a");
                break;
            }
        }
    } else {
        printf("n/a");
    }
    return flag;
}

void swap(int *p, int *b) {
    int temp;
    temp = *p;
    *p = *b;
    *b = temp;
}

void quick_sort(int *a, int l, int n) {
    if (l < n) {
        int pivot = a[(l + n) / 2];
        int i = l;
        int j = n;
        while (i <= j) {
            while (a[i] < pivot) {
                i++;
            }
            while (a[j] > pivot) {
                j--;
            }
            if (i <= j) {
                swap(&a[i], &a[j]);
                i++;
                j--;
            }
        }
        if (l < j) {
            quick_sort(a, l, j);
        }
        if (i < n) {
            quick_sort(a, i, n);
        }
    }
}

void merge_sort(int *b, int size) {
    if (size <= 1) {
        return;
    }
    int left[size];
    int right[size];
    int middle = size / 2;
    for (int i = 0; i < middle; i++) {
        left[i] = b[i];
    }
    for (int i = middle; i < size; i++) {
        right[i - middle] = b[i];
    }
    merge_sort(left, middle);
    merge_sort(right, size - middle);
    merge(left, middle, right, size - middle, b);
}

void merge(int *left, int size1, int *right, int size2, int *b) {
    int i = 0;
    int k = 0;
    int n = 0;
    while (i < size1 && k < size2) {
        if (left[i] <= right[k]) {
            b[n] = left[i];
            i++;
        } else {
            b[n] = right[k];
            k++;
        }
        n++;
    }
    while (i < size1) {
        b[n] = left[i];
        i++;
        n++;
    }
    while (k < size2) {
        b[n] = right[k];
        k++;
        n++;
    }
}

void output(int *a, int len_arr) {
    for (int *p = a; p - a < len_arr; p++) {
        if (p - a != len_arr - 1) {
            printf("%d ", *p);
        } else {
            printf("%d", *p);
        }
    }
}