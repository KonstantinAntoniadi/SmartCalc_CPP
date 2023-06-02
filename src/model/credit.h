#pragma once

#include <time.h>

#include <cmath>

namespace s21 {
constexpr int days_in_year = 365;  // нужно куда-то вынести
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
  double month_payment_{}, total_payment_{}, overpayment_{};
  double first_payment_{}, last_payment_{};
};

};  // namespace s21