//
// Federation.hh for Fede in /home/moulin_c/rendu
// 
// Made by Galdan MOULINNEUF
// Login   <moulin_c@epitech.net>
// 
// Started on  Tue Jan 13 12:26:12 2015 Galdan MOULINNEUF
// Last update Tue Jan 13 16:45:15 2015 Galdan MOULINNEUF
//

#ifndef FEDERATION_H_
# define FEDERATION_H_

# include	<iostream>
# include	"Warpsystem.hh"
# include	"Destination.hh"

namespace	Federation
{
  namespace	Starfleet
  {

    /* CAPTAIN STARFLEET */
    class	Captain
    {
    private:
      std::string	_name;
      int		_age;

    public:
      Captain(std::string name);
      std::string	getName();
      int		getAge();
      void		setAge(int);
      ~Captain();
    };

    /* SHIP STARFLEET */
    class	Ship
    {
    private:
      int			_length;
      int			_width;
      std::string		_name;
      short			_maxWarp;
      WarpSystem::Core		*_core;
      Starfleet::Captain	*_captain;
      Destination		_location;
      Destination		_home;

    public:
      Ship(int, int, std::string, short, Destination _home = EARTH);
      void		setupCore(WarpSystem::Core *);
      void		checkCore(void);
      void		promote(Captain *);
      bool		move(int, Destination);
      bool		move(int);
      bool		move(Destination);
      bool		move(void);
      ~Ship();
    };

    // ENSIGN STARFLEET
    class	Ensign
    {
    private:
      std::string	_name;

    public:
      explicit Ensign(std::string name);
      ~Ensign();
    };
  }

  /* SHIP INDEP */
  class	Ship
  {
  private:
    int			_length;
    int			_width;
    std::string		_name;
    short		_maxWarp;
    WarpSystem::Core	*_core;
    Destination		_location;
    Destination		_home;

  public:
    Ship(int, int, std::string, short _maxWarp = 1, Destination _home = VULCAN);
    void		checkCore();
    void		setupCore(WarpSystem::Core *);
      bool		move(int, Destination);
      bool		move(int);
      bool		move(Destination);
    bool		move(void);
    ~Ship();
  };
}

#endif /* !FEDERATION_H_ */
