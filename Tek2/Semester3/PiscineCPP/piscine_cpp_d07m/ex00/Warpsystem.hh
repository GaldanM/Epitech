//
// Warpsystem.hh for Fede in /home/moulin_c/rendu
// 
// Made by Galdan MOULINNEUF
// Login   <moulin_c@epitech.net>
// 
// Started on  Tue Jan 13 12:26:06 2015 Galdan MOULINNEUF
// Last update Tue Jan 13 15:39:07 2015 Galdan MOULINNEUF
//

#ifndef WARP_H_
# define WARP_H_

#include	<iostream>

namespace	WarpSystem
{
  class	QuantumReactor
  {
  private:
    bool	_stability;

  public:

    QuantumReactor(bool _stability = true);
    bool	isStable();
    void	setStability(bool);
    ~QuantumReactor();
  };

  class	Core
  {
  private:
    QuantumReactor	*_coreReactor;

  public:
    Core(QuantumReactor *);
    QuantumReactor	*checkReactor();
    ~Core();
  };
}

#endif /* !WARP_H_*/
