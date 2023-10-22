#ifndef CALCULATION_H
#define CALCULATION_H

#include "function.h"
#include "stack_n.h"

double from_char_to_double(char *parced_buff, int *i);
double to_double(char num);
int is_unar(char sign);
double unar(double num, char sign);
double binary(double first, double second, char sign);
double calculator(char *parced, int len_parced, double x);
void function_values(char *parced, int len_parced, double *results);

#endif