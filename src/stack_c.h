#ifndef STACK_C_H
#define STACK_C_H

#define INIT_SIZE 10
#define MULTIPLIER 2
#define STACK_OVERFLOW -100
#define STACK_UNDERFLOW -101
#define OUT_OF_MEMORY -102

typedef struct myStack {
    char *data;
    int size;
    int top;
} myStack;

myStack *createStack();
void deleteStack(myStack **stack);
void resize(myStack *stack);
void push(myStack *stack, char value);
char pop(myStack *stack);
char peek(const myStack *stack);

#endif