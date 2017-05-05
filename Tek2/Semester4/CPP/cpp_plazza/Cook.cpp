
#include <unistd.h>
#include <stdio.h>
#include "Cook.h"

Cook::Cook(void *(*fnc)(void *)) : _stat(WAITING), _toDo(NULL)
{
  this->_pipe.open("log.txt", std::istream::out);
  _th = new Thread(fnc, this);
}

Cook::~Cook()
{
  this->_pipe.close();
  delete _th;
}

void		Cook::startCook()
{

  while (1)
    {
      _th->wait();
      _stat = BUSY;
      usleep(_toDo->getTime());
      std::cout << _toDo->getStrPizza() << " is ready to be eat !" << std::endl;
      this->_pipe << _toDo->getStrPizza() << " is ready to be eat !" << std::endl;
      _stat = FINISHED;
    }
}

void		Cook::signalPizza()
{
	_th->signal();
}

Status  Cook::getStatus() const
{
	return _stat;
}

void    Cook::setStatus(Status stat)
{
  this->_stat = stat;
}

void		Cook::setPizza(Pizza *pizza)
{
	_toDo = pizza;
}

