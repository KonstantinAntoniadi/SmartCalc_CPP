#include "expression.h"

namespace s21 {
double Expression::Calculate(const double x) {
  x_ = x;
  // std::cout <<
  double res = 0;
  if (good_to_go_) {
    for (auto it = postfix_.begin(); it != postfix_.end(); it++) {
      Operation cur_op = it->GetOperation();
      if (cur_op == NUMBER) {
        calculate_.push(it->GetValue());
      } else if (cur_op == X) {
        calculate_.push(x_);
      } else if (cur_op == UNARMINUS) {
        calculate_.top() *= -1;
      } else if (cur_op == PLUS || cur_op == MINUS || cur_op == MUL ||
                 cur_op == DIV || cur_op == EXP || cur_op == MOD) {
        calculate_.push(alcOperand(cur_op));
      } else if (cur_op == COS || cur_op == SIN || cur_op == TAN ||
                 cur_op == ACOS || cur_op == ASIN || cur_op == ATAN ||
                 cur_op == SQRT || cur_op == LN || cur_op == LOG) {
        calculate_.push(CalcFunc(cur_op));
      }
    }
    res = calculate_.top();
  }

  // while (!calculate_.empty()) {
  //   calculate_.pop();
  // }
  return res;
}

double Expression::CalcFunc(Operation op) {
  double value = calculate_.top();
  calculate_.pop();

  double res = 0;
  if (op == COS) {
    res = std::cos(value);
  } else if (op == SIN) {
    res = std::sin(value);
  } else if (op == TAN) {
    res = std::tan(value);
  } else if (op == ACOS) {
    res = std::acos(value);
  } else if (op == ASIN) {
    res = std::asin(value);
  } else if (op == ATAN) {
    res = std::atan(value);
  } else if (op == SQRT) {
    res = std::sqrt(value);
  } else if (op == LN) {
    res = std::log(value);
  } else if (op == LOG) {
    res = std::log10(value);
  }

  return res;
}

double Expression::CalcOperand(Operation op) {
  double b = calculate_.top();
  calculate_.pop();
  double a = calculate_.top();
  calculate_.pop();

  double res = 0;

  if (op == PLUS) {
    res = a + b;
  } else if (op == MINUS) {
    res = a - b;
  } else if (op == MUL) {
    res = a * b;
  } else if (op == DIV) {
    res = a / b;
  } else if (op == EXP) {
    res = std::pow(a, b);
  } else if (op == MOD) {
    res = std::fmod(a, b);
  }

  return res;
}

bool Expression::ValidateFunc() {
  bool res = true;
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
    res = false;
  }

  return res;
}

bool Expression::IsOperator(const char check) {  // НЕ ООП
  std::string operators = "+-*/^m";
  return (operators.find(check) != std::string::npos);
}

bool Expression::ValidateOperator() {
  bool res = true;

  if (*cur_it_ == '+') {
    if (!lexemes_.empty() &&
        !lexemes_.at(lexemes_.size() - 1).GetOperation() == OPENBRACKET) {
      lexemes_.emplace_back(PLUS);
    }
  } else if (*cur_it_ == '-') {
    if (lexemes_.empty() ||
        lexemes_.at(lexemes_.size() - 1).GetOperation() == OPENBRACKET) {
      lexemes_.emplace_back(
          UNARMINUS);  // может стоит вынести это в польскую нотацию
    } else {
      lexemes_.emplace_back(MINUS);
    }
  } else if (*cur_it_ == '*') {
    lexemes_.emplace_back(MUL);
  } else if (*cur_it_ == '/') {
    lexemes_.emplace_back(DIV);
  } else if (*cur_it_ == '^') {
    lexemes_.emplace_back(EXP);
  } else if (!strncmp(&cur_it_[0], "mod", 3)) {
    lexemes_.emplace_back(MOD);
    cur_it_ += 2;
  } else {
    res = false;
  }

  return res;
}

void Expression::ConvertToLexemes() {
  for (cur_it_ = infix_.begin(); cur_it_ != infix_.end() && good_to_go_;
       cur_it_++) {
    char cur = *cur_it_;

    if (cur == 'x') {
      lexemes_.emplace_back(X, x_);
    } else if (cur == '(') {
      lexemes_.emplace_back(OPENBRACKET);
    } else if (cur == ')') {
      lexemes_.emplace_back(CLOSEBRACKET);
    } else if (IsFunc(cur)) {  // можно попробовать объединить с функций ниже
      good_to_go_ = ValidateFunc();
    } else if (IsOperator(cur)) {
      good_to_go_ = ValidateOperator();
    } else if (isdigit(cur)) {
      double number = 0;
      int count_symbols_read = 0;
      sscanf(&cur_it_[0], "%le %n", &number, &count_symbols_read);
      lexemes_.emplace_back(NUMBER, number);
      cur_it_ += count_symbols_read - 1;
    } else {
      good_to_go_ = false;
    }
  }
}

void Expression::GetPostfix() {
  for (auto it = lexemes_.begin(); it != lexemes_.end() && good_to_go_; it++) {
    Operation cur_op = it->GetOperation();
    if (cur_op == NUMBER || cur_op == X)
      postfix_.push_back(*it);
    else if (cur_op == OPENBRACKET)
      operations_.push(*it);
    else if (cur_op == COS || cur_op == SIN || cur_op == TAN ||
             cur_op == ACOS || cur_op == ASIN || cur_op == ATAN ||
             cur_op == SQRT || cur_op == LN || cur_op == LOG) {
      operations_.push(*it);
    } else if (cur_op == PLUS || cur_op == MINUS || cur_op == MUL ||
               cur_op == DIV || cur_op == EXP || cur_op == MOD ||
               cur_op == UNARMINUS) {
      ProcessOperator(*it);
    } else if (cur_op == CLOSEBRACKET) {
      ProcessBracket();
    }
  }

  if (good_to_go_) ProcessRemains();
  if (good_to_go_)
    good_to_go_ = ValidateRPN();  // возможно стоит флаг внутрь функции записать
}

bool Expression::ValidateRPN() {
  bool good_rpn = true;
  int value = 0;
  int size = 0;
  for (auto it : postfix_) {
    Operation op = it.GetOperation();
    if (op == NUMBER || op == X) {
      value = 0;
    } else if (op == COS || op == SIN || op == TAN || op == ACOS ||
               op == ASIN || op == ATAN || op == SQRT || op == LN ||
               op == LOG || op == UNARMINUS) {
      value = 1;
    } else if (op == PLUS || op == MINUS || op == MUL || op == DIV ||
               op == EXP || op == MOD) {
      value = 2;
    }

    size = size + 1 - value;
    if (size <= 0) good_rpn = false;
  }

  good_rpn = size == 1;

  return good_rpn;
}

void Expression::ProcessRemains() {
  while (!operations_.empty() && good_to_go_) {
    if (operations_.top().GetOperation() == OPENBRACKET ||
        operations_.top().GetOperation() == CLOSEBRACKET) {
      good_to_go_ = 0;
    }
    if (good_to_go_) {
      postfix_.push_back(operations_.top());
      operations_.pop();
    }
  }
}

void Expression::ProcessBracket() {
  if (!operations_.empty()) {
    while (!operations_.empty() &&
           operations_.top().GetOperation() != OPENBRACKET) {
      postfix_.push_back(operations_.top());
      operations_.pop();
    }
    if (operations_.empty()) {
      good_to_go_ = false;
    } else if (operations_.top().GetOperation() == OPENBRACKET) {
      operations_.pop();
    }

  } else {
    good_to_go_ = false;
  }

  // return good_to_go_;  // убрать это
}

void Expression::ProcessOperator(Lexeme &lexeme) {
  int pr_head = 0;
  if (!operations_.empty()) pr_head = operations_.top().GetPriority();
  int pr_c = lexeme.GetPriority();  // измени название
  while (!operations_.empty() &&
         (pr_head > pr_c || (pr_head == pr_c && CheckAssociativity(lexeme)))) {
    postfix_.push_back(operations_.top());
    operations_.pop();
    if (!operations_.empty()) pr_head = operations_.top().GetPriority();
  }
  operations_.push(lexeme);

  // return true;  // избавься потом от возврата
}

bool Expression::CheckAssociativity(Lexeme &lexeme) {
  // пожалуйста замени это на что-то нормальное
  Operation add_operation = lexeme.GetOperation();
  Operation stack_operation = operations_.top().GetOperation();
  return (add_operation == PLUS || add_operation == MINUS ||
          add_operation == MUL || add_operation == DIV ||
          add_operation == COS || add_operation == SIN ||
          add_operation == TAN || add_operation == ACOS ||
          add_operation == ASIN || add_operation == ATAN ||
          add_operation == SQRT || add_operation == LN ||
          add_operation == LOG) &&
         (stack_operation == PLUS || stack_operation == MINUS ||
          stack_operation == MUL || stack_operation == DIV ||
          stack_operation == COS || stack_operation == SIN ||
          stack_operation == TAN || stack_operation == ACOS ||
          stack_operation == ASIN || stack_operation == ATAN ||
          stack_operation == SQRT || stack_operation == LN ||
          stack_operation == LOG);
}

bool Expression::IsFunc(const char check) {  // НЕ ООП
  // перепиши и используй итератор
  std::string funcs = "cstal";
  return (funcs.find(check) != std::string::npos);
}

bool Expression::IsValidFunc() { return true; }

};  // namespace s21