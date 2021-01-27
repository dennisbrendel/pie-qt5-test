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
  auto qt5LE2 = new QLineEdit();
  m_pLabel = new QLabel("NULL");

  int row = 0;
  layout->addWidget(new QLabel("Qt4:"), row, 0);
  layout->addWidget(qt4LE, row, 1);
  layout->addWidget(new QLabel("Qt5:"), ++row, 0);
  layout->addWidget(qt5LE, row, 1);
  layout->addWidget(new QLabel("Qt5-\u03BB:"), ++row, 0);
  layout->addWidget(qt5LE2, row, 1);
  layout->addWidget(new QLabel("Result:"), ++row, 0);
  layout->addWidget(m_pLabel, row, 1);

  this->setLayout(layout);

  connect(qt4LE, SIGNAL(textChanged(const QString&)), m_pLabel, SLOT(setText(const QString&)));
  connect(qt5LE, &QLineEdit::textChanged, m_pLabel, &QLabel::setText);
  connect(qt5LE2, &QLineEdit::textChanged, [this, qt5LE2](){m_pLabel->setText(qt5LE2->text());});
}

