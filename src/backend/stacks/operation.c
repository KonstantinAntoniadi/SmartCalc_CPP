#include "operation.h"

int initOp(operation **stack, char c) {
  int result = SUCCSESS;
  operation *elem = (operation *)malloc(sizeof(operation));
  if (elem == NULL) {
    result = FAILTURE;  // LCOV_EXCL_LINE
  } else {
    elem->item = c;
    elem->lower = NULL;
    *stack = elem;
  }

  return result;
}

int pushOp(operation **head, char c) {
  int result = SUCCSESS;
  operation *elem = NULL;
  result = initOp(&elem, c);
  if (result) {
    elem->lower = *head;
    *head = elem;
  }

  return result;
}

operation *popOp(operation *head) {
  operation *current = NULL;
  if (head != NULL) {
    current = head;
    head = head->lower;
    free(current);
    current = NULL;
  }
  return head;
}

void clearOp(operation *head) {
  operation *current = NULL;
  while (head != NULL) {
    current = head;
    head = head->lower;
    free(current);
    current = NULL;
  }
}