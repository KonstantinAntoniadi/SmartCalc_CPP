#ifndef SMARTCALC_CPP_SRC_VIEW_CALCULATOR_H
#define SMARTCALC_CPP_SRC_VIEW_CALCULATOR_H

#include <QWidget>

#include "../controller/controllercalculator.h"

namespace Ui {
class Calculator;
}
class Calculator : public QWidget {
  Q_OBJECT

 public:
  explicit Calculator(QWidget *parent = nullptr);
  ~Calculator();

 private slots:
  void on_pushButton_graph_clicked();

 private slots:
  void on_calcButtonClicked();
  void delLastSymbol();
  void buttonInput_clicked();
  void clearInput();

 private:
  Ui::Calculator *ui_;
  double xBegin_, xEnd_, h_, X_;
  int N_;
  ControllerCalculator controller_{};

  QVector<double> x_, y_;
};
#endif  // SMARTCALC_CPP_SRC_VIEW_CALCULATOR_H
