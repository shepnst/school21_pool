#include "s21_string.h"

#include <stdio.h>
#include <stdlib.h>

int s21_strlen(char *str) {
    int len = 0;
    while (str[len] != '\0') {
        len++;
    }
    return len;
}

int s21_strcmp(char *str1, char *str2) {
    int status_equal = 0;
    int i = 0;
    while ((str1[i] != '\0' && str2[i] != '\0')) {
        if (str1[i] < str2[i]) {
            status_equal = (int)str1[i] - (int)str2[i];
        } else if (str1[i] > str2[i]) {
            status_equal = (int)str1[i] - (int)str2[i];
        }
        i++;
    }
    if (str1[i] == '\0' && str2[i] != '\0' && status_equal == 0) {
        status_equal = -1;
    }
    if (str1[i] != '\0' && str2[i] == '\0' && status_equal == 0) {
        status_equal = 1;
    }
    return status_equal;
}

void s21_strcpy(char *str1, char *str2, int n) {
    int i = 0;
    while (str2[i] != '\0' && i < n) {
        str1[i] = str2[i];
        i++;
    }
    str1[i] = '\0';
}

char *s21_strcat(char *str, char *str2) {
    int len = s21_strlen(str);

    for (int i = 0; str[i] != '\0'; i++) {
        str[len + i] = str2[i];
    }

    str[len + s21_strlen(str2)] = '\0';

    return str;
}