#include "logic.h"

void infixToPostfix(char* expression, char* output) {
    Stack stack;
    initStack(&stack);
    int j = 0;
    for (int i = 0; expression[i] != '\0'; i++) {
        char c = expression[i];
        if (c == ' ') continue;
        if (isDigit(c)) {
            output[j++] = c;
            if (!isDigit(expression[i + 1]) && expression[i + 1] != '\0') {
                output[j++] = ' ';
            }
        } else if (c == '+' || c == '-' || c == '*' || c == '/' || isFunction(c)) {
            while (!isEmpty(&stack) && precedence(peek(&stack)) >= precedence(c)) {
                output[j++] = pop(&stack);
                output[j++] = ' ';
            }
            push(&stack, c);
        } else if (c == '(') {
            push(&stack, c);
        } else if (c == ')') {
            while (!isEmpty(&stack) && peek(&stack) != '(') {
                output[j++] = pop(&stack);
                output[j++] = ' ';
            }
            pop(&stack);
        }
    }

    while (!isEmpty(&stack)) {
        if (output[j - 1] != ' ') {
            output[j++] = ' ';
        }
        output[j++] = pop(&stack);
        output[j++] = ' ';
    }

    output[j - 1] = '\0';
}

double calculator_of_polish_notation(char* temp, double x) {
    char out[200];
    strcpy(out, temp);
    DoubleStack stack;
    initStack_d(&stack);
    char* dop = strtok(out, " ");
    int flag = 0;
    while (dop != NULL) {
        if (flag == 1) {
            break;
        }
        if (isDigit(dop[0])) {
            double ans;
            if (dop[0] == 'x') {
                ans = x;
            } else {
                ans = strtod(dop, NULL);
            }
            push_d(&stack, ans);
        } else if (isFunction(dop[0])) {
            double a = pop_d(&stack);
            double result;
            if (dop[0] == 'q' && a >= 0) {
                result = sqrt(a);
            } else if (dop[0] == 's') {
                result = sin(a);
            } else if (dop[0] == 'c') {
                result = cos(a);
            } else if (dop[0] == 'l' && a > 0) {
                result = log(a);
            } else if (dop[0] == 't' && cos(a) != 0) {
                result = tan(a);
            } else if (dop[0] == 'g' && sin(a) != 0) {
                result = cos(a) / sin(a);
            } else {
                result = ERROR;
            }
            if (result != ERROR) {
                push_d(&stack, result);
            } else {
                flag = 1;
            }
        } else {
            double b = pop_d(&stack);
            double a = pop_d(&stack);
            double result;
            if (dop[0] == '/') {
                if (b == 0) {
                    flag = 1;
                } else {
                    result = a / b;
                }
            } else {
                switch (dop[0]) {
                    case '+':
                        result = a + b;
                        break;
                    case '-':
                        result = a - b;
                        break;
                    case '*':
                        result = a * b;
                        break;
                    case '/':
                        result = a / b;
                        break;
                    default:
                        flag = 1;
                }
            }
            if (flag != 1) {
                push_d(&stack, result);
            }
        }
        dop = strtok(NULL, " ");
    }
    return (flag == 0) ? pop_d(&stack) : ERROR;
}

void array_of_values(char* expression, double* b) {
    const int size = 80;
    double result[size];
    double step = 4 * M_PI / size;
    double condition = 4 * M_PI + 1e-6;
    for (int i = 0; i < size; i++) {
        result[i] = 0.0;
    }
    int current_index = 0;
    for (double x = 0; x < condition && current_index < size; x += step) {
        double value_x = calculator_of_polish_notation(expression, x);
        result[current_index++] = value_x;
    }
    for (int i = 0; i < current_index; i++) {
        b[i] = result[i];
    }
}
void output(const double* b) {
    char matrix[25][80];
    for (int i = 0; i < 25; i++) {
        for (int j = 0; j < 80; j++) {
            matrix[i][j] = '.';
        }
    }
    for (int i = 0; i < 80; i++) {
        int norm_y = round(((b[i] - Y_MIN) / (Y_MAX - Y_MIN)) * 24);
        if (norm_y >= 0 && norm_y <= 24) {
            matrix[24 - norm_y][i] = '*';
        }
    }
    for (int i = 0; i < 25; i++) {
        for (int j = 0; j < 80; j++) {
            printf("%c", matrix[i][j]);
        }
        if (i != 24) {
            printf("\n");
        }
    }
}

int validateExpression(const char* expression) {
    Stack stack;
    initStack(&stack);
    int valid = 1;

    for (int i = 0; expression[i] != '\0' && valid != 0; i++) {
        char c = expression[i];

        if (c == '(') {
            push(&stack, c);
        } else if (c == ')') {
            if (isEmpty(&stack) || peek(&stack) != '(') {
                valid = 0;
            }
            pop(&stack);
        } else if (!(isDigit(c) || c == '+' || c == '-' || c == '*' || c == '/' || c == ' ' || c == '(' ||
                     c == ')')) {
            if (expression[i] == 's' && expression[i + 1] == 'q' && expression[i + 2] == 'r' &&
                expression[i + 3] == 't') {
                i += 3;
            } else if (expression[i] == 's' && expression[i + 1] == 'i' && expression[i + 2] == 'n') {
                i += 2;
            } else if (expression[i] == 'c' && expression[i + 1] == 'o' && expression[i + 2] == 's') {
                i += 2;
            } else if (expression[i] == 't' && expression[i + 1] == 'a' && expression[i + 2] == 'n') {
                i += 2;
            } else if (expression[i] == 'c' && expression[i + 1] == 't' && expression[i + 2] == 'g') {
                i += 2;
            } else if (expression[i] == 'l' && expression[i + 1] == 'n') {
                i += 1;
            } else {
                valid = 0;
            }
        }
    }
    if (!isEmpty(&stack)) {
        valid = 0;
    }
    return valid;
}