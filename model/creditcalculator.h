#ifndef SMARTCALC_CPP_SRC_MODEL_CREDITCALCULATOR_H
#define SMARTCALC_CPP_SRC_MODEL_CREDITCALCULATOR_H

#include <time.h>

#include <cmath>

class CreditCalculator {
 public:
  CreditCalculator() = default;
  CreditCalculator(const double loan, const int period, const double rate)
      : loan_(loan), period_(period), rate_(rate){};
  ~CreditCalculator() = default;

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
  static constexpr int days_in_year_ = 365;
  static constexpr double months_in_year_ = 12.0;
};

#endif  // SMARTCALC_CPP_SRC_MODEL_CREDITCALCULATOR_H