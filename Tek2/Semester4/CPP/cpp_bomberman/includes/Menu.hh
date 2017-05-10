#ifndef MENU_HPP
#define MENU_HPP

#include "Img.hh"

#define WIDTH 1024
#define HEIGHT 768

class Menu
{
protected:
  gdl::SdlContext                       menu;
  gdl::Clock                            clock;
  gdl::BasicShader                      shader;
  gdl::Input                            input;
  std::vector<IObject*>                 obj;
  std::vector<IObject*>                 obj_bot;
  std::vector<IObject*>                 obj_save;
  std::vector<IObject*>                 obj_screen;
  std::vector<IObject*>                 obj_map;
  std::vector<IObject*>                 obj_bomb;

  std::vector<IObject*>                 obj_width;
  std::vector<IObject*>                 obj_height;  

  typedef bool                          (Menu::*ptr)(void);
  std::map<int , Menu::ptr>             create;

  typedef void                          (Menu::*tr)(void);
  std::map<int , Menu::tr>              create_draw;

  typedef bool                          (Menu::*fct)(void);
  std::map<int , Menu::fct>             create_map;

  int                                   exit;
  int	                                  nb_player;
  int	                                  nb_bots;
  int                                   page;

  std::string                           map_name;
  int                                   map;
  int                                   my_save;
  int                                   screen_size;
  int                                   width;
  int                                   height;

public:
  Menu();
  ~Menu();
  bool                                  update();
  bool                                  initialize();
  void                                  draw();
  bool                                  loadTexture();
  bool                                  checkStart();

  bool                                  drawBots(int);
  void                                  deleteImg();

  void                                  deleteSave();
  bool                                  drawSave();

  void                                  deleteScreen();
  bool                                  drawScreen();

  void                                  deleteMap();
  bool                                  drawMap();

  void                                  deleteBomb();
  void                                  drawPlayer();
  bool                                  affPlayers();

  void                                  deleteWidth();
  void                                  drawWidth();

  void                                  deleteHeight();
  void                                  drawHeight();

  bool                                  map1();
  bool                                  map2();
  bool                                  map3();
  bool                                  map4();

  bool                                  page2();
  bool                                  page4();
  bool                                  page5();
  bool                                  page6();
  bool                                  page7();

  void                                  draw2();
  void                                  draw4();
  void                                  draw5();
  void                                  draw6();
  void                                  draw7();

  void                                  setMap();

  int                                   getNbplayers() const;
  int                                   getNbBots() const;
  int                                   getLoad() const;
  std::string                           getMapName() const;
  std::pair<int, int>                   getResolution() const;
  std::pair<int, int>                   getMapSize() const;
  const std::vector<std::vector<int > > getVect(int, int, int, int, int, int, int, int, int);
  int                                   getScreenSize() const;;

  void                                  checkLadder();
  void                                  drawLadder(int, int);
  void                                  drawLadder(int);
};

#endif /* !MENU_HPP_*/
