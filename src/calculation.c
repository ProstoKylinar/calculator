#include "calculation.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

double from_char_to_double(char *parced_buff, int *i) {
    double result = 0;
    int counter_first = 1;
    int counter_second = 10;
    int tochka_check = 0;
    int check = 0;
    int minus_flag = 0;
    while (parced_buff[*i] != ' ') {
        if (parced_buff[*i] == '~') {
            minus_flag = 1;
        }
        if ((is_number(parced_buff[*i]) == 1) && (parced_buff[*i] != '.') &&
            (tochka_check == 0)) {  //число до точки
            if (check == 0) {
                result += to_double(parced_buff[*i]);
                check += 1;
                counter_first = counter_first * 10;
            } else {
                result = result * counter_first + to_double(parced_buff[*i]);
            }
        } else if (parced_buff[*i] == '.') {
            tochka_check += 1;
        } else if ((is_number(parced_buff[*i]) == 1) && (tochka_check != 0)) {  // дробная часть
            result += to_double(parced_buff[*i]) / counter_second;
            counter_second = counter_second * 10;
        }
        ++(*i);
    }
    if (minus_flag == 1) {
        result *= -1;
    }
    return result;
}

double to_double(char num) {
    double res = num - '0';
    return res;
}

int is_unar(char sign) {
    int result = 0;
    if ((sign == 's') || (sign == 'c') || (sign == 't') || (sign == 'l') || (sign == 'q') || (sign == 'g')) {
        result = 1;
    }
    return result;
}

double unar(double num, char sign) {
    double result;
    if (sign == 's') {
        result = sin(num);
    }
    if (sign == 'c') {
        result = cos(num);
    }
    if (sign == 't') {
        result = tan(num);
    }
    if (sign == 'g') {
        result = 1.0 / (tan(num));
    }
    if (sign == 'l') {
        result = log(num);
    }
    if (sign == 'q') {
        result = sqrt(num);
    }
    return result;
}

double binary(double first, double second, char sign) {
    double result;
    switch (sign) {
        case '+':
            result = first + second;
            break;
        case '-':
            result = first - second;
            break;
        case '*':
            result = first * second;
            break;
        case '/':
            if (second != 0.0)
                result = first / second;
            else
                result = 999;
            break;
    }
    return result;
}

double calculator(char *parced, int len_parced, double x) {
    struct myStack_n *stack = createStack_n();
    for (int i = 0; i < len_parced; ++i) {
        if ((is_number(parced[i]) == 1) || (parced[i] == '~')) {
            if ((parced[i] == '~') && (parced[i + 1] == 'x')) {
                push_n(stack, -1.0 * x);
                i += 1;
            } else if (parced[i] == 'x') {
                push_n(stack, x);
            } else {
                push_n(stack, from_char_to_double(parced, &i));
            }
        }
        if (is_sign(parced[i]) == 1) {
            if (is_unar(parced[i]) == 1) {
                double num = pop_n(stack);
                push_n(stack, unar(num, parced[i]));
            } else {
                double second = pop_n(stack);
                double first = pop_n(stack);
                push_n(stack, binary(first, second, parced[i]));
            }
        }
    }
    double result = pop_n(stack);
    deleteStack_n(&stack);
    return result;
}

void function_values(char *parced, int len_parced, double *results) {
    double x = 0;
    double up = (4.0 * M_PI) / (79.0);
    for (int i = 0; i < 80; i++) {
        results[i] = calculator(parced, len_parced, x);
        if (isnan(results[i]) != 0) {
            results[i] = 999;
        }
        x += up;
    }
}