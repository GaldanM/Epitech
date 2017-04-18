//
// Character.hh for Char in /home/moulin_c/rendu/piscine_cpp_d09/ex00
// 
// Made by Galdan MOULINNEUF
// Login   <moulin_c@epitech.net>
// 
// Started on  Thu Jan 15 12:03:55 2015 Galdan MOULINNEUF
// Last update Fri Jan 16 09:47:37 2015 Galdan MOULINNEUF
//

#ifndef PRIEST_H_
#define PRIEST_H_

# include <string>
# include <iostream>
# include "Mage.hh"

class	Priest : public Mage
{
public:
  /* INIT */
  Priest(const std::string , int);
  Priest(Priest const &);
  ~Priest();

  /* OTHERS */
  int	CloseAttack();
  void	Heal();

  /* OPERATORS */
  Priest&	operator=(Priest const &);

};

#endif /* !PRIEST_H_*/
