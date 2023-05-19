#include "calc.h"

int validateOperator(const char *str, int *i, operation *head, char *res,
                     char prev) {
  int result = SUCCSESS;

  if (!strncmp(str + *i, "mod", 3)) {
    *res = 'm';
    (*i) += 2;
  } else if (str[*i] == '+') {
    if (*i == 0 || (head != NULL && (prev == '(')))
      *res = '|';
    else
      *res = '+';
  } else if (str[*i] == '-') {
    if (*i == 0 || (head != NULL && (prev == '(')))
      *res = '~';
    else
      *res = '-';
  } else if (str[*i] == '*') {
    *res = '*';
  } else if (str[*i] == '/') {
    *res = '/';
  } else if (str[*i] == '^') {
    *res = '^';
  } else {
    result = FAILTURE;
  }

  return result;
}
