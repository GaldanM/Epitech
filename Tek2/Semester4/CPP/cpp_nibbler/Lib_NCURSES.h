/*
** Lib_NCURSES.h for NCURSE H in /home/ounajj_k/rendu/cpp_nibbler
** 
** Made by Khaled Ounajjar
** Login   <ounajj_k@epitech.net>
** 
** Started on  Sun Apr  5 20:46:26 2015 Khaled Ounajjar
** Last update Sun Apr  5 20:51:38 2015 Khaled Ounajjar
*/
#ifndef _LIB_NCURSE_
# define _LIB_NCURSE_

# include <string>
# include <ncurses/curses.h>
# include "ILibsDisplay.h"
# include "Game.h"

class MyNC : public ILibsDisplay
{


  int 			_x;
  int 			_y;
  std::string		_UDbar;
  WINDOW 		*_win;
  std::string		_Mbar;
  int 			_dir;

 public:
  MyNC(const Game &);
  ~MyNC();

 public:
  virtual void 	startGame(Game& game);
  void	DrawBack() const;
  void 	DispMap(Game & game) const;
  void 	MyBack();
  int 	KeyEvent();
};

#endif /* !_LIB_NCURSE_ */
