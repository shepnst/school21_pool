
#ifndef S21_STRING_H
#define S21_STRING_H

int s21_strlen(char *str);
int s21_strcmp(char *str1, char *str2);
void s21_strlen_test();
void s21_strcmp_test();
void s21_strcpy(char *str1, char *str2, int n);
void s21_strcpy_test();
char *s21_strcat(char *str, char *str2);
void s21_strcat_test();
void s21_strcat_test_result(char *res1, char *ans1);
int compare(char *str1, char *str2);
#endif
