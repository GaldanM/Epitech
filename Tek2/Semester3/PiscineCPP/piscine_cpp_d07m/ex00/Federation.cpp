//
// Federation.cpp for fede in /home/moulin_c/rendu
// 
// Made by Galdan MOULINNEUF
// Login   <moulin_c@epitech.net>
// 
// Started on  Tue Jan 13 12:32:38 2015 Galdan MOULINNEUF
// Last update Wed Jan 14 00:11:20 2015 Galdan MOULINNEUF
//

#include	"Federation.hh"

#define STAB(stab)	(stab == true ? "stable" : "unstable")

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

Federation::Starfleet::Ship::~Ship()
{

}

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
