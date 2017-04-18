#ifndef BORG_H_
# define BORG_H_

# include	<iostream>
# include	"Warpsystem.hh"
# include	"Destination.hh"

namespace	Borg
{
  class	Ship
  {
  private:

    int			_side;
    short		_maxWarp;
    WarpSystem::Core	*_core;
    Destination		_home;
    Destination		_location;

  public:
    Ship(Destination _home = UNICOMPLEX);
    void	setupCore(WarpSystem::Core *);
    void	checkCore();
    bool        move(int, Destination);
    bool        move(int);
    bool        move(Destination);
    bool        move(void);
    ~Ship();
  };
}

#endif /* !BORG_H_ */
