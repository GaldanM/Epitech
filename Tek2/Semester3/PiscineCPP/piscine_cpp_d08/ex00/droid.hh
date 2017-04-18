//
// droid.hh for droid in /home/moulin_c/rendu/piscine_cpp_d08
// 
// Made by Galdan MOULINNEUF
// Login   <moulin_c@epitech.net>
// 
// Started on  Wed Jan 14 10:52:07 2015 Galdan MOULINNEUF
// Last update Thu Jan 15 09:00:51 2015 Galdan MOULINNEUF
//

#ifndef DROID_H_
# define DROID_H_

# include	<cstddef>
# include	<string>
# include	<iostream>

class	Droid
{
private:
  std::string	_ID;
  size_t	_Energy;
  size_t const	_Attack;
  size_t const	_Toughness;
  std::string*	_Status;

public:
  /* INIT */
  Droid(std::string = "");
  Droid(Droid const &);
  ~Droid();

  /* GETTERS */
  std::string	getId() const;
  size_t	getEnergy() const;
  size_t	getAttack() const;
  size_t	getToughness() const;
  std::string	*getStatus() const;

  /* SETTERS */
  void		setId(std::string);
  void		setEnergy(size_t);
  void		setStatus(std::string *);

  /* OPERATORS */
  Droid&	operator=(Droid const &);
  bool		operator==(Droid const &) const;
  bool		operator!=(Droid const &) const;
  Droid&	operator<<(size_t &);
};

std::ostream&	operator<<(std::ostream&, Droid const &);

#endif /* !DROID_H_ */
