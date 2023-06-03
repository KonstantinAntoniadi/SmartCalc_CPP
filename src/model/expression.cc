#include "expresultsion.h"

namespace s21 {
void Expresultsion::ConvertToLexemes() {
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
    } else if (cur != ' ') {
      good_to_go_ = false;
    }
  }

  // ValidateRPN();
}

double Expresultsion::Calculate(const double x) {
  x_ = x;
  // std::cout <<
  double result = 0;
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
        calculate_.push(CalcOperand(cur_op));
      } else if (OperationIsFunc(cur_op)) {
        calculate_.push(CalcFunc(cur_op));
      }
    }
    result = calculate_.top();
  }

  // while (!calculate_.empty()) {
  //   calculate_.pop();
  // }
  return result;
}

double Expresultsion::CalcFunc(Operation op) {
  double value = calculate_.top();
  calculate_.pop();

  double result = 0;
  if (op == COS) {
    result = std::cos(value);
  } else if (op == SIN) {
    result = std::sin(value);
  } else if (op == TAN) {
    result = std::tan(value);
  } else if (op == ACOS) {
    result = std::acos(value);
  } else if (op == ASIN) {
    result = std::asin(value);
  } else if (op == ATAN) {
    result = std::atan(value);
  } else if (op == SQRT) {
    result = std::sqrt(value);
  } else if (op == LN) {
    result = std::log(value);
  } else if (op == LOG) {
    result = std::log10(value);
  }

  return result;
}

double Expresultsion::CalcOperand(Operation op) {
  double b = calculate_.top();
  calculate_.pop();
  double a = calculate_.top();
  calculate_.pop();

  double result = 0;

  if (op == PLUS) {
    result = a + b;
  } else if (op == MINUS) {
    result = a - b;
  } else if (op == MUL) {
    result = a * b;
  } else if (op == DIV) {
    result = a / b;
  } else if (op == EXP) {
    result = std::pow(a, b);
  } else if (op == MOD) {
    result = std::fmod(a, b);
  }

  return result;
}

bool Expresultsion::ValidateFunc() {
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

bool Expresultsion::IsOperator(const char check) {  // НЕ ООП
  std::string operators = "+-*/^m";
  return (operators.find(check) != std::string::npos);
}

bool Expresultsion::ValidateOperator() {
  bool result = true;

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
    result = false;
  }

  return result;
}

void Expresultsion::GetPostfix() {
  for (auto it = lexemes_.begin(); it != lexemes_.end() && good_to_go_; it++) {
    Operation cur_op = it->GetOperation();
    if (cur_op == NUMBER || cur_op == X)
      postfix_.push_back(*it);
    else if (cur_op == OPENBRACKET)
      operations_.push(*it);
    else if (OperationIsFunc(cur_op)) {
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
    good_to_go_ = ValidateRPN();  // возможно стоит флаг внутрь функции
  //   записать
}

bool Expresultsion::ValidateRPN() {
  bool good_rpn = true;
  int value = 0;
  int size = 0;
  for (auto it : postfix_) {
    Operation op = it.GetOperation();
    if (op == NUMBER || op == X) {
      value = 0;
    } else if (OperationIsFunc(op) || op == UNARMINUS) {
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

void Expresultsion::ProcessRemains() {
  while (!operations_.empty() && good_to_go_) {
    if (operations_.top().GetOperation() == OPENBRACKET ||
        operations_.top().GetOperation() == CLOSEBRACKET) {
      good_to_go_ = false;
    }
    if (good_to_go_) {
      postfix_.push_back(operations_.top());
      operations_.pop();
    }
  }
}

void Expresultsion::ProcessBracket() {
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

void Expresultsion::ProcessOperator(Lexeme &lexeme) {
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

bool Expresultsion::CheckAssociativity(Lexeme &lexeme) {
  Operation add_operation = lexeme.GetOperation();
  Operation stack_operation = operations_.top().GetOperation();
  return (add_operation != EXP && add_operation != UNARMINUS) ||
         (stack_operation != EXP && stack_operation != UNARMINUS);
}

bool Expresultsion::IsFunc(const char check) {  // НЕ ООП
  // перепиши и используй итератор
  std::string funcs = "cstal";
  return (funcs.find(check) != std::string::npos);
}

bool Expresultsion::IsValidFunc() { return true; }

bool Expresultsion::OperationIsFunc(Operation op) {
  return std::count(funcs_.begin(), funcs_.end(), op);
}

};  // namespace s21