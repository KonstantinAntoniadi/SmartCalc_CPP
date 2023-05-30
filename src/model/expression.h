// add headers
#include <iostream>
#include <stack>
#include <vector>
#include <cstring>
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
  Expression(const std::string infix) : infix_(infix){};
  Expression(const Expression &other) = delete;
  Expression(Expression &&other) = delete;

  double Calculate(double x);
  // стоит объединить функции ниже

  bool IsValidFunc();

 private:
  class Lexeme {
   public:
    Lexeme(Operation operation)
        : operation_(operation){SetPrirority();} Lexeme(Operation operation,
                                                       double value)
        : operation_(operation), value_(value) {}
    int GetPriority() { return priority_; }

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
      } else {
        priority_ = 4;
      }
    }
  };
  std::string ReadNumber();
  bool IsOperator(const char check);
  bool ValidateOperator();
  bool IsFunc(const char check);
  bool ValidateFunc();
  void GetPostfix();
  void ConvertToLexemes();
  // переделать на текущий итератор
  std::string::iterator cur_it_;
  std::string postfix_;
  std::string infix_;
  std::stack<Operation> operations_;
  std::stack<double> calculate_;
  bool good_to_go_ = true;
  Operation op_;
  size_t expresion_size_ = infix_.size();
  double x_{};
  std::vector<Lexeme> lexemes_{};
};

};  // namespace s21