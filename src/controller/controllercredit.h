#pragma once

#include "model/creditcalculator.h"
namespace s21 {
class ControllerCredit {
 public:
  ControllerCredit() = default;
  ~ControllerCredit() = default;
  void SetStartValues(const double loan, const double period,
                      const double rate);
  void CalcAnnuity();
  void CalcDifferentiated();
  double GetMonthPayment();
  double GetOverpayment();
  double GetTotalPayment();
  double GetFirstPayment();
  double GetLastPayment();

 private:
  CreditCalculator credit_;
};
};  // namespace s21