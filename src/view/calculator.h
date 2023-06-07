#ifndef CPP_SMART_CALC_V2_SRC_VIEW_CALCULATOR_H
#define CPP_SMART_CALC_V2_SRC_VIEW_CALCULATOR_H

#include <QWidget>

#include "../controller/controllercalculator.h"

namespace Ui {
class Calculator;
}
namespace s21 {
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
  s21::ControllerCalculator controller_{};

  QVector<double> x_, y_;
};
}  // namespace s21
#endif  // CPP_SMART_CALC_V2_SRC_VIEW_CALCULATOR_H
