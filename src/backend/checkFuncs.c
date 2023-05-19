#include "calc.h"

int checkPriority(char c) {
  int pr = -1;
  if (c == '+' || c == '-' || c == 'm')
    pr = 1;
  else if (c == '*' || c == '/')
    pr = 2;
  else if (c == '^' || c == '|' || c == '~')
    pr = 3;
  else if (c == 'c' || c == 's' || c == 't' || c == 'a' || c == 'l' ||
           c == 'o' || c == 'i' || c == 'n' || c == 'q' || c == 'g')
    pr = 4;

  return pr;
}

int checkAssociativity(char o1, char o2) {
  return (o1 == '+' || o1 == '-' || o1 == '*' || o1 == '/' || isFunc(o1)) &&
         (o2 == '+' || o2 == '-' || o2 == '*' || o2 == '/' || isFunc(o2));
}

int isFunc(char check) {
  int res = 0;
  char funcs[] = "cstal";
  int length = (int)strlen(funcs);
  for (int i = 0; i < length && !res; i++) {
    if (check == funcs[i]) res = 1;
  }

  return res;
}

int isTrig(char check) {
  int res = 0;
  char trig[] = "oitasnqlg";
  int length = (int)strlen(trig);
  for (int i = 0; i < length && !res; i++) {
    if (check == trig[i]) res = 1;
  }

  return res;
}

int isOperator(char check) {
  int res = 0;
  char operators[] = "+-*/^m";
  int length = strlen(operators);
  for (int i = 0; i < length && !res; i++) {
    if (check == operators[i]) res = 1;
  }

  return res;
}
