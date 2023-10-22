#include "stack_n.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

myStack_n *createStack_n() {
    myStack_n *out = NULL;
    out = malloc(sizeof(myStack_n));
    if (out == NULL) {
        exit(OUT_OF_MEMORY);
    }
    out->size = INIT_SIZE;
    out->data = malloc(out->size * sizeof(double));
    if (out->data == NULL) {
        free(out);
        exit(OUT_OF_MEMORY);
    }
    out->top = 0;
    return out;
}

void deleteStack_n(myStack_n **stack) {
    free((*stack)->data);
    free(*stack);
    *stack = NULL;
}

void resize_n(myStack_n *stack) {
    stack->size *= MULTIPLIER;
    stack->data = realloc(stack->data, stack->size * sizeof(double));
    if (stack->data == NULL) {
        exit(STACK_OVERFLOW);
    }
}

void push_n(myStack_n *stack, double value) {
    if (stack->top >= stack->size) {
        resize_n(stack);
    }
    stack->data[stack->top] = value;
    stack->top++;
}

double pop_n(myStack_n *stack) {
    if (stack->top == 0) {
        exit(STACK_UNDERFLOW);
    }
    stack->top--;
    return stack->data[stack->top];
}
