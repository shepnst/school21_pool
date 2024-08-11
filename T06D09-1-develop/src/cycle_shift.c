#include <math.h>
#include <stdio.h>
#define NMAX 10
int input(int *buffer, int *length);
void output(int *a, int len_arr);
void shift(int *a, int c, int len);
int input_c(int *n);

int main() {
  int n;
  int A[NMAX];
  int c;
  int flag2 = input(A, &n);

  if (flag2) {
    int flag = input_c(&c);
    if (flag) {
      shift(A, c, n);
      output(A, n);
    } else {
      printf("n/a");
    }
  }
}

int input(int *a, int *n) {
  char c;
  int res1 = scanf("%d%c", n, &c);
  int flag = 1;
  if ((res1 != 2) || (c != '\n')) {
    flag = 0;
  }
  if (*n <= 0 || *n > NMAX) {
    flag = 0;
  }
  if (flag) {
    for (int *p = a; p - a < *n; p++) {
      int res = scanf("%d%c", p, &c);
      if (((res != 2) || (c != ' ')) && p - a != *n - 1) {
        flag = 0;
      } else if (((res != 2) || (c != '\n')) && p - a == *n - 1) {
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

int input_c(int *n) {
  char c;
  int res1 = scanf("%d%c", n, &c);
  int flag = 1;
  if ((res1 != 2) || (c != '\n')) {
    flag = 0;
  }
  if (*n > NMAX) {
    flag = 0;
  }
  return flag;
}

void shift(int *a, int c, int len) {
  int temp[10];
  if (c > 0) {
    for (int i = 0; i < len; i++) {
      temp[i] = a[(i + c) % len];
    }
  } else if (c < 0) {
    int mod = c * (-1);
    for (int i = 0; i < len; i++) {

      temp[i] = a[(i + mod * 9) % len];
    }
  } else if (c == 0) {
    for (int i = 0; i < len; i++) {
      a[i] = temp[i];
    }
  }
  for (int i = 0; i < len; i++) {
    a[i] = temp[i];
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
