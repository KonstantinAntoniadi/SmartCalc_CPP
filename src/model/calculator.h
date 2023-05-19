// add headers
#include <iostream>
#include <stack>
namespace s21 {

    // add enums
class Calculator {
    enum Operation {
        BRACKET,

    };
    public:
        Calculator() = delete;
        Calculator(const std::string infix) : infix_ (infix) {};
        Calculator(const Calculator &other) = delete;
        Calculator(Calculator &&other) = delete;

        void Calculate();
        bool IsFunc(const char check);
        bool IsValidFunc()
    private:
        void GetPostfix();
        std::iterator cur_pos_;
        std::string postfix_;
        std::string infix_;
        std::stack<Operation> operations_;
        std::stack<double> calculate_;
};

};