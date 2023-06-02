#pragma once
#include "credit.h"

namespace s21 {

void Credit::SetStartValues(const double loan, const int period,
                            const double rate) {
  loan_ = loan;
  period_ = period;
  rate_ = rate;
}

void Credit::CalcAnnuity() {
  month_payment_ = CalcMonthAnnuity();
  total_payment_ = month_payment_ * period_;
  overpayment_ = total_payment_ - loan_;
}

void Credit::CalcDifferentiated() {
  double Sn = loan_ / period_;
  double payment = Sn + loan_ * rate_ / 100 * (365 / 12.0) / 365;
  first_payment_ = payment;
  total_payment_ = payment;
  for (int i = 1; i < period_; i++) {
    payment = Sn + (loan_ - i * Sn) * rate_ / 100 * (365 / 12.0) / 365;
    total_payment_ += payment;
  }

  last_payment_ = payment;
}

double Credit::CalcMonthAnnuity() {
  double month_rate = rate_ / 12.0 / 100.0;
  double temp = std::pow((1 + month_rate), period_);

  return loan_ * month_rate * temp / (temp - 1);
}

}  // namespace s21
