#include "expression.h"

namespace s21 {
double Expression::Calculate() {
  // std::cout <<
  double res = 0;
  if (good_to_go_) {
    for (auto it = postfix_.begin(); it != postfix_.end(); it++) {
      Operation cur_op = it->GetOperation();
      if (cur_op == NUMBER) {
        calculate_.push(it->GetValue());
      } else if (cur_op == UNARMINUS) {
        calculate_.top() *= -1;
      } else if (cur_op == PLUS || cur_op == MINUS || cur_op == MUL ||
                 cur_op == DIV || cur_op == EXP || cur_op == MOD) {
        CalcOperand(cur_op);
      } else if (cur_op == COS || cur_op == SIN || cur_op == TAN ||
                 cur_op == ACOS || cur_op == ASIN || cur_op == ATAN ||
                 cur_op == SQRT || cur_op == LN || cur_op == LOG) {
        CalcFunc(cur_op);
      }
    }
  }
  res = calculate_.top();
  return res;
}

void Expression::CalcFunc(Operation op) {
  double a = calculate_.top();
  calculate_.pop();
  if (op == COS) {
    calculate_.push(std::cos(a));
  } else if (op == SIN) {
    calculate_.push(std::sin(a));
  } else if (op == TAN) {
    calculate_.push(std::tan(a));
  } else if (op == ACOS) {
    calculate_.push(std::acos(a));
  } else if (op == ASIN) {
    calculate_.push(std::asin(a));
  } else if (op == ATAN) {
    calculate_.push(std::atan(a));
  } else if (op == SQRT) {
    calculate_.push(std::sqrt(a));
  } else if (op == LN) {
    calculate_.push(std::log(a));
  } else if (op == LOG) {
    calculate_.push(std::log10(a));
  }
}

void Expression::CalcOperand(Operation op) {
  double b = calculate_.top();
  calculate_.pop();
  double a = calculate_.top();
  calculate_.pop();

  if (op == PLUS) {
    calculate_.push(a + b);
  } else if (op == MINUS) {
    calculate_.push(a - b);
  } else if (op == MUL) {
    calculate_.push(a * b);
  } else if (op == DIV) {
    calculate_.push(a / b);
  } else if (op == EXP) {
    calculate_.push(std::pow(a, b));
  } else if (op == MOD) {
    calculate_.push(std::fmod(a, b));
  }
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

bool Expression::IsOperator(const char check) {  // НЕ ООП
  std::string operators = "+-*/^m";
  return (operators.find(check) != std::string::npos);
}

bool Expression::ValidateOperator() {
  bool result = true;

  if (*cur_it_ == '+') {
    lexemes_.emplace_back(PLUS);
  } else if (*cur_it_ == '-') {
    if (lexemes_.empty() ||
        lexemes_.at(lexemes_.size() - 2).GetOperation() == OPENBRACKET) {
      lexemes_.emplace_back(UNARMINUS);
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

std::string Expression::ReadNumber() {
  unsigned int dot_count = 0;
  std::string temp;
  while (good_to_go_ && (isdigit(*cur_it_) || *cur_it_ == '.')) {
    if (*cur_it_ == '.') dot_count++;
    if (dot_count <= 1) {
      temp += *cur_it_;
      cur_it_ += 1;
    } else {
      good_to_go_ = 0;
    }
  }
  cur_it_--;
  return temp;
}

void Expression::ConvertToLexemes() {
  for (cur_it_ = infix_.begin(); cur_it_ != infix_.end() && good_to_go_;
       cur_it_++) {
    char cur = *cur_it_;
    if (cur == 'x') {
      lexemes_.emplace_back(NUMBER, x_);
    } else if (cur == '(') {
      lexemes_.emplace_back(OPENBRACKET);
    } else if (cur == ')') {
      lexemes_.emplace_back(CLOSEBRACKET);
    } else if (IsFunc(cur)) {  // можно попробовать объединить с функций ниже
      good_to_go_ = ValidateFunc();
    } else if (IsOperator(cur)) {
      good_to_go_ = ValidateOperator();
    } else if (isdigit(cur)) {
      std::string str_number = ReadNumber();
      lexemes_.emplace_back(NUMBER, strtod(str_number.data(), 0));
    }
  }
}

void Expression::GetPostfix() {
  for (auto it = lexemes_.begin(); it != lexemes_.end() && good_to_go_; it++) {
    Operation cur_op = it->GetOperation();
    if (cur_op == NUMBER)
      postfix_.push_back(*it);
    else if (cur_op == OPENBRACKET)
      operations_.push(*it);
    else if (cur_op == COS || cur_op == SIN || cur_op == TAN ||
             cur_op == ACOS || cur_op == ASIN || cur_op == ATAN ||
             cur_op == SQRT || cur_op == LN || cur_op == LOG) {
      operations_.push(*it);
    } else if (cur_op == PLUS || cur_op == MINUS || cur_op == MUL ||
               cur_op == DIV || cur_op == EXP || cur_op == MOD) {
      good_to_go_ = ProcessOperator(*it);
    } else if (cur_op == CLOSEBRACKET) {
      good_to_go_ = ProcessBracket();
    }
  }

  if (good_to_go_) ProcessRemains();
  if (good_to_go_) ValidateRPN();
}

bool Expression::ValidateRPN() {
  bool good_rpn = true;
  int value = 0;
  int size = 0;
  for (auto it : postfix_) {
    Operation op = it.GetOperation();
    if (op == NUMBER) {
      value = 0;
    } else if (op == COS || op == SIN || op == TAN || op == ACOS ||
               op == ASIN || op == ATAN || op == SQRT || op == LN ||
               op == LOG) {
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
  if (!operations_.empty() && good_to_go_) {
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

bool Expression::ProcessBracket() {
  if (!operations_.empty()) {
    while (!operations_.empty() &&
           operations_.top().GetOperation() != OPENBRACKET) {
      postfix_.push_back(operations_.top());
      operations_.pop();
    }
    operations_.pop();
  } else {
    good_to_go_ = false;
  }

  return good_to_go_;  // убрать это
}

bool Expression::ProcessOperator(Lexeme &lexeme) {
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

  return true;  // избавься потом от возврата
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