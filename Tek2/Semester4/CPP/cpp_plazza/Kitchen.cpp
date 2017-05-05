//
// Kitchen.cpp for e in /home/zaband_b/test/plazza
// 
// Made by Bryan Zabandith
// Login   <zaband_b@epitech.net>
// 
// Started on  Thu Apr 23 22:37:43 2015 Bryan Zabandith
// Last update Sun Apr 26 02:06:03 2015 Bryan Zabandith
//

#include "Exception.hpp"
#include "Kitchen.h"
#include <stdlib.h>

Kitchen::Kitchen(float mul, int nbcook, int regen_time, int id) : _fifo(id)
{
  this->mul = mul;
  this->nbcook = nbcook;
  this->id = id;
  this->regen = regen_time * 1000;
  this->pizzaCooking = 0;
  this->initStock();
  this->pid = fork();
  if (this->pid > 0)
    this->_fifo.swap();
  else if (!this->pid)
    {
      this->launch();
      exit(0);
    }
}

Kitchen::~Kitchen()
{

  for (unsigned int i = 0; i < _cooks.size(); i++)
    delete _cooks[i];
}

void        *startCook(void *arg)
{
  reinterpret_cast<Cook *>(arg)->startCook();
  return (NULL);
}

void        *startRespawn(void *arg)
{
  reinterpret_cast<Kitchen *>(arg)->respawn();
  return (NULL);
}

void    Kitchen::initStock()
{
  this->_stock[DOE] = 5;
  this->_stock[TOMATO] = 5;
  this->_stock[GRUYERE] = 5;
  this->_stock[HAM] = 5;
  this->_stock[MUSHROOMS] = 5;
  this->_stock[STEAK] = 5;
  this->_stock[EGGPLANT] = 5;
  this->_stock[GOATCHEESE] = 5;
  this->_stock[CHIEFLOVE] = 5;
}

void		Kitchen::respawn()
{
  while (1)
  {
    std::map<Ingredient, int>::iterator it;

    for (it = this->_stock.begin(); it != this->_stock.end(); it++)
      ++it->second;
    usleep(regen);
  }
}

void      Kitchen::initCooks()
{
  for (int i = 0; i < this->nbcook; ++i)
  {
    Cook *cook = new Cook(startCook);
    _cooks.push_back(cook);
  }
}    

void		Kitchen::launch()
{
  int		ret;
  char		buff[256];
  std::string	str;
  Factory	f;
  Pizza		*pizza;
  Thread  MyRespawn(startRespawn, this);
  
  this->initStock();
  initCooks();
  this->pizzaCooking = 0;
  while ((ret = read(this->_fifo.getRead(), buff, 255)) > 0)
    {
      buff[ret] = '\0';
      str.assign(buff);
      if (str.compare("Update") != 0)
	     {
      	  pizza = f.UnPack(str);
          this->_pizzaWaiting.push(pizza);
      	}
      else
      	{
      	  usleep(20000);
      	  write(this->_fifo.getWrite(), this, sizeof(Kitchen));
      	}
     manageCooks();
    }
}

void      Kitchen::manageCooks()
{
  unsigned int i = 0;
  unsigned int a = 0;
  std::vector<Ingredient> ingr;

  while (i != _cooks.size())
  {
    
    if (_cooks[i]->getStatus() == FINISHED)
      {
        _cooks[i]->setStatus(WAITING);
        --pizzaCooking;
      }  
    if (_cooks[i]->getStatus() == WAITING && !_pizzaWaiting.empty() && this->enoughIngredients(_pizzaWaiting.front()))
      {
        _cooks[i]->setPizza(_pizzaWaiting.front()); 
        ++pizzaCooking;
      ingr = _pizzaWaiting.front()->getIngredient();
        a = 0;
        while (a != ingr.size())
        {

            for (std::map<Ingredient, int>::iterator it = _stock.begin(); it != _stock.end(); ++it)
            {
              if (it->first == ingr[a])
                _stock[ingr[a]]--;
            }
          a++;
        }
        _pizzaWaiting.pop();
        _cooks[i]->signalPizza();
      }
    i++;
  }
}

bool      Kitchen::enoughIngredients(Pizza *pizza)
{
  std::vector<Ingredient> ingr;
  unsigned int i = 0;

  ingr = pizza->getIngredient();
  while (i != ingr.size())
  {
     if (this->_stock[ingr[i]] == 0)
    {
      std::cout << "Need ingredients !\n";
      return false;
    }
    i++;
  }
  return true;
}

bool      Kitchen::checkCooks()
{
  unsigned int i = 0;

  while (i != _cooks.size())
  {
    if (_cooks[i]->getStatus() != WAITING)
      return (false);
    i++;
  }
  return (true);
}

void      Kitchen::closeKitchen()
{
  close(this->getRead());
  close(this->getWrite());
}

int	Kitchen::getPizzaCooking() const
{
  return (pizzaCooking);
}

int			Kitchen::getRead() const
{
  return (_fifo.getRead());
}

int	Kitchen::getId() const
{
  return (this->id);
}

int			Kitchen::getWrite() const
{
  return (_fifo.getWrite());
}

void		Kitchen::swap()
{
  _fifo.swap();
}

MyFifo		Kitchen::getFifo() const
{
  return _fifo;
}
int     Kitchen::getPizzaWaiting() const
{
  return _pizzaWaiting.size();
}

std::map<Ingredient, int> Kitchen::getStock() const
{
  
  return _stock;
}