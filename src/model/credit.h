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
  double GetMonthPayment() { return month_payment_; }
  double GetTotalPayment() { return total_payment_; }
  double GetOverpayment() { return overpayment_; }
  double GetFirstPayment() { return first_payment_; }
  double GetLastPayment() { return last_payment_; }

 private:
  double CalcMonthAnnuity();
  double loan_{};
  int period_{};
  double rate_{};
  double month_payment_{}, total_payment_{}, overpayment_{};
  double first_payment_{}, last_payment_{};
};

};  // namespace s21