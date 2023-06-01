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
    NUMBER

  };

 public:
  Expression() = delete;
  Expression(const std::string infix, const double x) : infix_(infix), x_(x) {
    ConvertToLexemes();
    GetPostfix();
  };  // добавить сюда сразу перевод в лексемы
  Expression(const Expression &other) = delete;
  Expression(Expression &&other) = delete;

  double Calculate();
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
      // для дефолтных нужно сделать 0

      if (operation_ == PLUS || operation_ == MINUS || operation_ == MOD) {
        priority_ = 1;
        // std::cout << "1" << std::endl;
      } else if (operation_ == MUL || operation_ == DIV) {
        priority_ = 2;
        // std::cout << "2" << std::endl;

      } else if (operation_ == EXP || operation_ == UNARMINUS) {
        priority_ = 3;
        // std::cout << "3" << std::endl;

      } else if (operation_ == COS || operation_ == SIN || operation_ == TAN ||
                 operation_ == ACOS || operation_ == ASIN ||
                 operation_ == ATAN || operation_ == SQRT || operation_ == LN ||
                 operation_ == LOG) {
        priority_ = 4;
        // std::cout << "4" << std::endl;
      } else {
        // std::cout << "0" << std::endl;
      }
    }
  };
  bool ValidateRPN();
  void CalcOperand(Operation op);
  void CalcFunc(Operation op);
  void ProcessBracket();
  void ProcessRemains();
  void ProcessOperator(Lexeme &lexema);
  bool CheckAssociativity(Lexeme &lexeme);
  std::string ReadNumber();
  bool IsOperator(const char check);
  bool ValidateOperator();
  bool IsFunc(const char check);
  bool ValidateFunc();
  void GetPostfix();
  void ConvertToLexemes();
  // переделать на текущий итератор
  std::string::iterator cur_it_;
  // std::string postfix_;
  std::string infix_;
  std::stack<Lexeme> operations_;
  std::stack<double> calculate_;
  bool good_to_go_ = true;
  Operation op_;
  size_t expresion_size_ = infix_.size();
  double x_{};
  std::vector<Lexeme> lexemes_{};
  std::vector<Lexeme> postfix_{};
};

};  // namespace s21