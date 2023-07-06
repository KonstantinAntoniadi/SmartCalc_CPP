#include "expression.h"

void Expression::ConvertExpressionToLexemes() {
  for (cur_iterator_ = infix_.begin();
       cur_iterator_ != infix_.end() && good_to_go_; cur_iterator_++) {
    char cur = *cur_iterator_;

    if (*cur_iterator_ == ' ') {
      continue;
    } else if (isdigit(cur)) {
      lexemes_.emplace_back(NUMBER, ReadDouble());
    } else if (*cur_iterator_ == '+') {
      ConvertUnarToLexeme(PLUS);
    } else if (*cur_iterator_ == '-') {
      ConvertUnarToLexeme(MINUS);
    } else {
      ConvertOperationToLexeme();
    }
  }
}

void Expression::ConvertUnarToLexeme(Operation op) {
  if (lexemes_.empty() ||
      lexemes_.at(lexemes_.size() - 1).GetOperation() == OPENBRACKET) {
    lexemes_.emplace_back(map_unar_.at(op));
  } else {
    lexemes_.emplace_back(op);
  }
}

void Expression::ConvertOperationToLexeme() {
  good_to_go_ = false;
  for (const auto &[k, x] : map_operations_) {
    if (!strncmp(&cur_iterator_[0], k.data(), k.size())) {
      lexemes_.emplace_back(x);
      cur_iterator_ += k.size() - 1;
      good_to_go_ = true;
    }
  }
}

double Expression::ReadDouble() {
  double number = 0;
  int count_symbols_read = 0;
  sscanf(&cur_iterator_[0], "%le %n", &number, &count_symbols_read);
  cur_iterator_ += count_symbols_read - 1;

  return number;
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

void Expression::ConvertToPostfix() {
  for (auto it = lexemes_.begin(); it != lexemes_.end() && good_to_go_; it++) {
    Operation op = it->GetOperation();
    if (op == NUMBER || op == X) {
      postfix_.push_back(*it);
    } else if (op == OPENBRACKET) {
      operations_.push(*it);
    } else if (OperationIsFunc(op)) {
      operations_.push(*it);
    } else if (OperationIsBinaryOperation(op) || op == UNARMINUS) {
      ProcessOperator(*it);
    } else if (op == CLOSEBRACKET) {
      ProcessBracket();
    }
  }

  if (good_to_go_) ProcessRemains();
}

void Expression::ValidateExpression() {
  int value = 0;
  int size = 0;
  for (auto it : lexemes_) {
    Operation op = it.GetOperation();

    if (op == NUMBER || op == X) {
      value = 0;
    } else if (OperationIsFunc(op) || op == UNARMINUS || op == UNARPLUS) {
      value = 1;
    } else if (OperationIsBinaryOperation(op)) {
      value = 2;
    }

    if (op != OPENBRACKET && op != CLOSEBRACKET) {
      size = size + 1 - value;
    }
    if (size < 0) good_to_go_ = false;
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
  ConvertExpressionToLexemes();
  if (good_to_go_) ValidateExpression();
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

const std::unordered_set<Expression::Operation> Expression::funcs_ = {
    COS, SIN, TAN, ACOS, ASIN, ATAN, SQRT, LN, LOG};

const std::unordered_set<Expression::Operation> Expression::binary_operations_ =
    {PLUS, MINUS, MUL, DIV, EXP, MOD};

const std::map<Expression::Operation, Expression::Operation>
    Expression::map_unar_ = {{MINUS, UNARMINUS}, {PLUS, UNARPLUS}};

const std::map<std::string, Expression::Operation> Expression::map_operations_ =
    {{"(", OPENBRACKET}, {")", CLOSEBRACKET}, {"cos", COS},   {"sin", SIN},
     {"tan", TAN},       {"acos", ACOS},      {"asin", ASIN}, {"atan", ATAN},
     {"sqrt", SQRT},     {"ln", LN},          {"log", LOG},   {"+", PLUS},
     {"-", MINUS},       {"mod", MOD},        {"*", MUL},     {"/", DIV},
     {"^", EXP},         {"~", UNARMINUS},    {"x", X}};
