#include "calc.h"

int validateFunc(const char *str, int *i, char *res) {
  int result = SUCCSESS;

  if (!strncmp(str + *i, "cos", 3)) {
    *res = 'o';
    (*i) += 2;
  } else if (!strncmp(str + *i, "sin", 3)) {
    *res = 'i';
    (*i) += 2;
  } else if (!strncmp(str + *i, "tan", 3)) {
    *res = 't';
    (*i) += 2;
  } else if (!strncmp(str + *i, "acos", 4)) {
    *res = 'a';
    (*i) += 3;
  } else if (!strncmp(str + *i, "asin", 4)) {
    *res = 's';
    (*i) += 3;
  } else if (!strncmp(str + *i, "atan", 4)) {
    *res = 'n';
    (*i) += 3;
  } else if (!strncmp(str + *i, "sqrt", 4)) {
    *res = 'q';
    (*i) += 3;
  } else if (!strncmp(str + *i, "ln", 2)) {
    *res = 'l';
    (*i) += 1;
  } else if (!strncmp(str + *i, "log", 3)) {
    *res = 'g';
    (*i) += 2;
  } else {
    result = FAILTURE;
  }

  return result;
}
