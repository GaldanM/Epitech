//
// Graphic.hh for Graphique in /home/doghri_f/Downloads/Graph
// 
// Made by Fares Doghri
// Login   <doghri_f@epitech.net>
// 
// Started on  Sun Jul  5 22:27:19 2015 Fares Doghri
// Last update Sun Jul  5 22:27:57 2015 Fares Doghri
//

#ifndef GRAPHIC_HH_
# define GRAPHIC_HH_

# include <iostream>
# include <string>
# include <sstream>

# include <SFML/Window.hpp>
# include <SFML/Graphics.hpp>
# include <SFML/System.hpp>

# include "Client.hh"
# include "Player.hh"

# define NB_TEXTURE 13

class Graphic : public Client
{
public:
  Graphic(std::string const &, int);
  ~Graphic();
private:
  void	init();
  void 	initMap();
  void	start();
  void	event();
  void 	readMap();
  void 	drawSprite(std::map<std::string, int> &, int, int);

  void 	mapSize(std::string &);
  void 	inBox(std::string &);
  void 	getTeamName(std::string &);
  void 	newPlayerConnected(std::string &);
  void 	positionPlayer(std::string &);
  void	levelPlayer(std::string &);
  void 	inventairePlayer(std::string &);
  void 	expulsion(std::string &);
  void 	messageBroad(std::string &);
  void 	startIncantation(std::string &);
  void 	endIncantation(std::string &);
  void 	layEggs(std::string &);
  void 	playersDead(std::string &);
  void 	newEggs(std::string &);
  void 	hatch(std::string &);
  void 	endGame(std::string &);

  bool 	isInit();
  std::vector<std::string> splitStr(std::string &);

  bool 				_isInit;

  bool 				_isEnd;

  int 				_mapX;
  int 				_mapY;

  int 				_viewX;
  int 				_viewY;

  sf::RenderWindow 	_window;
  sf::Sprite 			_sprite;
  sf::View 			_view;

  std::map<int, sf::Image>	_image;
  std::map<int, sf::Texture> 	_texture;

  std::map<int, sf::IntRect>	_direction;
  std::map<int, sf::IntRect> 	_crystal;
  std::map<int, sf::IntRect>  _object;

  std::vector<std::vector<std::map<std::string, int> > > _map;
  std::vector<std::string> 			_teamName;

  std::vector<Player *> 				_players;
  std::vector<std::pair<std::pair<int, bool>, std::pair<int, int> > > 	_eggs;

  std::vector<std::pair<std::pair<bool, int>, std::pair<int, int> > > _isIncant;

  typedef void (Graphic::*ptr)(std::string &);
  std::map<std::string, Graphic::ptr> _funPtr;
};

#endif //GRAPHIC_HH_
