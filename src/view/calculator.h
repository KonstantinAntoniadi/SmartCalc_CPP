#ifndef CPP_SMART_CALC_V2_SRC_VIEW_CALCULATOR_H
#define CPP_SMART_CALC_V2_SRC_VIEW_CALCULATOR_H

#include <QWidget>

#include "../controller/controllercalculator.h"
#define FAILTURE 0
#define SUCCSESS 1

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
  void on_lineEdit_textChanged(const QString &arg1);
  void on_lineEdit_textEdited(const QString &arg1);
  void delLastSymbol();
  void buttonInput_clicked();
  void clearInput();

 private:
  Ui::Calculator *ui;
  double xBegin, xEnd, h, X;
  int N;
  s21::ControllerCalculator controller_;

  QVector<double> x, y;
};

#endif  // CPP_SMART_CALC_V2_SRC_VIEW_CALCULATOR_H
