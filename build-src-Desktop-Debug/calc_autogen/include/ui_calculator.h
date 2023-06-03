/********************************************************************************
** Form generated from reading UI file 'calculator.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CALCULATOR_H
#define UI_CALCULATOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>
#include "view/qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_Calculator
{
public:
    QSpinBox *spinBox_xMin;
    QSpinBox *spinBox_xMax;
    QSpinBox *spinBox_yMax;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QPushButton *pushButton_6;
    QPushButton *pushButton_8;
    QPushButton *pushButton_dot;
    QPushButton *pushButton_7;
    QPushButton *pushButton_4;
    QPushButton *pushButton_9;
    QPushButton *pushButton_pow;
    QPushButton *pushButton_1;
    QPushButton *pushButton_5;
    QPushButton *pushButton_2;
    QPushButton *pushButton_0;
    QPushButton *pushButton_3;
    QPushButton *pushButton_openBracket;
    QPushButton *pushButton_closedBracket;
    QPushButton *pushButton_plus;
    QPushButton *pushButton_minus;
    QPushButton *pushButton_div;
    QPushButton *pushButton_mul;
    QWidget *gridLayoutWidget_2;
    QGridLayout *gridLayout_3;
    QPushButton *pushButton_acos;
    QPushButton *pushButton_log;
    QPushButton *pushButton_cos;
    QPushButton *pushButton_tan;
    QPushButton *pushButton_sin;
    QPushButton *pushButton_ln;
    QPushButton *pushButton_atan;
    QPushButton *pushButton_asin;
    QPushButton *pushButton_mod;
    QPushButton *pushButton_sqrt;
    QPushButton *pushButton_graph;
    QSpinBox *spinBox_yMin;
    QFrame *frame;
    QCustomPlot *customPlot;
    QWidget *gridLayoutWidget_3;
    QGridLayout *gridLayout_2;
    QPushButton *pushButton_calc;
    QPushButton *pushButton_x;
    QPushButton *pushButton_del;
    QPushButton *pushButton_ac;
    QDoubleSpinBox *doubleSpinBox;
    QLineEdit *lineEdit;

    void setupUi(QWidget *Calculator)
    {
        if (Calculator->objectName().isEmpty())
            Calculator->setObjectName(QString::fromUtf8("Calculator"));
        Calculator->resize(1450, 550);
        QFont font;
        font.setFamily(QString::fromUtf8("Pet Me"));
        Calculator->setFont(font);
        Calculator->setStyleSheet(QString::fromUtf8("QPushButton:pressed{\n"
"border:3px solid #FFF;\n"
"background-image: none;\n"
"background-color: #000; \n"
"font: 500 13pt \"Pet Me\";\n"
"color: #FFF;\n"
"}\n"
"\n"
"QPushButton, QLineEdit{\n"
"border:3px solid #000;\n"
"background-color: #FFF;\n"
"background-image: none;\n"
"font: 500 13pt \"Pet Me\";\n"
"color: #000;\n"
"}\n"
"\n"
"QDoubleSpinBox::up-button, QSpinBox::up-button{\n"
"    min-width:30px;\n"
"    min-height: 15px;\n"
"}\n"
"\n"
"QDoubleSpinBox::down-button, QSpinBox::down-button{\n"
"    min-width:30px;\n"
"    min-height: 15px;\n"
"}\n"
"\n"
"QDoubleSpinBox, QSpinBox{\n"
"background-color: #FFF;\n"
"border:3px solid #000;\n"
"font: 500 13pt \"Pet Me\";\n"
"color: #000;\n"
"}\n"
"\n"
"QFrame{\n"
"border:3px solid #000;\n"
"}\n"
"\n"
"\n"
""));
        spinBox_xMin = new QSpinBox(Calculator);
        spinBox_xMin->setObjectName(QString::fromUtf8("spinBox_xMin"));
        spinBox_xMin->setGeometry(QRect(615, 390, 91, 50));
        spinBox_xMin->setMinimum(-1000000);
        spinBox_xMin->setMaximum(1000000);
        spinBox_xMin->setSingleStep(10);
        spinBox_xMin->setValue(-50);
        spinBox_xMax = new QSpinBox(Calculator);
        spinBox_xMax->setObjectName(QString::fromUtf8("spinBox_xMax"));
        spinBox_xMax->setGeometry(QRect(965, 390, 101, 50));
        spinBox_xMax->setMinimum(-1000000);
        spinBox_xMax->setMaximum(1000000);
        spinBox_xMax->setSingleStep(10);
        spinBox_xMax->setValue(50);
        spinBox_yMax = new QSpinBox(Calculator);
        spinBox_yMax->setObjectName(QString::fromUtf8("spinBox_yMax"));
        spinBox_yMax->setGeometry(QRect(495, 90, 91, 50));
        spinBox_yMax->setMinimum(-1000000);
        spinBox_yMax->setMaximum(1000000);
        spinBox_yMax->setSingleStep(10);
        spinBox_yMax->setValue(50);
        gridLayoutWidget = new QWidget(Calculator);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(190, 160, 242, 321));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        gridLayout->setHorizontalSpacing(10);
        gridLayout->setVerticalSpacing(5);
        gridLayout->setContentsMargins(0, 0, 5, 5);
        pushButton_6 = new QPushButton(gridLayoutWidget);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        pushButton_6->setMinimumSize(QSize(50, 50));

        gridLayout->addWidget(pushButton_6, 2, 2, 1, 1);

        pushButton_8 = new QPushButton(gridLayoutWidget);
        pushButton_8->setObjectName(QString::fromUtf8("pushButton_8"));
        pushButton_8->setMinimumSize(QSize(50, 50));

        gridLayout->addWidget(pushButton_8, 1, 1, 1, 1);

        pushButton_dot = new QPushButton(gridLayoutWidget);
        pushButton_dot->setObjectName(QString::fromUtf8("pushButton_dot"));
        pushButton_dot->setMinimumSize(QSize(50, 50));

        gridLayout->addWidget(pushButton_dot, 5, 2, 1, 1);

        pushButton_7 = new QPushButton(gridLayoutWidget);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));
        pushButton_7->setMinimumSize(QSize(50, 50));

        gridLayout->addWidget(pushButton_7, 1, 0, 1, 1);

        pushButton_4 = new QPushButton(gridLayoutWidget);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setMinimumSize(QSize(50, 50));

        gridLayout->addWidget(pushButton_4, 2, 0, 1, 1);

        pushButton_9 = new QPushButton(gridLayoutWidget);
        pushButton_9->setObjectName(QString::fromUtf8("pushButton_9"));
        pushButton_9->setMinimumSize(QSize(50, 50));

        gridLayout->addWidget(pushButton_9, 1, 2, 1, 1);

        pushButton_pow = new QPushButton(gridLayoutWidget);
        pushButton_pow->setObjectName(QString::fromUtf8("pushButton_pow"));
        pushButton_pow->setMinimumSize(QSize(50, 50));
        pushButton_pow->setStyleSheet(QString::fromUtf8(""));

        gridLayout->addWidget(pushButton_pow, 0, 2, 1, 1);

        pushButton_1 = new QPushButton(gridLayoutWidget);
        pushButton_1->setObjectName(QString::fromUtf8("pushButton_1"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButton_1->sizePolicy().hasHeightForWidth());
        pushButton_1->setSizePolicy(sizePolicy);
        pushButton_1->setMinimumSize(QSize(50, 50));
        pushButton_1->setStyleSheet(QString::fromUtf8(""));
        pushButton_1->setCheckable(true);
        pushButton_1->setAutoDefault(false);
        pushButton_1->setFlat(false);

        gridLayout->addWidget(pushButton_1, 4, 0, 1, 1);

        pushButton_5 = new QPushButton(gridLayoutWidget);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setMinimumSize(QSize(50, 50));

        gridLayout->addWidget(pushButton_5, 2, 1, 1, 1);

        pushButton_2 = new QPushButton(gridLayoutWidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setMinimumSize(QSize(50, 50));

        gridLayout->addWidget(pushButton_2, 4, 1, 1, 1);

        pushButton_0 = new QPushButton(gridLayoutWidget);
        pushButton_0->setObjectName(QString::fromUtf8("pushButton_0"));
        pushButton_0->setMinimumSize(QSize(50, 50));

        gridLayout->addWidget(pushButton_0, 5, 0, 1, 2);

        pushButton_3 = new QPushButton(gridLayoutWidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setMinimumSize(QSize(50, 50));

        gridLayout->addWidget(pushButton_3, 4, 2, 1, 1);

        pushButton_openBracket = new QPushButton(gridLayoutWidget);
        pushButton_openBracket->setObjectName(QString::fromUtf8("pushButton_openBracket"));
        pushButton_openBracket->setMinimumSize(QSize(50, 50));

        gridLayout->addWidget(pushButton_openBracket, 0, 0, 1, 1);

        pushButton_closedBracket = new QPushButton(gridLayoutWidget);
        pushButton_closedBracket->setObjectName(QString::fromUtf8("pushButton_closedBracket"));
        pushButton_closedBracket->setMinimumSize(QSize(50, 50));

        gridLayout->addWidget(pushButton_closedBracket, 0, 1, 1, 1);

        pushButton_plus = new QPushButton(gridLayoutWidget);
        pushButton_plus->setObjectName(QString::fromUtf8("pushButton_plus"));
        pushButton_plus->setMinimumSize(QSize(50, 50));
        pushButton_plus->setStyleSheet(QString::fromUtf8(""));

        gridLayout->addWidget(pushButton_plus, 5, 3, 1, 1);

        pushButton_minus = new QPushButton(gridLayoutWidget);
        pushButton_minus->setObjectName(QString::fromUtf8("pushButton_minus"));
        pushButton_minus->setMinimumSize(QSize(50, 50));
        pushButton_minus->setStyleSheet(QString::fromUtf8(""));

        gridLayout->addWidget(pushButton_minus, 4, 3, 1, 1);

        pushButton_div = new QPushButton(gridLayoutWidget);
        pushButton_div->setObjectName(QString::fromUtf8("pushButton_div"));
        pushButton_div->setMinimumSize(QSize(50, 50));
        pushButton_div->setStyleSheet(QString::fromUtf8(""));

        gridLayout->addWidget(pushButton_div, 2, 3, 1, 1);

        pushButton_mul = new QPushButton(gridLayoutWidget);
        pushButton_mul->setObjectName(QString::fromUtf8("pushButton_mul"));
        pushButton_mul->setMinimumSize(QSize(50, 50));
        pushButton_mul->setStyleSheet(QString::fromUtf8(""));

        gridLayout->addWidget(pushButton_mul, 1, 3, 1, 1);

        gridLayout->setRowStretch(0, 1);
        gridLayoutWidget_2 = new QWidget(Calculator);
        gridLayoutWidget_2->setObjectName(QString::fromUtf8("gridLayoutWidget_2"));
        gridLayoutWidget_2->setGeometry(QRect(30, 160, 131, 321));
        gridLayout_3 = new QGridLayout(gridLayoutWidget_2);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setSizeConstraint(QLayout::SetDefaultConstraint);
        gridLayout_3->setHorizontalSpacing(10);
        gridLayout_3->setVerticalSpacing(5);
        gridLayout_3->setContentsMargins(0, 0, 5, 5);
        pushButton_acos = new QPushButton(gridLayoutWidget_2);
        pushButton_acos->setObjectName(QString::fromUtf8("pushButton_acos"));
        pushButton_acos->setMinimumSize(QSize(50, 50));

        gridLayout_3->addWidget(pushButton_acos, 2, 0, 1, 1);

        pushButton_log = new QPushButton(gridLayoutWidget_2);
        pushButton_log->setObjectName(QString::fromUtf8("pushButton_log"));
        pushButton_log->setMinimumSize(QSize(50, 50));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Pet Me"));
        font1.setPointSize(13);
        font1.setBold(true);
        font1.setItalic(false);
        font1.setWeight(62);
        pushButton_log->setFont(font1);

        gridLayout_3->addWidget(pushButton_log, 4, 1, 1, 1);

        pushButton_cos = new QPushButton(gridLayoutWidget_2);
        pushButton_cos->setObjectName(QString::fromUtf8("pushButton_cos"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(pushButton_cos->sizePolicy().hasHeightForWidth());
        pushButton_cos->setSizePolicy(sizePolicy1);
        pushButton_cos->setMinimumSize(QSize(50, 50));

        gridLayout_3->addWidget(pushButton_cos, 1, 0, 1, 1);

        pushButton_tan = new QPushButton(gridLayoutWidget_2);
        pushButton_tan->setObjectName(QString::fromUtf8("pushButton_tan"));
        pushButton_tan->setMinimumSize(QSize(50, 50));

        gridLayout_3->addWidget(pushButton_tan, 3, 0, 1, 1);

        pushButton_sin = new QPushButton(gridLayoutWidget_2);
        pushButton_sin->setObjectName(QString::fromUtf8("pushButton_sin"));
        pushButton_sin->setMinimumSize(QSize(50, 50));

        gridLayout_3->addWidget(pushButton_sin, 1, 1, 1, 1);

        pushButton_ln = new QPushButton(gridLayoutWidget_2);
        pushButton_ln->setObjectName(QString::fromUtf8("pushButton_ln"));
        pushButton_ln->setMinimumSize(QSize(50, 50));

        gridLayout_3->addWidget(pushButton_ln, 4, 0, 1, 1);

        pushButton_atan = new QPushButton(gridLayoutWidget_2);
        pushButton_atan->setObjectName(QString::fromUtf8("pushButton_atan"));
        pushButton_atan->setMinimumSize(QSize(50, 50));

        gridLayout_3->addWidget(pushButton_atan, 3, 1, 1, 1);

        pushButton_asin = new QPushButton(gridLayoutWidget_2);
        pushButton_asin->setObjectName(QString::fromUtf8("pushButton_asin"));
        QSizePolicy sizePolicy2(QSizePolicy::MinimumExpanding, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(pushButton_asin->sizePolicy().hasHeightForWidth());
        pushButton_asin->setSizePolicy(sizePolicy2);
        pushButton_asin->setMinimumSize(QSize(50, 50));

        gridLayout_3->addWidget(pushButton_asin, 2, 1, 1, 1);

        pushButton_mod = new QPushButton(gridLayoutWidget_2);
        pushButton_mod->setObjectName(QString::fromUtf8("pushButton_mod"));
        pushButton_mod->setMinimumSize(QSize(50, 50));
        pushButton_mod->setStyleSheet(QString::fromUtf8(""));

        gridLayout_3->addWidget(pushButton_mod, 0, 0, 1, 1);

        pushButton_sqrt = new QPushButton(gridLayoutWidget_2);
        pushButton_sqrt->setObjectName(QString::fromUtf8("pushButton_sqrt"));
        sizePolicy.setHeightForWidth(pushButton_sqrt->sizePolicy().hasHeightForWidth());
        pushButton_sqrt->setSizePolicy(sizePolicy);
        pushButton_sqrt->setMinimumSize(QSize(50, 50));

        gridLayout_3->addWidget(pushButton_sqrt, 0, 1, 1, 1);

        gridLayout_3->setRowStretch(0, 1);
        pushButton_graph = new QPushButton(Calculator);
        pushButton_graph->setObjectName(QString::fromUtf8("pushButton_graph"));
        pushButton_graph->setGeometry(QRect(495, 20, 91, 51));
        spinBox_yMin = new QSpinBox(Calculator);
        spinBox_yMin->setObjectName(QString::fromUtf8("spinBox_yMin"));
        spinBox_yMin->setGeometry(QRect(505, 330, 91, 50));
        spinBox_yMin->setMinimum(-1000000);
        spinBox_yMin->setMaximum(1000000);
        spinBox_yMin->setSingleStep(10);
        spinBox_yMin->setValue(-50);
        frame = new QFrame(Calculator);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(615, 20, 447, 357));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        customPlot = new QCustomPlot(frame);
        customPlot->setObjectName(QString::fromUtf8("customPlot"));
        customPlot->setGeometry(QRect(3, 3, 441, 351));
        gridLayoutWidget_3 = new QWidget(Calculator);
        gridLayoutWidget_3->setObjectName(QString::fromUtf8("gridLayoutWidget_3"));
        gridLayoutWidget_3->setGeometry(QRect(30, 10, 411, 71));
        gridLayout_2 = new QGridLayout(gridLayoutWidget_3);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 11, 0);
        pushButton_calc = new QPushButton(gridLayoutWidget_3);
        pushButton_calc->setObjectName(QString::fromUtf8("pushButton_calc"));
        pushButton_calc->setMinimumSize(QSize(50, 50));
        pushButton_calc->setMouseTracking(false);
        pushButton_calc->setToolTipDuration(0);

        gridLayout_2->addWidget(pushButton_calc, 0, 4, 1, 1);

        pushButton_x = new QPushButton(gridLayoutWidget_3);
        pushButton_x->setObjectName(QString::fromUtf8("pushButton_x"));
        pushButton_x->setMinimumSize(QSize(50, 50));

        gridLayout_2->addWidget(pushButton_x, 0, 0, 1, 1);

        pushButton_del = new QPushButton(gridLayoutWidget_3);
        pushButton_del->setObjectName(QString::fromUtf8("pushButton_del"));
        pushButton_del->setMinimumSize(QSize(50, 50));

        gridLayout_2->addWidget(pushButton_del, 0, 3, 1, 1);

        pushButton_ac = new QPushButton(gridLayoutWidget_3);
        pushButton_ac->setObjectName(QString::fromUtf8("pushButton_ac"));
        pushButton_ac->setMinimumSize(QSize(50, 50));

        gridLayout_2->addWidget(pushButton_ac, 0, 2, 1, 1);

        doubleSpinBox = new QDoubleSpinBox(gridLayoutWidget_3);
        doubleSpinBox->setObjectName(QString::fromUtf8("doubleSpinBox"));
        doubleSpinBox->setMinimumSize(QSize(50, 50));
        doubleSpinBox->setMinimum(-999999999.000000000000000);
        doubleSpinBox->setMaximum(9999999999.000000000000000);
        doubleSpinBox->setStepType(QAbstractSpinBox::AdaptiveDecimalStepType);
        doubleSpinBox->setValue(21.000000000000000);

        gridLayout_2->addWidget(doubleSpinBox, 0, 1, 1, 1);

        lineEdit = new QLineEdit(Calculator);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(30, 90, 400, 50));
        lineEdit->setMouseTracking(true);
        lineEdit->setTabletTracking(false);
        lineEdit->setFocusPolicy(Qt::StrongFocus);
        lineEdit->setMaxLength(255);
        lineEdit->setEchoMode(QLineEdit::Normal);
        lineEdit->setDragEnabled(false);
        lineEdit->setCursorMoveStyle(Qt::LogicalMoveStyle);
        lineEdit->setClearButtonEnabled(false);

        retranslateUi(Calculator);

        QMetaObject::connectSlotsByName(Calculator);
    } // setupUi

    void retranslateUi(QWidget *Calculator)
    {
        Calculator->setWindowTitle(QApplication::translate("Calculator", "Form", nullptr));
        pushButton_6->setText(QApplication::translate("Calculator", "6", nullptr));
        pushButton_6->setProperty("class", QVariant(QApplication::translate("Calculator", "digit", nullptr)));
        pushButton_8->setText(QApplication::translate("Calculator", "8", nullptr));
        pushButton_8->setProperty("class", QVariant(QApplication::translate("Calculator", "digit", nullptr)));
        pushButton_dot->setText(QApplication::translate("Calculator", ".", nullptr));
        pushButton_dot->setProperty("class", QVariant(QApplication::translate("Calculator", "digit", nullptr)));
        pushButton_7->setText(QApplication::translate("Calculator", "7", nullptr));
        pushButton_7->setProperty("class", QVariant(QApplication::translate("Calculator", "digit", nullptr)));
        pushButton_4->setText(QApplication::translate("Calculator", "4", nullptr));
        pushButton_4->setProperty("class", QVariant(QApplication::translate("Calculator", "digit", nullptr)));
        pushButton_9->setText(QApplication::translate("Calculator", "9", nullptr));
        pushButton_9->setProperty("class", QVariant(QApplication::translate("Calculator", "digit", nullptr)));
        pushButton_pow->setText(QApplication::translate("Calculator", "^", nullptr));
        pushButton_pow->setProperty("class", QVariant(QApplication::translate("Calculator", "operand", nullptr)));
        pushButton_1->setText(QApplication::translate("Calculator", "1", nullptr));
        pushButton_1->setProperty("class", QVariant(QApplication::translate("Calculator", "digit", nullptr)));
        pushButton_5->setText(QApplication::translate("Calculator", "5", nullptr));
        pushButton_5->setProperty("class", QVariant(QApplication::translate("Calculator", "digit", nullptr)));
        pushButton_2->setText(QApplication::translate("Calculator", "2", nullptr));
        pushButton_2->setProperty("class", QVariant(QApplication::translate("Calculator", "digit", nullptr)));
        pushButton_0->setText(QApplication::translate("Calculator", "0", nullptr));
        pushButton_0->setProperty("class", QVariant(QApplication::translate("Calculator", "digit", nullptr)));
        pushButton_3->setText(QApplication::translate("Calculator", "3", nullptr));
        pushButton_3->setProperty("class", QVariant(QApplication::translate("Calculator", "digit", nullptr)));
        pushButton_openBracket->setText(QApplication::translate("Calculator", "(", nullptr));
        pushButton_openBracket->setProperty("class", QVariant(QApplication::translate("Calculator", "brasket", nullptr)));
        pushButton_closedBracket->setText(QApplication::translate("Calculator", ")", nullptr));
        pushButton_closedBracket->setProperty("button-style", QVariant(QApplication::translate("Calculator", "ew", nullptr)));
        pushButton_closedBracket->setProperty("class", QVariant(QApplication::translate("Calculator", "brasket", nullptr)));
        pushButton_plus->setText(QApplication::translate("Calculator", "+", nullptr));
        pushButton_plus->setProperty("class", QVariant(QApplication::translate("Calculator", "operand", nullptr)));
        pushButton_minus->setText(QApplication::translate("Calculator", "-", nullptr));
        pushButton_minus->setProperty("class", QVariant(QApplication::translate("Calculator", "operand", nullptr)));
        pushButton_div->setText(QApplication::translate("Calculator", "/", nullptr));
        pushButton_div->setProperty("class", QVariant(QApplication::translate("Calculator", "operand", nullptr)));
        pushButton_mul->setText(QApplication::translate("Calculator", "*", nullptr));
        pushButton_mul->setProperty("class", QVariant(QApplication::translate("Calculator", "operand", nullptr)));
        pushButton_acos->setText(QApplication::translate("Calculator", "acos", nullptr));
        pushButton_acos->setProperty("class", QVariant(QApplication::translate("Calculator", "func", nullptr)));
        pushButton_log->setText(QApplication::translate("Calculator", "log", nullptr));
        pushButton_log->setProperty("class", QVariant(QApplication::translate("Calculator", "func", nullptr)));
        pushButton_cos->setText(QApplication::translate("Calculator", "cos", nullptr));
        pushButton_cos->setProperty("class", QVariant(QApplication::translate("Calculator", "func", nullptr)));
        pushButton_tan->setText(QApplication::translate("Calculator", "tan", nullptr));
        pushButton_tan->setProperty("class", QVariant(QApplication::translate("Calculator", "func", nullptr)));
        pushButton_sin->setText(QApplication::translate("Calculator", "sin", nullptr));
        pushButton_sin->setProperty("class", QVariant(QApplication::translate("Calculator", "func", nullptr)));
        pushButton_ln->setText(QApplication::translate("Calculator", "ln", nullptr));
        pushButton_ln->setProperty("class", QVariant(QApplication::translate("Calculator", "func", nullptr)));
        pushButton_atan->setText(QApplication::translate("Calculator", "atan", nullptr));
        pushButton_atan->setProperty("class", QVariant(QApplication::translate("Calculator", "func", nullptr)));
        pushButton_asin->setText(QApplication::translate("Calculator", "asin", nullptr));
        pushButton_asin->setProperty("class", QVariant(QApplication::translate("Calculator", "func", nullptr)));
        pushButton_mod->setText(QApplication::translate("Calculator", "mod", nullptr));
        pushButton_mod->setProperty("class", QVariant(QApplication::translate("Calculator", "operand", nullptr)));
        pushButton_sqrt->setText(QApplication::translate("Calculator", "sqrt", nullptr));
        pushButton_sqrt->setProperty("class", QVariant(QApplication::translate("Calculator", "func", nullptr)));
        pushButton_graph->setText(QApplication::translate("Calculator", "Graph", nullptr));
        pushButton_graph->setProperty("class", QVariant(QApplication::translate("Calculator", "control", nullptr)));
        pushButton_calc->setText(QApplication::translate("Calculator", "=", nullptr));
#ifndef QT_NO_SHORTCUT
        pushButton_calc->setShortcut(QApplication::translate("Calculator", "Return", nullptr));
#endif // QT_NO_SHORTCUT
        pushButton_calc->setProperty("class", QVariant(QApplication::translate("Calculator", "control", nullptr)));
        pushButton_x->setText(QApplication::translate("Calculator", "x", nullptr));
        pushButton_x->setProperty("class", QVariant(QApplication::translate("Calculator", "digit", nullptr)));
        pushButton_del->setText(QApplication::translate("Calculator", "del", nullptr));
        pushButton_del->setProperty("class", QVariant(QApplication::translate("Calculator", "control", nullptr)));
        pushButton_ac->setText(QApplication::translate("Calculator", "ac", nullptr));
        pushButton_ac->setProperty("class", QVariant(QApplication::translate("Calculator", "control", nullptr)));
        lineEdit->setText(QApplication::translate("Calculator", "0", nullptr));
        lineEdit->setPlaceholderText(QString());
    } // retranslateUi

};

namespace Ui {
    class Calculator: public Ui_Calculator {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CALCULATOR_H
