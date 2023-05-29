#ifndef S21_CALC_H
#define S21_CALC_H
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "stacks/number.h"
#include "stacks/operation.h"
#define FAILTURE 0
#define SUCCSESS 1

int calcFunc(number** nums, char op);
int calcOperand(number** nums, char op);
int processRemains(operation** head, char* postfix, int* index);
int processOperator(operation** head, char* postfix, int* index, char add);
int processBracket(operation** head, char* postfix, int* index);
int addDigit(const char* infix, int* i, char* postfix, int* index);
double monthAnnuity(double loan, int period, double rate);
int getPostfix(const char* infix, char* postfix);
int validateFunc(const char* str, int* i, char* res);
int validateOperator(const char* str, int* i, operation* head, char* res,
                     char prev);
int isFunc(char check);
int isTrig(char check);
int isOperator(char check);
int checkPriority(char c);
int checkAssociativity(char o1, char o2);
int calculate(const char* rpn, double x, double* res);
int validateRPN(char* postfix);
char* doPostfix(char* infix);

void printTest(char* str);  // что это?

#endif  // S21_CALC_H
