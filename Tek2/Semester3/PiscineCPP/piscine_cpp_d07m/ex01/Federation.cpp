//
// Federation.cpp for fede in /home/moulin_c/rendu
// 
// Made by Galdan MOULINNEUF
// Login   <moulin_c@epitech.net>
// 
// Started on  Tue Jan 13 12:32:38 2015 Galdan MOULINNEUF
// Last update Wed Jan 14 00:16:14 2015 Galdan MOULINNEUF
//

#include	"Federation.hh"

#define STAB(stab)	(stab == true ? "stable" : "unstable")

/* SHIP STARFLEET*/

Federation::Starfleet::Ship::Ship(int length, int width, std::string name, short maxWarp)
{
  this->_length = length;
  this->_width = width;
  this->_name = name;
  this->_maxWarp = maxWarp;
  std::cout << "The ship USS " << name << " has been finished. It is " << length << " m in length and " << width << " m in width." << std::endl << "It can go to Warp " << maxWarp << "!" << std::endl;
}

void		Federation::Starfleet::Ship::setupCore(WarpSystem::Core *core)
{
  this->_core = core;
  std::cout << "USS " << this->_name << ": The core is set." << std::endl;
}

void		Federation::Starfleet::Ship::checkCore()
{
  std::cout << "USS " << this->_name << ": The core is " << STAB(this->_core->checkReactor()->isStable()) << " at the time." << std::endl;
}

void		Federation::Starfleet::Ship::promote(Captain *captain)
{
  std::cout << captain->getName() << ": I'm glad to be the captain of the USS " << this->_name << "." << std::endl;
}

Federation::Starfleet::Ship::~Ship()
{

}

/* SHIP INDEP */

Federation::Ship::Ship(int length, int width, std::string name, short maxWarp)
{
  this->_length = length;
  this->_width = width;
  this->_name = name;
  this->_maxWarp = maxWarp;
  std::cout << "The independant ship " << name << " just finished its construction. It is " << length << " m in length and " << width << " m in width." << std::endl;
}

void		Federation::Ship::setupCore(WarpSystem::Core *core)
{
  this->_core = core;
  std::cout << this->_name << ": The core is set." << std::endl;
}

void		Federation::Ship::checkCore()
{
  std::cout << this->_name << ": The core is " << STAB(this->_core->checkReactor()->isStable()) << " at the time." << std::endl;
}

Federation::Ship::~Ship()
{

}

/* CAPTAIN STARFLEET */

Federation::Starfleet::Captain::Captain(std::string name)
{
  this->_name = name;
}

std::string	Federation::Starfleet::Captain::getName()
{
  return (this->_name);
}

int		Federation::Starfleet::Captain::getAge()
{
  return (this->_age);
}

void		Federation::Starfleet::Captain::setAge(int age)
{
  this->_age = age;
}

Federation::Starfleet::Captain::~Captain()
{

}

/* ENSIGN STARFLEET */

Federation::Starfleet::Ensign::Ensign(std::string name)
{
  this->_name = name;
  std::cout << "Ensign " << name << ", awaiting orders." << std::endl;
}

Federation::Starfleet::Ensign::~Ensign()
{

}
