#ifndef SMARTCALC_CPP_SRC_CONTROLLERCREDIT_H
#define SMARTCALC_CPP_SRC_CONTROLLERCREDIT_H

#include "model/creditcalculator.h"

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

#endif  // SMARTCALC_CPP_SRC_CONTROLLERCREDIT_H