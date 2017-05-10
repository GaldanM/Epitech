#include "Img.hh"

Img::Img(const std::vector<std::vector<int > > &coord, const std::string &filename, int page)
{
  this->screen_size = 1;
  this->nb_player = 1;
  this->nb_bot = 1;
  this->map = 1;

  this->width = 10;
  this->height = 10;

  this->name = filename;
  this->coo = coord;
  this->page = page;
  this->curr_page = 1;
  this->save_page.push_back(this->curr_page);

  this->create[1] = &Img::page1;
  this->create[2] = &Img::page2;
  this->create[4] = &Img::page4;
  this->create[5] = &Img::page5;
  this->create[7] = &Img::page7;
  this->create[6] = &Img::page6;

  this->create_bot[1] = &Img::bot1;
  this->create_bot[2] = &Img::bot2;
  this->create_bot[3] = &Img::bot3;
  this->create_bot[4] = &Img::bot4;

  this->create_size[1] = &Img::size1;
  this->create_size[2] = &Img::size2;
  this->create_size[3] = &Img::size3;
  this->create_size[4] = &Img::size4;
}

Img::~Img()
{

}

void Img::mySleep()
{
  float timer = 0.0f;

  while (timer <= 0.1f)
  {
    _context.updateClock(_clock);
    timer +=  static_cast<float>(this->_clock.getElapsed());
  }
}

bool Img::initialize()
{
	if (this->texture.load(this->name) == false)
       throw MyError("Failed to init");
    glDisable(GL_DEPTH_TEST);
    glEnable(GL_BLEND);
    glEnable(GL_ALPHA_TEST);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE);

    if (this->page > 0 && this->coo[3][2] == 0)
        this->geometry.setColor(glm::vec4(1, 0, 0, 1));
    else if (this->page == 0)
        this->geometry.setColor(glm::vec4(1, 1, 1, 0.2));
    else
        this->geometry.setColor(glm::vec4(1, 1, 1, 1));
    this->geometry.pushVertex(glm::vec3(this->coo[0][0], this->coo[0][1], this->coo[3][2]));
    this->geometry.pushVertex(glm::vec3(this->coo[1][0], this->coo[1][1], this->coo[3][2]));
    this->geometry.pushVertex(glm::vec3(this->coo[2][0], this->coo[2][1], this->coo[3][2]));
    this->geometry.pushVertex(glm::vec3(this->coo[3][0], this->coo[3][1], this->coo[3][2]));

    this->geometry.pushUv(glm::vec2(0.0f, 0.0f));
    this->geometry.pushUv(glm::vec2(1.0f, 0.0f));
    this->geometry.pushUv(glm::vec2(1.0f, 1.0f));
    this->geometry.pushUv(glm::vec2(0.0f, 1.0f));
    this->geometry.build();
    return (true);
}

void Img::refresh(gdl::Input &input)
{
  std::map<int, Img::ptr>::iterator it;
  SDL_GetMouseState(&(this->x), &(this->y));

  if (input.getKey(SDLK_BACKSPACE) && this->curr_page > 1)
  {
    this->mySleep();
    if (this->save_page.size() > 1)
      this->save_page.pop_back();
    this->curr_page = this->save_page[this->save_page.size() - 1];
  }
  for (it = this->create.begin(); it != this->create.end(); it++)
  {
    if (it->first == this->curr_page)
    {
      (this->*(it->second))(input);
      return;
    }
  }
}


void Img::check_save()
{
  std::ifstream file("./Save/Save.save", std::ios::in); 

  if(file)
  {
    this->save = 0; 
    file.close();
  }
  else 
    this->save = -1;
}

void Img::page1(gdl::Input &input)
{
  this->limit = get_limit1();
  if (input.getInput(SDL_BUTTON_LEFT))
  {
    this->mySleep();
    for (unsigned int i = 0; i < this->limit.size(); i++)
    {
      if ((this->x > this->limit[i][0] && this->x < this->limit[i][1]) && (this->y > this->limit[i][2] && this->y < this->limit[i][3]))
      {
        this->curr_page = this->opt[i];
        this->save_page.push_back(this->curr_page);
      }
    }
  }
}

void Img::page2(gdl::Input &input)
{
  this->check_save();
  if (this->save != -1)
  {
    if (input.getInput(SDL_BUTTON_LEFT))
    {
      this->mySleep();
      if ((this->x > 111 && this->x < 507) && (this->y > 316 && this->y < 379))
        this->curr_page = 9;
    }
  }
}

void Img::page4(gdl::Input &input)
{
  this->limit = get_limit4();
  if (input.getInput(SDL_BUTTON_LEFT))
  {
    this->mySleep();
    for (unsigned int i = 0; i < this->limit.size(); i++)
    {
      if ((this->x > this->limit[i][0] && this->x < this->limit[i][1]) && (this->y > this->limit[i][2] && this->y < this->limit[i][3]))
        this->screen_size = i + 1;
    }
  }
}

void Img::page5(gdl::Input &input)
{
  this->limit = get_limit5();
  for (unsigned int i = 0; i < this->limit.size(); i++)
  {
    if ((this->x > this->limit[i][0] && this->x < this->limit[i][1]) && (this->y > this->limit[i][2] && this->y < this->limit[i][3]))
      this->map = i + 1;
  }
  if (input.getInput(SDL_BUTTON_LEFT))
  {
    this->mySleep();
    for (unsigned int i = 0; i < this->limit.size(); i++)
    {
      if ((this->x > this->limit[i][0] && this->x < this->limit[i][1]) && (this->y > this->limit[i][2] && this->y < this->limit[i][3]))
      {
        this->map = i + 1;
        this->curr_page = this->opt5[i];
        this->save_page.push_back(this->curr_page);
      }
    }
  }
}

void Img::bot4()
{
  if (this->nb_bot > 0)
    this->nb_bot--;
}

void Img::bot3()
{
  if (this->nb_bot < ((this->width+this->height)/2) - 2)
    this->nb_bot++;
}

void Img::bot2()
{
  this->nb_player = 2;
}

void Img::bot1()
{
  this->nb_player = 1;
}

void Img::size1()
{
  this->width++;
}

void Img::size2()
{
  if (this->width > 10)
    this->width--;
}

void Img::size3()
{
  this->height++;
}

void Img::size4()
{
  if (this->height > 10)
    this->height--;
}

void Img::page6(gdl::Input &input)
{
  std::map<int, Img::tab>::iterator it;
  this->limit = get_limit6();
  if (input.getInput(SDL_BUTTON_LEFT))
  {
    for (unsigned int i = 0; i < this->limit.size(); i++)
    {
      if ((this->x > this->limit[i][0] && this->x < this->limit[i][1]) && (this->y > this->limit[i][2] && this->y < this->limit[i][3]))
      {
        for (it = this->create_size.begin(); it != this->create_size.end(); it++)
        {
          if (it->first == static_cast<int>(i + 1))
          {
            (this->*(it->second))();
            return;
          }
        }
      }
    }
  }
  if (input.getKey(SDLK_RETURN))
  {
    this->mySleep();
    this->curr_page = 7; 
    this->save_page.push_back(this->curr_page);
  }
}

void Img::page7(gdl::Input &input)
{
  std::map<int, Img::fct>::iterator it;

  this->limit = get_limit7();
  if (input.getInput(SDL_BUTTON_LEFT))
  {
    this->mySleep();
    for (unsigned int i = 0; i < this->limit.size(); i++)
    {
      if ((this->x > this->limit[i][0] && this->x < this->limit[i][1]) && (this->y > this->limit[i][2] && this->y < this->limit[i][3]))
      {
        for (it = this->create_bot.begin(); it != this->create_bot.end(); it++)
        {
          if (it->first == static_cast<int>(i + 1))
          {
            (this->*(it->second))();
            return;
          }
        }
      }
    }
  }
  if (input.getKey(SDLK_RETURN))
    this->curr_page = 8;
}

std::vector<std::vector<int> >Img::get_limit6()
{
  std::vector<std::vector<int> > lim;
  std::vector<int> x;

  for (unsigned int i = 0; i < 4; i++)
    lim.push_back(x);

  lim[0].push_back(580);
  lim[0].push_back(645);
  lim[0].push_back(318);
  lim[0].push_back(385);

  lim[1].push_back(910);
  lim[1].push_back(980);
  lim[1].push_back(318);
  lim[1].push_back(385);

  lim[2].push_back(580);
  lim[2].push_back(645);
  lim[2].push_back(607);
  lim[2].push_back(652);

  lim[3].push_back(910);
  lim[3].push_back(980);
  lim[3].push_back(607);
  lim[3].push_back(652);

  return (lim);
}

std::vector<std::vector<int> >Img::get_limit7()
{
  std::vector<std::vector<int> > lim;
  std::vector<int> x;

  for (unsigned int i = 0; i < 4; i++)
    lim.push_back(x);
  lim[0].push_back(111);
  lim[0].push_back(513);
  lim[0].push_back(316);
  lim[0].push_back(385);

  lim[1].push_back(111);
  lim[1].push_back(513);
  lim[1].push_back(452);
  lim[1].push_back(516);

  lim[2].push_back(710);
  lim[2].push_back(910);
  lim[2].push_back(285);
  lim[2].push_back(385);

  lim[3].push_back(710);
  lim[3].push_back(910);
  lim[3].push_back(548);
  lim[3].push_back(651);

  return (lim);
}

std::vector<std::vector<int> > Img::get_limit5()
{
  std::vector<std::vector<int> > lim;
  std::vector<int> x;

  for (unsigned int i = 0; i < 4; i++)
    lim.push_back(x);
  lim[0].push_back(111);
  lim[0].push_back(513);
  lim[0].push_back(318);
  lim[0].push_back(385);

  lim[1].push_back(111);
  lim[1].push_back(513);
  lim[1].push_back(418);
  lim[1].push_back(485);

  lim[2].push_back(111);
  lim[2].push_back(513);
  lim[2].push_back(518);
  lim[2].push_back(585);

  lim[3].push_back(111);
  lim[3].push_back(513);
  lim[3].push_back(618);
  lim[3].push_back(685);

  this->opt5.clear();
  this->opt5.push_back(8);
  this->opt5.push_back(8);
  this->opt5.push_back(8);
  this->opt5.push_back(6);

  return (lim);
}

std::vector<std::vector<int> > Img::get_limit4()
{
  std::vector<std::vector<int> > lim;
  std::vector<int> x;

  for (unsigned int i = 0; i < 3; i++)
    lim.push_back(x);
  lim[0].push_back(111);
  lim[0].push_back(507);
  lim[0].push_back(316);
  lim[0].push_back(379);

  lim[1].push_back(111);
  lim[1].push_back(507);
  lim[1].push_back(452);
  lim[1].push_back(516);

  lim[2].push_back(111);
  lim[2].push_back(507);
  lim[2].push_back(585);
  lim[2].push_back(650);

  return (lim);
}

std::vector<std::vector<int> > Img::get_limit1()
{
  std::vector<std::vector<int> > lim;
  std::vector<int> x;

  for (unsigned int i = 0; i < 5; i++)
    lim.push_back(x);
  lim[0].push_back(111);
  lim[0].push_back(507);
  lim[0].push_back(316);
  lim[0].push_back(379);

  lim[1].push_back(111);
  lim[1].push_back(507);
  lim[1].push_back(452);
  lim[1].push_back(516);

  lim[2].push_back(111);
  lim[2].push_back(507);
  lim[2].push_back(585);
  lim[2].push_back(650);

  lim[3].push_back(614);
  lim[3].push_back(1011);
  lim[3].push_back(316);
  lim[3].push_back(379);   

  lim[4].push_back(614);
  lim[4].push_back(1011);
  lim[4].push_back(452);
  lim[4].push_back(516);

  this->opt.clear();
  this->opt.push_back(5);
  this->opt.push_back(2);
  this->opt.push_back(0);
  this->opt.push_back(3);
  this->opt.push_back(4);

  return (lim);
}

void Img::update(gdl::Clock const &clock, gdl::Input &input)
{
  this->_clock = clock;
  this->refresh(input);
}

void Img::draw(gdl::AShader &shader, gdl::Clock const &clock)
{
  (void)clock;
  this->texture.bind();
  this->geometry.draw(shader, getTransformation(), GL_QUADS);
}

int Img::getPage() const
{
  return (this->page);
}

int Img::getCurrentPage() const
{
  return (this->curr_page);
}

int Img::getNbBot() const
{
  return (this->nb_bot);
}

int Img::getSave() const
{
  return (this->save);
}

int Img::getScreenSize() const
{
  return (this->screen_size);
}

int Img::getMap() const
{
  return (this->map);
}

int Img::getNbPlayer() const
{
  return (this->nb_player);
}

int Img::getWidth() const
{
  return (this->width);
}

int Img::getHeight() const
{
  return (this->height);
}