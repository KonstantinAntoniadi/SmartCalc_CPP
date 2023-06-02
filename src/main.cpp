#include <QApplication>
#include <QLocale>
#include <QTranslator>

#include "view/mainwindow.h"

int main(int argc, char *argv[]) {
  setenv("LC_NUMERIC", "C", 1);
  QApplication a(argc, argv);
  a.setWindowIcon(QIcon(":/icons/icon.png"));
  QTranslator translator;
  const QStringList uiLanguages = QLocale::system().uiLanguages();
  for (const QString &locale : uiLanguages) {
    const QString baseName = "s21_smartcalc_" + QLocale(locale).name();
    if (translator.load(":/i18n/" + baseName)) {
      a.installTranslator(&translator);
      break;
    }
  }
  MainWindow w;
  w.show();
  return a.exec();
}
