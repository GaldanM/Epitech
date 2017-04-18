#include "Ratatouille.h"

Ratatouille::Ratatouille()
{

}

Ratatouille::Ratatouille(Ratatouille const &cpy)
{
  _string << cpy._string.str();
}

Ratatouille::~Ratatouille()
{

}

Ratatouille	&Ratatouille::operator=(Ratatouille const &cpy)
{
  if (this != &cpy)
    {
      _string.str("");
      _string << cpy._string.str();
    }
  return (*this);
}

Ratatouille &Ratatouille::addVegetable(unsigned char Vegetable)
{
  _string << Vegetable;
  return (*this);
}

Ratatouille &Ratatouille::addCondiment(unsigned int Condiment)
{
  _string << Condiment;
  return (*this);
}

Ratatouille &Ratatouille::addSpice(double Spice)
{
  _string << Spice;
  return (*this);
}

Ratatouille &Ratatouille::addSauce(const std::string &Sauce)
{
  _string << Sauce;
  return (*this);
}

std::string	Ratatouille::kooc(void)
{
  std::string	recipe;

  recipe = _string.str();
  return (recipe);
}
