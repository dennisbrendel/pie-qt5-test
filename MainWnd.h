#pragma once

#include <QWidget>

class QLabel;
class MainWnd: public QWidget {
  Q_OBJECT

  public:
    MainWnd();
    ~MainWnd() = default;

  private:
    QLabel* m_pLabel;

};
