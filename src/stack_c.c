#include "stack_c.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

myStack *createStack() {
    myStack *out = NULL;
    out = malloc(sizeof(myStack));
    if (out == NULL) {
        exit(OUT_OF_MEMORY);
    }
    out->size = INIT_SIZE;
    out->data = malloc(out->size * sizeof(char));
    if (out->data == NULL) {
        free(out);
        exit(OUT_OF_MEMORY);
    }
    out->top = 0;
    return out;
}

void deleteStack(myStack **stack) {
    free((*stack)->data);
    free(*stack);
    *stack = NULL;
}

void resize(myStack *stack) {
    stack->size *= MULTIPLIER;
    stack->data = realloc(stack->data, stack->size * sizeof(char));
    if (stack->data == NULL) {
        exit(STACK_OVERFLOW);
    }
}

void push(myStack *stack, char value) {
    if (stack->top >= stack->size) {
        printf("%c ", value);
        resize(stack);
    }
    stack->data[stack->top] = value;
    stack->top++;
}

char pop(myStack *stack) {
    if (stack->top == 0) {
        exit(STACK_UNDERFLOW);
    }
    stack->top--;
    return stack->data[stack->top];
}

char peek(const myStack *stack) {
    if (stack->top <= 0) {
        exit(STACK_UNDERFLOW);
    }
    return stack->data[stack->top - 1];
}
