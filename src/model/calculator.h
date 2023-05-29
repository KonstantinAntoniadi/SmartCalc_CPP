// add headers
#include <iostream>
#include <stack>
namespace s21 {

// add enums
class Calculator {
  enum Operation {
    BRACKET,
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

  };

 public:
  Calculator() = delete;
  Calculator(const std::string infix) : infix_(infix){};
  Calculator(const Calculator &other) = delete;
  Calculator(Calculator &&other) = delete;

  void Calculate();
  // стоит объединить функции ниже
  bool IsValidFunc(const char check);
  bool IsValidFunc();

 private:
  class Lexema {
   public:
    Lexema(Operation operation) : operation_(operation) {}
    int GetPriority() { return priority_; }

   private:
    Operation operation_{};
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
  void GetPostfix();
  // переделать на текущий итератор
  std::string::iterator cur_pos_;
  std::string postfix_;
  std::string infix_;
  std::stack<Operation> operations_;
  std::stack<double> calculate_;
  bool good_to_go_ = true;
  Operation op_;
};

};  // namespace s21