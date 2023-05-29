#ifndef SRC_STACK_H_
#define SRC_STACK_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FAILTURE 0
#define SUCCSESS 1

typedef struct s_stack_operation {
  char item;
  struct s_stack_operation* lower;
} operation;

int initOp(operation** head, char c);
int pushOp(operation** head, char c);
operation* popOp(operation* head);
void clearOp(operation* head);

#endif  // SRC_STACK_H_
