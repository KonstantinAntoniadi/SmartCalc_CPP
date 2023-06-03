#include "mainwindow.h"

#include <QRegularExpression>
#include <QRegularExpressionValidator>

#include "./ui_mainwindow.h"
#include "calculator.h"
#include "credit.h"

namespace s21 {
MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
  Calculator* calculator = new Calculator();
  ui->stackedWidget->addWidget(calculator);
  ui->stackedWidget->addWidget(new Credit());
  this->setFixedSize(1080, 510);
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::on_actionCalculator_triggered() {
  ui->stackedWidget->setCurrentIndex(0);
  this->setFixedSize(1080, 510);
}

void MainWindow::on_actionCredit_triggered() {
  ui->stackedWidget->setCurrentIndex(1);
  this->setFixedSize(750, 300);
}
}  // namespace s21
