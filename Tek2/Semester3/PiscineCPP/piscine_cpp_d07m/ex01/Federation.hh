//
// Federation.hh for Fede in /home/moulin_c/rendu
// 
// Made by Galdan MOULINNEUF
// Login   <moulin_c@epitech.net>
// 
// Started on  Tue Jan 13 12:26:12 2015 Galdan MOULINNEUF
// Last update Tue Jan 13 15:50:12 2015 Galdan MOULINNEUF
//

#ifndef FEDERATION_H_
# define FEDERATION_H_

# include	<iostream>
# include	"Warpsystem.hh"

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
      int		_length;
      int		_width;
      std::string	_name;
      short		_maxWarp;
      WarpSystem::Core	*_core;
      Starfleet::Captain		*_captain;

    public:
      Ship(int, int, std::string, short);
      void		setupCore(WarpSystem::Core *);
      void		checkCore();
      void		promote(Captain *);
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

  public:
    Ship(int, int, std::string, short _maxWarp = 1);
    void		checkCore();
    void		setupCore(WarpSystem::Core *);
    ~Ship();
  };
}

#endif /* !FEDERATION_H_ */