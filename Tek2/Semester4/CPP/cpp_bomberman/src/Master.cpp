#include "Master.hh"

Master::Master()
{}

Master::~Master()
{}

const std::vector<std::vector<int> > Master::getVect( int x1,  int y1,  int x2,  int y2,  int x3,  int y3,  int x4,  int y4,  int z)
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

int 	Master::run()
{
	Menu	*menu;
	GameEngine *engine;

	std::vector<std::vector<int> > coord;
	int i = 0;
	int x = 0;
	float timer = 0.0f;
	
	if (!_context.start(1024.0f, 768.0f, "GTA VI"))
    return (false);
	if(!_shader.load("./LibGDL/shaders/basic.fp", GL_FRAGMENT_SHADER)
    ||!_shader.load("./LibGDL/shaders/basic.vp", GL_VERTEX_SHADER)
    ||!_shader.build())
    return (false);
  coord = this->getVect(85,-63, -85,-63, -85,63, 85,63, 2);
  IObject *bkgd = new Img(coord,"./texture/intro_r.tga", 3);
  if (bkgd->initialize() == false)
    return (false);
  this->_obj.push_back(bkgd);
  coord = this->getVect(85,-63, -85,-63, -85,63, 85,63, 2);
  IObject *introb = new Img(coord,"./texture/intro_b.tga", 3);
  if (introb->initialize() == false)
    return (false);
  this->_obj.push_back(introb);
  while (timer <= 5.0f)
  {
  	_context.updateClock(_clock);
    _context.updateInputs(_input);
    glClear(GL_COLOR_BUFFER_BIT);
    glm::mat4 projection;
    glm::mat4 transformation;
    projection = glm::perspective(60.0f, 1024.0f  / 768.0f, 0.1f, 1000.0f);
    transformation = glm::lookAt(glm::vec3(0, 0, -100), glm::vec3(0, 0, 0), glm::vec3(0, 1, 0));
    this->_shader.setUniform("view", transformation);
    this->_shader.setUniform("projection", projection);
    if (i == 8)
    {
    	i = 0;
    	x++;
    }
   	timer +=  static_cast<float>(this->_clock.getElapsed());
   	++i;
   	this->_obj[x % 2]->draw(this->_shader, this->_clock);
   	_shader.bind();
    _context.flush();
  }
  _context.stop();
  while (42)
  {
    menu = new Menu();

    if (menu->initialize() == false)
    	return (-1);
    while (menu->update() == true)
      menu->draw();
    if (!menu->checkStart())
   		return (-1);
   	if (menu->getLoad() == 9)
   		engine = new GameEngine(menu->getResolution());
   	else
    	engine = new GameEngine(menu->getNbplayers(), menu->getNbBots(), menu->getMapName(), menu->getMapSize(), menu->getResolution());
   	delete menu;

    if (!engine->initialize())
      return (-1);
    while (engine->update())
      engine->draw();
    engine->affScore();
    delete engine;
  }
  return EXIT_SUCCESS;
}