//
// Command.cpp for Command in /home/zaband_b/test/plazza
// 
// Made by Bryan Zabandith
// Login   <zaband_b@epitech.net>
// 
// Started on  Thu Apr 16 02:02:13 2015 Bryan Zabandith
// Last update Sun Apr 26 00:32:28 2015 Bryan Zabandith
//

#include "Parse.hpp"
#include "Command.hpp"
#include "Exception.hpp"

IMutex m;

Command::Command(char **av)
{
  std::stringstream ss;
  
  if (this->check_arg(av) != 0)
    throw(Exception("parameters must be numbers"));
  this->cmd = "";
  ss << av[1];
  ss >> this->mul;
  if (this->mul <= 0 || this->mul > 10)
    throw(Exception("multiple must be greater than 0 and lower than 10"));
  ss.str("");
  ss.clear();
  ss << av[2];
  ss >> this->nbcook;
  if (this->nbcook > 32 || this->nbcook < 0)
    throw(Exception("nb cook must be between 0 and 32"));
  ss.str("");
  ss.clear();
  ss << av[3];
  ss >> this->ms;
  if (this->nbcook <= 0 || this->ms <= 0 || this->ms >= 4000)
    throw(Exception("parameters must be greater than a 0 and the regen time must be lower than 4000"));
  this->id = 0;
  this->kitchen.clear();
  this->factor = new Factory();
}

Command::Command(const Command &ref) : cmd(ref.cmd), mul(ref.mul), ms(ref.ms), nbcook(ref.nbcook), pizza(ref.pizza), id(ref.id), kitchen(ref.kitchen), factor(ref.factor)
{

}

Command&    Command::operator=(const Command &ref)
{
  if (this != &ref)
    {
      this->cmd = ref.cmd;
      this->mul = ref.mul;
      this->ms = ref.ms;
      this->nbcook = ref.nbcook;
      this->pizza = ref.pizza;
      this->id = ref.id;
      this->kitchen = ref.kitchen;
      this->factor = ref.factor;
    }
  return (*this);
}

Command::~Command()
{

}

void        Command::freeKitchen()
{
  unsigned int i = 0;

    for (i = 0; i < kitchen.size(); i++)
      delete kitchen[i];
}

int         Command::find_pnt(const std::string &multipl) const
{
  int	i;
  std::size_t found = multipl.find_first_of(".");

  i = 0;
  while (found != std::string::npos)
    {
      i++;
      found = multipl.find_first_of(".", found+1);
    }
  return (i);
}

int         Command::check_arg(char **av) const
{
  std::stringstream ss;
  std::string arg;
  unsigned int	i;

  ss << av[1];
  arg = ss.str();
  if (this->find_pnt(arg) > 1)
    return (-1);
  for (i = 0; i < arg.size(); i++)
    {
      if (!isdigit(arg[i]) && arg[i] != '.')
	return (-1);
    }
  ss.str("");
  ss.clear();
  ss << av[2];
  arg = ss.str();
  for (i = 0; i < arg.size(); i++)
    {
      if (!isdigit(arg[i]))
	return (-1);
    }
  ss.str("");
  ss.clear();
  ss << av[2];
  arg = ss.str();
  for (i = 0; i < arg.size(); i++)
    {
      if (!isdigit(arg[i]))
	return (-1);
    }
  return (0);
}

void	       Command::fill_pizza(const std::vector<Pizza *> &ref)
{
  unsigned int	i = 0;

  if (this->pizza.size() == 0)
    this->pizza = ref;
  else
    {
      while (i != ref.size())
	     {
    	  this->pizza.push_back(ref[i]);
    	  i++;
    	}
    }
}

void		     Command::update(unsigned int nb_id)
{
  usleep(10000);
  if (write(this->kitchen[nb_id]->getFifo().getWrite(), "Update", 6) < 0)
    {
      std::cout << "Accueil: je delete la kitchen : "<< nb_id << std::endl;
      this->kitchen.erase(this->kitchen.begin() + nb_id);
      this->id--;
      return;
    }
  if (read(this->kitchen[nb_id]->getRead(), this->kitchen[nb_id], sizeof(Kitchen)) < 0)
    {
      std::cout << "Accueil: je delete la kitchen : "<< nb_id << std::endl;
      this->kitchen.erase(this->kitchen.begin() + nb_id);
      this->id--;
      return;

    }
  this->kitchen[nb_id]->swap();
}

void		    Command::send(int nb_id)
{
  std::string	str;

  str = this->factor->Pack(this->pizza[this->pizza.size() - 1]);
  usleep(10000);
  if (write(this->kitchen[nb_id]->getFifo().getWrite(), str.c_str(), str.size()) < 0)
    {
      std::cout << "Accueil:je delete la kitchen : "<< nb_id << std::endl;
      this->kitchen.erase(this->kitchen.begin() + nb_id);
      this->id--;
    }
}

void		    Command::start_cook()
{
 
  unsigned int	i;
  unsigned int	is_full;
  unsigned int	nb;
  
  while (1)
    {
      i = 0;
      nb = 0;
      is_full = 0;
          while (nb != this->kitchen.size())
          	{
          	  if (this->kitchen[nb]->getPizzaCooking() + this->kitchen[nb]->getPizzaWaiting() >= this->nbcook * 2)
          	    is_full++;
          	  nb++;
          	}
          if (is_full != this->kitchen.size() && this->pizza.size() != 0)
          	{
          	  while (i != this->kitchen.size())
          	    {
          	      if (this->kitchen[i]->getPizzaCooking() + this->kitchen[i]->getPizzaWaiting() < this->nbcook * 2 && pizza.size() > 0)
                		{
                		  this->send(this->kitchen[i]->getId());
                		  this->pizza.pop_back();
                		}
          	      i++;
          	    }
          	}
          if (this->pizza.size() != 0 && is_full == this->kitchen.size())
          	{
          	  this->kitchen.push_back(new Kitchen(this->mul, this->nbcook, this->ms, this->id));
          	  this->id++;
          	}
          nb = 0;
          while (nb != this->kitchen.size() && !kitchen.empty())
          	{
                 std::stringstream ss;
                 this->update(this->kitchen[nb]->getId());
                  _win->getTab()->removeRow(nb);
                    if (!kitchen.empty())
                    {
                  	 ss << "Kitchen :" << this->kitchen[nb]->getId() + 1 << "   PizzaCooking: " << this->kitchen[nb]->getPizzaCooking() <<  
                     "   PizzaWaiting: " << this->kitchen[nb]->getPizzaWaiting();
                     std::cout << ss.str() << std::endl;
                      _win->addRowDisplay(ss.str(), nb);
                     }
                  nb++;
          	}
    }
}

int	        Command::start(const std::string &str)
{
  Parse	*p;

  p = new Parse();
  if (p->pizza_max(str) == -1)
    return (-2);
  p->setLine(str);
  if (p->getnbPizza() != 0)
    {
      this->fill_pizza(p->getPizza(this->mul));
      return 0;
    }
  return -1;
}

std::vector<Pizza *> Command::getPizza() const
{
  return this->pizza;
}

void        Command::setPizza(std::vector<Pizza *> npizza)
{
  this->pizza = npizza;
}

void	       Command::setWin(Win *win)
{
  _win = win;
}
