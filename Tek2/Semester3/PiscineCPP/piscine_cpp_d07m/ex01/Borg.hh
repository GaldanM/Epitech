//
// Borg.hh for borg in /home/moulin_c/rendu/piscine_cpp_d07m/ex01
// 
// Made by Galdan MOULINNEUF
// Login   <moulin_c@epitech.net>
// 
// Started on  Tue Jan 13 19:19:36 2015 Galdan MOULINNEUF
// Last update Tue Jan 13 20:00:51 2015 Galdan MOULINNEUF
//

#ifndef BORG_H_
# define BORG_H_

# include	<iostream>
# include	"Warpsystem.hh"

namespace	Borg
{
  class	Ship
  {
  private:

    int			_side;
    short		_maxWarp;
    WarpSystem::Core	*_core;

  public:
    Ship();
    void	setupCore(WarpSystem::Core *);
    void	checkCore();
    ~Ship();
  };
}

#endif /* !BORG_H_ */
