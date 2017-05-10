//
// Player.cpp for Player in /home/doghri_f/Downloads/Graph
// 
// Made by Fares Doghri
// Login   <doghri_f@epitech.net>
// 
// Started on  Sun Jul  5 21:15:37 2015 Fares Doghri
// Last update Sun Jul  5 21:16:06 2015 Fares Doghri
//

# include "Player.hh"

Player::Player(int y, int x, int id, int direction, int level, std::string teamName)
  :	_y(y), _x(x), _id(id), _direction(direction), _level(level), _posY(0), _posX(0), _teamName(teamName)
{
  _inventaire["nourriture"] = 0;
  _inventaire["linemate"] = 0;
  _inventaire["deraumere"] = 0;
  _inventaire["sibur"] = 0;
  _inventaire["mendian"] = 0;
  _inventaire["phiras"] = 0;
  _inventaire["thystame"] = 0;
}

Player::~Player()
{
  delete this;
}

int 	Player::getY() const
{
  return (_y);
}

int 	Player::getX() const
{
  return (_x);
}

int 	Player::getId() const
{
  return (_id);
}

int 	Player::getDirection() const
{
  return (_direction);
}

int 	Player::getLevel() const
{
  return (_level);
}

int 	Player::getPosY() const
{
  return (_posY);
}

int 	Player::getPosX() const
{
  return (_posX);
}

const std::string 	&Player::getTeamName() const
{
  return (_teamName);
}

const std::map<std::string, int> &Player::getInventaire() const
{
  return (_inventaire);
}

void 	Player::setY(int y)
{
  _y = y;
}
void	Player::setX(int x)
{
  _x = x;
}
void	Player::setId(int id)
{
  _id = id;
}
void	Player::setDirection(int direction)
{
  _direction = direction;
}
void 	Player::setLevel(int level)
{
  _level = level;
}

void 	Player::setTeamName(std::string teamName)
{
  _teamName = teamName;
}

void 	Player::setInventaire(std::map<std::string, int> inventaire)
{
  _inventaire = inventaire;
}

void 	Player::setPosY(int posY)
{
  _posY = posY;
}
void 	Player::setPosX(int posX)
{
  _posX = posX;
}
