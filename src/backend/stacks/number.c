#include "number.h"

int initNum(number **stack, double c) {
  int result = SUCCSESS;
  number *elem = (number *)malloc(sizeof(number));
  if (elem == NULL) {
    result = FAILTURE;  //  LCOV_EXCL_LINE
  } else {
    elem->item = c;
    elem->lower = NULL;
    *stack = elem;
  }

  return result;
}

int pushNum(number **head, double c) {
  number *elem = NULL;
  int result = initNum(&elem, c);
  if (result) {
    elem->lower = *head;
    *head = elem;
  }
  return result;
}

number *popNum(number *head) {
  number *current = NULL;
  ;
  if (head != NULL) {
    current = head;
    head = head->lower;
    free(current);
  }
  return head;
}

void clearNum(number *head) {
  number *current = NULL;
  while (head != NULL) {
    current = head;
    head = head->lower;
    free(current);
    current = NULL;
  }
}
