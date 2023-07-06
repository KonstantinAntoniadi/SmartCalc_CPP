#ifndef SMARTCALC_CPP_SRC_VIEW_CREDIT_H
#define SMARTCALC_CPP_SRC_VIEW_CREDIT_H

#include <QWidget>

#include "../controller/controllercredit.h"
namespace Ui {
class Credit;
}

class Credit : public QWidget {
  Q_OBJECT

 public:
  explicit Credit(QWidget *parent = nullptr);
  ~Credit();

 private slots:
  void on_pushButton_calculate_clicked();

 private:
  Ui::Credit *ui_;
  ControllerCredit controller_credit_{};
};

#endif  // SMARTCALC_CPP_SRC_VIEW_CREDIT_H
