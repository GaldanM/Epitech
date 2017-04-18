//
// Skat.cpp for Skat in /home/moulin_c/rendu/piscine_cpp_d07a/ex00
// 
// Made by Galdan MOULINNEUF
// Login   <moulin_c@epitech.net>
// 
// Started on  Tue Jan 13 19:50:59 2015 Galdan MOULINNEUF
// Last update Wed Jan 14 09:53:08 2015 Galdan MOULINNEUF
//

#include	"Skat.h"

Skat::Skat(std::string const &name, int stimPaks)
{
  this->_name = name;
  this->_stimPaks = stimPaks;
}

int			&Skat::stimPaks()
{
  return (this->_stimPaks);
}

const std::string	&Skat::name()
{
  return (this->_name);
}

void			Skat::shareStimPaks(int number, int &stock)
{
  if (number <= this->_stimPaks)
    {
      stock = stock + number;
      this->_stimPaks = number + this->_stimPaks;
      std::cout << "Keep the change." << std::endl;
    }
  else
    std::cout << "Don't be greedy" << std::endl;
}

void			Skat::addStimPaks(unsigned int number)
{
  if (number > 0)
    this->_stimPaks = this->_stimPaks + number;
  else
    std::cout << "Hey boya, did you forget something ?" << std::endl;
}

void			Skat::useStimPaks()
{
  if (this->_stimPaks > 0)
    {
      std::cout << "Time to kick some ass and chew bubble gum." << std::endl;
      this->_stimPaks = this->_stimPaks - 1;
    }
  else
    std::cout << "Mediiiiiic" << std::endl;
}

void			Skat::status()
{
  std::cout << "Soldier " << this->_name << " reporting " << this->_stimPaks << " stimpaks remaining sir !" << std::endl;
}

Skat::~Skat()
{

}
