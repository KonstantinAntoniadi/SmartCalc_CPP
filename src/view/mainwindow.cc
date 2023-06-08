#include "mainwindow.h"

#include <QRegularExpression>
#include <QRegularExpressionValidator>

#include "./ui_mainwindow.h"
#include "calculator.h"
#include "credit.h"

namespace s21 {
MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent), ui_(new Ui::MainWindow) {
  ui_->setupUi(this);
  ui_->stackedWidget->addWidget(new Calculator());
  ui_->stackedWidget->addWidget(new Credit());
  this->setFixedSize(1080, 510);
}

MainWindow::~MainWindow() { delete ui_; }

void MainWindow::on_actionCalculator_triggered() {
  ui_->stackedWidget->setCurrentIndex(0);
  this->setFixedSize(1080, 510);
}

void MainWindow::on_actionCredit_triggered() {
  ui_->stackedWidget->setCurrentIndex(1);
  this->setFixedSize(750, 300);
}
}  // namespace s21
