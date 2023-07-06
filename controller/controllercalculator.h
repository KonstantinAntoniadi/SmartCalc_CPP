#ifndef SMARTCALC_CPP_SRC_CONTROLLERCALCULATOR_H
#define SMARTCALC_CPP_SRC_CONTROLLERCALCULATOR_H

#include "model/expression.h"

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

#endif  // SMARTCALC_CPP_SRC_CONTROLLERCALCULATOR_H