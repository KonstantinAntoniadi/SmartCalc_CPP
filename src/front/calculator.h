#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QWidget>
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

  QVector<double> x, y;
};

#endif  // CALCULATOR_H
