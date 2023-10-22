#ifndef FUNCTION_H
#define FUNCTION_H
#include "stack_c.h"

int is_number(char num);
int is_sign(char s);
int parcing(char* buff, char* parced_buff, int length);
int add_sign(char* parced_buff, struct myStack* stack, char sign, int counter);
int sign_priority(char sign);
void matrix_equality(char* buff, const char* co_buff, int len);
int correct_buff(char* buff, int* length);
int input(char* buff);
void sub_correct(int* j, int* len, int* i);

#endif