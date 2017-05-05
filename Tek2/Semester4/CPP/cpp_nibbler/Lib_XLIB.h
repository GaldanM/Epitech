#ifndef _LIBXLIB_H_
# define _LIBXLIB_H_

#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <X11/Xatom.h>
#include <iostream>
#include "ILibsDisplay.h"
#include "Game.h"
#include "MyError.h"

#define	SQUARE_SIZE 25
#define L 113
#define R 114
#define ESC 9

class MyXlib : public ILibsDisplay
{
protected:
	Game 		_g;
	Display   	*_disp;
	Window 		_win, _root;
	GC 			_gc;
	int 		_screen;

 public:
  MyXlib(const Game &);
  ~MyXlib();

 protected:
  virtual void		startGame(Game &);
  void				displayMap();
  void      		setColor(int r, int g, int b);
};

#endif //_LIBXLIB_H_
