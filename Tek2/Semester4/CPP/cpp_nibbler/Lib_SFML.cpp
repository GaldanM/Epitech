//
// Created by Galdan on 3/24/15.
//

#include <unistd.h>
#include "Lib_SFML.h"
#include "Game.h"
#include "MyError.h"

MySFML::MySFML(const Game &game) : _x(game.getWidth() * SQUARE_SIZE), _y(game.getHeight() * SQUARE_SIZE)
{
  _edgeSizeY = _y / 19;
  _edgeSizeX = _x / 20;
}

MySFML::~MySFML()
{

}

extern "C"
{
    ILibsDisplay    *create_lib(const Game &game)
    {
        return new MySFML(game);
    }
}

void    MySFML::makeSquare(int x, int y, sf::Color color)
{
  sf::Shape square;

  square.AddPoint(x, y, color, sf::Color(255, 255, 255));
  square.AddPoint(x + SQUARE_SIZE, y, color, sf::Color(255, 255, 255));
  square.AddPoint(x + SQUARE_SIZE, y + SQUARE_SIZE, color, sf::Color(255, 255, 255));
  square.AddPoint(x, y + SQUARE_SIZE, color, sf::Color(255, 255, 255));
  square.EnableFill(true);
  square.EnableOutline(false);
  square.SetOutlineWidth(1);
  _squares.push_back(square);
}

void    MySFML::displayMap(Game &game)
{
  int x = _edgeSizeX;
  int y = _edgeSizeY;
  std::vector<std::vector<int> > map = game.getMap();

  for (std::vector<std::vector<int> >::iterator it = map.begin(); it != map.end(); ++it)
    {
      x = _edgeSizeX;
      for (std::vector<int>::iterator jt = (*it).begin(); jt != (*it).end(); ++jt)
	{
	  if (*jt == Game::SNAKE)
	    makeSquare(x, y, sf::Color(141, 0, 0));
      else if (*jt == Game::FOOD)
        makeSquare(x, y, sf::Color(21, 96, 189));
      else if (*jt == Game::S_FOOD)
        makeSquare(x, y, sf::Color(255, 153, 51));
	  else
	    makeSquare(x, y, sf::Color(0, 0, 0, 0));
	  x = x + SQUARE_SIZE;
	}
      y = y + SQUARE_SIZE;
    }
}

void    MySFML::setBackground()
{
  sf::Image *Background = new sf::Image;

  Background->LoadFromFile("Images/Map_poknibler.png");
  _SBackGround.SetImage(*Background);
  _SBackGround.Resize(_x + (_edgeSizeX * 2), _y + (_edgeSizeY * 2));
}

void    MySFML::manageEvents(sf::RenderWindow *app, Game &game)
{
  int         direction;
  sf::Event event;

  direction = AHEAD;
  while (app->GetEvent(event))
    {
      if (event.Type == sf::Event::Closed || event.Key.Code == sf::Key::Escape)
	{
	  app->Close();
	  throw MyError("Game Over !!");
	}
      if (event.Type == sf::Event::KeyPressed)
        {
	  if (event.Key.Code == sf::Key::Left)
	    direction = LEFT;
	  else if (event.Key.Code == sf::Key::Right)
	    direction = RIGHT;
        }
    }
  game.updateMap(direction);
}

void    MySFML::drawMap(sf::RenderWindow *app)
{
    for (std::vector<sf::Shape>::iterator it = _squares.begin(); it != _squares.end(); ++it)
         app->Draw(*it);
    _squares.clear();
    app->Display();
}

void    MySFML::playGame(sf::RenderWindow *app, Game &game)
{
  manageEvents(app, game);
  displayMap(game);
  app->Clear();
  app->Draw(_SBackGround);
  drawMap(app);
  usleep(50000);
}

void	MySFML::startGame(Game &game)
{
  sf::RenderWindow app(sf::VideoMode(_x + (_edgeSizeX * 2), _y + (_edgeSizeY * 2), 32), "Nibbler");

  setBackground();
  app.EnableKeyRepeat(false);
  while (app.IsOpened())
    playGame(&app, game);
}
