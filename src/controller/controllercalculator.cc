#pragma once

#include "controllercalculator.h"

namespace s21 {
void ControllerCalculator::SetExpression(const std::string &infix) {
  expression_.SetExpression(infix);
}

bool ControllerCalculator::IsValidExpression() { return expression_.IsValid(); }

double ControllerCalculator::Calculate(const double x) {
  double res = expression_.Calculate(x);
  return res;
}

double ControllerCalculator::Calculate(const std::string &infix,
                                       const double x) {
  expression_.SetExpression(infix);

  return expression_.Calculate(x);
}

};  // namespace s21
