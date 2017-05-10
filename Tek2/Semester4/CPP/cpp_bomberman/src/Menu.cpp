#include "Menu.hh"

Menu::Menu()
{
    this->nb_player = 0;
    this->nb_bots = 1;
	  this->page = 0;
    this->my_save = 20;
    this->width = 15;
    this->height = 15;
    this->map = 0;
    this->exit = 0;
    this->screen_size = 123;

    this->create[2] = &Menu::page2;
    this->create[4] = &Menu::page4;
    this->create[5] = &Menu::page5;
    this->create[6] = &Menu::page6;
    this->create[7] = &Menu::page7;

    this->create_draw[2] = &Menu::draw2;
    this->create_draw[4] = &Menu::draw4;
    this->create_draw[5] = &Menu::draw5;
    this->create_draw[6] = &Menu::draw6;
    this->create_draw[7] = &Menu::draw7;

    this->create_map[1] = &Menu::map1;
    this->create_map[2] = &Menu::map2;
    this->create_map[3] = &Menu::map3;
    this->create_map[4] = &Menu::map4;
}

Menu::~Menu()
{ 
  for (size_t i = 0; i < this->obj.size(); ++i)
    delete this->obj[i];
  for (unsigned int i = 0; i < this->obj_bot.size(); i++)
    {
      this->obj_bot.erase(this->obj_bot.begin()+i);
      delete this->obj_bot[i];
    }
    for (unsigned int i = 0; i < this->obj_bomb.size(); i++)
      delete this->obj_bomb[i];
  for (unsigned int i = 0; i < this->obj_save.size(); i++)
    {
      this->obj_save.erase(this->obj_save.begin()+i);
      delete this->obj_save[i];
    }
  for (unsigned int i = 0; i < this->obj_screen.size(); i++)
    {
      this->obj_screen.erase(this->obj_screen.begin()+i);
      delete this->obj_screen[i];
    }
  for (unsigned int i = 0; i < this->obj_map.size(); i++)
    {
      this->obj_map.erase(this->obj_map.begin()+i);
      delete this->obj_map[i];
    }
 this->menu.stop();
}

bool Menu::initialize()
{
  glm::mat4 projection;
  glm::mat4 transformation;

  if (!this->menu.start(WIDTH,HEIGHT,"Menu Bomberman"))
    throw MyError("Failed to init");
  if (!shader.load("./shaders/basic.fp", GL_FRAGMENT_SHADER) || !shader.load("./shaders/basic.vp", GL_VERTEX_SHADER) || !shader.build())
    throw MyError("Failed to init");
  this->checkLadder();
  glEnable(GL_DEPTH_TEST);

  projection = glm::perspective(60.0f, 1024.0f / 768.0f, 0.1f, 1000.0f);
  transformation = glm::lookAt(glm::vec3(0, 0, -100), glm::vec3(0, 0, 0), glm::vec3(0, 1, 0));
  this->shader.bind();
  this->shader.setUniform("view", transformation);
  this->shader.setUniform("projection", projection);

  if (this->loadTexture() == false)
    throw MyError("Failed to init");
  return (true);
}

void Menu::drawLadder(int nb)
{
  std::stringstream ss;
  std::string number;
  std::vector<std::vector<int> > coord;

  ss << nb;
  number = ss.str();
  ss.clear();
  ss.str("");
  for (unsigned int i = 0; i < number.size(); i++)
  {
    std::string name;
    ss << "./texture/" << number[i] << ".tga";
    name = ss.str();
    ss.clear();
    ss.str("");
    coord = this->getVect(-10 + (i * -10),0, -10 + (i * -10) - 10,0, -10 + (i * -10) - 10,10, -10 + (i * -10),10, 1);
    IObject *num = new Img(coord, name, 3);
    if (num->initialize() == false)
      return;
    this->obj.push_back(num);
  }
}

void Menu::drawLadder(int nb, int useless)
{
  std::stringstream ss;
  std::string number;
  std::vector<std::vector<int> > coord;

  (void)useless;
  ss << nb;
  number = ss.str();
  ss.clear();
  ss.str("");
  for (unsigned int i = 0; i < number.size(); i++)
  {
    std::string name;
    ss << "./texture/" << number[i] << ".tga";
    name = ss.str();
    ss.clear();
    ss.str("");
    coord = this->getVect(-10 + (i * -10), -20, -20 + (i * -10),  -20, -20 + (i * -10), -10 , -10 + (i * -10), -10, 1);
    IObject *num = new Img(coord, name, 3);
    if (num->initialize() == false)
      return;
    this->obj.push_back(num);
  }
}

void Menu::checkLadder()
{
  std::string line;
  std::ifstream myfile ("./Ladder/ladder.txt");
  std::vector<int> lad;
  int nb;
  std::vector<std::vector<int> > coord;
  std::istringstream ss;


  if (myfile.is_open())
  {
    coord = this->getVect(60,0, 0,0, 0,10, 60,10, 0);
    IObject *play1 = new Img(coord,"./texture/play1.tga", 3);
    if (play1->initialize() == false)
      return ;
    this->obj.push_back(play1);

    coord = this->getVect(60, -20, 0,-20, 0,-10, 60,-10, 0);
    IObject *play2 = new Img(coord,"./texture/play2.tga", 3);
    if (play2->initialize() == false)
      return ;
    this->obj.push_back(play2);
    while ( std::getline (myfile,line) )
    {
      ss.str(line);
      ss >> nb;
      lad.push_back(nb);
      ss.clear();
      ss.str("");
    }
    this->drawLadder(lad[0]);
    this->drawLadder(lad[1], 1);
    myfile.close();
  }
  else
  {
    coord = this->getVect(60,0, 0,0, 0,10, 60,10, 0);
    IObject *start = new Img(coord,"./texture/noranking.tga", 3);
    if (start->initialize() == false)
      return ;
    this->obj.push_back(start);
  }
}

const std::vector<std::vector<int > > Menu::getVect(int x1,int y1, int x2,int y2, int x3,int y3, int x4,int y4, int z)
{
  std::vector<std::vector<int> >coord;
  std::vector<int> ok;
  for (unsigned int i = 0; i != 4; i++)
    coord.push_back(ok);
  coord[0].push_back(x1);
  coord[0].push_back(y1);
  coord[1].push_back(x2);
  coord[1].push_back(y2);
  coord[2].push_back(x3);
  coord[2].push_back(y3);
  coord[3].push_back(x4);
  coord[3].push_back(y4);
  coord[3].push_back(z);
  return (coord);
}

bool Menu::loadTexture()
{
  std::vector<std::vector<int> > coord;

  coord = this->getVect(78,-58, -78,-58, -78,58, 78,58, 0);
  IObject *bkgd = new Img(coord,"./texture/menu.tga", 0);
  if (bkgd->initialize() == false)
    return (false);
  this->obj.push_back(bkgd);

  coord = this->getVect(70,20, -70,20, -70,50, 70,50, 0);
  IObject *logo = new Img(coord,"./texture/logo.tga", 0);
  if (logo->initialize() == false)
    return (false);
  this->obj.push_back(logo);

  coord = this->getVect(70,20, -70,20, -70,50, 70,50, 1);
  IObject *ranking = new Img(coord,"./texture/ranking.tga", 3);
  if (ranking->initialize() == false)
    return (false);
  this->obj.push_back(ranking);

  coord = this->getVect(60,0, 0,0, 0,10, 60,10, 0);
  IObject *start = new Img(coord,"./texture/start.tga", 1);
  if (start->initialize() == false)
    return (false);
  this->obj.push_back(start);

  coord = this->getVect(60, -20, 0,-20, 0,-10, 60,-10, 0);
  IObject *save = new Img(coord,"./texture/load.tga", 1);
  if (save->initialize() == false)
    return (false);
  this->obj.push_back(save);

  coord = this->getVect(60, -40, 0,-40, 0,-30, 60,-30, 0);
  IObject *screen = new Img(coord,"./texture/exit.tga", 1);
  if (screen->initialize() == false)
    return (false);
  this->obj.push_back(screen);

  coord = this->getVect(-15,0, -75,0, -75,10, -15,10, 0); 
  IObject *rank = new Img(coord,"./texture/rank.tga", 1);
  if (rank->initialize() == false)
    return (false);
  this->obj.push_back(rank);

  coord = this->getVect(-15,-20, -75,-20, -75,-10, -15,-10, 0);
  IObject *exit = new Img(coord,"./texture/screen.tga", 1);
  if (exit->initialize() == false)
    return (false);
  this->obj.push_back(exit);

  coord = this->getVect(60,0, 0,0, 0,10, 60,10, 0);
  IObject *small = new Img(coord,"./texture/1200.tga", 4);
  if (small->initialize() == false)
    return (false);
  this->obj.push_back(small);

  coord = this->getVect(60, -20, 0,-20, 0,-10, 60,-10, 0);
  IObject *normal = new Img(coord,"./texture/1600.tga", 4);
  if (normal->initialize() == false)
    return (false);
  this->obj.push_back(normal);

  coord = this->getVect(60, -40, 0,-40, 0,-30, 60,-30, 0);
  IObject *tall = new Img(coord,"./texture/1920.tga", 4);
  if (tall->initialize() == false)
    return (false);
  this->obj.push_back(tall);

  coord = this->getVect(60,0, 0,0, 0,10, 60,10, 0);
  IObject *map1 = new Img(coord,"./texture/map1.tga", 5);
  if (map1->initialize() == false)
    return (false);
  this->obj.push_back(map1);

  coord = this->getVect(60, -15, 0,-15, 0,-5, 60,-5, 0);
  IObject *map2 = new Img(coord,"./texture/map2.tga", 5);
  if (map2->initialize() == false)
    return (false);
  this->obj.push_back(map2);

  coord = this->getVect(60, -30, 0,-30, 0,-20, 60,-20, 0);
  IObject *map3 = new Img(coord,"./texture/map3.tga", 5);
  if (map3->initialize() == false)
    return (false);
  this->obj.push_back(map3);

  coord = this->getVect(60, -45, 0,-45, 0,-35, 60,-35, 0);
  IObject *random = new Img(coord,"./texture/random.tga", 5);
  if (random->initialize() == false)
    return (false);
  this->obj.push_back(random);

  coord = this->getVect(60,0, 0,0, 0,10, 60,10, 0);
  IObject *player1 = new Img(coord,"./texture/player1.tga", 7);
  if (player1->initialize() == false)
    return (false);
  this->obj.push_back(player1);

  coord = this->getVect(60, -20, 0,-20, 0,-10, 60,-10, 0);
  IObject *player2 = new Img(coord,"./texture/player2.tga", 7);
  if (player2->initialize() == false)
    return (false);
  this->obj.push_back(player2);

  coord = this->getVect(-30, 0, -60,0, -60,15, -30,15, 1);
  IObject *plus = new Img(coord,"./texture/plus.tga", 7);
  if (plus->initialize() == false)
    return (false);
  this->obj.push_back(plus);

  coord = this->getVect(-30, -40, -60,-40, -60,-25, -30,-25, 1);
  IObject *moin = new Img(coord,"./texture/moin.tga", 7);
  if (moin->initialize() == false)
    return (false);
  this->obj.push_back(moin);

  coord = this->getVect(60, -40, 0,-40, 0,-30, 60,-30, 0);
  IObject *bots = new Img(coord,"./texture/bots.tga", 7);
  if (bots->initialize() == false)
    return (false);
  this->obj.push_back(bots);

  coord = this->getVect(-30, -20, -45, -20, -45, -5, -30, -5, 0);
  IObject *one = new Img(coord,"./texture/1.tga", 7);
  if (one->initialize() == false)
    return (false);
  this->obj_bot.push_back(one);

  coord = this->getVect(60,0, 0,0, 0,10, 60,10, 0);
  IObject *width = new Img(coord,"./texture/width.tga", 6);
  if (width->initialize() == false)
    return (false);
  this->obj.push_back(width);

  coord = this->getVect(60, -40, 0,-40, 0,-30, 60,-30, 0);
  IObject *height = new Img(coord,"./texture/height.tga", 6);
  if (height->initialize() == false)
    return (false);
  this->obj.push_back(height);

  coord = this->getVect(-10,0, -20,0, -20,10, -10, 10, 0);
  IObject *plu = new Img(coord,"./texture/plus.tga", 6);
  if (plu->initialize() == false)
    return (false);
  this->obj.push_back(plu);

  coord = this->getVect(-10,-40, -20,-40, -20,-30, -10,-30, 0);
  IObject *plous = new Img(coord,"./texture/plus.tga", 6);
  if (plous->initialize() == false)
    return (false);
  this->obj.push_back(plous);

  coord = this->getVect(-60,0, -70,0, -70,10, -60, 10, 0);
  IObject *moin1 = new Img(coord,"./texture/moin_bleu.tga", 6);
  if (moin1->initialize() == false)
    return (false);
  this->obj.push_back(moin1);

  coord = this->getVect(-60,-40, -70,-40, -70,-30, -60, -30, 0);
  IObject *moin2 = new Img(coord,"./texture/moin_bleu.tga", 6);
  if (moin2->initialize() == false)
    return (false);
  this->obj.push_back(moin2);

  return (true);
}

void Menu::deleteImg()
{
  for (unsigned int i = 0; i < this->obj_bot.size(); i++)
    this->obj_bot[i]->translate(glm::vec3(0,0,1) * 1500.0f);
}

bool Menu::drawBots(int nb)
{
  std::stringstream ss;
  std::string number;
  std::vector<std::vector<int> > coord;

  ss << nb;
  number = ss.str();
  ss.clear();
  ss.str("");
  for (unsigned int i = 0; i < number.size(); i++)
  {
    std::string name;
    ss << "./texture/" << number[i] << ".tga";
    name = ss.str();
    ss.clear();
    ss.str("");
    coord = this->getVect(-30 + (i * -15),-20, -30 + (i * -15) - 15,-20, -30 + (i * -15) - 15,-5, -30 + (i * -15),-5, 0);
    IObject *num = new Img(coord, name, 7);
    if (num->initialize() == false)
      return (false);
    this->obj_bot.push_back(num);
  }
  return (true);
}

void Menu::deleteSave()
{
  for (unsigned int i = 0; i < this->obj_save.size(); i++)
    this->obj_save[i]->translate(glm::vec3(0,0,1) * 1500.0f);
}

bool Menu::drawSave()
{
  std::vector<std::vector<int> > coord;
  if (this->my_save == 0)
  {
    coord = this->getVect(60,0, 0,0, 0,10, 60,10, 0);
    IObject *num = new Img(coord, "./texture/save.tga", 2);
    if (num->initialize() == false)
      return (false);
    this->obj_save.push_back(num);
  }
  else
  {
    coord = this->getVect(60,0, 0,0, 0,10, 60,10, 0);
    IObject *nosave = new Img(coord, "./texture/nosave.tga", 2);
    if (nosave->initialize() == false)
      return (false);
    this->obj_save.push_back(nosave);
  }
  return (true);
}

void Menu::deleteScreen()
{
  for (unsigned int i = 0; i < this->obj_screen.size(); i++)
    this->obj_screen[i]->translate(glm::vec3(0,0,1) * 1500.0f);
}

bool Menu::drawScreen()
{
  std::vector<std::vector<int> > coord;

  if (this->screen_size == 1)
  {
    coord = this->getVect(75, 0, 65,0, 65,10, 75,10, 2);
    IObject *bomb = new Img(coord,"./texture/bomb.tga", 4);
    if (bomb->initialize() == false)
      return (false);
    this->obj_screen.push_back(bomb);
  }
  else if (this->screen_size == 2)
  {
    coord = this->getVect(75, -20, 65,-20, 65,-10, 75,-10, 2);
    IObject *bomb = new Img(coord,"./texture/bomb.tga", 4);
    if (bomb->initialize() == false)
      return (false);
    this->obj_screen.push_back(bomb);
  }
  else
  {
    coord = this->getVect(75, -40, 65,-40, 65,-30, 75,-30, 2);
    IObject *bomb = new Img(coord,"./texture/bomb.tga", 4);
    if (bomb->initialize() == false)
      return (false);
    this->obj_screen.push_back(bomb);
  }
  return (true);
}

bool Menu::page2()
{
  int save;

  save = this->obj[0]->getSave();
  if (this->my_save != save)
  {
    this->my_save = this->obj[0]->getSave();
    this->deleteSave();
    if (this->drawSave() == false)
      return (false);
  }
  return (true);
}

bool Menu::page4()
{
  int screen;

  screen = this->obj[0]->getScreenSize();
  if (this->screen_size != screen)
  {
    this->screen_size = this->obj[0]->getScreenSize();
    this->deleteScreen();
    if (this->drawScreen() == false)
      return (false);
  }
  return (true);
}

void Menu::deleteMap()
{
  for (unsigned int i = 0; i < this->obj_map.size(); i++)
    this->obj_map[i]->translate(glm::vec3(0,0,1) * 1500.0f);
}

bool Menu::map1()
{
  std::vector<std::vector<int> > coord;

  coord = this->getVect(-10,-55, -75,-55, -75,20, -10,20, 2);
  IObject *bomb = new Img(coord,"./texture/csgo.tga", 5);
  if (bomb->initialize() == false)
    return (false);
  this->obj_map.push_back(bomb);
  return (true);
}

bool Menu::map2()
{
  std::vector<std::vector<int> > coord;

  coord = this->getVect(-10,-55, -75,-55, -75,20, -10,20, 2);
  IObject *dust = new Img(coord,"./texture/dust2.tga", 5);
  if (dust->initialize() == false)
    return (false);
  this->obj_map.push_back(dust);
  return (true);
}

bool Menu::map3()
{
  std::vector<std::vector<int> > coord;

  coord = this->getVect(-10,-55, -75,-55, -75,20, -10,20, 2);
  IObject *bomber = new Img(coord,"./texture/bomber.tga", 5);
  if (bomber->initialize() == false)
    return (false);
  this->obj_map.push_back(bomber);
  return (true);
}

bool Menu::map4()
{
  std::vector<std::vector<int> > coord;

  coord = this->getVect(-10,-55, -75,-55, -75,20, -10,20, 2);
  IObject *gta = new Img(coord,"./texture/gta.tga", 5);
  if (gta->initialize() == false)
    return (false);
  this->obj_map.push_back(gta);
  return (true);
}

bool Menu::drawMap()
{
  std::map<int, Menu::fct>::iterator it;

  for (it = this->create_map.begin(); it != this->create_map.end(); it++)
    {
      if (it->first == this->obj[0]->getMap())
        if ((this->*(it->second))() == false)
          return (false);
    }
  return (true);
}

bool Menu::page5()
{
  int nb_map;

  nb_map = this->obj[0]->getMap();
  if (this->map != nb_map)
  {
    this->map = this->obj[0]->getMap();
    this->setMap();
    this->deleteMap();
    if (this->drawMap() == false)
      return (false);
  }
  return (true);
}

bool Menu::affPlayers()
{
  std::vector<std::vector<int> > coord;

  if (this->obj[0]->getNbPlayer() == 1)
  {
    coord = this->getVect(75, 0, 65,0, 65,10, 75,10, 2);
    IObject *bomb = new Img(coord,"./texture/bomb.tga", 7);
    if (bomb->initialize() == false)
      return (false);
    this->obj_bomb.push_back(bomb);
  }
  else
  {
    coord = this->getVect(75, -20, 65,-20, 65,-10, 75,-10, 2);
    IObject *bomb = new Img(coord,"./texture/bomb.tga", 7);
    if (bomb->initialize() == false)
      return (false);
    this->obj_bomb.push_back(bomb);
  }
  return (true);
}

void Menu::deleteBomb()
{
  for (unsigned int i = 0; i < this->obj_bomb.size(); i++)
    this->obj_bomb[i]->translate(glm::vec3(0,0,1) * 1500.0f);
}
void Menu::drawPlayer()
{
  for (unsigned int a = 0; a < this->obj_bomb.size(); a++)
        this->obj_bomb[a]->draw(this->shader, this->clock);
}

bool Menu::page7()
{
  int bots;
  int players;

  players = this->obj[0]->getNbPlayer();
  bots = this->obj[0]->getNbBot();
  if (this->nb_bots != bots)
  {
    this->deleteImg();
    this->nb_bots = this->obj[0]->getNbBot();
    if (this->drawBots(this->nb_bots) == false)
      return (false);
  }
  if (players != this->nb_player)
  {
    this->deleteBomb();
    this->nb_player = players;
    this->affPlayers();
  }
  return (true);
}

void Menu::deleteWidth()
{
  for (unsigned int i = 0; i < this->obj_width.size(); i++)
    this->obj_width[i]->translate(glm::vec3(0,0,1) * 1500.0f);
}

void Menu::drawWidth()
{
  std::stringstream ss;
  std::string number;
  std::vector<std::vector<int> > coord;

  ss << this->width;
  number = ss.str();
  ss.clear();
  ss.str("");
  for (unsigned int i = 0; i < number.size(); i++)
  {
    std::string name;
    ss << "./texture/" << number[i] << ".tga";
    name = ss.str();
    ss.clear();
    ss.str("");
    coord = this->getVect(-25 - (i * 5),0, -30 - (i * 5),0, -30- (i * 5),10, -25 - (i * 5),10, 0);
    IObject *num = new Img(coord, name, 6);
    if (num->initialize() == false)
      return;
    this->obj_width.push_back(num);
  }
}

void Menu::deleteHeight()
{
  for (unsigned int i = 0; i < this->obj_height.size(); i++)
    this->obj_height[i]->translate(glm::vec3(0,0,1) * 1500.0f);
}

void Menu::drawHeight()
{
  std::stringstream ss;
  std::string number;
  std::vector<std::vector<int> > coord;

  ss << this->height;
  number = ss.str();
  ss.clear();
  ss.str("");
  for (unsigned int i = 0; i < number.size(); i++)
  {
    std::string name;
    ss << "./texture/" << number[i] << ".tga";
    name = ss.str();
    ss.clear();
    ss.str("");
    coord = this->getVect(-25 - (i * 5), -40, -30 - (i * 5),-40, -30- (i * 5),-30, -25 - (i * 5), -30, 0);
    IObject *num = new Img(coord, name, 6);
    if (num->initialize() == false)
      return;
    this->obj_height.push_back(num);
  }
}

bool Menu::page6()
{
  int wdth;
  int hght;

  wdth = this->obj[0]->getWidth();
  hght = this->obj[0]->getHeight();

  if (this->width != wdth)
  {
    this->deleteWidth();
    this->width = wdth;
    this->drawWidth();
  }
  if (this->height != hght)
  {
    this->deleteHeight();
    this->height = hght;
    this->drawHeight();
  }
  return (true);
}

bool Menu::update()
{
  std::map<int, Menu::ptr>::iterator it;

  if (this->input.getKey(SDLK_ESCAPE) || this->input.getInput(SDL_QUIT))
  {
      this->exit = - 1;
      return false;
  }
  this->menu.updateClock(this->clock);
  this->menu.updateInputs(this->input);
  this->obj[0]->update(this->clock, this->input);
  if (this->obj[0]->getCurrentPage() == 0 || this->obj[0]->getCurrentPage() == 9 || this->obj[0]->getCurrentPage() == 8)
    return (false);

  for (it = this->create.begin(); it != this->create.end(); it++)
    {
      if (it->first == this->obj[0]->getCurrentPage())
        if ((this->*(it->second))() == false)
          return (false);
    }
  return true;
}

bool Menu::checkStart()
{
  if (this->obj[0]->getCurrentPage() == 0)
    return (false);
  if (this->exit == -1)
    return (false);
  return (true);
}

void Menu::draw2()
{
  for (unsigned int a = 0; a < this->obj_save.size(); a++)
        this->obj_save[a]->draw(this->shader, this->clock);
}

void Menu::draw4()
{
  for (unsigned int a = 0; a < this->obj_screen.size(); a++)
        this->obj_screen[a]->draw(this->shader, this->clock);
}

void Menu::draw5()
{
  for (unsigned int a = 0; a < this->obj_map.size(); a++)
        this->obj_map[a]->draw(this->shader, this->clock);
}

void Menu::draw7()
{
  for (unsigned int a = 0; a < this->obj_bot.size(); a++)
        this->obj_bot[a]->draw(this->shader, this->clock);
  for (unsigned int a = 0; a < this->obj_bomb.size(); a++)
        this->obj_bomb[a]->draw(this->shader, this->clock);
}

void Menu::draw6()
{
  for (unsigned int a = 0; a < this->obj_width.size(); a++)
        this->obj_width[a]->draw(this->shader, this->clock);
  for (unsigned int a = 0; a < this->obj_height.size(); a++)
    this->obj_height[a]->draw(this->shader, this->clock);

}

void Menu::draw()
{
  std::map<int, Menu::tr>::iterator it;
  int page;
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	this->shader.bind();
  page = this->obj[0]->getCurrentPage();
  for (size_t i = 0; i < this->obj.size(); ++i)
  {
    if (this->obj[i]->getPage() == page || this->obj[i]->getPage() == 0)
      this->obj[i]->draw(this->shader, this->clock);
  }
  for (it = this->create_draw.begin(); it != this->create_draw.end(); it++)
    {
      if (it->first == this->obj[0]->getCurrentPage())
        (this->*(it->second))();
    }
	this->menu.flush();
}

int Menu::getScreenSize() const
{
  return (this->screen_size);
}

void Menu::setMap()
{
  std::vector<std::string> name;

  name.push_back("Map/map1.map");
  name.push_back("Map/map2.map");
  name.push_back("Map/map3.map");
  name.push_back("random.map");

  this->map_name = name[this->map - 1];
}

int Menu::getNbplayers() const
{
  return (this->nb_player);
}

int Menu::getNbBots() const
{
  return (this->nb_bots);
}

std::string Menu::getMapName() const
{
  return (this->map_name);
}

std::pair<int, int> Menu::getResolution() const
{
  std::pair<int, int> map_size;

  if (this->screen_size == 1)
    {
      map_size.first = 640;
      map_size.second = 480;
    }
  else if (this->screen_size == 2)
  {
    map_size.first = 800;
    map_size.second = 600;
  }
  else
  {
    map_size.first = 1024;
    map_size.second = 768;
  }
  return (map_size);
}

int Menu::getLoad() const
{
  return (this->obj[0]->getCurrentPage());
}

std::pair<int, int> Menu::getMapSize() const
{
  std::pair<int, int> map_size;

  map_size.first = this->width;
  map_size.second = this->height;
  return (map_size);
}