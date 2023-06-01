// ifndef
#pragma once
#include "model/expression.h"

namespace s21 {
class ControllerCalculator {
 public:
  ControllerCalculator() = default;
  ~ControllerCalculator() = default;

  double Calculate(const std::string &infix, const double x);
 private:
  Expression expression_{};
};

};  // namespace s21
