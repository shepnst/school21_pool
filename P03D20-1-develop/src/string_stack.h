#ifndef STRING_STACK_H
#define STRING_STACK_H

#define MAX 100

typedef struct Stack {
    int top;
    char items[MAX];
} Stack;

void initStack(Stack* s);
int isFull(Stack* s);
int isEmpty(Stack* s);
void push(Stack* s, char item);
char pop(Stack* s);
char peek(Stack* s);

#endif