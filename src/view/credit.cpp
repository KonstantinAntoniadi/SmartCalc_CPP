#include "credit.h"

#include <QDate>

#include "../backend/credit.c"
#include "ui_credit.h"

Credit::Credit(QWidget *parent) : QWidget(parent), ui(new Ui::Credit) {
  ui->setupUi(this);
}

Credit::~Credit() { delete ui; }

void Credit::on_pushButton_calculate_clicked() {
  double loan = ui->spinBox_loan->value();
  int period = ui->spinBox_period->value();
  double rate = ui->doubleSpinBox_rate->value();
  int mode = ui->comboBox_type->currentIndex();

  controller_credit_.SetStartValues(loan, period, rate);
  if (mode == 0) {
    controller_credit_.CalcAnnuity();

    ui->lineEdit_month->setText(
        QString("%L1").arg(controller_credit_.GetMonthPayment(), 0, 'f', 2));
    ui->lineEdit_over->setText(
        QString("%L1").arg(controller_credit_.GetOverpayment(), 0, 'f', 2));
    ui->lineEdit_total->setText(
        QString("%L1").arg(controller_credit_.GetTotalPayment(), 0, 'f', 2));
  } else {
    controller_credit_.CalcDifferentiated();

    ui->lineEdit_month->setText(
        QString("%L1").arg(controller_credit_.GetFirstPayment(), 0, 'f', 2) +
        ".." +
        QString("%L1").arg(controller_credit_.GetLastPayment(), 0, 'f', 2));
    ui->lineEdit_over->setText(
        QString("%L1").arg(controller_credit_.GetOverpayment(), 0, 'f', 2));
    ui->lineEdit_total->setText(
        QString("%L1").arg(controller_credit_.GetTotalPayment(), 0, 'f', 2));
  }
}
