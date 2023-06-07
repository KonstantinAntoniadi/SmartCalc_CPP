#include "controllercalculator.h"

namespace s21 {
void ControllerCalculator::SetExpression(const std::string &infix) {
  expression_.SetExpression(infix);
}

bool ControllerCalculator::IsValidExpression() {
  return expression_.IsValidExpression();
}

double ControllerCalculator::Calculate(const double x) {
  double res = expression_.Calculate(x);
  return res;
}



};  // namespace s21
