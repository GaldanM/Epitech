#include <unistd.h>
#include <stdio.h>

#include "Lib_XLIB.h"

extern "C"
{
  ILibsDisplay	*create_lib(const Game &g)
  {
    return new MyXlib(g);
  }
}

MyXlib::MyXlib(const Game& g) : _g(g)
{
  unsigned long black, white;
  int   width = g.getWidth() * SQUARE_SIZE;
  int   height = g.getHeight() * SQUARE_SIZE;

  if ((_disp = XOpenDisplay(NULL)) == NULL)
      throw MyError("Xlib: Cannot open the window");
  _screen = XDefaultScreen(_disp);
  _root = XRootWindow(_disp, _screen);
  black = XBlackPixel(_disp, _screen);
  white = XWhitePixel(_disp, _screen);
  _win = XCreateSimpleWindow(_disp, RootWindow(_disp ,_screen), 0, 0, width, height, 5, black, white);
  _gc = DefaultGC(_disp, _screen);
  XSelectInput(_disp, _win, KeyPressMask | ExposureMask);
   Atom WM_DELETE_WINDOW = XInternAtom(_disp, "WM_DELETE_WINDOW", False); 
  XSetWMProtocols(_disp, _win, &WM_DELETE_WINDOW, 1);
  XMapWindow(_disp, _win);
}

MyXlib::~MyXlib()
{

}

void      MyXlib::setColor(int r, int g, int b)
{
  Colormap colorMap = DefaultColormap(_disp ,_screen);
  XColor xcolour;
 
   xcolour.red = r;
   xcolour.green = g;
   xcolour.blue = b;
   xcolour.flags = DoRed | DoGreen | DoBlue;
   XAllocColor(_disp ,colorMap ,&xcolour);
   XSetForeground(_disp ,_gc ,xcolour.pixel);
}

void			MyXlib::displayMap()
{
  int                 x = 0;
  int                 y = 0;
 
  std::vector<std::vector<int> >  map = _g.getMap();

  for (std::vector<std::vector<int> >::iterator it = map.begin(); it != map.end(); ++it)
    {
      x = 0;
      for (std::vector<int>::iterator jt = (*it).begin(); jt != (*it).end(); ++jt)
       {
        
        if (*jt == Game::SNAKE)
            {
              setColor(25500, 0, 0);
              XFillRectangle(_disp ,_win, _gc ,x ,y ,SQUARE_SIZE ,SQUARE_SIZE);
            }
        else if (*jt == Game::FOOD)
            {
              setColor(20400, 85000, 0);
              XFillRectangle(_disp ,_win, _gc ,x ,y ,SQUARE_SIZE ,SQUARE_SIZE);
            }
        else if (*jt == Game::S_FOOD)
            {
              setColor(25500, 0, 0);
              XFillRectangle(_disp ,_win, _gc ,x ,y ,SQUARE_SIZE ,SQUARE_SIZE);
            }
        x += SQUARE_SIZE;
       }
      y += SQUARE_SIZE;
    }
    XFlush(_disp);
}

void			MyXlib::startGame(Game &g)
{
  XEvent  ev;
  int     dir;
  
  
 static_cast<void>(g);
  XAutoRepeatOff(_disp);
  while (1)
    {
      XClearWindow(_disp ,_win);
      dir = AHEAD;
     if (XPending(_disp) > 0)
        {
            XNextEvent(_disp, &ev);
            if (ev.type == KeyPress)
              {
                if (ev.xkey.keycode == L)
                  dir = LEFT;
                else if (ev.xkey.keycode == R)
                  dir = RIGHT;
                else if (ev.xkey.keycode == ESC)  
                {
                  XAutoRepeatOn(_disp);
                  XPending(_disp);
                  throw MyError("Game Over !");
                 }
              }
              else if (ev.type == ClientMessage)
                  throw MyError("Game Over !");
         }
      displayMap();
       try
      {
        _g.updateMap(dir);
      }
      catch (const std::exception &e)
      {
        XAutoRepeatOn(_disp);
        XPending(_disp);
        std::cout << e.what() << std::endl;
         return ;
      }
      usleep(99999);
    }
}
