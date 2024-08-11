#include "double_stack.h"

void initStack_d(DoubleStack* s) { s->top = -1; }

int isFull_d(DoubleStack* s) { return s->top == MAX - 1; }

int isEmpty_d(DoubleStack* s) { return s->top == -1; }

void push_d(DoubleStack* s, double item) {
    if (!isFull_d(s)) {
        s->items[++s->top] = item;
    }
}

double pop_d(DoubleStack* s) {
    double ans = 0.0f;
    if (!isEmpty_d(s)) {
        ans = s->items[s->top--];
    }
    return ans;
}