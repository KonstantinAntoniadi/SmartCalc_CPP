#include "expression.h"

namespace s21 {
void Expression::ConvertToLexemes() {
  for (cur_iterator_ = infix_.begin();
       cur_iterator_ != infix_.end() && good_to_go_; cur_iterator_++) {
    char cur = *cur_iterator_;

    if (cur == 'x') {
      lexemes_.emplace_back(X, x_);
    } else if (cur == '(') {
      lexemes_.emplace_back(OPENBRACKET);
    } else if (cur == ')') {
      lexemes_.emplace_back(CLOSEBRACKET);
    } else if (IsFunc(cur)) {
      good_to_go_ = ValidateFunc();
    } else if (IsOperator(cur)) {
      good_to_go_ = ValidateOperator();
    } else if (isdigit(cur)) {
      double number = 0;
      int count_symbols_read = 0;
      sscanf(&cur_iterator_[0], "%le %n", &number, &count_symbols_read);
      lexemes_.emplace_back(NUMBER, number);
      cur_iterator_ += count_symbols_read - 1;
    } else if (cur != ' ') {
      good_to_go_ = false;
    }
  }
}

double Expression::Calculate(const double x) {
  x_ = x;

  double result = 0;
  if (good_to_go_) {
    for (auto it = postfix_.begin(); it != postfix_.end(); it++) {
      Operation op = it->GetOperation();
      if (op == NUMBER) {
        calculate_.push(it->GetValue());
      } else if (op == X) {
        calculate_.push(x_);
      } else if (op == UNARMINUS) {
        calculate_.top() *= -1;
      } else if (OperationIsBinaryOperation(op)) {
        calculate_.push(CalcOperand(op));
      } else if (OperationIsFunc(op)) {
        calculate_.push(CalcFunc(op));
      }
    }
    result = calculate_.top();
  }

  return result;
}

double Expression::CalcFunc(Operation op) {
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

double Expression::CalcOperand(Operation op) {
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

bool Expression::ValidateFunc() {
  bool result = true;
  if (!strncmp(&cur_iterator_[0], "cos", 3)) {
    lexemes_.emplace_back(COS);
    cur_iterator_ += 2;
  } else if (!strncmp(&cur_iterator_[0], "sin", 3)) {
    lexemes_.emplace_back(SIN);
    cur_iterator_ += 2;
  } else if (!strncmp(&cur_iterator_[0], "tan", 3)) {
    lexemes_.emplace_back(TAN);
    cur_iterator_ += 2;
  } else if (!strncmp(&cur_iterator_[0], "acos", 4)) {
    lexemes_.emplace_back(ACOS);
    cur_iterator_ += 3;
  } else if (!strncmp(&cur_iterator_[0], "asin", 4)) {
    lexemes_.emplace_back(ASIN);
    cur_iterator_ += 3;
  } else if (!strncmp(&cur_iterator_[0], "atan", 4)) {
    lexemes_.emplace_back(ATAN);
    cur_iterator_ += 3;
  } else if (!strncmp(&cur_iterator_[0], "sqrt", 4)) {
    lexemes_.emplace_back(SQRT);
    cur_iterator_ += 3;
  } else if (!strncmp(&cur_iterator_[0], "ln", 2)) {
    lexemes_.emplace_back(LN);
    cur_iterator_ += 1;
  } else if (!strncmp(&cur_iterator_[0], "log", 3)) {
    lexemes_.emplace_back(LOG);
    cur_iterator_ += 2;
  } else {
    result = false;
  }

  return result;
}

bool Expression::ValidateOperator() {
  bool result = true;

  if (*cur_iterator_ == '+') {
    if (!lexemes_.empty() &&
        lexemes_.at(lexemes_.size() - 1).GetOperation() != OPENBRACKET) {
      lexemes_.emplace_back(PLUS);
    }
  } else if (*cur_iterator_ == '-') {
    if (lexemes_.empty() ||
        lexemes_.at(lexemes_.size() - 1).GetOperation() == OPENBRACKET) {
      lexemes_.emplace_back(UNARMINUS);
    } else {
      lexemes_.emplace_back(MINUS);
    }
  } else if (*cur_iterator_ == '*') {
    lexemes_.emplace_back(MUL);
  } else if (*cur_iterator_ == '/') {
    lexemes_.emplace_back(DIV);
  } else if (*cur_iterator_ == '^') {
    lexemes_.emplace_back(EXP);
  } else if (!strncmp(&cur_iterator_[0], "mod", 3)) {
    lexemes_.emplace_back(MOD);
    cur_iterator_ += 2;
  } else {
    result = false;
  }

  return result;
}

void Expression::ConvertToPostfix() {
  for (auto it = lexemes_.begin(); it != lexemes_.end() && good_to_go_; it++) {
    Operation op = it->GetOperation();
    if (op == NUMBER || op == X)
      postfix_.push_back(*it);
    else if (op == OPENBRACKET)
      operations_.push(*it);
    else if (OperationIsFunc(op)) {
      operations_.push(*it);
    } else if (OperationIsBinaryOperation(op) || op == UNARMINUS) {
      ProcessOperator(*it);
    } else if (op == CLOSEBRACKET) {
      ProcessBracket();
    }
  }

  if (good_to_go_) ProcessRemains();
  ValidateRPN();
}

void Expression::ValidateRPN() {
  int value = 0;
  int size = 0;
  for (auto it : postfix_) {
    Operation op = it.GetOperation();
    if (op == NUMBER || op == X) {
      value = 0;
    } else if (OperationIsFunc(op) || op == UNARMINUS) {
      value = 1;
    } else if (OperationIsBinaryOperation(op)) {
      value = 2;
    }

    size = size + 1 - value;
    if (size <= 0) good_to_go_ = false;
  }

  good_to_go_ = size == 1;
}

void Expression::ProcessRemains() {
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
}

void Expression::ProcessOperator(Lexeme &lexeme) {
  int pr_head_lexeme = 0;
  if (!operations_.empty()) pr_head_lexeme = operations_.top().GetPriority();
  int pr_lexeme_for_add = lexeme.GetPriority();
  while (!operations_.empty() && (pr_head_lexeme > pr_lexeme_for_add ||
                                  (pr_head_lexeme == pr_lexeme_for_add &&
                                   CheckAssociativity(lexeme)))) {
    postfix_.push_back(operations_.top());
    operations_.pop();
    if (!operations_.empty()) pr_head_lexeme = operations_.top().GetPriority();
  }
  operations_.push(lexeme);
}

bool Expression::CheckAssociativity(Lexeme &lexeme) {
  Operation add_operation = lexeme.GetOperation();
  Operation stack_operation = operations_.top().GetOperation();
  return (add_operation != EXP && add_operation != UNARMINUS) ||
         (stack_operation != EXP && stack_operation != UNARMINUS);
}

void Expression::SetExpression(const std::string &infix) {
  infix_ = infix;
  Clear();
  ConvertToLexemes();
  ConvertToPostfix();
}

void Expression::Clear() {
  good_to_go_ = true;
  ClearCalculate();
  ClearOperations();
  lexemes_.clear();
  postfix_.clear();
}

void Expression::ClearCalculate() {
  while (!calculate_.empty()) {
    calculate_.pop();
  }
}

void Expression::ClearOperations() {
  while (!operations_.empty()) {
    operations_.pop();
  }
}

bool Expression::OperationIsFunc(Operation op) { return funcs_.count(op); }

bool Expression::OperationIsBinaryOperation(Operation op) {
  return binary_operations_.count(op);
}

bool Expression::IsFunc(const char check) { return char_funcs_.count(check); }

bool Expression::IsOperator(const char check) {
  return char_operators_.count(check);
}

const std::unordered_set<Expression::Operation> Expression::funcs_ = {
    COS, SIN, TAN, ACOS, ASIN, ATAN, SQRT, LN, LOG};

const std::unordered_set<Expression::Operation> Expression::binary_operations_ =
    {PLUS, MINUS, MUL, DIV, EXP, MOD};

const std::unordered_set<char> Expression::char_operators_ = {'+', '-', '*',
                                                              '/', '^', 'm'};

const std::unordered_set<char> Expression::char_funcs_ = {'c', 's', 't', 'a',
                                                          'l'};

}  // namespace s21
