#include	"GameEngine.hh"

GameEngine::GameEngine(int nbPlayers, int nbBots, const std::string &mapName, const std::pair<int, int> &mapSize, const std::pair<int, int> &winRes)
{
  _nbPlayers = nbPlayers;
  _nbBots = nbBots;
  _mapName = mapName;
  _mapX = mapSize.first;
  _mapY = mapSize.second;
  _winX = static_cast<float>(winRes.first);
  _winY = static_cast<float>(winRes.second);
  _winner = AObject::IA;
  this->pause = false;
  _range = 2;
  this->create[1] = &GameEngine::get_limit1;
  this->create[2] = &GameEngine::get_limit2;
  this->create[3] = &GameEngine::get_limit3;
  this->create_pause[1] = &GameEngine::getOut;
  this->create_pause[2] = &GameEngine::saveQuit;
  this->create_pause[3] = &GameEngine::Quit;
}

GameEngine::GameEngine(const std::pair<int, int > &resolution)
{
  _winX = static_cast<float>(resolution.first);
  _winY = static_cast<float>(resolution.second);
  _winner = AObject::IA;
  this->pause = false;
  _range = 2;
  _mapName = "./Save/Save.save";
  this->create[1] = &GameEngine::get_limit1;
  this->create[2] = &GameEngine::get_limit2;
  this->create[3] = &GameEngine::get_limit3;
  this->create_pause[1] = &GameEngine::getOut;
  this->create_pause[2] = &GameEngine::saveQuit;
  this->create_pause[3] = &GameEngine::Quit;
}

GameEngine::~GameEngine()
{
  for (unsigned int i = 0; i < _players.size(); ++i)
    delete _players[i];
  _context.stop();
}

std::vector<std::vector<int > > GameEngine::get_limit1()
{
  std::vector<std::vector<int> > lim;
  std::vector<int> x;

  for (unsigned int i = 0; i < 3; i++)
    lim.push_back(x);
  lim[0].push_back(156);
  lim[0].push_back(465);
  lim[0].push_back(70);
  lim[0].push_back(134);

  lim[1].push_back(86);
  lim[1].push_back(579);
  lim[1].push_back(199);
  lim[1].push_back(263);

  lim[2].push_back(212);
  lim[2].push_back(376);
  lim[2].push_back(326);
  lim[2].push_back(393);

  return (lim);
}

std::vector<std::vector<int > > GameEngine::get_limit2()
{
  std::vector<std::vector<int> > lim;
  std::vector<int> x;

  for (unsigned int i = 0; i < 3; i++)
    lim.push_back(x);
  lim[0].push_back(195);
  lim[0].push_back(584);
  lim[0].push_back(84);
  lim[0].push_back(171);

  lim[1].push_back(108);
  lim[1].push_back(724);
  lim[1].push_back(245);
  lim[1].push_back(346);

  lim[2].push_back(267);
  lim[2].push_back(470);
  lim[2].push_back(407);
  lim[2].push_back(493);

  return (lim);
}

std::vector<std::vector<int > > GameEngine::get_limit3()
{
  std::vector<std::vector<int> > lim;
  std::vector<int> x;

  for (unsigned int i = 0; i < 3; i++)
    lim.push_back(x);
  lim[0].push_back(251);
  lim[0].push_back(747);
  lim[0].push_back(110);
  lim[0].push_back(217);

  lim[1].push_back(137);
  lim[1].push_back(925);
  lim[1].push_back(314);
  lim[1].push_back(443);

  lim[2].push_back(340);
  lim[2].push_back(603);
  lim[2].push_back(520);
  lim[2].push_back(629);

  return (lim);
}

void  GameEngine::initPage()
{
  if (_winX == 640)
    this->page = 1;
  else if (_winX == 800)
    this->page = 2;
  else
    this->page = 3;
}

std::vector<std::vector<int> > GameEngine::getVect(int x1,int y1, int x2,int y2, int x3,int y3, int x4,int y4, int z)
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

bool    GameEngine::initialize()
{
  std::vector<std::vector<int> >  coord;
  glm::vec3                       pos;
  int                             a = 2;

  if (!_context.start(_winX, _winY, "The Bomberman"))
    throw MyError("Failed in context.start()");
  glEnable(GL_DEPTH_TEST);
  if(!_shader.load("./LibGDL/shaders/basic.fp", GL_FRAGMENT_SHADER)
      ||!_shader.load("./LibGDL/shaders/basic.vp", GL_VERTEX_SHADER)
      ||!_shader.build())
    throw MyError("Failed to load _shaders");

  coord = this->getVect(85,-63, -85,-63, -85,63, 85,63, 2);
  IObject *bkgd = new Img(coord,"./texture/fond.tga", 3);
  if (bkgd->initialize() == false)
    throw MyError("Failed to init bkdg");
    
  this->obj.push_back(bkgd);
  glDisable(GL_BLEND);
  glDisable(GL_ALPHA_TEST);
  glEnable(GL_DEPTH_TEST);
  this->initPage();
  if (_nbBots > 150)
    _nbBots = 150;
  if (_mapName == "random.map")
    _map = new Map(_mapY, _mapX, _nbPlayers, _nbBots);
  else
  {
    _map = new Map(_mapName);
    _mapY = _map->getY();
    _mapX = _map->getX();
    _nbPlayers = _map->getNbPlayer();
    _nbBots = _map->getNbBot();
  }

  pos = _map->getPosPlayers()[0];
  _players.push_back(new Player1(round(pos.y), round(pos.x)));
  if (pos.y == 0 && pos.x == 0)
    _players[0]->setDead();

  pos = _map->getPosPlayers()[1];
  _players.push_back(new Player2(round(pos.y), round(pos.x)));
  if (pos.y == 0 && pos.x == 0)
    _players[1]->setDead();

  for (unsigned int i = 0; i < _map->getPosIa().size(); ++i)
  {
    pos = _map->getPosIa()[i];
    _players.push_back(new Ia(pos.y, pos.x));
    if (i % 2 == 0)
        _players[i]->setTacticIa(1);
    ++a;
  }
  return (true);
}

bool    GameEngine::update()
{
  std::map<int, GameEngine::ptr>::iterator it;
  std::map<int, GameEngine::ps>::iterator its;
  
  if (_input.getInput(SDL_QUIT))
    return (false);
  if (_input.getKey(SDLK_ESCAPE, true))
  {
    if (this->pause == true)
      pause = false;
    else
      pause = true;
  }
  if (checkAlive() == false)
    return false;
  _context.updateClock(_clock);
  _context.updateInputs(_input);
  if (this->pause == false)
  {
    if (_input.getKey(SDLK_SPACE))
      putBomb(0);
    if (_input.getKey(SDLK_KP_0))
      putBomb(1);
    for (unsigned int i = 0; i < _bombs.size(); ++i)
    {
      if (_bombs[i]->update(_clock) == false)
        explosions(i);
    }
    for (unsigned int i = 0; i < _players.size(); ++i)
    {
      if (_players[i]->getType() == AObject::PLAYER1 || _players[i]->getType() == AObject::PLAYER2)
        _players[i]->update(_clock, _input, _map);
      else
        iaEngine(i);
    }
  }
  else
  {
    SDL_GetMouseState(&(this->x_screen), &(this->y_screen));
    for (it = this->create.begin(); it != this->create.end(); it++)
    {
      if (it->first == this->page)
        this->limit = (this->*(it->second))();
    }
   if (_input.getInput(SDL_BUTTON_LEFT))
    {
      for (unsigned int i = 0; i < this->limit.size(); i++)
      {
        if ((this->x_screen > this->limit[i][0] && this->x_screen < this->limit[i][1]) && (this->y_screen > this->limit[i][2] && this->y_screen < this->limit[i][3]))
        {
          for (its = this->create_pause.begin(); its != this->create_pause.end(); its++)
          {
            if (its->first == static_cast<int>(i + 1))
              return ((this->*(its->second))());
          }  
        }
      }
    }
  }
  return (true);
}

int   GameEngine::round(float nb_f)
{
    int nb_i = nb_f;

    if (nb_f - nb_i > 0.5f)
      return nb_i + 1;
    return nb_i;
}

bool    GameEngine::checkAsset(int y, int x)
{
  if (_map->getMap()[y][x].first == AObject::ASSETBOMB
    || _map->getMap()[y][x].first == AObject::ASSETSPEED
    || _map->getMap()[y][x].first == AObject::ASSETRANGE)
    return true;
  return false;
}

bool    GameEngine::explosionsConditions(int y, int x)
{
  if (_map->getMap()[y][x].first == AObject::BOX)
  {
    _map->setType(y, x, AObject::FIRE, AObject::BOX);
    _players[_id]->setScore(100);
    return false;
  }
  else if (checkAsset(y, x) == true)
  {
    _map->setType(y, x, AObject::FIRE, AObject::ASSET);
    return false;
  }
  if (_map->getMap()[y][x].first == AObject::FIRE && _map->getMap()[y][x].second == AObject::BOMB)
    return false;
  else if (_map->getMap()[y][x].first == AObject::BOMB)
  {
    for (unsigned int i = 0; i < _bombs.size(); ++i)
    {
        glm::vec3 pos = _bombs[i]->getPosition();
        if (pos.y == y && pos.x == x)
        {
          _map->setType(y, x, AObject::FIRE, AObject::BOMB);
          _bombs[i]->explose();
          explosions(i);
          return false;
        }
    }
  }
  for (unsigned int i = 0; i < _players.size(); ++i)
  {
    glm::vec3 pos = _players[i]->getPosition();
    if (round(pos.y) == y && round(pos.x) == x)
    {
      if (i != _id)
        _players[_id]->setScore(1000);
      _players[i]->setDead(); 
    }
  }
  return true;
}

void    GameEngine::explosionTop(int rangePosY, int curPosY, int curPosX, int i)
{
  int r = 0;
  AObject::Type  next = _map->getMap()[rangePosY + 1][curPosX].first;

  while (rangePosY < curPosY + _range && next != AObject::WALL)
  {
    ++rangePosY;
    ++r;
    _bombs[i]->setTop(r);
    if (explosionsConditions(rangePosY, curPosX) == false)
      return ;
    _map->setType(rangePosY, curPosX, AObject::FIRE);
    next = _map->getMap()[rangePosY + 1][curPosX].first;
  }
}


void    GameEngine::explosionRight(int rangePosX, int curPosY, int curPosX, int i)
{
  int r = 0;
  AObject::Type   next = _map->getMap()[curPosY][rangePosX + 1].first;

  while (rangePosX < curPosX + _range && next != AObject::WALL)
  {
    ++rangePosX;
    ++r;
    _bombs[i]->setRight(r);
    if (explosionsConditions(curPosY, rangePosX) == false)
      return ;
    _map->setType(curPosY, rangePosX, AObject::FIRE);
    next = _map->getMap()[curPosY][rangePosX + 1].first;
  }
}

void    GameEngine::explosionBottom(int rangePosY, int curPosY, int curPosX, int i)
{
  int r = 0;
  AObject::Type   next = _map->getMap()[rangePosY - 1][curPosX].first;

  while (rangePosY > curPosY - _range && next != AObject::WALL)
  {
    --rangePosY;
    ++r;
    _bombs[i]->setBottom(r);
    if (explosionsConditions(rangePosY, curPosX) == false)
      return ;
    _map->setType(rangePosY, curPosX, AObject::FIRE);
    next = _map->getMap()[rangePosY - 1][curPosX].first;
  }    
}

void    GameEngine::explosionLeft(int rangePosX, int curPosY, int curPosX, int i)
{
  int r = 0;
  AObject::Type   next = _map->getMap()[curPosY][rangePosX - 1].first;

  while (rangePosX > curPosX - _range && next != AObject::WALL)
  {
    --rangePosX;
    ++r;
    _bombs[i]->setLeft(r);
    if (explosionsConditions(curPosY, rangePosX) == false)
      return;
    _map->setType(curPosY, rangePosX, AObject::FIRE);
    next = _map->getMap()[curPosY][rangePosX - 1].first;
  }
}

void    GameEngine::putAsset(int y, int x)
{
  srand(time(NULL) + y + x);
  int nb = (rand() % 10);

  if (nb >= 6)
  {
    if (nb == 6 || nb == 7)
      _map->setType(y, x, AObject::ASSETBOMB);
    else if (nb == 8)
      _map->setType(y, x, AObject::ASSETSPEED);
    else
      _map->setType(y, x, AObject::ASSETRANGE);
  }
  else
    _map->setType(y, x, AObject::FLOOR);
}

bool    GameEngine::floorConditions(int y, int x)
{
  if ((_map->getMap()[y][x].first == AObject::FIRE && _map->getMap()[y][x].second == AObject::ASSET) ||
        (_map->getMap()[y][x].first == AObject::FIRE && _map->getMap()[y][x].second == AObject::BOMB)) 
  {
    _map->setType(y, x, AObject::FLOOR);
    return false;
  }
  else if (_map->getMap()[y][x].first == AObject::FIRE && _map->getMap()[y][x].second == AObject::BOX)
  {
    putAsset(y, x);
    return false;
  }
  else
    _map->setType(y, x, AObject::FLOOR);
  return true;
}

void    GameEngine::floorTop(int rangePosY, int curPosY, int curPosX, int i)
{
  AObject::Type   next = _map->getMap()[rangePosY + 1][curPosX].first;

  while (rangePosY < curPosY + _bombs[i]->getTop() && next != AObject::WALL)
  {
    ++rangePosY;
    if (floorConditions(rangePosY, curPosX) == false)
      return ;
    next = _map->getMap()[rangePosY + 1][curPosX].first;
  }    
}

void    GameEngine::floorBottom(int rangePosY, int curPosY, int curPosX, int i)
{
  AObject::Type   next = _map->getMap()[rangePosY - 1][curPosX].first;

  while (rangePosY > curPosY - _bombs[i]->getBottom() && next != AObject::WALL)
  {
    --rangePosY;
     if (floorConditions(rangePosY, curPosX) == false)
      return ;
    next = _map->getMap()[rangePosY - 1][curPosX].first;
  }    
}

void    GameEngine::floorRight(int rangePosX, int curPosY, int curPosX, int i)
{
  AObject::Type   next = _map->getMap()[curPosY][rangePosX + 1].first;

  while (rangePosX < curPosX + _bombs[i]->getRight() && next != AObject::WALL)
  {
    ++rangePosX;
    if (floorConditions(curPosY, rangePosX) == false)
        return ;
    next = _map->getMap()[curPosY][rangePosX + 1].first;
  }
}

void    GameEngine::floorLeft(int rangePosX, int curPosY, int curPosX, int i)
{
  AObject::Type   next = _map->getMap()[curPosY][rangePosX - 1].first;

  while (rangePosX > curPosX - _bombs[i]->getLeft() && next != AObject::WALL)
  {
    --rangePosX;
    if (floorConditions(curPosY, rangePosX) == false)
        return ;
    next = _map->getMap()[curPosY][rangePosX - 1].first;
  }
}

void        GameEngine::bombs(int i, int rangePosY, int rangePosX, const glm::vec3 &pos)
{
  _bombs[i]->setExplosed();
  if (!(_map->getMap()[rangePosY][rangePosX].first == AObject::FIRE && _map->getMap()[rangePosY][rangePosX].second == AObject::BOMB))
    _map->setType(rangePosY, rangePosX, AObject::FIRE, AObject::BOMB);
  for (unsigned int a = 0; a < _players.size(); ++a)
  {
    glm::vec3 pos = _players[a]->getPosition();
    if (round(pos.y) == rangePosY && round(pos.x) == rangePosX)
      _players[a]->setDead();
  }
  explosionTop(rangePosY, round(pos.y), round(pos.x), i);
  explosionBottom(rangePosY, round(pos.y), round(pos.x), i);
  explosionRight(rangePosX, round(pos.y), round(pos.x), i);
  explosionLeft(rangePosX, round(pos.y), round(pos.x), i);
}

void        GameEngine::fires(int i, int rangePosY, int rangePosX, const glm::vec3 &pos)
{
  _map->setType(rangePosY, rangePosX, AObject::FLOOR);
  _players[_id]->setBomb(1);

  for (unsigned int a = 0; a < _players.size(); ++a)
  {
    glm::vec3 pos = _players[a]->getPosition();
    if (round(pos.y) == rangePosY && round(pos.x) == rangePosX)
      _players[a]->setDead();                        
  }
  floorTop(rangePosY, round(pos.y), round(pos.x), i);
  floorBottom(rangePosY, round(pos.y), round(pos.x), i);
  floorRight(rangePosX, round(pos.y), round(pos.x), i);
  floorLeft(rangePosX, round(pos.y), round(pos.x), i);
  delete _bombs[i];
  _bombs.erase(_bombs.begin() + i);
}

void        GameEngine::explosions(int i)
{
  glm::vec3 pos = _bombs[i]->getPosition();
  int rangePosY = round(pos.y);
  int rangePosX = round(pos.x);
  _id = _bombs[i]->getId();
  _range = _players[_id]->getRange();

  if ((_map->getMap()[rangePosY][rangePosX].first == AObject::BOMB ||
      _map->getMap()[rangePosY][rangePosX].first == AObject::FIRE) &&
      _bombs[i]->getExplosed() == false)
    bombs(i, rangePosY, rangePosX, pos);
  else if (_bombs[i]->updateFire(_clock) == false)
    fires(i, rangePosY, rangePosX, pos);
}

void        GameEngine::putBomb(int id)
{
  glm::vec3 pos = _players[id]->getPosition();

  if (_players[id]->getDead() == false && _map->getMap()[round(pos.y)][round(pos.x)].first == AObject::FLOOR)
  {
      if ( _players[id]->getBomb() > 0)
      {
        _players[id]->setBomb(-1);
        _map->setType(round(pos.y), round(pos.x), AObject::BOMB);
        _bombs.push_back(new Bomb(round(pos.y), round(pos.x), id));
      }
  }
}

bool GameEngine::getOut()
{
  this->pause = false;
  return (true);
}

bool GameEngine::saveQuit()
{
  saveMap(_map->getMap());
  return (false);
}

bool GameEngine::Quit()
{
  return (false);
}

void GameEngine::initScore(int size)
{
  std::vector<std::vector<int> > coord;

  if (size == 1)
  {
    coord = this->getVect(85,-63, -85,-63, -85,63, 85,63, 2);
    IObject *bkgd = new Img(coord,"./texture/score1.tga", 3);
    if (bkgd->initialize() == false)
      throw MyError("Failed to load bkgd");
    this->obj_score.push_back(bkgd);  
  }
  else
  {
    coord = this->getVect(85,-63, -85,-63, -85,63, 85,63, 2);
    IObject *bkgd = new Img(coord,"./texture/score2.tga", 3);
    if (bkgd->initialize() == false)
      throw MyError("Failed to init bkgd");
    this->obj_score.push_back(bkgd);
  }
  glDisable(GL_BLEND);
  glDisable(GL_ALPHA_TEST);
  glEnable(GL_DEPTH_TEST);
}

void GameEngine::drawScore(int nb)
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
    coord = this->getVect(20 - (i * 10),-20, 10 - (i * 10), -20, 10 - (i * 10),0, 20 - (i * 10),0, 1);
    IObject *num = new Img(coord, name, 6);
    if (num->initialize() == false)
      throw MyError("Failed to init num");
    this->obj_nb.push_back(num);
  }
}

void GameEngine::drawScore(int nb, int nb2)
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
    coord = this->getVect(40 - (i * 10), 0, 30 - (i * 10), 0, 30 - (i * 10),20, 40 - (i * 10),20, 1);
    IObject *num = new Img(coord, name, 6);
    if (num->initialize() == false)
      throw MyError("Failed to init num");
    this->obj_nb.push_back(num);
  }
  ss << nb2;
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
    coord = this->getVect(40 - (i * 10), -40, 30 - (i * 10), -40, 30 - (i * 10),-20, 40 - (i * 10),-20, 1);
    IObject *num = new Img(coord, name, 6);
    if (num->initialize() == false)
      throw MyError("Failed to init num");
    this->obj_nb.push_back(num);
  }
}

void GameEngine::affScore()
{
  std::vector<int>score;
  this->ladder();
  if (_nbPlayers == 2)
  {
    score.push_back(_players[0]->getScore());
    score.push_back(_players[1]->getScore());
  }
  else
    score.push_back(_players[0]->getScore());
  this->affWinner();
  this->initScore(score.size());
  if (score.size() == 1)
    drawScore(score[0]);
  else
    drawScore(score[0], score[1]);
  while (1)
  {
    _context.updateClock(_clock);
    _context.updateInputs(_input);
    if (_input.getKey(SDLK_RETURN) || _input.getKey(SDLK_ESCAPE))
      return;
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glm::mat4 projection;
    glm::mat4 transformation;
    glViewport(0, 0, _winX, _winY);
    projection = glm::perspective(60.0f, _winX  / _winY, 0.1f, 1000.0f);
    transformation = glm::lookAt(glm::vec3(0, 0, -100), glm::vec3(0, 0, 0), glm::vec3(0, 1, 0));
    this->_shader.setUniform("view", transformation);
    this->_shader.setUniform("projection", projection);
    for (size_t i = 0; i < this->obj_score.size(); ++i)
      this->obj_score[i]->draw(this->_shader, this->_clock);
    for (size_t i = 0; i < this->obj_nb.size(); ++i)
      this->obj_nb[i]->draw(this->_shader, this->_clock);
    for (size_t i = 0; i < this->obj_win.size(); ++i)
      this->obj_win[i]->draw(this->_shader, this->_clock);
    _shader.bind();
    _context.flush();
  }
}

void   GameEngine::affWinner()
{
  std::vector<std::vector<int> > coord;

  if (_nbPlayers == 1)
  {
    if (_winner == AObject::PLAYER1)
    {
      coord = this->getVect(-40 , 0, -75, 0, -75,20, -40,20, 1);
      IObject *bkgd = new Img(coord,"./texture/win.tga", 6);
      if (bkgd->initialize() == false)
        throw MyError("Failed to init");
      this->obj_win.push_back(bkgd);
    }
  else
    {
      coord = this->getVect(-20 , -40, -75, -40, -75,-20, -20,-20, 1);
      IObject *ia = new Img(coord,"./texture/ia_win.tga", 6);
      if (ia->initialize() == false)
        throw MyError("Failed to init");
      this->obj_win.push_back(ia);
    }  
  }
  else
  {
    if (_winner == AObject::PLAYER1)
    {
      coord = this->getVect(-40 , 20, -75, 20, -75,40, -40,40, 1);
      IObject *play1 = new Img(coord,"./texture/win.tga", 6);
      if (play1->initialize() == false)
        throw MyError("Failed to init");
      this->obj_win.push_back(play1);
    }
   else if (_winner == AObject::PLAYER2)
   {
      coord = this->getVect(-40 , -20, -75, -20, -75,0, -40,0, 1);
      IObject *play2 = new Img(coord,"./texture/win.tga", 6);
      if (play2->initialize() == false)
        throw MyError("Failed to init");
      this->obj_win.push_back(play2);
   }
   else
   {
    coord = this->getVect(-20 , -40, -75, -40, -75,-20, -20,-20, 1);
    IObject *ia = new Img(coord,"./texture/ia_win.tga", 6);
    if (ia->initialize() == false)
     throw MyError("Failed to init");  
    this->obj_win.push_back(ia);
   }
  }
}

bool    GameEngine::checkAlive()
{
  int   nbPlayersAlive = 0;

  for (unsigned int i = 0; i < _players.size(); ++i)
  {
    if (_players[i]->getDead() == false)
        nbPlayersAlive++;
  }
  
  if (_players[0]->getDead() == true && _players[1]->getDead() == true)
  {
    _winner = AObject::IA;
    return false;
  }
  if (nbPlayersAlive == 1)
  {
    if (_players[0]->getDead() == false)
      _winner = AObject::PLAYER1;
    else if (_players[1]->getDead() == false)
      _winner = AObject::PLAYER2;
    return false;
  }
  return true;
}

void    GameEngine::drawPlayers(int id)
{
  glm::vec3   position = _players[id]->getPosition();

  for (unsigned int i = 0; i < _players.size(); ++i)
  {
    if (_players[i]->getDead() == false
      && (_players[i]->getPosition().x >= position.x - CLIPPING && _players[i]->getPosition().x <= position.x + CLIPPING) 
      && (_players[i]->getPosition().y >= position.y - CLIPPING && _players[i]->getPosition().y <= position.y + CLIPPING))
      _players[i]->draw(_shader, _clock);
  }
}

void    GameEngine::drawMap(int id)
{
  _map->updateLimits(_players[id]->getPosition());
  _map->draw(_shader, _clock);
}

void    GameEngine::setCamera(float x, float width, int id)
{
  glViewport(x, 0, width, _winY);
  
  glm::vec3   position = _players[id]->getPosition();
  glm::mat4   transformation = glm::lookAt(glm::vec3(position.x, position.y - INCLINAISON, 10), glm::vec3(position.x, position.y, position.z), glm::vec3(0, 1, 0));
  _shader.setUniform("view", transformation);
}

void        GameEngine::drawOnePlayer()
{
  glm::mat4   projection = glm::perspective(60.0f, _winX / _winY, 0.1f, 100.0f);
  _shader.setUniform("projection", projection);  

  setCamera(0, _winX, 0);
  drawMap(0);
  drawPlayers(0);
}

void        GameEngine::drawTwoPlayer()
{
  glm::mat4   projection = glm::perspective(60.0f, (_winX / 2) / _winY, 0.1f, 100.0f);
  _shader.setUniform("projection", projection);

  for (int i = 0; i < 2; ++i)
  {
    if (_players[i]->getDead() == false)
    {
      if (!i)
        setCamera(0, _winX / 2 - 15, i);
      else
        setCamera(_winX / 2 + 15, _winX / 2 + 15, i);
      drawMap(i);
      drawPlayers(i);
    }
  }
}

void        GameEngine::draw()
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glm::mat4 projection;
  glm::mat4 transformation;

  if (this->pause == false)
  {
    if (_nbPlayers == 1)
      drawOnePlayer();
    else
      drawTwoPlayer();
  }
  else
  {
    glViewport(0, 0, _winX, _winY);
    projection = glm::perspective(60.0f, _winX  / _winY, 0.1f, 1000.0f);
    transformation = glm::lookAt(glm::vec3(0, 0, -100), glm::vec3(0, 0, 0), glm::vec3(0, 1, 0));

    this->_shader.setUniform("view", transformation);
    this->_shader.setUniform("projection", projection);
    for (size_t i = 0; i < this->obj.size(); ++i)
      this->obj[i]->draw(this->_shader, this->_clock);
  }
  _shader.bind();
  _context.flush();
}

int        GameEngine::checkNearestEnemy(int idIa, const glm::vec3 &posIa)
{
  bool    key = false;
  int     nearId = 0;
  int     firstGap = 0;
  int     gap = -1;

  for (unsigned int i = 0; i < _players.size(); ++i)
  {
      if (i != static_cast<unsigned int>(idIa) && _players[i]->getDead() == false)
      {
        glm::vec3 posEnemy = _players[i]->getPosition();
        firstGap = std::abs(posEnemy.y - posIa.y) + std::abs(posEnemy.x - posIa.x);
        if (key == false)
        {
          key = true;
          gap = firstGap;
          nearId = i;
        }
        else if (firstGap < gap)
        {
          gap = firstGap;
          nearId = i;
        }
      }
  }
  return nearId;
}

void        GameEngine::calcY(int idIa, const glm::vec3 &posEnemy, const glm::vec3 &posIa)
{
  if (posIa.y > round(posEnemy.y) && _players[idIa]->getImIn() == true
    && (_map->getMap()[round(posIa.y) - 1][round(posIa.x)].first == AObject::FLOOR ||
      checkAsset(round(posIa.y) - 1, round(posIa.x))))
  {
    _players[idIa]->setDown(round(posIa.y) - 1);
    _players[idIa]->setImIn(false);
    _players[idIa]->setDirection(DOWN);
    if (_players[idIa]->getRun() == 0)
      _players[idIa]->setRun(1);
  }
  else if (posIa.y < round(posEnemy.y) && _players[idIa]->getImIn() == true
  && (_map->getMap()[round(posIa.y) + 1][round(posIa.x)].first == AObject::FLOOR ||
    checkAsset(round(posIa.y) + 1, round(posIa.x))))
  {
    _players[idIa]->setUp(round(posIa.y) + 1);
    _players[idIa]->setImIn(false);
    _players[idIa]->setDirection(UP);
    if (_players[idIa]->getRun() == 0)
      _players[idIa]->setRun(1);
  }
}

void        GameEngine::calcX(int idIa, const glm::vec3 &posEnemy, const glm::vec3 &posIa)
{
  if (posIa.x > round(posEnemy.x) && _players[idIa]->getImIn() == true
    && (_map->getMap()[round(posIa.y)][round(posIa.x) - 1].first == AObject::FLOOR ||
      checkAsset(round(posIa.y), round(posIa.x) - 1)))
  {
    _players[idIa]->setLeft(round(posIa.x) - 1);
    _players[idIa]->setImIn(false);
    _players[idIa]->setDirection(LEFT);
    if (_players[idIa]->getRun() == 0)
      _players[idIa]->setRun(1);
  }
  else if (posIa.x < round(posEnemy.x) && _players[idIa]->getImIn() == true  
    && (_map->getMap()[round(posIa.y)][round(posIa.x) + 1].first == AObject::FLOOR
      || checkAsset(round(posIa.y), round(posIa.x) + 1)))
  {  
    _players[idIa]->setRight(round(posIa.x) + 1);
    _players[idIa]->setImIn(false);
    _players[idIa]->setDirection(RIGHT);
    if (_players[idIa]->getRun() == 0)
      _players[idIa]->setRun(1);
  }
}

void      GameEngine::goY(int idIa, glm::vec3 &posIa)
{
  if (_players[idIa]->getImIn() == false)
  {
    if (_players[idIa]->getDirection() == DOWN)
    {
      _players[idIa]->goDown(-1);
      posIa = _players[idIa]->getPosition();
      if (posIa.y <= _players[idIa]->getDown())
      {
        _players[idIa]->setImIn(true);
        _players[idIa]->setDirection(0);
        _players[idIa]->setRun(0);
        _players[idIa]->gereAnim(-1);
        _players[idIa]->setPosition(_players[idIa]->getDown(), posIa.x);
      }
    }
    else if (_players[idIa]->getDirection() == UP)
    {
      _players[idIa]->goUp(-1);
      posIa = _players[idIa]->getPosition();
      if (posIa.y >= _players[idIa]->getUp())
      {
        _players[idIa]->setImIn(true);
        _players[idIa]->setDirection(0);
        _players[idIa]->setRun(0);
        _players[idIa]->gereAnim(-1);
        _players[idIa]->setPosition(_players[idIa]->getUp(), posIa.x);
     }
    }
  }
}

void      GameEngine::goX(int idIa, glm::vec3 &posIa)
{
  if (_players[idIa]->getImIn() == false)
  {
    if (_players[idIa]->getDirection() == LEFT)
    {
      _players[idIa]->goLeft(-1);
      posIa = _players[idIa]->getPosition();
      if (posIa.x <= _players[idIa]->getLeft())
      {
        _players[idIa]->setImIn(true);
        _players[idIa]->setDirection(0);
        _players[idIa]->setRun(0); 
        _players[idIa]->gereAnim(-1);
        _players[idIa]->setPosition(posIa.y, _players[idIa]->getLeft());
      }
    }
    else if (_players[idIa]->getDirection() == RIGHT)
    {
      _players[idIa]->goRight(-1);
      posIa = _players[idIa]->getPosition();
      if (posIa.x >= _players[idIa]->getRight())
      {
        _players[idIa]->setImIn(true);
        _players[idIa]->setDirection(0);
        _players[idIa]->setRun(0);
        _players[idIa]->gereAnim(-1);
        _players[idIa]->setPosition(posIa.y, _players[idIa]->getRight());
      }
    }
  }
}

void        GameEngine::YcloseToEnemy(int idIa, const glm::vec3 &posEnemy)
{
  glm::vec3 posIa = _players[idIa]->getPosition();

  calcY(idIa, posEnemy, posIa);
  goY(idIa, posIa);
}

void        GameEngine::XcloseToEnemy(int idIa, const glm::vec3 &posEnemy)
{
  glm::vec3 posIa = _players[idIa]->getPosition();

  calcX(idIa, posEnemy, posIa);
  goX(idIa, posIa);
}

bool        GameEngine::checkBox(int y, int x)
{
  if (_map->getMap()[y + 1][x].first == AObject::BOX ||
    _map->getMap()[y - 1][x].first == AObject::BOX ||
    _map->getMap()[y][x + 1].first == AObject::BOX||
    _map->getMap()[y][x - 1].first == AObject::BOX)
      return true;
    return false;
}

bool   GameEngine::checkEnemyInTop(int idIa)
{
  glm::vec3 posIa = _players[idIa]->getPosition();
  int       range = _players[idIa]->getRange();
  AObject::Type  next = _map->getMap()[round(posIa.y) + 1][round(posIa.x)].first;
  int       i = 0;

   while (i < range && next != AObject::WALL)
   {
    for (unsigned int a = 0; a < _players.size(); a++)
    {
      glm::vec3 posEnemy = _players[a]->getPosition();

      if (_players[a]->getDead() == false && static_cast<int>(a) != idIa &&
        round(posIa.y) + i == round(posEnemy.y) && round(posIa.x) == round(posEnemy.x))
      {
        putBomb(idIa);
        return true;
      }
    }
    next = _map->getMap()[round(posIa.y) + i][round(posIa.x)].first;
    ++i;
   }
return false;
}

bool   GameEngine::checkEnemyInBot(int idIa)
{
  glm::vec3 posIa = _players[idIa]->getPosition();
  int       range = _players[idIa]->getRange();

  AObject::Type next = _map->getMap()[round(posIa.y) - 1][round(posIa.x)].first;
   int i = 0;
   while (i < range && next != AObject::WALL)
   {
      for (unsigned int a = 0; a < _players.size(); a++)
      {
        glm::vec3 posEnemy = _players[a]->getPosition();

        if (_players[a]->getDead() == false && static_cast<int>(a) != idIa &&
          round(posIa.y) - i == round(posEnemy.y) && round(posIa.x) == round(posEnemy.x))
        {
          putBomb(idIa);
          return true;
        }
      }
      next = _map->getMap()[round(posIa.y) - i][round(posIa.x)].first;
      ++i;
   }
   return false;
}

bool   GameEngine::checkEnemyInLeft(int idIa)
{
  glm::vec3       posIa = _players[idIa]->getPosition();
  int             range = _players[idIa]->getRange();
  AObject::Type   next = _map->getMap()[round(posIa.y)][round(posIa.x) - 1].first;
  int             i = 0;

   while (i < range && next != AObject::WALL)
   {
    for (unsigned int a = 0; a < _players.size(); a++)
    {
      glm::vec3 posEnemy = _players[a]->getPosition();

      if (_players[a]->getDead() == false && static_cast<int>(a) != idIa &&
        round(posIa.y) == round(posEnemy.y) && round(posIa.x) == round(posEnemy.x) - 1)
      {
        putBomb(idIa);
        return true;
      }
    }
    next = _map->getMap()[round(posIa.y)][round(posIa.x) - i].first;
    ++i;
  }
  return false;
}

bool   GameEngine::checkEnemyInRight(int idIa)
{
  glm::vec3       posIa = _players[idIa]->getPosition();
  int             range = _players[idIa]->getRange();
  AObject::Type   next = _map->getMap()[round(posIa.y)][round(posIa.x) + 1].first;
  int             i = 0;

   while (i < range && next != AObject::WALL)
   {
    for (unsigned int a = 0; a < _players.size(); a++)
    {
      glm::vec3 posEnemy = _players[a]->getPosition();
      if (_players[a]->getDead() == false && static_cast<int>(a) != idIa &&
        round(posIa.y) == round(posEnemy.y) && round(posIa.x) == round(posEnemy.x) + 1)
      {
        putBomb(idIa);
        return true;
      }
    }
    next = _map->getMap()[round(posIa.y)][round(posIa.x) + i].first;
    ++i;
  }
  return false;
}

void        GameEngine::checkEnemyInRange(int idIa)
{
  if (checkEnemyInTop(idIa) || checkEnemyInBot(idIa) ||
    checkEnemyInLeft(idIa) || checkEnemyInRight(idIa))
    return ;
}

void        GameEngine::checkIaPutBombs(int idIa)
{
  glm::vec3 posIa = _players[idIa]->getPosition();

  if (_players[idIa]->getInFlee() == false && checkBox(round(posIa.y), round(posIa.x)) == true)
    putBomb(idIa);
  else if (_players[idIa]->getInFlee() == false)
    checkEnemyInRange(idIa);
}

bool        GameEngine::checkCase(int y, int x)
{
  glm::vec3 posBomb;
  int       idBomber;
  for (unsigned int i = 0; i < _bombs.size(); ++i)
  {
    idBomber = _bombs[i]->getId();
    posBomb = _bombs[i]->getPosition();
     for (int a = 0; a <= _players[idBomber]->getRange(); a++)
      {
        if ((y == round(posBomb.y) + a && x == round(posBomb.x)) ||
            (y == round(posBomb.y) - a && x == round(posBomb.x)) ||
            (y == round(posBomb.y) && x == round(posBomb.x) + a) ||
            (y == round(posBomb.y) && x == round(posBomb.x) - a))
          return false;
      }
  }
  return true;
}

bool        GameEngine::goToFlee(int idIa, int y, int x)
{
  glm::vec3 toGo;
 
  if (y < 0)
    y = 0;
  if (x < 0)
    x = 0;
  if (y > _mapY - 1)
    y = _mapY - 1;
  if (x > _mapX - 1)
    x = _mapX - 1;
  if ((_map->getMap()[y][x].first == AObject::FLOOR || checkAsset(y, x)) && checkCase(y , x))
  {
       toGo.y = y;
       toGo.x = x;
       _players[idIa]->setToGo(toGo);
       _players[idIa]->setInFlee(true);
      YcloseToEnemy(idIa, toGo);
      XcloseToEnemy(idIa, toGo);
      return true;
  }
  return false;
}

void        GameEngine::flee(int idIa)
{
  glm::vec3 posIa = _players[idIa]->getPosition();
  int       radar = 1;

  while (radar < 12)
  {
    if (goToFlee(idIa, round(posIa.y) + radar, round(posIa.x)) ||
      goToFlee(idIa, round(posIa.y) + radar, round(posIa.x) - radar) ||
      goToFlee(idIa, round(posIa.y) + radar, round(posIa.x) + radar) ||
      goToFlee(idIa, round(posIa.y), round(posIa.x) - radar))
      return ;
    if (goToFlee(idIa, round(posIa.y), round(posIa.x) + radar) ||
      goToFlee(idIa, round(posIa.y) - radar, round(posIa.x) - radar) ||
      goToFlee(idIa, round(posIa.y) - radar, round(posIa.x)) ||
      goToFlee(idIa, round(posIa.y) - radar, round(posIa.x) + radar))
      return ;
    radar++;
  }
}

bool        GameEngine::checkFlee(int idIa, const glm::vec3 &posIa, int y, int x)
{
  if (round(posIa.y) == y && round(posIa.x) == x)
  {
    flee(idIa);
    return true;
  }
  return false;
}

bool        GameEngine::checkIaInBombRange(int idIa)
{
  glm::vec3 posIa = _players[idIa]->getPosition();
  glm::vec3 posBomb;
  int       idBomber;

  for (unsigned int i = 0; i < _bombs.size(); ++i)
  {
    idBomber = _bombs[i]->getId();
    posBomb = _bombs[i]->getPosition();
    _players[idIa]->setIdEnemy(idBomber);
    for (int a = 0; a < _players[idBomber]->getRange(); a++)
    {
      if (checkFlee(idIa, posIa, round(posBomb.y) + a, round(posBomb.x)) ||
        checkFlee(idIa, posIa, round(posBomb.y) - a, round(posBomb.x)) ||
        checkFlee(idIa, posIa, round(posBomb.y), round(posBomb.x) + a) ||
        checkFlee(idIa, posIa, round(posBomb.y), round(posBomb.x) - a))
        return true;
    }
  }
 return false;
}

void        GameEngine::iaEngine(int idIa)
{
  _players[idIa]->update(_clock, _input, _map);
  glm::vec3 posIa = _players[idIa]->getPosition();
  int       nearEnemyId = 0;
  nearEnemyId = checkNearestEnemy(idIa, posIa);
  checkIaPutBombs(idIa);

  if (_players[idIa]->getTacticIa() == 1)
  {
    if (_players[0]->getDead() == false)
    {
      YcloseToEnemy(idIa, _players[0]->getPosition());
      XcloseToEnemy(idIa, _players[0]->getPosition());
    }
    else if (_players[1]->getDead() == false)
    {
      YcloseToEnemy(idIa, _players[1]->getPosition());
      XcloseToEnemy(idIa, _players[1]->getPosition());
    }
  }
  else if (checkIaInBombRange(idIa) == false)
  {
    unsigned int idEnemy = _players[idIa]->getIdEnemy();
    if (_bombs.size() == 0 || (_bombs.size() > 0 && idEnemy < _bombs.size() && _bombs[idEnemy]->getExplosed() == true))
    {
      _players[idIa]->setInFlee(false);
      YcloseToEnemy(idIa, _players[nearEnemyId]->getPosition());
      XcloseToEnemy(idIa, _players[nearEnemyId]->getPosition());
    }
    else
    {
      glm::vec3 toGo = _players[idIa]->getToGo();
      _players[idIa]->setRun(0);
      _players[idIa]->setInFlee(true);
      YcloseToEnemy(idIa, toGo);
      XcloseToEnemy(idIa, toGo);
    }
  }
}

std::string             GameEngine::getFname() const
{
  return _fname;
}

void                    GameEngine::saveMap(MAP map)
{
  std::ofstream myfile;
  int   flag = 0;

  _fname = "Save/Save.save";
  myfile.open(getFname().c_str(), std::fstream::binary | std::fstream::trunc | std::fstream::in);
  if (myfile.is_open())
  {
    for (unsigned int y = 0; y < map.size(); ++y)
    {
      for (unsigned int x = 0; x < map[y].size(); ++x)
      {
        for (unsigned int i = 0; i < _players.size(); ++i)
        {
          glm::vec3 pos = _players[i]->getPosition();

          if (static_cast<unsigned int>(round(pos.y)) == y && static_cast<unsigned int>(round(pos.x)) == x
            && _players[i]->getDead() == false)
          {
            myfile << _players[i]->getType();
            flag = 1;
            break ;
          }
        }
        if (map[y][x].first != AObject::PLAYER1 && map[y][x].first != AObject::PLAYER2 &&
          map[y][x].first != AObject::IA && map[y][x].first != AObject::FLOOR &&
          map[y][x].first != AObject::BOX && map[y][x].first != AObject::WALL )
        {
          map[y][x].first = AObject::FLOOR;
          map[y][x].second = AObject::FLOOR;
        }
        if (flag == 0)
          myfile << map[y][x].first;
        flag = 0;
      }
      if (y != map.size() - 1)
        myfile << std::endl;
    }
    myfile.close();
  }
  else
  {
    myfile.close();
    throw MyError("Failed to load _shaders");
  }
}

void    GameEngine::ladder()
{
  std::ofstream ofs;
  int p1 = _players[0]->getScore();
  int p2 = _players[1]->getScore();

  ofs.open("./Ladder/ladder.txt", std::fstream::binary | std::fstream::trunc | std::fstream::in);
  if (ofs.is_open())
  {
    ofs << p1 << std::endl;
    ofs << p2 << std::endl;
  }
  ofs.close();
}