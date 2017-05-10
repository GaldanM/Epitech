//
// Graphic.cpp for Graphique in /home/doghri_f/Downloads/Graph
// 
// Made by Fares Doghri
// Login   <doghri_f@epitech.net>
// 
// Started on  Sun Jul  5 21:16:56 2015 Fares Doghri
// Last update Sun Jul  5 21:19:11 2015 Fares Doghri
//

#include "Graphic.hh"
#include <unistd.h>

Graphic::Graphic(std::string const &ip, int port)
  : Client (ip, port), _isInit(false), _isEnd(false), _mapX(0), _mapY(0), _viewX(1400), _viewY(800)
{
  connectToServer();
  receiveFromServer();
  std::string buf = _buf;
  if (buf.compare("BIENVENUE\n") != 0)
    throw MyError("Wrong message");

  sendToServer("GRAPHIC\n");
  receiveFromServer();

  _funPtr["msz"] = &Graphic::mapSize;
  _funPtr["bct"] = &Graphic::inBox;
  _funPtr["tna"] = &Graphic::getTeamName;
  _funPtr["pnw"] = &Graphic::newPlayerConnected;
  _funPtr["ppo"] = &Graphic::positionPlayer;
  _funPtr["plv"] = &Graphic::levelPlayer;
  _funPtr["pin"] = &Graphic::inventairePlayer;
  _funPtr["pex"] = &Graphic::expulsion;
  _funPtr["pbc"] = &Graphic::messageBroad;
  _funPtr["pic"] = &Graphic::startIncantation;
  _funPtr["pie"] = &Graphic::endIncantation;
  _funPtr["pfk"] = &Graphic::layEggs;
  _funPtr["pdi"] = &Graphic::playersDead;
  _funPtr["enw"] = &Graphic::newEggs;
  _funPtr["eht"] = &Graphic::hatch;
  _funPtr["seg"] = &Graphic::endGame;

  _direction[0] = sf::IntRect(32, 96, 32, 32);
  _direction[1] = sf::IntRect(32, 64, 32, 32);
  _direction[2] = sf::IntRect(32, 0, 32, 32);
  _direction[3] = sf::IntRect(32, 32, 32, 32);

  _crystal[0] = sf::IntRect(sf::IntRect(0, 0, 52, 90));
  _crystal[1] = sf::IntRect(sf::IntRect(52, 0, 52, 90));
  _crystal[2] = sf::IntRect(sf::IntRect(104, 0, 52, 90));
  _crystal[3] = sf::IntRect(sf::IntRect(156, 0, 52, 90));
  _crystal[4] = sf::IntRect(sf::IntRect(208, 0, 52, 90));
  _crystal[5] = sf::IntRect(sf::IntRect(260, 0, 52, 90));
  _crystal[6] = sf::IntRect(sf::IntRect(315, 0, 52, 90));

  _object[0] = sf::IntRect(sf::IntRect(0, 0, 16, 18));
  _object[1] = sf::IntRect(sf::IntRect(16, 0, 16, 18));
  _object[2] = sf::IntRect(sf::IntRect(32, 0, 16, 18));
  _object[3] = sf::IntRect(sf::IntRect(48, 0, 16, 18));
  _object[4] = sf::IntRect(sf::IntRect(64, 0, 16, 18));
  _object[5] = sf::IntRect(sf::IntRect(80, 0, 16, 18));
  _object[6] = sf::IntRect(sf::IntRect(96, 0, 16, 18));

  init();
  start();
}

Graphic::~Graphic()
{

}

void 		Graphic::init()
{
  std::vector<std::string>	image;

  _window.create(sf::VideoMode(1400, 800), "Zappy",
		 sf::Style::Close | sf::Style::Titlebar);

  _window.setFramerateLimit(60);

  image.push_back("bleu.jpg");
  image.push_back("green.png");

  image.push_back("player1.png");
  image.push_back("player2.png");
  image.push_back("player3.png");
  image.push_back("player4.png");
  image.push_back("player5.png");
  image.push_back("player6.png");
  image.push_back("player7.png");

  image.push_back("crystals.bmp");
  image.push_back("egg.bmp");
  image.push_back("fork.bmp");
  image.push_back("resources.bmp");

  for (int i = 0; i < NB_TEXTURE; ++i)
    {
      sf::Image Image;
      _image[i] = Image;
    }

  int count = 0;
  for (std::map<int, sf::Image>::iterator it = _image.begin(); it != _image.end(); ++it)
    {
      if (!it->second.loadFromFile(image[count]))
	std::cerr << "Erreur durant le chargement de l'image" << std::endl;

      if (count > 8)
	_image[count].createMaskFromColor(sf::Color::Blue);
      else
	_image[count].createMaskFromColor(sf::Color::White);
      if (!_texture[count].loadFromImage(_image[count]))
	std::cerr << "Erreur durant le chargement de la texture" << std::endl;

      ++count;
    }
  initMap();
}

std::vector<std::string> 	Graphic::splitStr(std::string &str)
{
  std::string 			tmp("");
  std::vector<std::string> cmd;

  for (std::string::iterator it = str.begin(); it != str.end(); ++it)
    {
      if ((*it) == ' ' || (*it) == '\n')
	{
	  cmd.push_back(tmp);
	  tmp = "";
	}
      else
	tmp += (*it);
    }

  return (cmd);
}

bool 		Graphic::isInit()
{
  return (_isInit);
}

void 		Graphic::mapSize(std::string &str)
{
  std::vector<std::string> cmd = splitStr(str);

  if (cmd.size() != 3)
    throw MyError("#1 mapSize wrong cmd");

  if (isInit() == false)
    {
      int x = 0;
      int y = 0;

      std::vector<std::map<std::string, int> > vec;
      std::map<std::string, int> map;

      map["nourriture"] = 0;
      map["linemate"] = 0;
      map["deraumere"] = 0;
      map["sibur"] = 0;
      map["mendian"] = 0;
      map["phiras"] = 0;
      map["thystame"] = 0;

      _mapX = std::atoi(cmd[1].c_str());
      _mapY = std::atoi(cmd[2].c_str());

      if (_mapX < 0 && _mapY < 0)
	throw MyError("Wrong size map");
      while (y < _mapY)
	{
	  _map.push_back(vec);
	  while (x < _mapX)
	    {
	      _map[y].push_back(map);
	      ++x;
	    }
	  x = 0;
	  ++y;
	}
      _isInit = true;
    }
}

void 		Graphic::inBox(std::string &str)
{
  std::vector<std::string> cmd = splitStr(str);

  if (cmd.size() != 10)
    throw MyError("#1 wrong command in box");

  int x = std::atoi(cmd[1].c_str());
  int y = std::atoi(cmd[2].c_str());

  if (x > _mapX || x < 0 || y > _mapY || y < 0)
    throw MyError("Wrong parameters");

  _map[y][x]["nourriture"] = std::atoi(cmd[3].c_str());
  _map[y][x]["linemate"] = std::atoi(cmd[4].c_str());
  _map[y][x]["deraumere"] = std::atoi(cmd[5].c_str());
  _map[y][x]["sibur"] = std::atoi(cmd[6].c_str());
  _map[y][x]["mendian"] = std::atoi(cmd[7].c_str());
  _map[y][x]["phiras"] = std::atoi(cmd[8].c_str());
  _map[y][x]["thystame"] = std::atoi(cmd[9].c_str());
}

void 		Graphic::getTeamName(std::string &str)
{
  bool 	key = true;
  std::vector<std::string> cmd = splitStr(str);

  if (cmd.size() != 2)
    throw MyError("Wrong parameters");

  for (std::vector<std::string>::iterator it = _teamName.begin(); it != _teamName.end(); ++it)
    {
      if ((*it) == cmd[1])
	key = false;
    }
  if (key)
    _teamName.push_back(cmd[1]);
}

void 		Graphic::newPlayerConnected(std::string &str)
{
  std::vector<std::string> cmd = splitStr(str);

  if (cmd.size() != 7)
    throw MyError("Wrong parameters");

  int x = std::atoi(cmd[2].c_str());
  int y = std::atoi(cmd[3].c_str());

  if (x > _mapX || x < 0 || y > _mapY || y < 0)
    throw MyError("Wrong parameters");

  if (!(std::atoi(cmd[4].c_str()) > 0 && std::atoi(cmd[4].c_str()) < 5))
    throw MyError("Wrong parameters");

  Player 	 	*player = new Player(y, x, std::atoi(cmd[1].c_str()), std::atoi(cmd[4].c_str()), std::atoi(cmd[5].c_str()), cmd[6]);

  _players.push_back(player);
}

void 	Graphic::positionPlayer(std::string &str)
{
  std::vector<std::string> cmd = splitStr(str);

  if (cmd.size() != 5)
    throw MyError("Wrong parameters");

  int x = std::atoi(cmd[2].c_str());
  int y = std::atoi(cmd[3].c_str());

  if (x > _mapX || x < 0 || y > _mapY || y < 0)
    throw MyError("Wrong parameters");

  if (!(std::atoi(cmd[4].c_str()) > 0 && std::atoi(cmd[4].c_str()) < 5))
    throw MyError("Wrong parameters");

  unsigned int i = 0;
  while (i < _players.size())
    {
      if (_players[i]->getId() == std::atoi(cmd[1].c_str()))
	{
	  _players[i]->setX(x);
	  _players[i]->setY(y);
	  _players[i]->setDirection(std::atoi(cmd[4].c_str()));
	}
      ++i;
    }
}

void 	Graphic::levelPlayer(std::string &str)
{
  std::vector<std::string> cmd = splitStr(str);

  if (cmd.size() != 3)
    throw MyError("Wrong parameters");

  if (std::atoi(cmd[2].c_str()) < 0)
    throw MyError("Wrong parameters");

  unsigned int i = 0;
  while (i < _players.size())
    {
      if (_players[i]->getId() == std::atoi(cmd[1].c_str()))
	_players[i]->setLevel(std::atoi(cmd[2].c_str()));
      ++i;
    }
}

void 		Graphic::inventairePlayer(std::string &str)
{
  std::vector<std::string> cmd = splitStr(str);

  if (cmd.size() != 11)
    throw MyError("Wrong parameters");

  int x = std::atoi(cmd[2].c_str());
  int y = std::atoi(cmd[3].c_str());

  if (x > _mapX || x < 0 || y > _mapY || y < 0)
    throw MyError("Wrong parameters");

  std::map<std::string, int> save;

  save["nourriture"] = std::atoi(cmd[4].c_str());
  save["linemate"] = std::atoi(cmd[5].c_str());
  save["deraumere"] = std::atoi(cmd[6].c_str());
  save["sibur"] = std::atoi(cmd[7].c_str());
  save["mendian"] = std::atoi(cmd[8].c_str());
  save["phiras"] = std::atoi(cmd[9].c_str());
  save["thystame"] = std::atoi(cmd[10].c_str());

  unsigned int i = 0;
  while (i < _players.size())
    {
      if (_players[i]->getId() == std::atoi(cmd[1].c_str()))
	{
	  _players[i]->setX(x);
	  _players[i]->setY(y);
	  _players[i]->setInventaire(save);
	}
      ++i;
    }
}

void 		Graphic::expulsion(std::string &str)
{
  std::vector<std::string> cmd = splitStr(str);

  if (cmd.size() != 2)
    throw MyError("Wrong parameters");
}

void 	Graphic::messageBroad(std::string &str)
{
  std::vector<std::string> cmd = splitStr(str);

  if (cmd.size() < 3)
    throw MyError("Wrong parameters");
}

void 	Graphic::startIncantation(std::string &str)
{
  std::vector<std::string> cmd = splitStr(str);

  if (cmd.size() < 5)
    throw MyError("Wrong parameters");

  int x = std::atoi(cmd[1].c_str());
  int y = std::atoi(cmd[2].c_str());

  if (x > _mapX || x < 0 || y > _mapY || y < 0)
    throw MyError("Wrong parameters");

  std::pair<int, int>	save;

  save.first = y;
  save.second = x;

  std::pair<std::pair<bool, int>, std::pair<int, int> > save2;

  save2.first.first = true;
  save2.first.second = std::atoi(cmd[3].c_str());
  save2.second = save;

  _isIncant.push_back(save2);
}

void 	Graphic::endIncantation(std::string &str)
{
  std::vector<std::string> cmd = splitStr(str);

  if (cmd.size() != 4)
    throw MyError("Wrong parameters");

  int x = std::atoi(cmd[1].c_str());
  int y = std::atoi(cmd[2].c_str());

  if (x > _mapX || x < 0 || y > _mapY || y < 0)
    throw MyError("Wrong parameters");

  for (std::vector<std::pair<std::pair<bool, int>, std::pair<int, int> > >::iterator it = _isIncant.begin(); it != _isIncant.end(); ++it)
    {
      if (it->first.first == true)
	{
	  if (it->second.first == y && it->second.second == x)
	    it->first.first = false;
	}
    }
}

void 	Graphic::layEggs(std::string &str)
{
  std::vector<std::string> cmd = splitStr(str);

  if (cmd.size() != 2)
    throw MyError("Wrong parameters");
}

void  	Graphic::playersDead(std::string &str)
{
  std::vector<std::string> cmd = splitStr(str);

  if (cmd.size() != 2)
    throw MyError("Wrong parameters");

  unsigned int i = 0;
  while (i < _players.size())
    {
      if (_players[i]->getId() == std::atoi(cmd[1].c_str()))
	_players.erase(_players.begin() + i);
      ++i;
    }
}

void 		Graphic::newEggs(std::string &str)
{
  std::vector<std::string> cmd = splitStr(str);

  if (cmd.size() != 5)
    throw MyError("Wrong parameters");
  int x = std::atoi(cmd[3].c_str());
  int y = std::atoi(cmd[4].c_str());

  if (x > _mapX || x < 0 || y > _mapY || y < 0)
    throw MyError("Wrong parameters");

  std::pair<std::pair<int, bool>, std::pair<int , int> > save;

  save.first.first = std::atoi(cmd[2].c_str());
  save.first.second = false;
  save.second.first = y;
  save.second.second = x;
  _eggs.push_back(save);
}

void 		Graphic::hatch(std::string &str)
{
  std::vector<std::string> cmd = splitStr(str);

  if (cmd.size() != 2)
    throw MyError("Wrong parameters");
}

void 		Graphic::endGame(std::string &str)
{
  std::vector<std::string> cmd = splitStr(str);

  if (cmd.size() != 2)
    throw MyError("Wrong parameters");

  _isEnd = true;
}

void 		Graphic::initMap()
{
  std::string	buf = _buf;
  std::string tmp("");
  std::vector<std::string> cmd;

  for (std::string::iterator it = buf.begin(); it != buf.end(); ++it)
    {
      if ((*it) == '\n')
	{
	  tmp += (*it);
	  cmd.push_back(tmp);
	  tmp = "";
	}
      else
	tmp += (*it);
    }

  for (std::vector<std::string>::iterator it = cmd.begin(); it != cmd.end(); ++it)
    {
      if (it->find(" ") != std::string::npos)
	{
	  for (std::map<std::string, Graphic::ptr>::iterator jt = _funPtr.begin(); jt != _funPtr.end(); ++jt)
	    {
	      if (jt->first == it->substr(0, it->find(" ")))
		(this->*_funPtr[it->substr(0, it->find(" "))])((*it));
	    }
	}
    }
}

void 		Graphic::drawSprite(std::map<std::string, int > &contents, int y, int x)
{
  int i = 0;

  for (std::map<std::string, int>::iterator it = contents.begin(); it != contents.end(); ++it)
    {
      if (it->second != 0)
	i = 1;
    }
  _sprite.setTexture(_texture[i]);
  _sprite.setTextureRect(sf::IntRect(0, 100, 100, 100));
  _sprite.setPosition(sf::Vector2f(x, y));
  _window.draw(_sprite);
}

void 		Graphic::readMap()
{
  int y = 0;
  int x = 0;
  for (std::vector<std::vector<std::map<std::string, int> > >::iterator it = _map.begin(); it != _map.end(); ++it)
    {
      for (std::vector<std::map<std::string, int> >::iterator jt = it->begin(); jt != it->end(); ++jt)
	{
	  drawSprite((*jt), y, x);
	  x += 100;
	}
      x = 0;
      y += 100;
    }

  unsigned int i = 0;
  while (i < _players.size())
    {
      if (_players[i]->getLevel() == 8)
	_sprite.setTexture(_texture[_players[i]->getLevel()]);
      else
	_sprite.setTexture(_texture[_players[i]->getLevel() + 1]);
      _sprite.setTextureRect(_direction[_players[i]->getDirection() - 1]);
      _sprite.setPosition(sf::Vector2f(_players[i]->getX() * 100, _players[i]->getY() * 100));
      _window.draw(_sprite);
      ++i;
    }

  for (std::vector<std::pair<std::pair<bool, int>, std::pair<int, int> > >::iterator it = _isIncant.begin(); it != _isIncant.end(); ++it)
    {
      if (it->first.first == true)
	{
	  _sprite.setTexture(_texture[9]);
	  _sprite.setTextureRect(_crystal[it->first.second - 1]);
	  _sprite.setPosition(sf::Vector2f(it->second.second * 100, it->second.first * 100));
	  _window.draw(_sprite);
	}
    }

  unsigned int count = 0;
  while (count < _eggs.size())
    {
      if (_eggs[count].first.second == false)
	{
	  _sprite.setTexture(_texture[10]);
	  _sprite.setTextureRect(sf::IntRect(0, 0, 50, 50));
	}
      else
	{
	  _sprite.setTexture(_texture[11]);
	  _sprite.setTextureRect(sf::IntRect(0, 0, 100, 100));
	}
      _sprite.setPosition(sf::Vector2f(_eggs[count].second.second * 100, _eggs[count].second.first * 100));
      _window.draw(_sprite);
      ++count;
    }

  y = 0;
  x = 0;
  for (std::vector<std::vector<std::map<std::string, int> > >::iterator it = _map.begin(); it != _map.end(); ++it)
    {
      for (std::vector<std::map<std::string, int> >::iterator jt = it->begin(); jt != it->end(); ++jt)
	{
	  count = 0;
	  int tmpX = x;
	  int tmpY = y;
	  for (std::map<std::string, int>::iterator lt = jt->begin(); lt != jt->end(); ++lt)
	    {
	      if (lt->second != 0)
		{
		  i = 0;
		  while (i < static_cast<unsigned int>(lt->second))
		    {
		      _sprite.setTexture(_texture[12]);
		      _sprite.setTextureRect(_object[count]);
		      _sprite.setPosition(sf::Vector2f(tmpX, tmpY));
		      _window.draw(_sprite);
		      ++i;
		    }
		  tmpX += 10;
		  tmpY += 10;
		}
	      ++count;
	    }
	  x += 100;
	}
      x = 0;
      y += 100;
    }
}

void 		Graphic::start()
{
  while (_window.isOpen())
    {
      if (_isEnd == true)
	_window.close();
      if (handleSelect())
	initMap();
      event();
      _window.clear();
      readMap();
      _window.display();
    }
}

void 		Graphic::event()
{
  sf::Event	event;
  while (_window.pollEvent(event))
    {
      if (event.type == sf::Event::Closed)
	_window.close();
      else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
	_window.close();
      else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
	  _view.setSize(1400, 800);
	  _view.move(sf::Vector2f(-30, 0));
	  _window.setView(_view);
	}
      else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
	  _view.setSize(1400, 800);
	  _view.move(sf::Vector2f(30, 0));
	  _window.setView(_view);
	}
      else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
	  _view.setSize(1400, 800);
	  _view.move(sf::Vector2f(0, -30));
	  _window.setView(_view);
	}
      else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
	  _view.setSize(1400, 800);
	  _view.move(sf::Vector2f(0, 30));
	  _window.setView(_view);
	}
    }
}

int 		main(int ac, char **av, char **envp)
{
  if (envp[0] == NULL)
    {
      std::cerr << "Error ENV" << std::endl;
      return (-1);
    }
  if (ac != 3)
    return (-1);
  try
    {
      Graphic 	sfml(av[1], std::atoi(av[2]));
    }
  catch (MyError const &error)
    {
      std::cerr << error.what() << std::endl;
    }
  return (0);
}
