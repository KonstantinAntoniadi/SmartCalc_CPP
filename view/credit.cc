#include "credit.h"

#include <QDate>

#include "ui_credit.h"
namespace s21 {
Credit::Credit(QWidget *parent) : QWidget(parent), ui_(new Ui::Credit) {
  ui_->setupUi(this);
}

Credit::~Credit() { delete ui_; }

void Credit::on_pushButton_calculate_clicked() {
  double loan = ui_->spinBox_loan->value();
  int period = ui_->spinBox_period->value();
  double rate = ui_->doubleSpinBox_rate->value();
  int mode = ui_->comboBox_type->currentIndex();

  controller_credit_.SetStartValues(loan, period, rate);
  if (mode == 0) {
    controller_credit_.CalcAnnuity();

    ui_->lineEdit_month->setText(
        QString("%L1").arg(controller_credit_.GetMonthPayment(), 0, 'f', 2));
    ui_->lineEdit_over->setText(
        QString("%L1").arg(controller_credit_.GetOverpayment(), 0, 'f', 2));
    ui_->lineEdit_total->setText(
        QString("%L1").arg(controller_credit_.GetTotalPayment(), 0, 'f', 2));
  } else {
    controller_credit_.CalcDifferentiated();

    ui_->lineEdit_month->setText(
        QString("%L1").arg(controller_credit_.GetFirstPayment(), 0, 'f', 2) +
        ".." +
        QString("%L1").arg(controller_credit_.GetLastPayment(), 0, 'f', 2));
    ui_->lineEdit_over->setText(
        QString("%L1").arg(controller_credit_.GetOverpayment(), 0, 'f', 2));
    ui_->lineEdit_total->setText(
        QString("%L1").arg(controller_credit_.GetTotalPayment(), 0, 'f', 2));
  }
}

}  // namespace s21