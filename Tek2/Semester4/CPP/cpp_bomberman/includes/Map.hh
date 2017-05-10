#ifndef BOMBERMAN_Map_H
# define BOMBERMAN_Map_H

# include	<iostream>
# include	<vector>
# include	<sstream>
# include	<fstream>
# include	<string>
# include	"AObject.hh"
# include 	"Floor.hh"
# include 	"Wall.hh"
# include 	"Box.hh"
# include	"Bomb.hh"
# include 	"Fire.hh"
# include 	"AssetBomb.hh"
# include 	"AssetSpeed.hh"
# include 	"AssetRange.hh"
# include	"MyError.h"

# define	CLIPPING 12

typedef std::vector<std::vector<std::pair<AObject::Type, AObject::Type> > > MAP;

class Map
{
private:
	MAP							_tab;
	glm::vec3					_limits;
	AObject						*_bomb;
	AObject						*_wall;
	AObject						*_floor;
	AObject						*_box;
	AObject						*_fire;
	AObject						*_assetBomb;
	AObject						*_assetSpeed;
	AObject						*_assetRange;
	int 						_x;
	int 						_y;
	int 						_p1;
	int 						_p2;
	int 						_nbPlayers;
	int 						_nbBots;
	std::vector<glm::vec3> 		_posPlayers;
	std::vector<glm::vec3> 		_posIa;


public:
	Map(int, int, int, int);
	Map(const std::string&);
	~Map();

	void							draw(gdl::AShader&, gdl::Clock const&);
	void               				updateLimits(glm::vec3 const &limits);
	void                			setWall();
	void                			setBox();

	const MAP&						getMap() const;
	int								getX() const;
	int								getY() const;
	int								getNbPlayer() const;
	int								getNbBot() const;
	const std::vector<glm::vec3>&	getPosPlayers() const;
	const std::vector<glm::vec3>&	getPosIa() const;
	void							setType(int, int, AObject::Type);
	void							setType(int, int, AObject::Type, AObject::Type);

	void 							setSpawn(int, int);
	void                			setSpace(int, int);

	bool 							checkMap();

	void                			firstCorner(glm::vec3&, int);
	void                			secondCorner(glm::vec3&, int);
	void                			thirdCorner(glm::vec3&, int);
	void                			fourthCorner(glm::vec3&, int);
	void                			firstPlayerCorner(glm::vec3&);
	void                			secondPlayerCorner(glm::vec3&);
	void                			firstCheck(char, int *, int);
	void                			secondCheck(char, int *, int);
	void                			thirdCheck(char);
};

#endif /* BOMBERMAN_Map_H */
