#pragma once
#include "credit.h"

namespace s21 {

void Credit::SetStartValues(const double loan, const int period, const double rate) {
    loan_ = loan;
    period_ = period;
    rate_ = rate;
}

void Credit::CalcAnnuity() {
    month_ = CalcMonthAnnuity();
    total_ = month_ * period_;
    overpayment_ = total_ - loan_;
}

void Credit::CalcDifferentiated() {
    time_t the_time = time(NULL);
    struct tm *today = localtime(&the_time);

    int day = today->tm_mday;
}

double Credit::CalcMonthAnnuity() {
  double month_rate = rate_ / 12.0 / 100.0;
  double temp = std::pow((1 + month_rate), period_);

  return loan_ * month_rate * temp / (temp - 1);
}
}  // namespace s21
