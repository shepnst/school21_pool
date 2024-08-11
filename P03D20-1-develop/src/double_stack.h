#ifndef DOUBLE_STACK_H
#define DOUBLE_STACK_H
#define MAX 100
#include <stdio.h>

typedef struct {
    double items[MAX];
    int top;
} DoubleStack;

void initStack_d(DoubleStack* s);
int isFull_d(DoubleStack* s);
int isEmpty_d(DoubleStack* s);
void push_d(DoubleStack* s, double item);
double pop_d(DoubleStack* s);

#endif