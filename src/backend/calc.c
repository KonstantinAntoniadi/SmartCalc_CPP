#include "calc.h"

int calculate(const char* rpn, double x, double* res) {
  int result = SUCCSESS;

  *res = 0;
  double tmp = 0;
  int rpn_len = (int)strlen(rpn);
  number* nums = NULL;
  char* endptr = NULL;

  for (int i = 0; i < rpn_len && result; i++) {
    char op = rpn[i];
    if (isdigit(op)) {
      tmp = strtod(rpn + i, &endptr);
      i = endptr - rpn;
      result = pushNum(&nums, tmp);
    } else if (op == 'x') {
      result = pushNum(&nums, x);
    } else if (op == '~') {
      nums->item = -1 * nums->item;
    } else if (isOperator(op) || op == 'm') {
      result = calcOperand(&nums, op);
    } else if (isTrig(op)) {
      result = calcFunc(&nums, op);
    }
  }

  *res = nums->item;
  clearNum(nums);

  return result;
}

int calcFunc(number** nums, char op) {
  int result = SUCCSESS;
  double a = 0;
  a = (*nums)->item;
  *nums = popNum(*nums);
  if (op == 'o') {
    result = pushNum(nums, cos(a));
  } else if (op == 'i') {
    result = pushNum(nums, sin(a));
  } else if (op == 't') {
    result = pushNum(nums, tan(a));
  } else if (op == 'a') {
    result = pushNum(nums, acos(a));
  } else if (op == 's') {
    result = pushNum(nums, asin(a));
  } else if (op == 'n') {
    result = pushNum(nums, atan(a));
  } else if (op == 'q') {
    result = pushNum(nums, sqrt(a));
  } else if (op == 'l') {
    result = pushNum(nums, log(a));
  } else if (op == 'g') {
    result = pushNum(nums, log10(a));
  }

  return result;
}

int calcOperand(number** nums, char op) {
  int result = SUCCSESS;
  double a = 0;
  double b = 0;
  b = (*nums)->item;
  *nums = popNum(*nums);
  a = (*nums)->item;
  *nums = popNum(*nums);
  if (op == '+') {
    result = pushNum(nums, a + b);
  } else if (op == '-') {
    result = pushNum(nums, a - b);
  } else if (op == '*') {
    result = pushNum(nums, a * b);
  } else if (op == '/') {
    result = pushNum(nums, a / b);
  } else if (op == '^') {
    result = pushNum(nums, pow(a, b));
  } else if (op == 'm') {
    result = pushNum(nums, fmod(a, b));
  }

  return result;
}
