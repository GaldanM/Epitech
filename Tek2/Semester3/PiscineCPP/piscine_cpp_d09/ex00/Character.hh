//
// Character.hh for Char in /home/moulin_c/rendu/piscine_cpp_d09/ex00
// 
// Made by Galdan MOULINNEUF
// Login   <moulin_c@epitech.net>
// 
// Started on  Thu Jan 15 12:03:55 2015 Galdan MOULINNEUF
// Last update Thu Jan 15 20:51:35 2015 Galdan MOULINNEUF
//

#ifndef CHARACTER_H_
#define CHARACTER_H_

# include <string>
# include <iostream>

class	Character
{
protected:
  std::string const	_name;
  std::string		_class;
  std::string		_race;
  int			_lvl;
  int			_life;
  int			_energy;
  int			_str;
  int			_sta;
  int			_intel;
  int			_spir;
  int			_agi;

public:
  typedef enum	AttackRange
    {
      CLOSE,
      RANGE
    }		AttackRange;
  AttackRange		Range;

public:
  /* INIT */
  Character(const std::string &, int);
  Character(Character const &);
  ~Character();

  /* GETTERS */
  std::string	getName() const;
  std::string	getClass() const;
  std::string	getRace() const;
  int		getLvl() const;
  int		getPv() const;
  int		getPower() const;
  int		getStrenght() const;
  int		getStamina() const;
  int		getIntelligence() const;
  int		getSpirit() const;
  int		getAgility() const;

  /* OTHERS */
  int		CloseAttack();
  int		RangeAttack();
  void		Heal();
  void		RestorePower();
  void		TakeDamage(int);

  /* OPERATORS */
  Character&	operator=(Character const &);

};

#endif /* !CHARACTER_H_*/
