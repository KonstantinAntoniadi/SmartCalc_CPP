#include "calc.h"

int processRemains(operation** head, char* postfix, int* index) {
  int good_to_go = 1;
  while ((*head) != NULL && good_to_go) {
    if ((*head)->item == '(' || (*head)->item == ')') {
      clearOp(*head);
      good_to_go = 0;
    }
    if (good_to_go) {
      postfix[(*index)++] = (*head)->item;
      postfix[(*index)++] = ' ';
      *head = popOp(*head);
    }
  }
  return good_to_go;
}

int processOperator(operation** head, char* postfix, int* index, char add) {
  int prHead = 0;
  if ((*head) != NULL) prHead = checkPriority((*head)->item);
  int prC = checkPriority(add);
  while ((*head) != NULL &&
         (prHead > prC ||
          (prHead == prC && checkAssociativity(add, (*head)->item)))) {
    postfix[(*index)++] = (*head)->item;
    postfix[(*index)++] = ' ';
    *head = popOp(*head);
    if ((*head) != NULL) prHead = checkPriority((*head)->item);
  }
  int good_to_go = pushOp(head, add);

  return good_to_go;
}

int processBracket(operation** head, char* postfix, int* index) {
  int good_to_go = 1;
  if (*head != NULL) {
    while (*head != NULL && (*head)->item != '(') {
      postfix[(*index)++] = (*head)->item;
      postfix[(*index)++] = ' ';
      *head = popOp(*head);
    }
    *head = popOp(*head);
  } else {
    good_to_go = 0;  // LCOV_EXCL_LINE
  }

  return good_to_go;
}

int addDigit(const char* infix, int* i, char* postfix, int* index) {
  int good_to_go = 1;
  int dot_count = 0;
  while (good_to_go && (isdigit(infix[*i]) || infix[*i] == '.')) {
    if (infix[*i] == '.') dot_count++;
    if (dot_count <= 1) {
      postfix[(*index)++] = infix[*i];
      (*i)++;
    } else {
      good_to_go = 0;
    }
  }
  (*i)--;
  postfix[(*index)++] = ' ';
  return good_to_go;
}
