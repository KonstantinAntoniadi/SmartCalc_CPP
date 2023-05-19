#include "mainwindow.h"

#include <QRegularExpression>
#include <QRegularExpressionValidator>

#include "./ui_mainwindow.h"
#include "calculator.h"
#include "credit.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
  ui->stackedWidget->addWidget(new Calculator());
  ui->stackedWidget->addWidget(new Credit());
  this->setFixedSize(1080, 500);
}

MainWindow::~MainWindow() {
  setenv("LC_NUMERIC", "C", 1);

  delete ui;
}

void MainWindow::on_actionCalculator_triggered() {
  ui->stackedWidget->setCurrentIndex(0);
  this->setFixedSize(1080, 500);
}

void MainWindow::on_actionCredit_triggered() {
  ui->stackedWidget->setCurrentIndex(1);
  this->setFixedSize(750, 280);
}
