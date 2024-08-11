#include "string_functions.h"

int isDigit(char c) { return (c >= '0' && c <= '9') || c == '.' || c == 'x'; }

int precedence(char operation) {
    int ans = 0;
    switch (operation) {
        case '+':
        case '-':
            ans = 1;
            break;
        case '*':
        case '/':
            ans = 2;
            break;
        case 'q':
        case 's':
        case 'c':
        case 'g':
        case 't':
        case 'l':
            ans = 3;
            break;
    }
    return ans;
}

int isFunction(char c) { return c == 's' || c == 'q' || c == 'c' || c == 'g' || c == 't' || c == 'l'; }

char *replace(const char *str, const char *sub, const char *replace) {
    if (!str || !sub || !replace) {
        return NULL;
    }
    int flag = 0;
    int count = 0;
    const char *tmp = str;
    while ((tmp = strstr(tmp, sub))) {
        count++;
        tmp += strlen(sub);
    }

    size_t replace_len = strlen(replace);
    size_t sub_len = strlen(sub);
    size_t result_len = strlen(str) + count * (replace_len - sub_len);

    char *result = (char *)malloc(result_len + 1);
    if (!result) {
        flag = 1;
    }
    char *dest = result;
    if (!flag) {
        while (*str) {
            const char *p = strstr(str, sub);
            if (p) {
                size_t len = p - str;
                memcpy(dest, str, len);
                dest += len;
                memcpy(dest, replace, replace_len);
                dest += replace_len;
                str = p + sub_len;
            } else {
                strcpy(dest, str);
                break;
            }
        }
    }
    return result;
}

char *replace_all_functions(const char *str) {
    char *temp = replace(str, "sqrt", "q");
    char *next_temp = replace(temp, "sin", "s");
    free(temp);
    temp = replace(next_temp, "cos", "c");
    free(next_temp);
    next_temp = replace(temp, "ctg", "g");
    free(temp);
    temp = replace(next_temp, "tan", "t");
    free(next_temp);
    next_temp = replace(temp, "ln", "l");
    free(temp);
    return next_temp;
}