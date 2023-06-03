#ifndef CPP_SMART_CALC_V2_SRC_VIEW_MAINWINDOW_H
#define CPP_SMART_CALC_V2_SRC_VIEW_MAINWINDOW_H

#include <QMainWindow>
#include <QVector>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

namespace s21 {
class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

 private slots:
  void on_actionCredit_triggered();

 private slots:
  void on_actionCalculator_triggered();

 private slots:

 private:
  Ui::MainWindow *ui;
};
}  // namespace s21

#endif  // CPP_SMART_CALC_V2_SRC_VIEW_MAINWINDOW_H
