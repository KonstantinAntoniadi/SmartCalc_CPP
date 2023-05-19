#include "calc.h"

int validateRPN(char* postfix) {
  int good_expression = SUCCSESS;
  char* str = postfix;
  int size = 0;
  char ch = '\0';
  int value = 0;
  int len = (int)strlen(str);

  for (int i = 0; i < len && good_expression; i++) {
    ch = str[i];
    if (isdigit(ch) || ch == 'x') {
      value = 0;
    } else if (isTrig(ch) || (isFunc(ch) && ch != 'm') || ch == '~' ||
               ch == '|') {
      value = 1;
    } else if (isOperator(ch) || ch == 'm') {
      value = 2;
    }

    size = size + 1 - value;
    if (size <= 0) good_expression = FAILTURE;
    while (i < len && str[i] != ' ') i++;
  }

  good_expression = size == 1;

  return good_expression;
}
