//
// Character.hh for Char in /home/moulin_c/rendu/piscine_cpp_d09/ex00
// 
// Made by Galdan MOULINNEUF
// Login   <moulin_c@epitech.net>
// 
// Started on  Thu Jan 15 12:03:55 2015 Galdan MOULINNEUF
// Last update Fri Jan 16 09:44:44 2015 Galdan MOULINNEUF
//

#ifndef MAGE_H_
#define MAGE_H_

# include <string>
# include <iostream>
# include "Character.hh"

class	Mage : public Character
{
public:
  /* INIT */
  Mage(const std::string , int);
  Mage(Mage const &);
  ~Mage();

  /* OTHERS */
  int	CloseAttack();
  int	RangeAttack();
  void	RestorePower();

  /* OPERATORS */
  Mage&	operator=(Mage const &);

};

#endif /* !MAGE_H_*/
