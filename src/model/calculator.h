// add headers
#include <iostream>
#include <stack>
namespace s21 {

    // add enums
class Calculator {
    enum Operation  {
        BRACKET,
        COS,
        SIN,
        TAN,
        ACOS,
        ASIN,
        ATAN,
        SQRT,
        LN,
        LOG
    };

    public:
        Calculator() = delete;
        Calculator(const std::string infix) : infix_ (infix) {};
        Calculator(const Calculator &other) = delete;
        Calculator(Calculator &&other) = delete;

        void Calculate();
        // стоит объединить функции ниже
        bool IsValidFunc(const char check);
        bool IsValidFunc();
    private:
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

};