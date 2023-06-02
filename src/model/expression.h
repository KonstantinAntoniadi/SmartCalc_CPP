// add headers
#include <cmath>
#pragma once
#include <cstring>
#include <iostream>
#include <stack>
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
  Expression(const Expression &other) = delete;
  Expression(Expression &&other) = delete;
  void SetExpression(const std::string &infix) {
    infix_ = infix;
    Clear();
    ConvertToLexemes();
    GetPostfix();
  }

  bool IsValid() { return good_to_go_; }

  double Calculate(const double x);
  // стоит объединить функции ниже

  bool IsValidFunc();

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

      } else if (operation_ == COS || operation_ == SIN || operation_ == TAN ||
                 operation_ == ACOS || operation_ == ASIN ||
                 operation_ == ATAN || operation_ == SQRT || operation_ == LN ||
                 operation_ == LOG) {
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
  bool ValidateRPN();
  void CalcOperand(Operation op);
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
  // переделать на текущий итератор
  std::string::iterator cur_it_;
  std::string infix_;
  std::stack<Lexeme> operations_;
  std::stack<double> calculate_;
  bool good_to_go_ = false;
  double x_{};
  std::vector<Lexeme> lexemes_{};
  std::vector<Lexeme> postfix_{};
};

};  // namespace s21
