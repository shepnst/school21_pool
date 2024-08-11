#ifndef STRING_FUNCTIONS_H
#define STRING_FUNCTIONS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isDigit(char c);
int precedence(char operation);
int isFunction(char c);
char *replace(const char *str, const char *sub, const char *replace);
char *replace_all_functions(const char *str);

#endif