//
// Character.cpp for Chara in /home/moulin_c/rendu/piscine_cpp_d09/ex00
// 
// Made by Galdan MOULINNEUF
// Login   <moulin_c@epitech.net>
// 
// Started on  Thu Jan 15 12:17:37 2015 Galdan MOULINNEUF
// Last update Thu Jan 15 21:09:58 2015 Galdan MOULINNEUF
//

#include	"Character.hh"

/* INIT */
Character::Character(const std::string &name, int lvl) : _name(name), _class("Character"), _race("Koala"), _lvl(lvl), _life(100), _energy(100), _str(5), _sta(5), _intel(5), _spir(5), _agi(5)
{
  this->Range = Character::CLOSE;
  std::cout << name << " Created" << std::endl;
}

Character::Character(Character const &to_copy) : _name(to_copy._name), _class(to_copy._class), _race(to_copy._race), _lvl(to_copy._lvl),_life(to_copy._life), _energy(to_copy._energy), _str(to_copy._str), _sta(to_copy._sta), _intel(to_copy._intel), _spir(to_copy._spir), _agi(to_copy._agi), Range(to_copy.Range)
{

}

Character::~Character()
{

}

    /* GETTERS */

std::string	Character::getName() const
{
  return (this->_name);
}

std::string	Character::getClass() const
{
  return (this->_class);
}

std::string	Character::getRace() const
{
  return (this->_race);
}

int		Character::getLvl() const
{
  return (this->_lvl);
}

int		Character::getPv() const
{
  return (this->_life);
}

int		Character::getPower() const
{
  return (this->_energy);
}

int		Character::getStrenght() const
{
  return (this->_str);
}

int		Character::getStamina() const
{
  return (this->_sta);
}

int		Character::getIntelligence() const
{
  return (this->_intel);
}

int		Character::getSpirit() const
{
  return (this->_spir);
}

int		Character::getAgility() const
{
  return (this->_agi);
}

/* OTHERS */

int		Character::CloseAttack()
{
  if (this->_energy >= 10)
    {
      this->_energy -= 10;
      std::cout << this->_name << " strikes with a wood stick" << std::endl;
      return (this->_str + 10);
    }
  std::cout << this->_name << " out of power" << std::endl;
  return (0);
}

int		Character::RangeAttack()
{
  if (this->_energy >= 10)
    {
      this->_energy -= 10;
      std::cout << this->_name << " launches a stone" << std::endl;
      return (this->_str + 5);
    }
  std::cout << this->_name << " out of power" << std::endl;
  return (0);
}

void		Character::Heal()
{
  this->_life += 50;
  if (this->_life > 100)
    this->_life = 100;
  std::cout << this->_name << " takes a potion" << std::endl;
}

void		Character::RestorePower()
{
  this->_energy = 100;
  std::cout << this->_name << " eats" << std::endl;
}

void		Character::TakeDamage(int _damage)
{
  if (this->_life > _damage)
    {
      this->_life -= _damage;
      std::cout << this->_name << " takes " << _damage << " damage" << std::endl;
    }
  else
    std::cout << this->_name << " out of combat" << std::endl;
}

/* OPERATORS */

Character&	Character::operator=(Character const &to_copy)
{
  if (&to_copy)
    {
      if (to_copy._name != _name || to_copy._lvl != _lvl || to_copy._life != _life || to_copy._energy != _energy || to_copy._str != _str || to_copy._sta != _sta || to_copy._intel != _intel || to_copy._spir != _spir || to_copy._agi != _agi || to_copy.Range != Range|| to_copy._race != _race || to_copy._class != _class)
	{
	  _lvl = to_copy._lvl;
	  _race = to_copy._race;
	  _class = to_copy._class;
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
