#pragma once

#include "controllercredit.h"

namespace s21 {
void ControllerCredit::SetStartValues(const double loan, const double period,
                                      const double rate) {
  credit_.SetStartValues(loan, period, rate);
}

void ControllerCredit::CalcAnnuity() { credit_.CalcAnnuity(); }

void ControllerCredit::CalcDifferentiated() { credit_.CalcDifferentiated(); }

double ControllerCredit::GetMonthPayment() { credit_.GetMonthPayment(); }

double ControllerCredit::GetOverpayment() { credit_.GetOverpayment(); }

double ControllerCredit::GetTotalPayment() { credit_.GetTotalPayment(); }

double ControllerCredit::GetFirstPayment() { credit_.GetFirstPayment(); }

double ControllerCredit::GetLastPayment() { credit_.GetLastPayment(); }

};  // namespace s21