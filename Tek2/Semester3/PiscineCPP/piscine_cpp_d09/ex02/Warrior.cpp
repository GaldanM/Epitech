//
// Character.cpp for Chara in /home/moulin_c/rendu/piscine_cpp_d09/ex00
// 
// Made by Galdan MOULINNEUF
// Login   <moulin_c@epitech.net>
// 
// Started on  Thu Jan 15 12:17:37 2015 Galdan MOULINNEUF
// Last update Fri Jan 16 09:02:06 2015 Galdan MOULINNEUF
//

#include	"Warrior.hh"

/* INIT */
Warrior::Warrior(const std::string name, int lvl) : Character(name, lvl), _weapon("hammer")
{
  this->_class = "Warrior";
  this->_race = "Dwarf";
  this->_str = 12;
  this->_sta = 12;
  this->_intel = 6;
  this->_spir = 5;
  this->_agi = 7;
  std::cout << "I'm " << name << " KKKKKKKKKKRRRRRRRRRRRRRREEEEEEEEOOOOOOORRRRGGGGGGG" << std::endl;
}

Warrior::Warrior(Warrior const &to_copy) : Character(to_copy), _weapon(to_copy._weapon)
{
  this->_class = to_copy._class;
  this->_race = to_copy._race;
  this->_str = to_copy._str;
  this->_sta = to_copy._sta;
  this->_intel = to_copy._intel;
  this->_spir = to_copy._spir;
  this->_agi = to_copy._agi;
}

Warrior::~Warrior()
{

}

/* GETTERS */

std::string	Warrior::getweaponName() const
{
  return (this->_weapon);
}

/* OTHERS */

int		Warrior::CloseAttack()
{
  if (this->_energy >= 30)
    {
      this->_energy -= 30;
      std::cout << this->_name << " strikes with his " << this->_weapon << std::endl;
      return (this->_str + 20);
    }
  std::cout << this->_name << " out of power" << std::endl;
  return (0);
}

int		Warrior::RangeAttack()
{
  if (this->_energy >= 10)
    {
      this->_energy -= 10;
      std::cout << this->_name << " intercepts" << std::endl;
      this->Range = Character::CLOSE;
      return (0);
    }
  std::cout << this->_name << " out of power" << std::endl;
  return (0);
}

/* OPERATORS */

Warrior&	Warrior::operator=(Warrior const &to_copy)
{
  if (&to_copy)
    {
      if (to_copy._name != _name || to_copy._lvl != _lvl || to_copy._life != _life || to_copy._energy != _energy || to_copy._str != _str || to_copy._sta != _sta || to_copy._intel != _intel || to_copy._spir != _spir || to_copy._agi != _agi || to_copy.Range != Range)
	{
	  _race = to_copy._race;
	  _class = to_copy._class;
	  _weapon = to_copy._weapon;
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
