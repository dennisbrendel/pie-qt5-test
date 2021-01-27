#include <QLabel>
#include <QGridLayout>
#include <QLineEdit>

#include "MainWnd.h"

MainWnd::MainWnd() : QWidget()
, m_pLabel(nullptr)
{
  auto layout = new QGridLayout();

  auto qt4LE = new QLineEdit();
  auto qt5LE = new QLineEdit();
  m_pLabel = new QLabel("NULL");

  int row = 0;
  layout->addWidget(new QLabel("Qt4:"), row, 0);
  layout->addWidget(qt4LE, row, 1);
  layout->addWidget(new QLabel("Qt5:"), ++row, 0);
  layout->addWidget(qt5LE, row, 1);
  layout->addWidget(new QLabel("Result:"), ++row, 0);
  layout->addWidget(m_pLabel, row, 1);

  this->setLayout(layout);

  connect(qt4LE, SIGNAL(textChanged(const QString&)), m_pLabel, SLOT(setText(const QString&)));
  connect(qt5LE, &QLineEdit::textChanged, m_pLabel, &QLabel::setText);
}

