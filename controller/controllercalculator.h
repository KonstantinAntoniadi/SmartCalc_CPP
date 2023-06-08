#ifndef CPP_SMART_CALC_V2_SRC_CONTROLLERCALCULATOR_H
#define CPP_SMART_CALC_V2_SRC_CONTROLLERCALCULATOR_H

#include "model/expression.h"

namespace s21 {
class ControllerCalculator {
 public:
  ControllerCalculator() = default;
  ~ControllerCalculator() = default;

  double Calculate(const double x);
  void SetExpression(const std::string &infix);
  bool IsValidExpression();

 private:
  Expression expression_{};
};

};  // namespace s21

#endif  // CPP_SMART_CALC_V2_SRC_CONTROLLERCALCULATOR_H