//
// Character.hh for Char in /home/moulin_c/rendu/piscine_cpp_d09/ex00
// 
// Made by Galdan MOULINNEUF
// Login   <moulin_c@epitech.net>
// 
// Started on  Thu Jan 15 12:03:55 2015 Galdan MOULINNEUF
// Last update Thu Jan 15 20:20:37 2015 Galdan MOULINNEUF
//

#ifndef WARRIOR_H_
#define WARRIOR_H_

# include <string>
# include <iostream>
# include "Character.hh"

class	Warrior : public Character
{
protected:
  std::string	_weapon;

public:
  /* INIT */
  Warrior(const std::string , int);
  Warrior(Warrior const &);
  ~Warrior();

  /* GETTERS*/
  std::string	getweaponName() const;

  /* OTHERS */
  int	CloseAttack();
  int	RangeAttack();

  /* OPERATORS */
  Warrior&	operator=(Warrior const &);

};

#endif /* !WARRIOR_H_*/
