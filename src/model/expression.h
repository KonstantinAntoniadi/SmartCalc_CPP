#ifndef CPP_SMART_CALC_V2_SRC_MODEL_EXPRESSION_H
#define CPP_SMART_CALC_V2_SRC_MODEL_EXPRESSION_H

#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <stack>
#include <unordered_set>
#include <vector>

namespace s21 {

// add enums
class Expression {
  enum Operation {
    OPENBRACKET,
    CLOSEBRACKET,
    COS,
    SIN,
    TAN,
    ACOS,
    ASIN,
    ATAN,
    SQRT,
    LN,
    LOG,
    // between lexems
    PLUS,
    MINUS,
    MOD,
    MUL,
    DIV,
    EXP,
    // unar
    UNARMINUS,
    NUMBER,
    X

  };

 public:
  Expression() = default;
  ~Expression() = default;
  void SetExpression(const std::string &infix) {
    infix_ = infix;
    Clear();
    ConvertToLexemes();
    GetPostfix();
  }

  bool IsValid() { return good_to_go_; }
  double Calculate() { return Calculate(0); }
  double Calculate(const double x);
  // стоит объединить функции ниже

 private:
  class Lexeme {
   public:
    Lexeme(Operation operation) : operation_(operation) { SetPrirority(); }
    Lexeme(Operation operation, double value)
        : operation_(operation), value_(value) {}
    int GetPriority() { return priority_; }
    Operation GetOperation() { return operation_; }
    double GetValue() { return value_; }

   private:
    Operation operation_{};
    double value_{};
    unsigned int priority_{};

    void SetPrirority() {
      if (operation_ == PLUS || operation_ == MINUS || operation_ == MOD) {
        priority_ = 1;
      } else if (operation_ == MUL || operation_ == DIV) {
        priority_ = 2;
      } else if (operation_ == EXP || operation_ == UNARMINUS) {
        priority_ = 3;
      } else if (OperationIsFunc(operation_)) {
        priority_ = 4;
      }
    }
  };
  void Clear() {
    good_to_go_ = true;
    while (!calculate_.empty()) {  // может стоит вынести отдельно
      calculate_.pop();
    }
    while (!operations_.empty()) {
      operations_.pop();
    }
    lexemes_.clear();
    postfix_.clear();
  }

  static bool OperationIsFunc(Operation op);
  void ValidateRPN();
  double CalcOperand(Operation op);
  double CalcFunc(Operation op);
  void ProcessBracket();
  void ProcessRemains();
  void ProcessOperator(Lexeme &lexema);
  bool CheckAssociativity(Lexeme &lexeme);
  bool IsOperator(const char check);
  bool ValidateOperator();
  bool IsFunc(const char check);
  bool ValidateFunc();
  void GetPostfix();
  void ConvertToLexemes();
  std::string::iterator cur_iterator_;
  std::string infix_;
  std::stack<Lexeme> operations_;
  std::stack<double> calculate_;
  bool good_to_go_ = false;
  double x_{};
  std::vector<Lexeme> lexemes_{};
  std::vector<Lexeme> postfix_{};
  static const std::unordered_set<Operation> funcs_;
  static const std::unordered_set<char> char_operators_;
  static const std::unordered_set<char> char_funcs_;
};

}  // namespace s21

#endif  // CPP_SMART_CALC_V2_SRC_MODEL_EXPRESSION_H