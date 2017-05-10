//
// IA.cpp for Ia in /home/doghri_f/Downloads/ClientQuiMarche
// 
// Made by Fares Doghri
// Login   <doghri_f@epitech.net>
// 
// Started on  Sun Jul  5 20:59:11 2015 Fares Doghri
// Last update Sun Jul  5 21:08:26 2015 Fares Doghri
//

#include "IA.hpp"

IA::IA(const std::string &ip, const int &port, const std::string &name) : Client(ip, port)
{
  this->_teamName = name;
  this->_lvl = 1;
  this->_elevation = 0;
  this->_xIA = 0;
  this->_yIA = 0;
  this->_dir = 0;

  this->_directions["avance"] = &IA::goUp;
  this->_directions["recule"] = &IA::goDown;
  this->_directions["droite"] = &IA::goRight;
  this->_directions["gauche"] = &IA::goLeft;
  this->_directions["extremDroite"] = &IA::extremRight;
  this->_directions["extremGauche"] = &IA::extremLeft;

  this->_stuff["nourriture"] = 10;
  this->_stuff["linemate"] = 0;
  this->_stuff["deraumere"] = 0;
  this->_stuff["sibur"] = 0;
  this->_stuff["mendiane"] = 0;
  this->_stuff["phiras"] = 0;
  this->_stuff["thystame"] = 0;

  this->_Actions["avance"] = &IA::avance;
  this->_Actions["droite"] = &IA::droite;
  this->_Actions["gauche"] = &IA::gauche;
  this->_Actions["inventaire"] = &IA::inventaire;
  this->_Actions["prend"] = &IA::prend;
  this->_Actions["pose"] = &IA::pose;
  this->_Actions["broadcast"] = &IA::broadcast;
  this->_Actions["voir"] = &IA::voir;
  this->_Actions["fork"] = &IA::doFork;
  this->_Actions["incantation"] = &IA::incantation;

  this->_deplacement[1] = &IA::one;
  this->_deplacement[2] = &IA::two;
  this->_deplacement[3] = &IA::three;
  this->_deplacement[4] = &IA::four;
  this->_deplacement[5] = &IA::five;
  this->_deplacement[6] = &IA::six;
  this->_deplacement[7] = &IA::seven;
  this->_deplacement[8] = &IA::eight;

  this->_vision = this->getVision(this->_lvl);
  this->initstats();
}

void	IA::initstats()
{
  std::map<std::string, int> stat;

  stat["linemate"] = 0;
  stat["deraumere"] = 0;
  stat["sibur"] = 0;
  stat["mendiane"] = 0;
  stat["phiras"] = 0;
  stat["thystame"] = 0;

  for (int i = 0; i < 7; i++)
    this->_stats.push_back(stat);

  this->_stats[0]["linemate"] = 1;

  this->_stats[1]["linemate"] = 1;
  this->_stats[1]["deraumere"] = 1;
  this->_stats[1]["sibur"] = 1;

  this->_stats[2]["linemate"] = 2;
  this->_stats[2]["sibur"] = 1;
  this->_stats[2]["phiras"] = 2;

  this->_stats[3]["linemate"] = 1;
  this->_stats[3]["deraumere"] = 1;
  this->_stats[3]["sibur"] = 2;
  this->_stats[3]["phiras"] = 1;

  this->_stats[4]["linemate"] = 1;
  this->_stats[4]["deraumere"] = 2;
  this->_stats[4]["sibur"] = 1;
  this->_stats[4]["mendiane"] = 3;

  this->_stats[5]["linemate"] = 1;
  this->_stats[5]["deraumere"] = 2;
  this->_stats[5]["sibur"] = 3;
  this->_stats[5]["phiras"] = 1;

  this->_stats[6]["linemate"] = 2;
  this->_stats[6]["deraumere"] = 2;
  this->_stats[6]["sibur"] = 2;
  this->_stats[6]["mendiane"] = 2;
  this->_stats[6]["phiras"] = 2;
  this->_stats[6]["thystame"] = 1;

  this->_players.push_back(1);
  this->_players.push_back(2);
  this->_players.push_back(2);
  this->_players.push_back(4);
  this->_players.push_back(4);
  this->_players.push_back(6);
  this->_players.push_back(6);
}

IA::~IA()
{
}

int 	IA::foodBox()
{
  int 	food = 0;

  for (size_t z = 0; z < this->_mapvision.size(); z++)
    {
      for (std::map<std::string, int>::iterator it = this->_mapvision[z].begin(); it != this->_mapvision[z].end(); it++)
	{
	  if (it->first == "nourriture" && it->second != 0)
	    food = food + it->second;
	}
    }
  return (food);
}

int 	IA::checkVision()
{
  std::vector<std::string>	need;
  int 					 	nbObj = 0;

  for (std::map<std::string, int>::iterator it = this->_stats[this->_lvl - 1].begin(); it != this->_stats[this->_lvl - 1].end(); it++)
    {
      if (it->second != 0)
	{
	  for (std::map<std::string, int>::iterator jt = this->_stuff.begin(); jt != this->_stuff.end(); jt++)
	    {
	      if ((it->first == jt->first) && (it->second != jt->second))
		need.push_back(it->first);
	    }
	}
    }
  this->_objNeed = need;
  for (size_t i = 0; i < this->_objNeed.size(); i++)
    {
      for (size_t z = 0; z < this->_mapvision.size(); z++)
	{
	  for (std::map<std::string, int>::iterator it = this->_mapvision[z].begin(); it != this->_mapvision[z].end(); it++)
	    {
	      if (it->first == this->_objNeed[i] && it->second != 0)
		nbObj++;
	    }
	}
    }
  return (nbObj);
}

int		IA::searchFood()
{
  for (size_t y = 0; y < this->_mapvision.size(); y++)
    {
      for (std::map<std::string, int>::iterator it = this->_mapvision[y].begin(); it != this->_mapvision[y].end(); it++)
	{
	  if (it->first == "nourriture" && it->second != 0)
	    return (y);
	}
    }
  return (0);
}

void		IA::goUp()
{
  while (this->_dir != 0)
    {
      this->_dir--;
      if (this->_dir == -1)
	this->_dir = 3;
      this->_fillAction.first = "droite";
      this->_fillAction.second = "droite";
      this->_listAction.push_back(this->_fillAction);
    }
  while (this->_yIA < this->_sy)
    {
      if (this->_yIA > 1000 || this->_sy > 1000)
	return;
      this->_yIA++;
      this->_xIA++;
      this->_fillAction.first = "avance";
      this->_fillAction.second = "avance";
      this->_listAction.push_back(this->_fillAction);
    }
}

void		IA::goDown()
{
  while (this->_dir != 2)
    {
      this->_dir++;
      if (this->_dir == 4)
	this->_dir = 0;
      this->_fillAction.first = "droite";
      this->_fillAction.second = "droite";
      this->_listAction.push_back(this->_fillAction);
    }
  while (this->_yIA > this->_sy)
    {
      this->_yIA--;
      this->_xIA--;
      if (this->_yIA > 1000|| this->_sy > 1000)
	return;
      this->_fillAction.first = "avance";
      this->_fillAction.second = "avance";
      this->_listAction.push_back(this->_fillAction);
    }
}

void		IA::goRight()
{
  while (this->_dir != 1)
    {
      this->_dir++;
      if (this->_dir == 4)
	this->_dir = 0;
      this->_fillAction.first = "droite";
      this->_fillAction.second = "droite";
      this->_listAction.push_back(this->_fillAction);
    }
  while (this->_xIA < this->_sx)
    {
      this->_xIA++;
      this->_fillAction.first = "avance";
      this->_fillAction.second = "avance";
      this->_listAction.push_back(this->_fillAction);
    }
}

void		IA::goLeft()
{
  while (this->_dir != 3)
    {
      this->_dir--;
      if (this->_dir == -1)
	this->_dir = 3;
      this->_fillAction.first = "gauche";
      this->_fillAction.second = "gauche";
      this->_listAction.push_back(this->_fillAction);
    }
  while (this->_xIA > this->_sx)
    {
      this->_xIA--;
      this->_fillAction.first = "avance";
      this->_fillAction.second = "avance";
      this->_listAction.push_back(this->_fillAction);
    }
}

void		IA::extremRight()
{
  while (this->_dir != 1)
    {
      this->_dir--;
      if (this->_dir == -1)
	this->_dir = 3;
      this->_fillAction.first = "gauche";
      this->_fillAction.second = "gauche";
      this->_listAction.push_back(this->_fillAction);
    }
  this->_xIA++;
  this->_fillAction.first = "avance";
  this->_fillAction.second = "avance";
  this->_listAction.push_back(this->_fillAction);
  this->_dir++;
  if (this->_dir == 4)
    this->_dir = 0;
  this->_fillAction.first = "droite";
  this->_fillAction.second = "droite";
  this->_listAction.push_back(this->_fillAction);
  this->_xIA--;
  this->_yIA--;
  this->_fillAction.first = "avance";
  this->_fillAction.second = "avance";
  this->_listAction.push_back(this->_fillAction);
}

void		IA::extremLeft()
{
  while (this->_dir != 3)
    {
      this->_dir++;
      if (this->_dir == 4)
	this->_dir = 0;
      this->_fillAction.first = "droite";
      this->_fillAction.second = "droite";
      this->_listAction.push_back(this->_fillAction);
    }
  this->_xIA--;
  this->_fillAction.first = "avance";
  this->_fillAction.second = "avance";
  this->_listAction.push_back(this->_fillAction);
  this->_dir--;
  if (this->_dir == 4)
    this->_dir = 0;
  this->_fillAction.first = "gauche";
  this->_fillAction.second = "gauche";
  this->_listAction.push_back(this->_fillAction);
  this->_xIA--;
  this->_yIA--;
  this->_xIA--;
  this->_fillAction.first = "avance";
  this->_fillAction.second = "avance";
  this->_listAction.push_back(this->_fillAction);
}

std::string 	IA::checkDir(int sy, int sx)
{
  if (sy < this->_yIA && this->_xIA == static_cast<int>(this->_vision[this->_yIA].size() - 1))
    return ("extremDroite");
  if (this->_yIA == sy && this->_xIA > sx)
    return ("gauche");
  if (this->_yIA == sy && this->_xIA < sx)
    return ("droite");
  return ("RIEN");
}

std::string		IA::checkDirections(int sy, int sx)
{
  if (sy > this->_yIA)
    return ("avance");
  if (sy < this->_yIA && (this->_xIA != 0 && this->_xIA != static_cast<int>(this->_vision[this->_yIA].size() - 1)))
    return ("recule");
  if (sy < this->_yIA && (this->_xIA == 0))
    return ("extremGauche");
  return (this->checkDir(sy, sx));
}

int 	IA::checkPos() const
{
  if (this->_xIA == this->_sx	&& this->_yIA == this->_sy)
    return (0);
  return (-1);
}

void	IA::moveInCase(int nb)
{
  size_t y;
  size_t x;
  int save_x = 0;
  int save_y = 0;
  std::string str;

  for (y = 0; y < this->_vision.size(); y++)
    for (x = 0; x < this->_vision[y].size(); x++)
      if (this->_vision[y][x] == nb)
	{
	  save_x = x;
	  save_y = y;
	}
  this->_sx = save_x;
  this->_sy = save_y;
  while (this->checkPos() != 0)
    {
      str = this->checkDirections(save_y, save_x);
      for (std::map<std::string, IA::ptr>::iterator it = this->_directions.begin(); it != this->_directions.end(); it++)
	if (it->first == str)
	  (this->*(it->second))();
    }
}

void	IA::takeFood()
{
  int y;

  if ((this->_xIA == this->_sx) && (this->_yIA == this->_sy))
    {
      y = this->_vision[this->_yIA][this->_xIA];
      for (std::map<std::string, int>::iterator it = this->_mapvision[y].begin(); it != this->_mapvision[y].end(); it++)
	{
	  if (it->first == "nourriture" && it->second > 0)
	    {
	      it->second--;

	      this->_fillAction.first = "prend";
	      this->_fillAction.second = "prend nourriture";
	      this->_listAction.push_back(this->_fillAction);
	      this->_stuff["nourriture"]++;
	    }
	}
    }
}

int 	IA::searchGem()
{
  for (size_t i = 0; i < this->_objNeed.size(); i++)
    {
      for (size_t z = 0; z < this->_mapvision.size(); z++)
	{
	  for (std::map<std::string, int>::iterator it = this->_mapvision[z].begin(); it != this->_mapvision[z].end(); it++)
	    {
	      if (it->first == this->_objNeed[i] && it->second != 0)
		return (z);
	    }
	}
    }
  return (0);
}

int 	IA::checkStuff(std::string &str)
{
  if (this->_stuff[str] == this->_stats[this->_lvl - 1][str])
    return (0);
  return (-1);
}

void	IA::takeGem()
{
  int y;

  if ((this->_xIA == this->_sx) && (this->_yIA == this->_sy))
    {
      y = this->_vision[this->_yIA][this->_xIA];
      for (std::map<std::string, int>::iterator it = this->_mapvision[y].begin(); it != this->_mapvision[y].end(); it++)
	{
	  for (size_t a = 0; a < this->_objNeed.size(); a++)
	    {
	      if (it->first == this->_objNeed[a] && it->second > 0)
		{
		  while (this->checkStuff(this->_objNeed[a]) != 0 && it->second > 0)
		    {
		      it->second--;
		      this->_fillAction.first = "prend";
		      this->_fillAction.second = "prend " + this->_objNeed[a];
		      this->_listAction.push_back(this->_fillAction);
		      this->_stuff[this->_objNeed[a]]++;
		    }
		}

	    }
	}
    }
  for (size_t a = 0; a < this->_objNeed.size(); a++)
    {
      if (this->_stuff[this->_objNeed[a]] == this->_stats[this->_lvl - 1][this->_objNeed[a]])
	this->_objNeed.erase(this->_objNeed.begin() + a);
    }
}

int 	IA::needObj()
{
  int nbObj = 0;

  for (size_t i = 0; i < this->_objNeed.size(); i++)
    {
      for (size_t z = 0; z < this->_mapvision.size(); z++)
	{
	  for (std::map<std::string, int>::iterator it = this->_mapvision[z].begin(); it != this->_mapvision[z].end(); it++)
	    {
	      if (it->first == this->_objNeed[i] && it->second != 0)
		nbObj++;
	    }
	}
    }
  return (nbObj);
}

void	IA::survive()
{
  int food;
  int nbfood = this->foodBox();
  int i = 0;

  if (nbfood != 0)
    {
      while (nbfood > 0)
	{
	  i++;
	  food = this->searchFood();
	  this->moveInCase(food);
	  this->takeFood();
	  nbfood = this->foodBox();
	  if (i == 300)
	    throw MyError("disconnected");
	}
    }
}

void	IA::move()
{
  int food;
  int gem;
  int nbfood = this->foodBox();
  int i = 0;

  if (nbfood != 0)
    {
      while (nbfood > 0)
	{
	  i++;
	  food = this->searchFood();
	  this->moveInCase(food);
	  this->takeFood();
	  nbfood = this->foodBox();
	  if (i == 300)
	    throw MyError("disconnected");
	}
    }
  if (this->_objNeed.size() != 0)
    {
      while (this->needObj() != 0)
	{
	  i++;
	  gem = this->searchGem();
	  this->moveInCase(gem);
	  this->takeGem();
	  if (i == 300)
	    throw MyError("disconnected");
	}
    }
}

unsigned int 	IA::nbWord()
{
  int	i = 0;
  std::size_t found = this->_cmd.find_first_of(",");

  while (found != std::string::npos)
    {
      i++;
      found = this->_cmd.find_first_of(",", found + 1);
    }
  return (i + 1);
}

std::vector<std::string>	IA::wordvect(std::string str)
{
  std::vector<std::string> tab;
  unsigned int	i;

  i = 0;
  while (i < str.size())
    {
      if (str[i] != ' ')
	{
	  std::vector<char> v;
	  while (str[i] != ' ' && i < str.size())
	    {
	      v.push_back(str[i]);
	      i++;
	    }
	  std::string sti(v.begin(), v.end());
	  tab.push_back(sti);
	}
      i++;
    }
  return (tab);
}

void	IA::fillmap(std::vector<std::string> tab)
{
  std::map<std::string, int> stat;
  std::vector<std::map<std::string, int> > maps;
  std::vector<std::vector<std::string> > save;

  unsigned int x = 0;
  unsigned int y = 0;

  stat["joueur"] = 0;
  stat["linemate"] = 0;
  stat["deraumere"] = 0;
  stat["sibur"] = 0;
  stat["mendiane"] = 0;
  stat["phiras"] = 0;
  stat["thystame"] = 0;

  for (unsigned int i = 0; i < nbWord(); i++)
    maps.push_back(stat);

  for (size_t i = 0; i < nbWord(); i++)
    save.push_back(wordvect(tab[i]));

  while (y < maps.size())
    {
      x = 0;
      while (x < save[y].size())
	{
	  maps[y][save[y][x]]++;
	  x++;
	}
      y++;
    }
  this->_mapvision = maps;
}

void 	IA::splitString()
{
  std::vector<std::string> tab;
  std::string st;
  unsigned int	i;
  int nb = 0;

  for (i = 0; i < nbWord(); i++)
    tab.push_back(st);

  i = 0;
  while (i < this->_cmd.size())
    {
      if (this->_cmd[i] != ',')
	{
	  std::vector<char> v;
	  while (this->_cmd[i] != ',' && (i < this->_cmd.size() - 1))
	    {
	      v.push_back(this->_cmd[i]);
	      i++;
	    }
	  std::string str(v.begin(), v.end());
	  tab[nb] = str;
	}
      i++;
      nb++;
    }
  this->fillmap(tab);
}

void	IA::fillVision()
{
  this->_xIA = 0;
  this->_yIA = 0;
  this->_dir = 0;
  this->_cmd.erase(0,2);
  this->_cmd.erase(this->_cmd.end() - 2);
  this->splitString();
  this->_lock = 0;
}

void	IA::fillStuff(std::string str)
{
  std::vector<std::string> tab;
  std::string st;

  unsigned int  i;
  int nb = 0;

  for (i = 0; i < 7; i++)
    tab.push_back(st);

  i = 0;
  while (i < str.size())
    {
      if (str[i] != ',')
	{
	  std::vector<char> v;
	  while (str[i] != ',' && (i < str.size() - 1))
	    {
	      v.push_back(str[i]);
	      i++;
	    }
	  std::string stre(v.begin(), v.end());
	  tab[nb] = stre;
	}
      i++;
      nb++;
    }
  for (i = 0; i < tab.size(); i++)
    {
      int x;
      std::stringstream ss;
      std::string nb;
      std::size_t found = tab[i].find_first_of(" ");
      std::string save = tab[i].substr(0, found);
      nb = tab[i].substr(found + 1, tab[i].size());
      ss << nb;
      ss >> x;
      this->_stuff[save] = x;
    }
}

void 	IA::fillHp()
{
  size_t it;
  std::string str;
  int hp;
  std::stringstream ss;
  std::string save;

  if (this->_cmd.size() > 10 && this->_cmd[this->_cmd.size() - 2] == '}' && this->_cmd[0] == '{')
    {
      this->_cmd.erase(0,1);
      this->_cmd.erase(this->_cmd.end() - 2);
      save = this->_cmd;
      for (it = 0; it < this->_cmd.size() && this->_cmd[it] != ' '; it++);
      this->_cmd.erase(0, it + 1);
      for (it = 0; it < this->_cmd.size() && this->_cmd[it] != ',';it++);
      str = this->_cmd.substr(0, it);
      ss << str;
      ss >> hp;
      this->_stuff["nourriture"] = hp;
      this->fillStuff(save);
    }
}

void	IA::look()
{
  this->_fillAction.first = "voir";
  this->_fillAction.second = "voir";
  this->_listAction.push_back(this->_fillAction);
}

void	IA::resetHp()
{
  this->_fillAction.first = "inventaire";
  this->_fillAction.second = "inventaire";
  this->_listAction.push_back(this->_fillAction);
}

void	IA::moveRand()
{
  int rd;
  std::vector<std::string> mvm;

  rd = rand() % 4;
  mvm.push_back("avance");
  mvm.push_back("droite");
  mvm.push_back("gauche");
  mvm.push_back("recule");
  (this->*_directions[mvm[rd]])();
}

int 	IA::checkEvolve()
{
  for (std::map<std::string, int>::iterator it = this->_stats[this->_lvl - 1].begin(); it != this->_stats[this->_lvl - 1].end(); it++)
    {
      if (it->second != 0)
	{
	  for (std::map<std::string, int>::iterator jt = this->_stuff.begin(); jt != this->_stuff.end(); jt++)
	    {
	      if ((it->first == jt->first) && (it->second > jt->second))
		return (-1);
	    }
	}
    }
  return (0);
}

void 	IA::players()
{
  std::stringstream ss;
  std::map<std::string, int>::iterator it;

  ss << "broadcast lvl ";
  ss << this->_lvl;

  this->look();

  this->_fillAction.first = "broadcast";
  this->_fillAction.second = ss.str();
  this->_listAction.push_back(this->_fillAction);

  this->_fillAction.first = "fork";
  this->_fillAction.second = "fork";
  this->_listAction.push_back(this->_fillAction);

  for (it = this->_mapvision[0].begin(); it != this->_mapvision[0].end(); it++)
    {
      if (it->first.compare("joueur") == 0 && it->second > this->_players[this->_lvl - 1])
	{
	  this->_fillAction.first = "expulse";
	  this->_fillAction.second = "expulse";
	  this->_listAction.push_back(this->_fillAction);
	}
      else if (it->first.compare("joueur") == 0 && it->second == this->_players[this->_lvl - 1])
	{
	  for (std::map<std::string, int>::iterator jt = this->_mapvision[this->_lvl - 1].begin(); jt != this->_mapvision[this->_lvl - 1].end(); jt++)
	    {
	      if (jt->first.compare("joueur") != 0 && jt->second > 1)
		{
		  jt->second--;
		  this->_fillAction.first = "prend";
		  this->_fillAction.second = "prend " + jt->first;
		  this->_listAction.push_back(this->_fillAction);
		  this->_stuff[jt->first]++;
		}
	    }
	  for (std::map<std::string, int>::iterator it = this->_stuff.begin(); it != this->_stuff.end(); it++)
	    {
	      if (it->second != 0 && this->_stuff[it->first] > 0)
		{
		  this->_stuff[it->first]--;
		  this->_fillAction.first = "pose";
		  this->_fillAction.second = "pose " + it->first;
		}
	    }
	  this->_fillAction.first = "incantation";
	  this->_fillAction.second = "incantation";
	  this->_listAction.push_back(this->_fillAction);
	}
    }
  this->survive();
}

void	IA::Evolve()
{
  if (this->checkEvolve() == 0)
    {
      this->look();
      if (this->_lvl == 1)
	{
	  for (std::map<std::string, int>::iterator it = this->_mapvision[this->_lvl - 1].begin(); it != this->_mapvision[this->_lvl - 1].end(); it++)
	    {
	      if (it->first.compare("joueur") != 0 && it->second > 1)
		{
		  it->second--;
		  this->_fillAction.first = "prend";
		  this->_fillAction.second = "prend " + it->first;
		  this->_listAction.push_back(this->_fillAction);
		  this->_stuff[it->first]++;
		}
	    }
	  if (this->_stuff["linemate"] != 0)
	    {
	      this->_stuff["linemate"]--;
	      this->_fillAction.first = "pose";
	      this->_fillAction.second = "pose linemate";
	      this->_listAction.push_back(this->_fillAction);
	      this->_fillAction.first = "incantation";
	      this->_fillAction.second = "incantation";
	      this->_listAction.push_back(this->_fillAction);
	      this->_fillAction.first = "fork";
	      this->_fillAction.second = "fork";
	      this->_listAction.push_back(this->_fillAction);
	    }
	}
      else
	this->players();
    }
}

std::vector<std::vector<int> > IA::getVision(int lvl)
{
  std::vector<std::vector<int> > vision;
  std::vector<int> stack;
  int nb = 1;
  int width = 0;
  int nb_col = 3;
  int save = 1;

  for (int i = 0; i <= lvl; i++)
    vision.push_back(stack);
  vision[0].push_back(0);
  for (nb = 1; nb <= lvl; nb++)
    {
      width = 0;
      for (;width < nb_col; width++)
	{
	  vision[nb].push_back(save);
	  save++;
	}
      nb_col += 2;
    }
  return (vision);
}

void	IA::voir(std::string &)
{
  this->fillVision();
}

void	IA::avance(std::string &)
{
}

void	IA::droite(std::string &)
{
}

void	IA::gauche(std::string &)
{
}

void	IA::inventaire(std::string &)
{
  this->fillHp();
}

std::string IA::getObj()
{
  std::string str = this->_listAction[0].second;
  std::string save;

  std::size_t found = str.find_first_of(" ");
  save = str.substr(found + 1, str.size());
  return (save);
}

void	IA::prend(std::string &)
{
  if (this->_cmd.compare("ok\n") != 0)
    this->_stuff[this->getObj()]--;
}

void	IA::pose(std::string &)
{
  if (this->_cmd.compare("ok\n") != 0)
    this->_stuff[this->getObj()] = 0;
}

void	IA::broadcast(std::string &)
{
}

void	IA::doFork(std::string &)
{
}

void	IA::incantation(std::string &)
{
  if (this->_cmd == "elevation en cours\n")
    {
      this->_lvl++;
      this->_vision = this->getVision(this->_lvl);
      this->_fork = 0;
      this->_elevation = 1;

    }
}

int 	IA::checkBroadcast()
{
  std::string str;
  if (this->_cmd.size() > 7)
    {
      str = this->_cmd.substr(0, 7);
      if (str == "message")
	{
	  if (this->_lvl == this->LvlIa() && this->checkEvolve() == 0)
	    return (0);
	}
    }
  return (-1);
}

int 	IA::LvlIa() const
{
  int i;
  std::stringstream ss;
  std::string x;

  x = this->_cmd.substr(this->_cmd.size() - 2, this->_cmd.size() -1);
  ss << x;
  ss >> i;
  return (i);
}

int 	IA::getDir()
{
  std::stringstream ss;
  int dir;

  std::string save;
  std::string str = this->_cmd;
  std::size_t found = str.find_first_of(" ");
  save = str.substr(found + 1, str.size());
  save = save.substr(0, 1);

  ss << save;
  ss >> dir;
  return (dir);
}

void	IA::one()
{
  this->_fillAction.first = "avance";
  this->_fillAction.second = "avance;";
  this->_listAction.push_back(this->_fillAction);
}

void	IA::two()
{
  this->_fillAction.first = "avance";
  this->_fillAction.second = "avance;";
  this->_listAction.push_back(this->_fillAction);
  this->_fillAction.first = "gauche";
  this->_fillAction.second = "gauche;";
  this->_listAction.push_back(this->_fillAction);
  this->_fillAction.first = "avance";
  this->_fillAction.second = "avance;";
  this->_listAction.push_back(this->_fillAction);
}

void	IA::three()
{
  this->_fillAction.first = "gauche";
  this->_fillAction.second = "gauche;";
  this->_listAction.push_back(this->_fillAction);
  this->_fillAction.first = "avance";
  this->_fillAction.second = "avance;";
  this->_listAction.push_back(this->_fillAction);
}

void	IA::four()
{
  this->_fillAction.first = "gauche";
  this->_fillAction.second = "gauche;";
  this->_listAction.push_back(this->_fillAction);
  this->_fillAction.first = "avance";
  this->_fillAction.second = "avance;";
  this->_listAction.push_back(this->_fillAction);
  this->_fillAction.first = "gauche";
  this->_fillAction.second = "gauche;";
  this->_listAction.push_back(this->_fillAction);
  this->_fillAction.first = "avance";
  this->_fillAction.second = "avance;";
  this->_listAction.push_back(this->_fillAction);
}

void	IA::five()
{
  this->_fillAction.first = "gauche";
  this->_fillAction.second = "gauche;";
  this->_listAction.push_back(this->_fillAction);
  this->_fillAction.first = "gauche";
  this->_fillAction.second = "gauche;";
  this->_listAction.push_back(this->_fillAction);
  this->_fillAction.first = "avance";
  this->_fillAction.second = "avance;";
  this->_listAction.push_back(this->_fillAction);
}

void	IA::six()
{
  this->_fillAction.first = "droite";
  this->_fillAction.second = "droite;";
  this->_listAction.push_back(this->_fillAction);
  this->_fillAction.first = "avance";
  this->_fillAction.second = "avance;";
  this->_listAction.push_back(this->_fillAction);
  this->_fillAction.first = "droite";
  this->_fillAction.second = "droite;";
  this->_listAction.push_back(this->_fillAction);
  this->_fillAction.first = "avance";
  this->_fillAction.second = "avance;";
  this->_listAction.push_back(this->_fillAction);
}

void	IA::seven()
{
  this->_fillAction.first = "droite";
  this->_fillAction.second = "droite;";
  this->_listAction.push_back(this->_fillAction);
  this->_fillAction.first = "avance";
  this->_fillAction.second = "avance;";
  this->_listAction.push_back(this->_fillAction);
}

void	IA::eight()
{
  this->_fillAction.first = "avance";
  this->_fillAction.second = "avance;";
  this->_listAction.push_back(this->_fillAction);
  this->_fillAction.first = "droite";
  this->_fillAction.second = "droite;";
  this->_listAction.push_back(this->_fillAction);
  this->_fillAction.first = "avance";
  this->_fillAction.second = "avance;";
  this->_listAction.push_back(this->_fillAction);
}

void	IA::getBroadcast()
{
  int dir;

  this->_listAction.clear();
  dir = this->getDir();
  if (dir != 0)
    (this->*_deplacement[dir])();
}

int 	IA::checkElev()
{
  std::string save;
  std::string str = this->_cmd;
  std::size_t found = str.find_first_of(" ");
  found = str.find_first_of(" ", found + 1);
  if (this->_cmd.size() > 7)
    {
      std::size_t found = str.find_first_of(" ");
      found = str.find_first_of(" ", found + 1);
      save = str.substr(0, found);
      if (save == "niveau actuel")
	{
	  this->_elevation = 0;
	  return (0);
	}
    }
  return (-1);
}

int 	IA::checkExpulse()
{
  if (this->_cmd.size() > 8)
    {
      std::size_t found = this->_cmd.find_first_of(" ");;
      std::string str = this->_cmd.substr(0, found);
      if (str == "deplacement")
	return (0);
    }
  return (-1);
}

int 	IA::expulseDir()
{
  int a;
  std::stringstream ss;
  std::string save;
  std::size_t found = this->_cmd.find_first_of(" ");

  save = this->_cmd.substr(0, this->_cmd.size() - 1);
  found = save.find_first_of(" ");
  save = save.substr(found+1, found + 1);
  ss << save;
  ss >> a;
  return (a);
}


void	IA::expulse()
{
  int dir;

  dir = this->expulseDir();
  (this->*_deplacement[dir])();
}

void	IA::doAction()
{
  char buffer[1024];
  int len;

  if ((len = read(this->_fd, buffer, 1023)) == -1)
    throw MyError("fail read\n");
  if (len == 0)
    {
      close(this->_fd);
      throw MyError("disconnected");
    }
  buffer[len] = 0;
  this->_cmd = buffer;
  if (this->checkBroadcast() == 0)
    {
      this->getBroadcast();
      return;
    }
  if (this->checkExpulse() == 0)
    {
      this->expulse();
      return;
    }
  if (this->checkBroadcast() != 0 && this->checkElev() != 0)
    {
      if (this->_listAction.size() != 0)
  	{
	  for (std::map<std::string, IA::fct>::iterator it = this->_Actions.begin(); it != this->_Actions.end(); it++)
	    {
	      if (it->first == this->_listAction[0].first)
		{
		  (this->*(it->second))(this->_listAction[0].second);
		  this->_listAction.erase(this->_listAction.begin());
		}
	    }
	}
    }
}

void	IA::active()
{
  const char		*buffer;
  std::string str;

  if (this->_elevation == 0)
    {
      str = this->_listAction[0].first + "\n";
      buffer = str.c_str();
      if (str.compare("broadcast\n") != 0 && str.compare("prend\n") != 0 && str.compare("pose\n") != 0)
	write(this->_fd, buffer, str.size());
      if (str == "broadcast\n" || str == "prend\n" || str == "pose\n")
	{
	  str = this->_listAction[0].second + "\n";
	  buffer = str.c_str();
	  write(this->_fd, buffer, str.size());
	}
    }
}

void	IA::Com()
{
  std::stringstream ss;

  ss << this->_teamName;
  ss << "\n";
  std::string str = ss.str();
  this->receiveFromServer();
  write(this->_fd, str.c_str(), str.size());
  this->receiveFromServer();
  this->receiveFromServer();
}

void	IA::handleSelect()
{
  fd_set 			  		readfds;
  std::pair<std::string, std::string> see;

  srand(time(NULL));
  this->connectToServer();
  this->Com();
  this->_set = 0;
  while(1)
    {
      FD_ZERO(&readfds);
      FD_SET(this->_fd, &readfds);
      if (this->_set == 0)
	{
	  write(this->_fd, "voir\n", 5);
	  this->_set = 1;
	  this->look();
	}
      if (select(this->_fd + 1, &readfds, NULL, NULL, NULL) == -1)
	throw MyError("error on select");
      else
    	{
    	  if (FD_ISSET(this->_fd, &readfds))
	    this->doAction();
    	}
      if (this->_listAction.size() == 0)
	this->run();
      else
	this->active();
    }
}

void	IA::run()
{
  this->look();
  this->resetHp();
  if (this->_stuff["nourriture"] < 3)
    {
      if (this->foodBox() != 0)
	this->survive();
      else
	this->moveRand();
    }
  else if ((this->_nbObj = this->checkVision()) != 0 || this->foodBox() != 0)
    {
      this->move();
    }
  else
    this->moveRand();
  this->Evolve();
  this->active();
}
