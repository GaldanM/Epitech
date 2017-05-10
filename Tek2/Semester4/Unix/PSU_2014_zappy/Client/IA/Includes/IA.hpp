//
// IA.hpp for ia in /home/doghri_f/Downloads/IA
// 
// Made by Fares Doghri
// Login   <doghri_f@epitech.net>
// 
// Started on  Sun Jul  5 21:27:03 2015 Fares Doghri
// Last update Sun Jul  5 21:30:22 2015 Fares Doghri
//

#ifndef IA_HH
# define IA_HH

# include "Client.hh"
# include  <map>
# include <vector>
# include <sstream>
# include <time.h>
# include <utility>

class IA : public Client
{
protected:
  typedef void (IA::*ptr)();
  std::map<std::string, IA::ptr> 						_directions;

  typedef void (IA::*fct)(std::string &);
  std::map<std::string, IA::fct> 						_Actions;

  typedef void (IA::*mov)();
  std::map<int, IA::mov>							_deplacement;

  std::map<std::string, int> 							_stuff;
  std::string 									_teamName;
  char										_buf[4096];

  std::vector<std::vector<int> >						_vision;
  std::vector<std::map<std::string, int> >					_mapvision;
  std::vector<std::map<std::string, int> >					_stats;
	std::vector<int> 							_players;
  std::vector<std::string>							_objNeed;

  int										_food;
  int										_lvl;
  int 										_xIA;
  int 										_yIA;
  int 										_dir;

  int 										_sx;
  int 										_sy;

  int 										_nbObj;
  int 										_lock;
  int 										_fork;

  int 										_set;
  int 										_elevation;

  std::pair<std::string, std::string>						_fillAction;
  std::vector<std::pair<std::string, std::string> >				_listAction;
public:
  IA(const std::string &, const int &, const std::string &);
  ~IA();

  void						takeFood();
  void						goUp();
  void						goDown();
  void						goRight();
  void						goLeft();
  void						extremRight();
  void						extremLeft();

  std::string					checkDirections(int, int);
  std::string					checkDir(int, int);
  void						moveInCase(int);
  void						move();
  void						run();
  void						look();
  void						resetHp();
  void						pose();
  void						initStuff();
  void						initstats();
  void						fillVision();
  void						splitString();
  void						fillmap(std::vector<std::string>);
  void						takeGem();
  void						survive();
  void 						fillHp();
  void 						moveRand();
  void						Evolve();
  void						handleSelect();
  void						players();
  void						doAction();
  void						active();
  void 						getBroadcast();
  void 						expulse();
  void						Com();
  void 						fillStuff(std::string);

  void						avance(std::string &);
  void						voir(std::string &);
  void						droite(std::string &);
  void						gauche(std::string &);
  void						inventaire(std::string &);
  void						prend(std::string &);
  void						pose(std::string &);
  void						broadcast(std::string &);
  void						doFork(std::string &);
  void						incantation(std::string &);

  void						one();
  void						two();
  void						three();
  void						four();
  void						five();
  void						six();
  void						seven();
  void						eight();

  int 						getDir();
  int 						checkElev();
  int						searchFood();
  int						checkVision();
  int 						foodBox();
  int 						checkPos() const;
  int 						searchGem();
  int 						needObj();
  int 						checkStuff(std::string &);
  int 						checkEvolve();
  int 						checkBroadcast();
  int 						LvlIa() const;
  int 						checkExpulse();
  int 						expulseDir();

  unsigned int					nbWord();

  std::string					getObj();
  std::vector<std::string>			wordvect(std::string);
  std::vector<std::vector<int> >		getVision(int);
};

#endif /* !IA_HH */
