//
// Parse.cpp for e in /home/zaband_b/test/plazza
// 
// Made by Bryan Zabandith
// Login   <zaband_b@epitech.net>
// 
// Started on  Thu Apr 16 03:54:00 2015 Bryan Zabandith
// Last update Tue Apr 21 19:45:31 2015 Bryan Zabandith
//

#include "Parse.hpp"
#include <unistd.h>

Parse::Parse()
{
  this->factory = new Factory();
  this->init_type();
  this->init_size();
  this->pizza.clear();
}

Parse::~Parse()
{
}

Parse::Parse(const Parse &ref) : line(ref.line), pizza_t(ref.pizza_t), pizza_s(ref.pizza_s), pizza_nb(ref.pizza_nb), type(ref.type), size(ref.size),cmd(ref.cmd), pizza(ref.pizza), factory(ref.factory)
{
}

Parse &Parse::operator=(const Parse &ref)
{
  if (this != &ref)
    {
      this->line = ref.line;
      this->pizza_t = ref.pizza_t;
      this->pizza_s = ref.pizza_s;
      this->pizza_nb = ref.pizza_nb;
      this->type = ref.type;
      this->size = ref.size;
      this->cmd = ref.cmd;
      this->pizza = ref.pizza;
      this->factory = ref.factory;
    }
  return (*this);
}

void	Parse::init_type()
{
  this->type.push_back("regina");
  this->type.push_back("margarita");
  this->type.push_back("americaine");
  this->type.push_back("fantasia");
}

void	Parse::init_size()
{
  this->size.push_back("s");
  this->size.push_back("m");
  this->size.push_back("l");
  this->size.push_back("xl");
  this->size.push_back("xxl");
}

std::vector<std::string>   Parse::split_string(std::string str)
{
  unsigned int  i;
  std::vector<std::string> cm;

  i = 0;
  cm.clear();
  while (i < str.size())
    {
      if (str[i] != ';')
  {
    std::vector<char> v;
    while (str[i] != ';')
      {
        v.push_back(str[i]);
        i++;
      }
    std::string sta(v.begin(), v.end());
    cm.push_back(sta);
  }
      i++;
    }
  for (i = 0; i < cm.size(); i++)
    cm[i] = this->epur(cm[i]);
  return (cm);
}

void		Parse::split_string()
{
  unsigned int	i;

  i = 0;
  this->cmd.clear();
  while (i < this->line.size())
    {
      if (this->line[i] != ';')
	{
	  std::vector<char> v;
	  while (this->line[i] != ';')
	    {
	      v.push_back(this->line[i]);
	      i++;
	    }
	  std::string str(v.begin(), v.end());
	  this->cmd.push_back(str);
	}
      i++;
    }
  for (i = 0; i < this->cmd.size(); i++)
    this->cmd[i] = this->epur(this->cmd[i]);
}

std::string	Parse::epur(const std::string &cmd) const
{
  int		i = 0;
  std::vector<char> c;

  while (cmd[i])
    {
      if (cmd[i] != ' ' && cmd[i] != '\t')
	{
	  c.push_back(cmd[i]);
	  if (cmd[i + 1] == ' ' || cmd[i + 1] == '\t')
	    c.push_back(' ');
	}
      i++;
    }
  std::string a(c.begin(), c.end());
  return (a);
}

void	Parse::setLine(const std::string &cmd)
{
  this->line = cmd;
  std::transform(this->line.begin(), this->line.end(), this->line.begin(), ::tolower);
  if (this->line[this->line.size() - 1] != ';')
    this->line = this->line + ";";
  this->split_string();
  this->fill_pizza();
}

int	Parse::nb_word(const std::string &str) const
{
  int	i = 0;
  std::size_t found = str.find_first_of(" ");

  while (found != std::string::npos)
    {
      i++;
      found = str.find_first_of(" ", found + 1);
    }
  return (i + 1);
}

int		Parse::check_type() const
{
  unsigned int	i;

  i = 0;
  while (i != this->type.size())
    {
      if (this->pizza_t == this->type[i])
	return (0);
      i++;
    }
  return (-1);
}

int		Parse::check_size() const
{
  unsigned int	i;

  i = 0;
  while (i != this->size.size())
    {
      if (this->pizza_s.compare(this->size[i]) == 0)
	return (0);
      i++;
    }
  return (-1);
}

int   Parse::check_nb(std::string str) const
{
  unsigned int  i;

  i = 1;
  if (str[0] != 'x')
    return (-1);
  while (i != str.size())
    {
      if (!isdigit(str[i]))
  return (-1);
      i++;
    }
  return (0);
}

int		Parse::check_nb() const
{
  unsigned int	i;

  i = 1;
  if (this->pizza_nb[0] != 'x')
    return (-1);
  while (i != this->pizza_nb.size())
    {
      if (!isdigit(this->pizza_nb[i]))
	return (-1);
      i++;
    }
  return (0);
}

void		Parse::fill()
{
  Pizza		*new_Pizza;
  std::stringstream ss;
  unsigned int	nb;
  unsigned int	i = 0;

  ss.clear();
  if ((this->check_type() != 0) || (this->check_size() != 0) || (this->check_nb() != 0))
    return;
  this->pizza_nb.erase(this->pizza_nb.begin());
  ss << this->pizza_nb;
  ss >> nb;
  if (nb > 500)
    return;
  new_Pizza = this->factory->fill(this->pizza_t, this->pizza_s);
  while (i != nb)
    {
      this->pizza.push_back(new_Pizza);
      i++;
    }
}

int    Parse::pizza_max(std::string str)
{
  unsigned i = 0;
  unsigned int nb = 0;
  unsigned int nb2 = 0;
  unsigned int it;
  unsigned int it2;
  std::string number;
  std::stringstream ss;
  std::transform(str.begin(), str.end(), str.begin(), ::tolower);
  std::vector<std::string > ok;

  ok = this->split_string(str);
  while (i != ok.size())
  {
    if (this->nb_word(ok[i]) >= 3)
    {
    for (it = 0; it < ok[i].size() && (ok[i][it] != ' '); it++);
    it++;
    it2 = it;
    for (; ((it2 < ok[i].size()) && (ok[i][it2] != ' ')); it2++);
    it2++;
    it = it2;
    for (; it2 < ok[i].size() && (ok[i][it2] != ' '); it2++);
    number = ok[i].substr(it, it2 - it);
    if (this->check_nb(number) == 0)
      {
        number.erase(number.begin());
        ss << number;
        ss >> nb;
        nb2 = nb + nb2;
      }
      i++;
    }
  }
  if (nb2 > 500)
    return (-1);
  return (0);
}

void		Parse::fill_pizza()
{
  unsigned int	i = 0;
  unsigned int	it;
  unsigned int	it2;


  while (i < this->cmd.size())
    {
      if (this->nb_word(this->cmd[i]) >= 3)
	{
	  for (it = 0; it < this->cmd[i].size() && (this->cmd[i][it] != ' '); it++);
	  this->pizza_t = this->cmd[i].substr(0, it);
	  it++;
	  it2 = it;
	  for (; ((it2 < this->cmd[i].size()) && (this->cmd[i][it2] != ' ')); it2++);
	  this->pizza_s = this->cmd[i].substr(it, it2 - it);
	  it2++;
	  it = it2;
	  for (; it2 < this->cmd[i].size() && (this->cmd[i][it2] != ' '); it2++);
	  this->pizza_nb = this->cmd[i].substr(it, it2 - it);
	  this->fill();
	}
      i++;
    }
}

std::vector<Pizza *> Parse::getPizza(const float &mul) const
{
  unsigned int i = 0;
  while (i != this->pizza.size())
  {
    this->pizza[i]->setMultiple(mul);
    i++;
  }
  return (this->pizza);
}

int	Parse::getnbPizza() const
{
  return (this->pizza.size());
}
