
#ifndef _WIN_H_
#define _WIN_H_

#include <QTableWidget>
#include <QWidget>
#include <QCloseEvent>
#include <QHBoxLayout>
#include <QPushButton>
#include <QTextEdit>
#include <string>
#include "Command.hpp"

class Command;

class Win : public QWidget
{
  Q_OBJECT

  QTableWidget	*_tab;
  QHBoxLayout	*_mainLayout;
  QPushButton	*_cook;
  QTextEdit	*_txt;
  Command	*_cmd;
  Thread *startCook;

protected:
    virtual void closeEvent(QCloseEvent*);
 
 public:
  Win(char **);
  ~Win();
  void		createLeft();
  void		display();
  void		createTabDisplay();
  void		addRowDisplay(std::string, int);
  QTableWidget  *   getTab() const;
  
  public slots:
    void	goCook();
};

#endif /* !_WIN_H_ */
