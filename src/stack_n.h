#ifndef STACK_N_H
#define STACK_N_H

#define INIT_SIZE 10
#define MULTIPLIER 2
#define STACK_OVERFLOW -100
#define STACK_UNDERFLOW -101
#define OUT_OF_MEMORY -102

typedef struct myStack_n {
    double *data;
    int size;
    int top;
} myStack_n;

myStack_n *createStack_n();
void deleteStack_n(myStack_n **stack);
void resize_n(myStack_n *stack);
void push_n(myStack_n *stack, double value);
double pop_n(myStack_n *stack);

#endif