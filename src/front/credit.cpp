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
  if (mode == 0) {
    double month = monthAnnuity(loan, period, rate);
    double total = month * period;
    double overpayment = total - loan;

    ui->lineEdit_month->setText(QString("%L1").arg(month, 0, 'f', 2));
    ui->lineEdit_over->setText(QString("%L1").arg(overpayment, 0, 'f', 2));
    ui->lineEdit_total->setText(QString("%L1").arg(total, 0, 'f', 2));
  } else {
    QDate date_current = QDate::currentDate();
    QDate date_finish = date_current.addMonths(period);

    double Sn = loan / period;
    double payment = Sn + loan * rate / 100 *
                              (date_current.daysInYear() / 12.0) /
                              date_current.daysInYear();
    double first = payment;
    double total = payment;
    for (int i = 1; i < period; i++) {
      payment = Sn + (loan - i * Sn) * rate / 100 *
                         (date_current.daysInYear() / 12.0) /
                         date_current.daysInYear();
      total += payment;
      date_current = date_current.addMonths(1);
    }

    double last = payment;
    ui->lineEdit_month->setText(QString("%L1").arg(first, 0, 'f', 2) + ".." +
                                QString("%L1").arg(last, 0, 'f', 2));
    ui->lineEdit_over->setText(QString("%L1").arg(total - loan, 0, 'f', 2));
    ui->lineEdit_total->setText(QString("%L1").arg(total, 0, 'f', 2));
  }
}
