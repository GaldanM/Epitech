//
// Character.cpp for Chara in /home/moulin_c/rendu/piscine_cpp_d09/ex00
// 
// Made by Galdan MOULINNEUF
// Login   <moulin_c@epitech.net>
// 
// Started on  Thu Jan 15 12:17:37 2015 Galdan MOULINNEUF
// Last update Fri Jan 16 09:48:21 2015 Galdan MOULINNEUF
//

#include	"Priest.hh"

/* INIT */
Priest::Priest(const std::string name, int lvl) : Mage(name, lvl)
{
  this->_class = "Priest";
  this->_race = "Orc";
  this->_str = 4;
  this->_sta = 4;
  this->_intel = 42;
  this->_spir = 21;
  this->_agi = 2;
  std::cout << name << " enters in the order" << std::endl;
}

Priest::Priest(Priest const &to_copy) : Mage(to_copy)
{
  this->_class = to_copy._class;
  this->_race = to_copy._race;
  this->_str = to_copy._str;
  this->_sta = to_copy._sta;
  this->_intel = to_copy._intel;
  this->_spir = to_copy._spir;
  this->_agi = to_copy._agi;
}

Priest::~Priest()
{

}

/* OTHERS */

int		Priest::CloseAttack()
{
  if (this->_energy >= 10)
    {
      this->_energy -= 10;
      std::cout << this->_name << " uses a spirit explosion" << std::endl;
      return (this->_spir + 10);
    }
  std::cout << this->_name << " out of power" << std::endl;
  return (0);
}

void		Priest::Heal()
{
  this->_life += 70;
  if (this->_life > 100)
    this->_life = 100;
  std::cout << this->_name << " takes a mana potion" << std::endl;
}

/* OPERATORS */

Priest&	Priest::operator=(Priest const &to_copy)
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
