#include "calc.h"

int getPostfix(const char *infix, char *postfix) {
  int good_to_go = 1;
  int index = 0;
  int infix_len = (int)strlen(infix);
  char in = {0};
  char add = {0};
  operation *head = NULL;
  char prev = {0};

  for (int i = 0; i < infix_len && good_to_go; i++) {
    in = infix[i];
    if (in == 'x') {
      postfix[index++] = in;
      postfix[index++] = ' ';
    } else if (in == '(') {
      good_to_go = pushOp(&head, in);
    } else if (isFunc(in)) {
      good_to_go = validateFunc(infix, &i, &add);
      if (good_to_go) good_to_go = pushOp(&head, add);
    } else if (isOperator(in)) {
      good_to_go = validateOperator(infix, &i, head, &add, prev);
      if (good_to_go) good_to_go = processOperator(&head, postfix, &index, add);
    } else if (in == ')') {
      good_to_go = processBracket(&head, postfix, &index);
    } else if (isdigit(in)) {
      good_to_go = addDigit(infix, &i, postfix, &index);
    } else if (in != ' ') {
      good_to_go = 0;
    }

    prev = in;
  }
  if (good_to_go) good_to_go = processRemains(&head, postfix, &index);
  if (good_to_go) good_to_go = validateRPN(postfix);

  return good_to_go;
}
