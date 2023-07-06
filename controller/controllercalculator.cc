#include "controllercalculator.h"

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