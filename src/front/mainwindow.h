#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVector>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

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
#endif  // MAINWINDOW_H
