#include <QtWidgets/QApplication>

#include "MainWnd.h"

int main (int argc, char** argv) {
  QApplication a(argc, argv);

  MainWnd* pMainWnd = new MainWnd();
  pMainWnd->show();

  return a.exec();
}
