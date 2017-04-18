//
// Character.cpp for Chara in /home/moulin_c/rendu/piscine_cpp_d09/ex00
// 
// Made by Galdan MOULINNEUF
// Login   <moulin_c@epitech.net>
// 
// Started on  Thu Jan 15 12:17:37 2015 Galdan MOULINNEUF
// Last update Fri Jan 16 09:47:02 2015 Galdan MOULINNEUF
//

#include	"Mage.hh"

/* INIT */
Mage::Mage(const std::string name, int lvl) : Character(name, lvl)
{
  this->_class = "Mage";
  this->_race = "Gnome";
  this->_str = 6;
  this->_sta = 6;
  this->_intel = 12;
  this->_spir = 11;
  this->_agi = 7;
  std::cout << name << " teleported" << std::endl;
}

Mage::Mage(Mage const &to_copy) : Character(to_copy)
{
  this->_class = to_copy._class;
  this->_race = to_copy._race;
  this->_str = to_copy._str;
  this->_sta = to_copy._sta;
  this->_intel = to_copy._intel;
  this->_spir = to_copy._spir;
  this->_agi = to_copy._agi;
}

Mage::~Mage()
{

}

/* OTHERS */

int		Mage::CloseAttack()
{
  if (this->_energy >= 10)
    {
      this->_energy -= 10;
      std::cout << this->_name << " blinks" << std::endl;
      this->Range = Character::RANGE;
      return (0);
    }
  std::cout << this->_name << " out of power" << std::endl;
  return (0);
}

int		Mage::RangeAttack()
{
  if (this->_energy >= 25)
    {
      this->_energy -= 25;
      std::cout << this->_name << " launches a fire ball" << std::endl;
      return (this->_spir + 20);
    }
  std::cout << this->_name << " out of power" << std::endl;
  return (0);
}

void		Mage::RestorePower()
{
  this->_energy = this->_energy + (this->_intel + 50);
  if (this->_energy > 100)
    this->_energy = 100;
  std::cout << this->_name << " takes a mana potion" << std::endl;
}

/* OPERATORS */

Mage&	Mage::operator=(Mage const &to_copy)
{
  if (&to_copy)
    {
      if (to_copy._name != _name || to_copy._lvl != _lvl || to_copy._life != _life || to_copy._energy != _energy || to_copy._str != _str || to_copy._sta != _sta || to_copy._intel != _intel || to_copy._spir != _spir || to_copy._agi != _agi || to_copy.Range != Range)
	{
	  _race = to_copy._race;
	  _class = to_copy._class;
	  _lvl = to_copy._lvl;
	  _life = to_copy._life;
	  _energy = to_copy._energy;
	  _str = to_copy._str;
	  _sta = to_copy._sta;
	  _intel = to_copy._intel;
	  _spir = to_copy._spir;
	  _agi = to_copy._agi;
	  Range = to_copy.Range;
	}
    }
  return (*this);
}
