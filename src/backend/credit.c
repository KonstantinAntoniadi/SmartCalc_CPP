#include "calc.h"

double monthAnnuity(double loan, int period, double rate) {
  double month_rate = rate / 12.0 / 100.0;
  double temp = pow((1 + month_rate), period);

  return loan * month_rate * temp / (temp - 1);
}