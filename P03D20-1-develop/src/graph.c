#include "logic.h"

int main() {
    char expression[MAX];
    printf("Введите выражение: ");
    fgets(expression, sizeof(expression), stdin);
    size_t len = strlen(expression);
    if (len > 0 && expression[len - 1] == '\n') {
        expression[len - 1] = '\0';
    }
    if (validateExpression(expression) != 0) {
        char out[2 * MAX];
        char *temp = replace_all_functions(expression);
        strcpy(expression, temp);
        free(temp);
        infixToPostfix(expression, out);
        double *b = malloc(81 * sizeof(double));
        array_of_values(out, b);
        output(b);
        free(b);
    } else {
        printf("n/a");
    }
    return 0;
}
