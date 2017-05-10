#ifndef BOMBERMAN_GAMEENGINE_HH_
# define BOMBERMAN_GAMEENGINE_HH_

# include <Game.hh>
# include <BasicShader.hh>
# include <sys/types.h>
# include <dirent.h>
# include <ctime>
# include <cstdlib>
# include <unistd.h>
# include "AObject.hh"
# include "Map.hh"
# include "Bomb.hh"
# include "Img.hh"

# include "ACharacter.hh"
# include "Player1.hh"
# include "Player2.hh"
# include "Ia.hh"

# define INCLINAISON 4
# define DOWN 1
# define UP 2
# define LEFT 3
# define RIGHT 4


class GameEngine : public gdl::Game
{
private:
	gdl::SdlContext							_context;
	gdl::Clock								_clock;
	gdl::Input								_input;
	gdl::BasicShader						_shader;

	int 									_nbPlayers;
	int 									_nbBots;
	std::string								_mapName;
	int 									_mapY;
	int 									_mapX;
	float 									_winY;
	float 									_winX;

	bool									pause;
	std::vector<IObject*> 					obj;
	std::vector<IObject*>					obj_score;
	std::vector<IObject*>					obj_nb;
	std::vector<IObject*>					obj_win;

	Map										*_map;
	std::vector<ACharacter *> 				_players;
	std::vector<Bomb *> 					_bombs;
	int 									_range;
	unsigned int 							_id;

	int 									x_screen;
	int 									y_screen;
	int 									page;
	std::vector<std::vector<int> >			limit;
	typedef std::vector<std::vector<int> >	(GameEngine::*ptr)();
    std::map<int , GameEngine::ptr>			create;
    typedef bool 							(GameEngine::*ps)();
    std::map<int , GameEngine::ps> 			create_pause;
  	AObject::Type 							_winner;
  	std::string                           	_fname;

public:
	GameEngine(int, int, const std::string&, const std::pair<int, int>&, const std::pair<int, int>&);
	GameEngine(const std::pair<int, int>&);
	~GameEngine();

	bool							initialize();

	bool							update();
	void							drawPlayers(int);
	void							drawMap(int);
	void							setCamera(float, float, int);
	void							drawOnePlayer();
	void							drawTwoPlayer();
	void							draw();

	bool    						checkAlive();
	void 							affWinner();

	int   							round(float);

	void							explosions(int);
	void    						explosionTop(int , int , int, int);
	void    						explosionBottom(int , int , int, int);		
	void    						explosionRight(int , int , int, int);
	void    						explosionLeft(int , int , int, int);
	bool    						explosionsConditions(int, int);

	void    						floorTop(int , int , int, int);
	void    						floorBottom(int , int , int, int);		
	void    						floorRight(int , int , int, int);
	void    						floorLeft(int , int , int, int);
	bool    						floorConditions(int, int);

	void							putAsset(int, int);
	bool    						checkAsset(int, int);
	bool    						checkBox(int, int);

	void							bombs(int, int, int, const glm::vec3&);
	void							fires(int, int, int, const glm::vec3&);
	void							putBomb(int);

	int   							checkNearestEnemy(int, const glm::vec3&);
	void							YcloseToEnemy(int, const glm::vec3&);
	void							XcloseToEnemy(int, const glm::vec3&);
	void							checkIaPutBombs(int);
	void							checkEnemyInRange(int);
	void							iaEngine(int);
	bool							checkEnemyInTop(int);
	bool							checkEnemyInBot(int);
	bool							checkEnemyInLeft(int);
	bool							checkEnemyInRight(int);
	bool							checkIaInBombRange(int);
	bool							checkCase(int, int);
	void							flee(int);
	bool							goToFlee(int, int, int);
	bool    						checkFlee(int, const glm::vec3&, int, int);
	void							calcY(int, const glm::vec3&, const glm::vec3&);
	void							calcX(int, const glm::vec3&, const glm::vec3&);
	void							goY(int, glm::vec3&);
	void							goX(int, glm::vec3&);


	std::vector<std::vector<int > >	get_limit1();
    std::vector<std::vector<int > >	get_limit2();
    std::vector<std::vector<int > >	get_limit3();
	std::vector<std::vector<int> >	getVect(int, int, int, int, int, int, int, int, int);
	void 							initPage();

	bool 							getOut();
	bool 							saveQuit();
	bool 							Quit();

	void 							initScore(int);
	void 							affScore();
	void 							drawScore(int);
	void 							drawScore(int, int);

  	std::string           			getFname() const;
  	void                  			saveMap(MAP);
  	void							ladder();
};

#endif /* BOMBERMAN_GAMEENGINE_HH_ */