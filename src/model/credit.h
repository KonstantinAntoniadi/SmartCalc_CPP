#ifndef CPP_SMART_CALC_V2_SRC_MODEL_CREDIT_H
#define CPP_SMART_CALC_V2_SRC_MODEL_CREDIT_H

#include <time.h>

#include <cmath>

namespace s21 {

// вынести 12 в константу
class Credit {
 public:
  Credit() = default;
  Credit(const double loan, const int period, const double rate)
      : loan_(loan), period_(period), rate_(rate){};
  ~Credit() = default;
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
  double first_payment_{}, last_payment_{};
  double month_payment_{}, total_payment_{}, overpayment_{};
  int days_in_year_ = 365;
  double months_in_year_ = 12.0;
};

}  // namespace s21

#endif  // CPP_SMART_CALC_V2_SRC_MODEL_CREDIT_H
