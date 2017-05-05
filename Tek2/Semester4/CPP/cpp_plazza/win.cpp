#include <QApplication>
#include <QVBoxLayout>
#include <QLabel>
#include <QRadioButton>
#include <QTableWidgetItem>
#include <QHeaderView>
#include <iostream>
#include <QMessageBox>
#include "Exception.hpp"
#include "win.h"

void    *doCook(void *arg)
{
    reinterpret_cast<Command *>(arg)->start_cook();
    return (NULL);
}

Win::Win(char **av) : _tab(new QTableWidget(this)), _mainLayout(new QHBoxLayout), _cook(new QPushButton("Cook")), _txt(new QTextEdit), _cmd(new Command(av))
{
  this->startCook = new Thread(doCook, _cmd);
  _cmd->setWin(this);
  setFixedSize(1200, 700);
  this->createLeft();
  this->display();
  this->setLayout(_mainLayout);

  QObject::connect(_cook, SIGNAL(clicked()), this, SLOT(goCook()));
}

void	Win::goCook()
{
  std::vector<Pizza *>	pizza;
  QString		text;
  int ret;

  text = _txt->toPlainText();
  if ((ret =_cmd->start(text.toStdString())) == -1)
      QMessageBox::critical(this, "Bad command", "TYPE   SIZE   NUMBER");
  else if (ret == -2)
      QMessageBox::critical(this, "Bad command", "500 PIZZAS MAX");
  _txt->clear();
}

void	Win::createLeft()
{
  QHBoxLayout *buttonLeft = new QHBoxLayout;
  QVBoxLayout *left = new QVBoxLayout;

  left->addWidget(_txt);
  buttonLeft->addWidget(_cook);
  left->addLayout(buttonLeft);
  _mainLayout->addLayout(left);
}

void          Win::createTabDisplay()
{
  QStringList	hName;
  hName << "Kitchens";

  _tab->insertColumn(0);
  _tab->horizontalHeader()->setResizeMode(QHeaderView::Stretch);
  _tab->setHorizontalHeaderLabels(hName);
  _tab->setEditTriggers(QAbstractItemView::NoEditTriggers);
}

void          Win::addRowDisplay(std::string str, int nb)
{
  QString qstr = QString::fromStdString(str);

  _tab->insertRow(nb);
  _tab->setItem(nb, 0, new QTableWidgetItem(qstr));
}

void          Win::display()
{
  this->createTabDisplay();
  _mainLayout->addWidget(_tab);
}

QTableWidget  *Win::getTab() const
{
  return _tab;
}

void Win::closeEvent(QCloseEvent* even)
{
  even->ignore();
}

Win::~Win()
{
}

int		main(int ac, char **av)
{
  if (ac != 4)
    {
      std::cerr << "Usage: multiplicator_time numbers_of_cook time_in_ms_for_ingredient" << std::endl;
      return (0);
    }
  try
    {
      QApplication	app(ac, av);
      Win		win(av);

      win.show();
      return app.exec();      
    }
  catch (Exception const &error)
    {
      std::cerr << "PLAZZA ERROR : " << error.what() << std::endl;
    }
  return (0);
}
