#ifndef MAX
#define MAX 100
#endif

#ifndef LOGIC_h
#define LOGIC_H

#include <math.h>

#include "double_stack.h"
#include "string_functions.h"
#include "string_stack.h"
#define ERROR -99999
#define X_MIN 0
#define Y_MAX 1
#define Y_MIN -1

void infixToPostfix(char *expression, char *output);
double calculator_of_polish_notation(char *output, double x);
int validateExpression(const char *expression);
void array_of_values(char *expression, double *b);
void output(const double *b);

#endif