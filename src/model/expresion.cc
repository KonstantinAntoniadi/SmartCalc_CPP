#include "expression.h"

namespace s21 {
double Expression::Calculate(double x) {
  GetPostfix();
  // std::cout <<
}

bool Expression::ValidateFunc() {
  bool result = true;
    if (!strncmp(&cur_it_[0], "cos", 3)) {
    lexemes_.emplace_back(COS);
    cur_it_ += 2;
  } else if (!strncmp(&cur_it_[0], "sin", 3)) {
    lexemes_.emplace_back(SIN);
    cur_it_ += 2;
  } else if (!strncmp(&cur_it_[0], "tan", 3)) {
    lexemes_.emplace_back(TAN);
    cur_it_ += 2;
  } else if (!strncmp(&cur_it_[0], "acos", 4)) {
    lexemes_.emplace_back(ACOS);
    cur_it_ += 3;
  } else if (!strncmp(&cur_it_[0], "asin", 4)) {
    lexemes_.emplace_back(ASIN);
    cur_it_ += 3;
  } else if (!strncmp(&cur_it_[0], "atan", 4)) {
    lexemes_.emplace_back(ATAN);
    cur_it_ += 3;
  } else if (!strncmp(&cur_it_[0], "sqrt", 4)) {
    lexemes_.emplace_back(SQRT);
    cur_it_ += 3;
  } else if (!strncmp(&cur_it_[0], "ln", 2)) {
    lexemes_.emplace_back(LN);
    cur_it_ += 1;
  } else if (!strncmp(&cur_it_[0], "log", 3)) {
    lexemes_.emplace_back(LOG);
    cur_it_ += 2;
  } else {
    result = false;
  }

  return result;
}

bool Expression::IsOperator(const char check) { // НЕ ООП
  std::string operators = "+-*/^m";
  return (operators.find(check) != std::string::npos);
}

bool Expression::ValidateOperator() {
  bool result = true;

  if (*cur_it_ == '+') {
    lexemes_.emplace_back(PLUS);
  } else if (*cur_it_ == '-') {
    lexemes_.emplace_back(MINUS);
  } else if (*cur_it_ == '*') {
    lexemes_.emplace_back(MUL);
  } else if (*cur_it_ == '/') {
    lexemes_.emplace_back(DIV);
  } else if (*cur_it_ == '^') {
    lexemes_.emplace_back(EXP);
  } 
  else if (!strncmp(&cur_it_[0], "mod", 3)) {
    lexemes_.emplace_back(MOD);
    cur_it_ += 2;
  } else {
    result = false;
  }

  return result;
}

void Expression::ConvertToLexemes() {
  for (cur_it_ = infix_.begin(); cur_it_ != infix_.end() && good_to_go_; cur_it_++) {
    char cur = *cur_it_;
    if (cur == 'x') {
      lexemes_.emplace_back(NUMBER, x_);
    } else if (cur == '(') {
      lexemes_.emplace_back(OPENBRACKET);
    } else if (cur == ')') {
      lexemes_.emplace_back(CLOSEBRACKET);
    } else if (IsFunc(cur)) {
      good_to_go_ = ValidateFunc();
    } else if (IsOperator(cur)) {

    }
  }
}

void Expression::GetPostfix() {

}

bool Expression::IsFunc(const char check) { // НЕ ООП
  // перепиши и используй итератор
  std::string funcs = "cstal";
  return (funcs.find(check) != std::string::npos);
}

bool Expression::IsValidFunc() {
  

  return true;
}

};  // namespace s21