#ifndef CPP_SMART_CALC_V2_SRC_MODEL_EXPRESSION_H
#define CPP_SMART_CALC_V2_SRC_MODEL_EXPRESSION_H

#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <map>
#include <stack>
#include <unordered_set>
#include <vector>

namespace s21 {

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
    PLUS,
    MINUS,
    MOD,
    MUL,
    DIV,
    EXP,
    UNARMINUS,
    NUMBER,
    X
  };

 public:
  Expression() = default;
  ~Expression() = default;

  void SetExpression(const std::string &infix);
  inline bool IsValidExpression() { return good_to_go_; }
  double Calculate(const double x);
  double Calculate() { return Calculate(0); }

 private:
  class Lexeme {
   public:
    Lexeme(Operation operation) : operation_(operation) { SetPrirority(); }
    Lexeme(Operation operation, double value)
        : operation_(operation), value_(value) {}
    inline int GetPriority() { return priority_; }
    inline Operation GetOperation() { return operation_; }
    inline double GetValue() { return value_; }

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

 private:
  void Clear();
  void ClearCalculate();
  void ClearOperations();
  void ValidateRPN();
  double CalcOperand(Operation op);
  double CalcFunc(Operation op);
  void ProcessBracket();
  void ProcessRemains();
  void ProcessOperator(Lexeme &lexema);
  bool CheckAssociativity(Lexeme &lexeme);

  bool ValidateOperator();
  bool ValidateFunc();
  void ConvertToPostfix();
  void ConvertToLexemes();
  inline bool IsOperator(const char check);
  inline bool IsFunc(const char check);
  static bool OperationIsFunc(Operation op);
  inline static bool OperationIsBinaryOperation(Operation op);
  std::string::iterator cur_iterator_;
  std::string infix_;
  std::stack<Lexeme> operations_;
  std::stack<double> calculate_;
  bool good_to_go_ = false;
  double x_{};
  std::vector<Lexeme> lexemes_{};
  std::vector<Lexeme> postfix_{};
  static const std::unordered_set<Operation> funcs_;
  static const std::unordered_set<Operation> binary_operations_;
  static const std::map<std::string, Operation> map_operations_;
};

}  // namespace s21

#endif  // CPP_SMART_CALC_V2_SRC_MODEL_EXPRESSION_H