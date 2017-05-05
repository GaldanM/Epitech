//
// Created by moulin_c on 3/24/15.
//

#ifndef _SFMLIC_SDL_H_
# define _SFMLIC_SDL_H_

# include <iostream>
# include <sstream>
# include <vector>
# include <SFML/Graphics.hpp>
# include "Game.h"
# include "ILibsDisplay.h"

# define SQUARE_SIZE 25

class MySFML : public ILibsDisplay
{
  int     						_x;
  int     						_y;
  int                             _edgeSizeX;
  int                             _edgeSizeY;
  sf::Sprite 						_SBackGround;
  std::vector<std::vector<int> >	_map;
  std::vector<sf::Shape> 			_squares;

 public:
  MySFML(const Game&);
  MySFML(const MySFML&);
  ~MySFML();
  MySFML&	      operator=(const MySFML&);

  virtual void	startGame(Game&);

 private:
  void        makeSquare(int, int, sf::Color);
  void        displayMap(Game&);
  void        setBackground();
  void        manageEvents(sf::RenderWindow*, Game&);
  void        drawMap(sf::RenderWindow*);
  void	      playGame(sf::RenderWindow*, Game&);
};

#endif //_SFMLIC_SDL_H_
