//
// droid.cpp for droid in /home/moulin_c/rendu/piscine_cpp_d08
// 
// Made by Galdan MOULINNEUF
// Login   <moulin_c@epitech.net>
// 
// Started on  Wed Jan 14 12:35:27 2015 Galdan MOULINNEUF
// Last update Thu Jan 15 09:16:43 2015 Galdan MOULINNEUF
//

#include	"droid.hh"

/* INIT */
Droid::Droid(std::string id) : _ID(""), _Energy(50), _Attack(25),_Toughness(15)
{
  this->_Status = new std::string("Standing by");
  this->_ID = id;
  this->_BattleMemory = new DroidMemory();
  std::cout << "Droid '" << this->_ID << "' Activated" << std::endl;
}

Droid::Droid(Droid const &to_copy) : _ID(to_copy._ID), _Energy(to_copy._Energy), _Attack(to_copy._Attack), _Toughness(to_copy._Toughness)
{
  if (to_copy._Status)
    this->_Status = new std::string(*(to_copy._Status));
  else
    this->_Status = new std::string("Standing by");
  if (to_copy._BattleMemory)
    this->_BattleMemory = new DroidMemory(*(to_copy._BattleMemory));
  else
    this->_BattleMemory = new DroidMemory();


  std::cout << "Droid '" << this->_ID << "' Activated, Memory Dumped" << std::endl;
}

Droid::~Droid()
{
  std::cout << "Droid '" << this->_ID << "' Destroyed" << std::endl;
  if (this->_Status)
    delete this->_Status;
  if (this->_BattleMemory)
    delete this->_BattleMemory;
}

/* GETTERS */
std::string	Droid::getId() const
{
  return (this->_ID);
}

size_t		Droid::getEnergy() const
{
  return (this->_Energy);
}

size_t		Droid::getAttack() const
{
  return (this->_Attack);
}

size_t		Droid::getToughness() const
{
  return (this->_Toughness);
}

std::string	*Droid::getStatus() const
{
  return (this->_Status);
}

DroidMemory	*Droid::getBattleMemory() const
{
  return (this->_BattleMemory);
}

/* SETTERS */
void		Droid::setId(std::string id)
{
  this->_ID = id;
}

void		Droid::setEnergy(size_t nrj)
{
  this->_Energy = nrj;
}

void		Droid::setStatus(std::string *status)
{
  if (this->_Status)
    delete this->_Status;
  this->_Status = status;
}

void		Droid::setBattleMemory(DroidMemory *BM)
{
  if (this->_BattleMemory)
    delete this->_BattleMemory;
  this->_BattleMemory = BM;
}

/* OPERATORS*/
Droid&		Droid::operator=(Droid const &to_copy)
{
  if (&to_copy)
    {
      if(this != &to_copy)
	{
	  if (this->_Status)
	    delete this->_Status;
	  if (this->_BattleMemory)
	    delete this->_BattleMemory;
	  this->_ID = to_copy._ID;
	  this->_Energy = to_copy._Energy;
	  this->_Status = new std::string(*(to_copy._Status));
	  this->_BattleMemory = new DroidMemory(*(to_copy._BattleMemory));
	}
    }
  return (*this);
}

bool		Droid::operator==(Droid const &to_comp) const
{
  if (&to_comp)
    if(to_comp._Status == _Status)
      return (true);
  return (false);
}

bool		Droid::operator!=(Droid const &to_comp) const
{
  if (&to_comp)
    if(to_comp._Status != _Status)
      return (true);
  return (false);
}

Droid&		Droid::operator<<(size_t &stock)
{
  unsigned int		to_add;

  if (_Energy == 100)
    return (*this);
  to_add = 100 - _Energy;
  if (to_add <= stock)
    {
      _Energy += to_add;
      stock -= to_add;
    }
  else if (to_add > stock)
    {
      _Energy += stock;
      stock = 0;
    }
  return (*this);
}

std::ostream&	operator<<(std::ostream& os, Droid const &xperia)
{
  os << "Droid '" << xperia.getId() << "', " << *xperia.getStatus() << ", " << xperia.getEnergy();

  return (os);
}
