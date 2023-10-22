#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "function.h"

int is_number(char num) {
    int res = 0;
    if ((num >= '0' && num <= '9') || num == '.' || num == 'x') {
        res = 1;
    }
    return res;
}

int is_sign(char s) {
    int res = 0;
    if (s == '+' || s == '-' || s == '*' || s == '/') {
        res = 1;
    } else if (s == '(' || s == ')') {
        res = 1;
    } else if (s == 's' || s == 'c' || s == 't' || s == 'g' || s == 'q' || s == 'l') {
        res = 1;
    }
    return res;
}

int parcing(char* buff, char* parced_buff, int length) {
    int parced_counter = 0;
    struct myStack* stack = createStack();
    for (int i = 0; i < length; i++) {
        if (is_number(buff[i])) {
            int j = i;
            int count = 0;
            while (is_number(buff[j])) {
                parced_buff[parced_counter] = buff[j];
                count += 1;
                parced_counter += 1;
                j += 1;
            }
            parced_buff[parced_counter] = ' ';
            parced_counter += 1;
            i += count - 1;
        } else if (buff[i] == '-') {
            if (i == 0 || ((is_number(buff[i - 1]) != 1) && buff[i - 1] != ')')) {
                parced_buff[parced_counter] = '~';
                parced_counter += 1;
            } else {
                parced_counter = add_sign(parced_buff, stack, buff[i], parced_counter);
            }
        } else if (is_sign(buff[i]) == 1) {
            parced_counter = add_sign(parced_buff, stack, buff[i], parced_counter);
        }
    }
    while (stack->top > 0) {
        parced_buff[parced_counter] = pop(stack);
        if (stack->top != 0) {
            parced_buff[parced_counter + 1] = ' ';
            parced_counter += 1;
        }
        parced_counter++;
    }
    deleteStack(&stack);
    return parced_counter;
}

int add_sign(char* parced_buff, struct myStack* stack, char sign, int counter) {
    if (stack->top == 0) {
        push(stack, sign);
    } else {
        if (sign_priority(sign) == 2) {
            push(stack, sign);
        } else if (sign == '(') {
            push(stack, sign);
        } else if (sign == ')') {
            while ((peek(stack) != '(') && (stack->top != 0)) {
                parced_buff[counter] = pop(stack);
                parced_buff[counter + 1] = ' ';
                counter += 2;
            }
            pop(stack);
        } else {
            while ((sign_priority(sign) <= sign_priority(peek(stack))) && (stack->top != 0)) {
                parced_buff[counter] = pop(stack);
                parced_buff[counter + 1] = ' ';
                counter += 2;
            }
            push(stack, sign);
        }
    }
    return counter;
}

int sign_priority(char sign) {
    int res = 0;
    if (sign == '+' || sign == '-') {
        res = 0;
    }
    if (sign == '*' || sign == '/') {
        res = 1;
    }
    if (sign == 's' || sign == 'c' || sign == 't' || sign == 'g' || sign == 'q' || sign == 'l') {
        res = 2;
    }
    if (sign == '(' || sign == ')') {
        res = -1;
    }
    return res;
}

int input(char* buff) {
    int res = 0;
    char read = ' ';
    int length = 0;
    while (res == 0) {
        if (scanf("%c", &read) != 1) {
            res = -1;
        }
        if (read == '\n') {
            res = 1;
        }
        if ((res == 0) && (read != ' ')) {
            buff[length] = read;
            ++length;
        }
    }
    if (res != -1) {
        res = length;
    }
    return res;
}

void matrix_equality(char* buff, const char* co_buff, int len) {
    for (int i = 0; i < len; i++) {
        buff[i] = co_buff[i];
    }
}

void sub_correct(int* j, int* len, int* i) {
    ++*j;
    *len += 1;
    *i += 2;
}

int correct_buff(char* buff, int* length) {
    char correct_buff[100000];
    int j = 0, len = 0, bracket_counter = 0, result = 0;
    for (int i = 0; i < *length; ++i) {
        if ((buff[i] == 's') && (buff[i + 1] == 'i') && (buff[i + 2] == 'n')) {
            correct_buff[j] = 's';
            sub_correct(&j, &len, &i);
        } else if ((buff[i] == 'c') && (buff[i + 1] == 'o') && (buff[i + 2] == 's')) {
            correct_buff[j] = 'c';
            sub_correct(&j, &len, &i);
        } else if ((buff[i] == 't') && (buff[i + 1] == 'a') && (buff[i + 2] == 'n')) {
            correct_buff[j] = 't';
            sub_correct(&j, &len, &i);
        } else if ((buff[i] == 'c') && (buff[i + 1] == 't') && (buff[i + 2] == 'g')) {
            correct_buff[j] = 'g';
            sub_correct(&j, &len, &i);
        } else if ((buff[i] == 'l') && (buff[i + 1] == 'n')) {
            correct_buff[j] = 'l';
            ++j;
            len += 1;
            i += 1;
        } else if ((buff[i] == 's') && (buff[i + 1] == 'q') && (buff[i + 3] == 't')) {
            correct_buff[j] = 'q';
            ++j;
            len += 1;
            i += 3;
        } else if ((is_sign(buff[i]) == 1) || (is_number(buff[i]) == 1)) {
            correct_buff[j] = buff[i];
            ++j;
            len += 1;
        } else {
            result = -1;
        }
        if (buff[i] == '(') {
            bracket_counter += 1;
        }
        if (buff[i] == ')') {
            bracket_counter -= 1;
        }
    }
    *length = len;
    matrix_equality(buff, correct_buff, *length);
    if (bracket_counter != 0) {
        result = -1;
    }
    return result;
}