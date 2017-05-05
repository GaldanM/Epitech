//
// Factory.cpp for e in /home/zaband_b/test/plazza
// 
// Made by Bryan Zabandith
// Login   <zaband_b@epitech.net>
// 
// Started on  Mon Apr 20 18:31:02 2015 Bryan Zabandith
// Last update Fri Apr 24 00:32:52 2015 Bryan Zabandith
//

#include "Factory.hpp"

Factory::Factory()
{
  this->create["regina"] = &Factory::create_regina;
  this->create["americaine"] = &Factory::create_americaine;
  this->create["margarita"] = &Factory::create_margarita;
  this->create["fantasia"] = &Factory::create_fantasia;

  this->size_pizza["s"] = S;
  this->size_pizza["m"] = M;
  this->size_pizza["l"] = L;
  this->size_pizza["xl"] = XL;
  this->size_pizza["xxl"] = XXL;
}

Factory::~Factory()
{
}

Factory::Factory(const Factory &ref): size_pizza(ref.size_pizza), create(ref.create)
{
}

Factory &Factory::operator=(const Factory &ref)
{
  if (this != &ref)
    {
      this->size_pizza = ref.size_pizza;
      this->create = ref.create;
    }
  return (*this);
}

Pizza	*Factory::fill(const std::string &type, const std::string &size)
{
  std::map<std::string, Factory::ptr>::iterator it;

  for (it = this->create.begin(); it != this->create.end(); it++)
    {
      if (it->first == type)
	return (this->*(it->second))(this->size_pizza[size]);
    }
  return (NULL);
}

Pizza	*Factory::create_margarita(const TaillePizza &size)
{
  Pizza	*newpizza = new Margarita(size);
  return (newpizza);
}

Pizza	*Factory::create_regina(const TaillePizza &size)
{
  Pizza *newpizza = new Regina(size);
  return (newpizza);
}

Pizza   *Factory::create_americaine(const TaillePizza &size)
{
  Pizza *newpizza = new Americaine(size);
  return (newpizza);
}

Pizza   *Factory::create_fantasia(const TaillePizza &size)
{
  Pizza *newpizza = new Fantasia(size);
  return (newpizza);
}

std::string Factory::Pack(Pizza *new_pizza) const
{
  return (new_pizza->getStrPizza() + " " + new_pizza->getStrSize());
}

Pizza		*Factory::UnPack(std::string ref)
{
  std::string	type;
  std::string	size;
  unsigned int	i;
  unsigned int	i2;

  for (i = 0; i < ref.size() && (ref[i] != ' '); i++);
  type = ref.substr(0, i);
  i++;
  i2 = i;
  for (; i2 < ref.size() && (ref[i2] != ' '); i2++);
  size = ref.substr(i, i2 - i);
  return (this->fill(type, size));
}
