//
// Player.hh for Player in /home/doghri_f/Downloads/Graph
// 
// Made by Fares Doghri
// Login   <doghri_f@epitech.net>
// 
// Started on  Sun Jul  5 22:27:12 2015 Fares Doghri
// Last update Sun Jul  5 22:27:13 2015 Fares Doghri
//

#ifndef PLAYER_HH_
# define PLAYER_HH_

# include <iostream>
# include <string>
# include <map>

class Player
{
public:
  Player(int, int, int, int, int, std::string);
  ~Player();

  int 	getY() const;
  int 	getX() const;
  int 	getId() const;
  int 	getDirection() const;
  int 	getLevel() const;
  int 	getPosY() const;
  int 	getPosX() const;

  const std::string 	&getTeamName() const;

  const std::map<std::string, int> &getInventaire() const;

  void 	setY(int);
  void	setX(int);
  void	setId(int);
  void	setDirection(int);
  void 	setLevel(int);
  void 	setPosY(int);
  void 	setPosX(int);

  void 	setTeamName(std::string);

  void	setInventaire(std::map<std::string, int>);

private:
  int 	_y;
  int 	_x;
  int 	_id;
  int 	_direction;
  int 	_level;

  int 	_posY;
  int 	_posX;

  std::string	_teamName;

  std::map<std::string, int> _inventaire;
};

#endif //PLAYER_HH_
