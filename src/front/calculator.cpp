#include "calculator.h"

#include <QRegularExpression>
#include <QRegularExpressionValidator>

#include "../backend/calc.c"
#include "../backend/checkFuncs.c"
#include "../backend/getPostfix.c"
#include "../backend/processFuncs.c"
#include "../backend/stacks/number.c"
#include "../backend/stacks/operation.c"
#include "../backend/validateFunc.c"
#include "../backend/validateOperator.c"
#include "../backend/validateRPN.c"
#include "ui_calculator.h"

Calculator::Calculator(QWidget *parent)
    : QWidget(parent), ui(new Ui::Calculator) {
  ui->setupUi(this);
  ui->customPlot->setStyleSheet("border:10px solid #000");

  foreach (QPushButton *button, findChildren<QPushButton *>()) {
    QGraphicsDropShadowEffect *effect = new QGraphicsDropShadowEffect(button);
    effect->setColor(QColor(0, 0, 0, 255));
    effect->setXOffset(5);
    effect->setYOffset(5);

    button->setGraphicsEffect(effect);
  }

  connect(ui->pushButton_0, SIGNAL(clicked()), this,
          SLOT(buttonInput_clicked()));
  connect(ui->pushButton_1, SIGNAL(clicked()), this,
          SLOT(buttonInput_clicked()));
  connect(ui->pushButton_2, SIGNAL(clicked()), this,
          SLOT(buttonInput_clicked()));
  connect(ui->pushButton_3, SIGNAL(clicked()), this,
          SLOT(buttonInput_clicked()));
  connect(ui->pushButton_4, SIGNAL(clicked()), this,
          SLOT(buttonInput_clicked()));
  connect(ui->pushButton_5, SIGNAL(clicked()), this,
          SLOT(buttonInput_clicked()));
  connect(ui->pushButton_6, SIGNAL(clicked()), this,
          SLOT(buttonInput_clicked()));
  connect(ui->pushButton_7, SIGNAL(clicked()), this,
          SLOT(buttonInput_clicked()));
  connect(ui->pushButton_8, SIGNAL(clicked()), this,
          SLOT(buttonInput_clicked()));
  connect(ui->pushButton_9, SIGNAL(clicked()), this,
          SLOT(buttonInput_clicked()));
  connect(ui->pushButton_dot, SIGNAL(clicked()), this,
          SLOT(buttonInput_clicked()));
  connect(ui->pushButton_x, SIGNAL(clicked()), this,
          SLOT(buttonInput_clicked()));

  connect(ui->pushButton_pow, SIGNAL(clicked()), this,
          SLOT(buttonInput_clicked()));
  connect(ui->pushButton_mod, SIGNAL(clicked()), this,
          SLOT(buttonInput_clicked()));
  connect(ui->pushButton_cos, SIGNAL(clicked()), this,
          SLOT(buttonInput_clicked()));
  connect(ui->pushButton_sin, SIGNAL(clicked()), this,
          SLOT(buttonInput_clicked()));
  connect(ui->pushButton_tan, SIGNAL(clicked()), this,
          SLOT(buttonInput_clicked()));
  connect(ui->pushButton_acos, SIGNAL(clicked()), this,
          SLOT(buttonInput_clicked()));
  connect(ui->pushButton_asin, SIGNAL(clicked()), this,
          SLOT(buttonInput_clicked()));
  connect(ui->pushButton_atan, SIGNAL(clicked()), this,
          SLOT(buttonInput_clicked()));
  connect(ui->pushButton_sqrt, SIGNAL(clicked()), this,
          SLOT(buttonInput_clicked()));
  connect(ui->pushButton_ln, SIGNAL(clicked()), this,
          SLOT(buttonInput_clicked()));
  connect(ui->pushButton_log, SIGNAL(clicked()), this,
          SLOT(buttonInput_clicked()));

  connect(ui->pushButton_mul, SIGNAL(clicked()), this,
          SLOT(buttonInput_clicked()));
  connect(ui->pushButton_div, SIGNAL(clicked()), this,
          SLOT(buttonInput_clicked()));
  connect(ui->pushButton_minus, SIGNAL(clicked()), this,
          SLOT(buttonInput_clicked()));
  connect(ui->pushButton_plus, SIGNAL(clicked()), this,
          SLOT(buttonInput_clicked()));

  connect(ui->pushButton_openBracket, SIGNAL(clicked()), this,
          SLOT(buttonInput_clicked()));
  connect(ui->pushButton_closedBracket, SIGNAL(clicked()), this,
          SLOT(buttonInput_clicked()));

  connect(ui->pushButton_calc, SIGNAL(clicked()), this,
          SLOT(on_calcButtonClicked()));

  connect(ui->pushButton_ac, SIGNAL(clicked()), this, SLOT(clearInput()));
  connect(ui->pushButton_del, SIGNAL(clicked()), this, SLOT(delLastSymbol()));
}

Calculator::~Calculator() {
  setenv("LC_NUMERIC", "C", 1);
  delete ui;
}

void Calculator::clearInput() { ui->lineEdit->clear(); }

void Calculator::delLastSymbol() {
  QString text = ui->lineEdit->text();
  text.chop(1);
  ui->lineEdit->setText(text);
}

void Calculator::buttonInput_clicked() {
  QPushButton *button = (QPushButton *)sender();
  QString className = button->property("class").toString();
  ui->lineEdit->insert(button->text());
  if (className == "func") ui->lineEdit->insert("(");
}

void Calculator::on_calcButtonClicked() {
  QString expressionLine = ui->lineEdit->text();
  QByteArray ba = expressionLine.toLocal8Bit();
  char *expression = ba.data();
  char polish[512] = {0};
  int good = getPostfix(expression, polish);
  if (good) {
    double x = ui->doubleSpinBox->value();
    double res = 0;
    good = calculate(polish, x, &res);
    if (good)
      ui->lineEdit->setText(QString::number(res));
    else
      ui->lineEdit->setText("Error");
  } else {
    ui->lineEdit->setText("Error");
  }
}

void Calculator::on_lineEdit_textChanged(const QString &arg1) {
  if (arg1 == ')') ui->lineEdit->setText("+");
}

void Calculator::on_lineEdit_textEdited(const QString &arg1) {
  if (arg1 == '(') ui->lineEdit->setText("-");
}

void Calculator::on_pushButton_graph_clicked() {
  QString expressionLine = ui->lineEdit->text();
  QByteArray ba = expressionLine.toLocal8Bit();
  char *expression = ba.data();
  char polish[512] = {0};

  if (getPostfix(expression, polish)) {
    ui->customPlot->clearGraphs();
    x.clear();
    y.clear();
    h = 0.1;
    xBegin = ui->spinBox_xMin->value();
    xEnd = ui->spinBox_xMax->value() + h;
    ui->customPlot->xAxis->setRange(ui->spinBox_xMin->value(),
                                    ui->spinBox_xMax->value());
    ui->customPlot->yAxis->setRange(ui->spinBox_yMin->value(),
                                    ui->spinBox_yMax->value());
    X = xBegin;
    N = (xEnd - xBegin) / h + 2;

    int graph_counter = 0;
    int non_nun_count = 0;
    int non_nun = 0;
    int good_to_go = SUCCSESS;
    double res = 0;
    for (X = xBegin; X <= xEnd && good_to_go; X += h) {
      x.push_back(X);
      good_to_go = calculate(polish, X, &res);
      if (good_to_go) y.push_back(res);
    }
    ui->customPlot->addGraph();
    ui->customPlot->graph(0)->setPen(QPen(Qt::black));
    ui->customPlot->graph(0)->addData(x, y);
    ui->customPlot->replot();
    if (!good_to_go) ui->lineEdit->setText("Error");
  } else {
    ui->lineEdit->setText("Error");
    ui->customPlot->clearGraphs();
    ui->customPlot->replot();
  }
}
