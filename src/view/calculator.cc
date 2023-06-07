#include "calculator.h"

#include <QRegularExpression>
#include <QRegularExpressionValidator>

#include "model/expression.h"
#include "ui_calculator.h"

namespace s21 {
Calculator::Calculator(QWidget *parent)
    : QWidget(parent), ui_(new Ui::Calculator) {
  ui_->setupUi(this);
  ui_->customPlot->setStyleSheet("border:10px solid #000");

  foreach (QPushButton *button, findChildren<QPushButton *>()) {
    QGraphicsDropShadowEffect *effect = new QGraphicsDropShadowEffect(button);
    effect->setColor(QColor(0, 0, 0, 255));
    effect->setXOffset(5);
    effect->setYOffset(5);

    button->setGraphicsEffect(effect);
  }

  connect(ui_->pushButton_0, SIGNAL(clicked()), this,
          SLOT(buttonInput_clicked()));
  connect(ui_->pushButton_1, SIGNAL(clicked()), this,
          SLOT(buttonInput_clicked()));
  connect(ui_->pushButton_2, SIGNAL(clicked()), this,
          SLOT(buttonInput_clicked()));
  connect(ui_->pushButton_3, SIGNAL(clicked()), this,
          SLOT(buttonInput_clicked()));
  connect(ui_->pushButton_4, SIGNAL(clicked()), this,
          SLOT(buttonInput_clicked()));
  connect(ui_->pushButton_5, SIGNAL(clicked()), this,
          SLOT(buttonInput_clicked()));
  connect(ui_->pushButton_6, SIGNAL(clicked()), this,
          SLOT(buttonInput_clicked()));
  connect(ui_->pushButton_7, SIGNAL(clicked()), this,
          SLOT(buttonInput_clicked()));
  connect(ui_->pushButton_8, SIGNAL(clicked()), this,
          SLOT(buttonInput_clicked()));
  connect(ui_->pushButton_9, SIGNAL(clicked()), this,
          SLOT(buttonInput_clicked()));
  connect(ui_->pushButton_dot, SIGNAL(clicked()), this,
          SLOT(buttonInput_clicked()));
  connect(ui_->pushButton_x, SIGNAL(clicked()), this,
          SLOT(buttonInput_clicked()));

  connect(ui_->pushButton_pow, SIGNAL(clicked()), this,
          SLOT(buttonInput_clicked()));
  connect(ui_->pushButton_mod, SIGNAL(clicked()), this,
          SLOT(buttonInput_clicked()));
  connect(ui_->pushButton_cos, SIGNAL(clicked()), this,
          SLOT(buttonInput_clicked()));
  connect(ui_->pushButton_sin, SIGNAL(clicked()), this,
          SLOT(buttonInput_clicked()));
  connect(ui_->pushButton_tan, SIGNAL(clicked()), this,
          SLOT(buttonInput_clicked()));
  connect(ui_->pushButton_acos, SIGNAL(clicked()), this,
          SLOT(buttonInput_clicked()));
  connect(ui_->pushButton_asin, SIGNAL(clicked()), this,
          SLOT(buttonInput_clicked()));
  connect(ui_->pushButton_atan, SIGNAL(clicked()), this,
          SLOT(buttonInput_clicked()));
  connect(ui_->pushButton_sqrt, SIGNAL(clicked()), this,
          SLOT(buttonInput_clicked()));
  connect(ui_->pushButton_ln, SIGNAL(clicked()), this,
          SLOT(buttonInput_clicked()));
  connect(ui_->pushButton_log, SIGNAL(clicked()), this,
          SLOT(buttonInput_clicked()));

  connect(ui_->pushButton_mul, SIGNAL(clicked()), this,
          SLOT(buttonInput_clicked()));
  connect(ui_->pushButton_div, SIGNAL(clicked()), this,
          SLOT(buttonInput_clicked()));
  connect(ui_->pushButton_minus, SIGNAL(clicked()), this,
          SLOT(buttonInput_clicked()));
  connect(ui_->pushButton_plus, SIGNAL(clicked()), this,
          SLOT(buttonInput_clicked()));

  connect(ui_->pushButton_openBracket, SIGNAL(clicked()), this,
          SLOT(buttonInput_clicked()));
  connect(ui_->pushButton_closedBracket, SIGNAL(clicked()), this,
          SLOT(buttonInput_clicked()));

  connect(ui_->pushButton_calc, SIGNAL(clicked()), this,
          SLOT(on_calcButtonClicked()));

  connect(ui_->pushButton_ac, SIGNAL(clicked()), this, SLOT(clearInput()));
  connect(ui_->pushButton_del, SIGNAL(clicked()), this, SLOT(delLastSymbol()));
}

Calculator::~Calculator() {
  setenv("LC_NUMERIC", "C", 1);
  delete ui_;
}

void Calculator::clearInput() { ui_->lineEdit->clear(); }

void Calculator::delLastSymbol() {
  QString text = ui_->lineEdit->text();
  text.chop(1);
  ui_->lineEdit->setText(text);
}

void Calculator::buttonInput_clicked() {
  QPushButton *button = (QPushButton *)sender();
  QString className = button->property("class").toString();
  ui_->lineEdit->insert(button->text());
  if (className == "func") ui_->lineEdit->insert("(");
}

void Calculator::on_calcButtonClicked() {
  QString expression_str = ui_->lineEdit->text();
  QByteArray ba = expression_str.toLocal8Bit();
  std::string expression = ba.data();
  controller_.SetExpression(expression);
  double x_ = ui_->doubleSpinBox->value();
  if (controller_.IsValidExpression()) {
    ui_->lineEdit->setText(QString::number(controller_.Calculate(x_)));
  } else {
    ui_->lineEdit->setText("Error");
  }
}

void Calculator::on_pushButton_graph_clicked() {
  QString expressionLine = ui_->lineEdit->text();
  QByteArray ba = expressionLine.toLocal8Bit();

  std::string expression = ba.data();
  controller_.SetExpression(expression);

  if (controller_.IsValidExpression()) {
    ui_->customPlot->clearGraphs();
    x_.clear();
    y_.clear();
    h_ = 0.1;
    xBegin_ = ui_->spinBox_xMin->value();
    xEnd_ = ui_->spinBox_xMax->value() + h_;
    ui_->customPlot->xAxis->setRange(ui_->spinBox_xMin->value(),
                                     ui_->spinBox_xMax->value());
    ui_->customPlot->yAxis->setRange(ui_->spinBox_yMin->value(),
                                     ui_->spinBox_yMax->value());
    X_ = xBegin_;
    N_ = (xEnd_ - xBegin_) / h_ + 2;

    int graph_counter = 0;
    int non_nun_count = 0;
    int non_nun = 0;
    for (X_ = xBegin_; X_ <= xEnd_; X_ += h_) {
      x_.push_back(X_);
      y_.push_back(controller_.Calculate(X_));
    }
    ui_->customPlot->addGraph();
    ui_->customPlot->graph(0)->setPen(QPen(Qt::black));
    ui_->customPlot->graph(0)->addData(x_, y_);
    ui_->customPlot->replot();
  } else {
    ui_->lineEdit->setText("Error");
    ui_->customPlot->clearGraphs();
    ui_->customPlot->replot();
  }
}

}  // namespace s21