// ifndef
#pragma once
#include "model/expression.h"

namespace s21 {
class ControllerCalculator {
 public:
  ControllerCalculator() = default;
  ~ControllerCalculator() = default;
 private:
  Expression expression_{};
};

};  // namespace s21
