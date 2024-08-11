#include "s21_string.h"

#include <stdio.h>
#include <stdlib.h>
int compare(char *str1, char *str2) {
    int i = 0;
    while (str1[i] != '\0' || str2[i] != '\0') {
        i++;
    }
    if (str1[i] == '\0' && str2[i] == '\0') {
        return 1;
    }
    return 0;
}
void s21_strcat_test_result(char *source, char *dest) {
    if (compare(source, dest)) {
        printf("SUCCESS\n");
    } else {
        printf("FAIL\n");
    }
}
void s21_strlen_test() {
    if (s21_strlen("hello world") == 11) {
        printf("hello world ");
        printf("%d ", s21_strlen("hello world"));
        printf("SUCCESS\n");
    } else {
        printf("hello world ");
        printf("%d ", s21_strlen("hello world"));
        printf("FAIL\n");
    }
    if (s21_strlen("\n") == 1) {
        printf("\\n ");
        printf("%d ", s21_strlen("\n"));
        printf("SUCCESS\n");
    } else {
        printf("\\n ");
        printf("%d ", s21_strlen("\n"));
        printf("FAIL\n");
    }
    if (s21_strlen("\0") == 0) {
        printf("\\0 ");
        printf("%d ", s21_strlen("\0"));
        printf("SUCCESS\n");
    } else {
        printf("\\0 ");
        printf("%d ", s21_strlen("\0"));
        printf("FAIL\n");
    }
    if (s21_strlen("") == 0) {
        printf("\"\" ");
        printf("%d ", s21_strlen(""));
        printf("SUCCESS\n");
    } else {
        printf("\"\"");
        printf("%d ", s21_strlen(""));
        printf("FAIL\n");
    }
}

void s21_strcmp_test() {
    if (s21_strcmp("a", "c") == -2) {
        printf("a c ");
        printf("%d ", s21_strcmp("a", "c"));
        printf("SUCCESS\n");
    } else {
        printf("a c ");
        printf("%d ", s21_strcmp("a", "c"));
        printf("FAIL\n");
    }
    if (s21_strcmp("abc", "abc") == 0) {
        printf("abc abc ");
        printf("%d ", s21_strcmp("abc", "abc"));
        printf("SUCCESS\n");
    } else {
        printf("abc abc ");
        printf("%d ", s21_strcmp("abc", "abc"));
        printf("FAIL\n");
    }
    if (s21_strcmp("abc", "bcd") == -1) {
        printf("abc bcd ");
        printf("%d ", s21_strcmp("abc", "bcd"));
        printf("SUCCESS\n");
    } else {
        printf("abc bcd ");
        printf("%d", s21_strcmp("abc", "bcd"));
        printf("FAIL\n");
    }
    if (s21_strcmp("hello", "aiiii") == 6) {
        printf("hello aiiii ");
        printf("%d ", s21_strcmp("hello", "aiiii"));
        printf("SUCCESS\n");
    } else {
        printf("hello aiiii ");
        printf("%d ", s21_strcmp("hello", "aiiii"));
        printf("FAIL\n");
    }
    if (s21_strcmp(" ", "\t") == 6) {
        printf(" \\t ");
        printf("%d ", s21_strcmp(" ", "\t"));
        printf("SUCCESS\n");
    } else {
        printf(" \\t  ");
        printf("%d ", s21_strcmp(" ", "\t"));
        printf("FAIL\n");
    }
}

void s21_strcpy_test() {
    char str1[4] = "abcd";
    char str2[4] = "abc";
    s21_strcpy(str1, str2, 3);
    if (s21_strcmp(str1, str2) == 0) {
        printf("abcd abc ");
        printf("SUCCESS\n");
    } else {
        printf("abcd abc ");
        printf("FAIL\n");
    }
    char str3[6] = "hello";
    char str4[3] = "ai";
    s21_strcpy(str3, str4, 3);
    if (s21_strcmp(str2, str1) == 0) {
        printf("hello ai ");
        printf("SUCCESS\n");
    } else {
        printf("hello ai ");
        printf("FAIL\n");
    }
    char str5[2] = " ";
    char str6[3] = "ok";
    s21_strcpy(str5, str6, 3);
    if (s21_strcmp(str5, str6) == 0) {
        printf(" ok ");
        printf("SUCCESS\n");
    } else {
        printf(" ok ");
        printf("FAIL\n");
    }
}

void s21_strcat_test() {
    char source1[100] = "abcd";
    char source1_copy[100];
    s21_strcpy(source1_copy, source1, 4);
    char dest1[100] = "efgh";
    char ans1[100] = "abcdefgh";
    char *res1 = s21_strcat(source1, dest1);

    char source2[100] = " ";
    char source2_copy[100];
    s21_strcpy(source2_copy, source2, 1);
    char dest2[100] = " ";
    char ans2[100] = "  ";
    char *res2 = s21_strcat(source2, dest2);

    char source3[100] = "\t";
    char source3_copy[100];
    s21_strcpy(source3_copy, source3, 1);
    char dest3[100] = "\t";
    char ans3[100] = "\t\t";
    char *res3 = s21_strcat(source3, dest3);

    printf("%s %s %s ", source1_copy, dest1, res1);
    s21_strcat_test_result(res1, ans1);

    printf("%s %s %s ", source2_copy, dest2, res2);
    s21_strcat_test_result(res2, ans2);

    printf("%s %s %s ", source3_copy, dest3, res3);
    s21_strcat_test_result(res3, ans3);
}
int main() {
#ifdef S21_STRLEN_TEST
    s21_strlen_test();
#elif S21_STRCMP_TEST
    s21_strcmp_test();
#elif S21_STRCPY_TEST
    s21_strcpy_test();
#elif S21_STRCAT_TEST
    s21_strcat_test();
#endif
    return 0;
}