// ifndef
#pragma once
#include "model/expression.h"

namespace s21 {
class ControllerCalculator {
 public:
  ControllerCalculator() = default;
  ~ControllerCalculator() = default;

  double Calculate(const std::string &infix, const double x);
  double Calculate(const double x);
  void SetExpression(const std::string &infix);
  bool IsValidExpression();

 private:
  Expression expression_{};
};

};  // namespace s21
