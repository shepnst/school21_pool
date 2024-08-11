#include "string_stack.h"

void initStack(Stack* s) { s->top = -1; }

int isFull(Stack* s) { return s->top == MAX - 1; }
int isEmpty(Stack* s) { return s->top == -1; }

void push(Stack* s, char item) {
    if (!isFull(s)) {
        s->items[++s->top] = item;
    }
}

char pop(Stack* s) {
    char item = '\0';
    if (!isEmpty(s)) {
        item = s->items[s->top--];
    }
    return item;
}
char peek(Stack* s) {
    char item = '\0';
    if (!isEmpty(s)) {
        item = s->items[s->top];
    }
    return item;
}
