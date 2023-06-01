#pragma once

#include <cmath>
#include <time.h>

namespace s21 {
class Credit {
 public:
  Credit() = default;
  void SetStartValues(const double loan, const int period, const double rate);
  void CalcAnnuity();
  void CalcDifferentiated();
 private:
  double CalcMonthAnnuity();
  double loan_{};
  int period_{};
  double rate_{};
  double month_{}, total_{}, overpayment_{};
  double first_payment_{}, last_payment_{};
};

};  // namespace s21