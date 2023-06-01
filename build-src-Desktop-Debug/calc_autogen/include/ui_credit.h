/********************************************************************************
** Form generated from reading UI file 'credit.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREDIT_H
#define UI_CREDIT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Credit
{
public:
    QPushButton *pushButton_calculate;
    QSpinBox *spinBox_loan;
    QDoubleSpinBox *doubleSpinBox_rate;
    QSpinBox *spinBox_period;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QComboBox *comboBox_type;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLineEdit *lineEdit_month;
    QLineEdit *lineEdit_over;
    QLineEdit *lineEdit_total;

    void setupUi(QWidget *Credit)
    {
        if (Credit->objectName().isEmpty())
            Credit->setObjectName(QString::fromUtf8("Credit"));
        Credit->resize(750, 280);
        Credit->setStyleSheet(QString::fromUtf8("\n"
"\n"
"QPushButton, QLineEdit, QComboBox{\n"
"border:3px solid #000;\n"
"background-color: #FFF;\n"
"background-image: none;\n"
"font: 500 13pt \"Pet Me\";\n"
"color: #000;\n"
"}\n"
"\n"
"\n"
"QPushButton:pressed{\n"
"border:3px solid #FFF;\n"
"background-image: none;\n"
"background-color: #000; \n"
"font: 500 13pt \"Pet Me\";\n"
"color: #FFF;\n"
"}\n"
"\n"
"\n"
"QDoubleSpinBox, QSpinBox{\n"
"background-color: #FFF;\n"
"border:3px solid #000;\n"
"font: 500 13pt \"Pet Me\";\n"
"color: #000;\n"
"}\n"
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
"\n"
"QLabel{\n"
"background-color: #000; \n"
"font: 500 13pt \"Pet Me\";\n"
"color: #FFF;\n"
"}\n"
""));
        pushButton_calculate = new QPushButton(Credit);
        pushButton_calculate->setObjectName(QString::fromUtf8("pushButton_calculate"));
        pushButton_calculate->setGeometry(QRect(120, 210, 141, 50));
        pushButton_calculate->setAutoFillBackground(false);
        pushButton_calculate->setStyleSheet(QString::fromUtf8(""));
        spinBox_loan = new QSpinBox(Credit);
        spinBox_loan->setObjectName(QString::fromUtf8("spinBox_loan"));
        spinBox_loan->setGeometry(QRect(120, 20, 211, 51));
        spinBox_loan->setMaximum(100000000);
        spinBox_loan->setValue(300000);
        doubleSpinBox_rate = new QDoubleSpinBox(Credit);
        doubleSpinBox_rate->setObjectName(QString::fromUtf8("doubleSpinBox_rate"));
        doubleSpinBox_rate->setGeometry(QRect(120, 120, 111, 31));
        doubleSpinBox_rate->setValue(15.000000000000000);
        spinBox_period = new QSpinBox(Credit);
        spinBox_period->setObjectName(QString::fromUtf8("spinBox_period"));
        spinBox_period->setGeometry(QRect(120, 80, 111, 31));
        spinBox_period->setMinimum(1);
        spinBox_period->setMaximum(360);
        spinBox_period->setValue(18);
        label = new QLabel(Credit);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(50, 40, 61, 16));
        label_2 = new QLabel(Credit);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(60, 130, 51, 16));
        label_3 = new QLabel(Credit);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(30, 90, 81, 16));
        comboBox_type = new QComboBox(Credit);
        comboBox_type->addItem(QString());
        comboBox_type->addItem(QString());
        comboBox_type->setObjectName(QString::fromUtf8("comboBox_type"));
        comboBox_type->setGeometry(QRect(120, 160, 211, 32));
        label_4 = new QLabel(Credit);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(50, 170, 61, 16));
        label_5 = new QLabel(Credit);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(360, 20, 211, 16));
        label_6 = new QLabel(Credit);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(360, 80, 171, 16));
        label_7 = new QLabel(Credit);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(360, 140, 171, 16));
        lineEdit_month = new QLineEdit(Credit);
        lineEdit_month->setObjectName(QString::fromUtf8("lineEdit_month"));
        lineEdit_month->setEnabled(true);
        lineEdit_month->setGeometry(QRect(360, 40, 361, 31));
        lineEdit_month->setReadOnly(true);
        lineEdit_over = new QLineEdit(Credit);
        lineEdit_over->setObjectName(QString::fromUtf8("lineEdit_over"));
        lineEdit_over->setGeometry(QRect(360, 100, 361, 31));
        lineEdit_over->setReadOnly(true);
        lineEdit_total = new QLineEdit(Credit);
        lineEdit_total->setObjectName(QString::fromUtf8("lineEdit_total"));
        lineEdit_total->setGeometry(QRect(360, 160, 361, 31));
        lineEdit_total->setReadOnly(true);

        retranslateUi(Credit);

        QMetaObject::connectSlotsByName(Credit);
    } // setupUi

    void retranslateUi(QWidget *Credit)
    {
        Credit->setWindowTitle(QApplication::translate("Credit", "Form", nullptr));
        pushButton_calculate->setText(QApplication::translate("Credit", "Calculate", nullptr));
        label->setText(QApplication::translate("Credit", "Loan ", nullptr));
        label_2->setText(QApplication::translate("Credit", "Rate", nullptr));
        label_3->setText(QApplication::translate("Credit", "Period", nullptr));
        comboBox_type->setItemText(0, QApplication::translate("Credit", "Annuity", nullptr));
        comboBox_type->setItemText(1, QApplication::translate("Credit", "Differentiated", nullptr));

        label_4->setText(QApplication::translate("Credit", "Type", nullptr));
        label_5->setText(QApplication::translate("Credit", "Monthly payment", nullptr));
        label_6->setText(QApplication::translate("Credit", "Overpayment", nullptr));
        label_7->setText(QApplication::translate("Credit", "Total payout", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Credit: public Ui_Credit {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREDIT_H
