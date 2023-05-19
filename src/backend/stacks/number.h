#ifndef SRC_NUMBER_H_
#define SRC_NUMBER_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define FAILTURE 0
#define SUCCSESS 1

typedef struct s_stack_number {
  double item;
  struct s_stack_number* lower;
} number;

int initNum(number** stack, double c);
int pushNum(number** head, double c);
number* popNum(number* head);
void clearNum(number* head);

#endif  // SRC_NUMBER_H_
