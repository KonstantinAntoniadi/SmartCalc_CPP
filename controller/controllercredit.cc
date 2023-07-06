#include "controllercredit.h"

void ControllerCredit::SetStartValues(const double loan, const double period,
                                      const double rate) {
  credit_.SetStartValues(loan, period, rate);
}

void ControllerCredit::CalcAnnuity() { credit_.CalcAnnuity(); }

void ControllerCredit::CalcDifferentiated() { credit_.CalcDifferentiated(); }

double ControllerCredit::GetMonthPayment() { return credit_.GetMonthPayment(); }

double ControllerCredit::GetOverpayment() { return credit_.GetOverpayment(); }

double ControllerCredit::GetTotalPayment() { return credit_.GetTotalPayment(); }

double ControllerCredit::GetFirstPayment() { return credit_.GetFirstPayment(); }

double ControllerCredit::GetLastPayment() { return credit_.GetLastPayment(); }
