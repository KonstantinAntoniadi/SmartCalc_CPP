#ifndef CPP_SMART_CALC_V2_SRC_VIEW_CREDIT_H
#define CPP_SMART_CALC_V2_SRC_VIEW_CREDIT_H

#include <QWidget>

#include "../controller/controllercredit.h"
namespace Ui {
class Credit;
}

namespace s21 {
class Credit : public QWidget {
  Q_OBJECT

 public:
  explicit Credit(QWidget *parent = nullptr);
  ~Credit();

 private slots:
  void on_pushButton_calculate_clicked();

 private:
  Ui::Credit *ui;
  s21::ControllerCredit controller_credit_{};
};
}  // namespace s21

#endif  // CPP_SMART_CALC_V2_SRC_VIEW_CREDIT_H
