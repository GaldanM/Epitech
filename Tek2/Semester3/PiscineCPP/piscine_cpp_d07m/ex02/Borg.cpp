#include "Borg.hh"
#include "Warpsystem.hh"
#include "Destination.hh"

Borg::Ship::Ship(Destination home)
{
  this->_home = home;
  this->_location = this->_home;
  this->_side = 300;
  this->_maxWarp = 9;
  std::cout << "We are the Borgs. Lower your shields and surrender yourselves unconditionally." << std::endl << "Your biological characteristics and technologies will be assimilated." << std::endl << "Resistance is futile." << std::endl;
}

void	Borg::Ship::setupCore(WarpSystem::Core *core)
{
  this->_core = core;
}

void	Borg::Ship::checkCore()
{
  if (this->_core->checkReactor()->isStable())
    std::cout << "Everything is in order." << std::endl;
  else
    std::cout << "Critical failure imminent." << std::endl;
}


bool		Borg::Ship::move(int warp, Destination d)
{
  if (warp <= this->_maxWarp && d != this->_location
      && this->_core->checkReactor()->isStable())
    {
      this->_location = d;
      return (true);
    }
  return (false);
}

bool		Borg::Ship::move(int warp)
{
  if (warp <= this->_maxWarp && this->_home != this->_location
      && this->_core->checkReactor()->isStable())
    {
      this->_location = this->_home;
      return (true);
    }
  return (false);

}

bool		Borg::Ship::move(Destination d)
{
  if (d != this->_location && this->_core->checkReactor()->isStable())
    {
      this->_location = d;
      return (true);
    }
  return (false);
}

bool		Borg::Ship::move()
{
  if (this->_location != this->_home &&  this->_core->checkReactor()->isStable())
    {
      this->_location = this->_home;
      return (true);
    }
  return (false);

}


Borg::Ship::~Ship()
{

}
