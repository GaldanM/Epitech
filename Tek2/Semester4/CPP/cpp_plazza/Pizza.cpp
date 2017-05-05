//
// Pizza.cpp for e in /home/zaband_b/test/plazza
// 
// Made by Bryan Zabandith
// Login   <zaband_b@epitech.net>
// 
// Started on  Thu Apr 23 16:28:11 2015 Bryan Zabandith
// Last update Thu Apr 23 23:28:17 2015 Bryan Zabandith
//

#include "Pizza.hpp"

Pizza::Pizza()
{
  this->my_type[REGINA] = "regina";
  this->my_type[MARGARITA] = "margarita";
  this->my_type[AMERICAINE] = "americaine";
  this->my_type[FANTASIA] = "fantasia";

  this->my_size[S] = "s";
  this->my_size[M] = "m";
  this->my_size[L] = "l";
  this->my_size[XL] = "xl";
  this->my_size[XXL] = "xxl";
}

Pizza::Pizza(const Pizza &ref): size(ref.size), type(ref.type), list(ref.list), my_type(ref.my_type), time(ref.time), multiple(ref.multiple), my_size(ref.my_size)
{
}

Pizza	&Pizza::operator=(const Pizza &ref)
{
  if (this != &ref)
    {
      this->size = ref.size;
      this->type = ref.type;
      this->list = ref.list;
      this->my_type = ref.my_type;
      this->my_size = ref.my_size;
    }
  return (*this);
}

std::vector<Ingredient> Pizza::getIngredient() const
{
  return (this->list);
}

TypePizza Pizza::getType() const
{
  return (this->type);
}

TaillePizza Pizza::getSize() const
{
  return (this->size);
}

std::string Pizza::getStrPizza()
{
  return (this->my_type[this->type]);
}

std::string Pizza::getStrSize()
{
  return (this->my_size[this->size]);
}

int	Pizza::getTime() const
{
  return (this->time);
}

void	Pizza::setMultiple(const float &mul)
{
  this->time = this->time * mul;
}
