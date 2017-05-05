//
// Lib_NCURSES.cpp for Ncursecpp in /home/ounajj_k/rendu/cpp_nibbler
// 
// Made by Khaled Ounajjar
// Login   <ounajj_k@epitech.net>
// 
// Started on  Sun Apr  5 20:43:23 2015 Khaled Ounajjar
// Last update Sun Apr  5 22:35:01 2015 Khaled Ounajjar
//

#include <iostream>
#include <fstream>
#include <unistd.h>
#include "Lib_NCURSES.h"

MyNC::MyNC(const Game &g) : _x(g.getWidth()), _y(g.getHeight())
{	
  initscr();
  noecho();
  keypad(stdscr, TRUE);
  curs_set(FALSE);
  nodelay(stdscr, TRUE);
  MyBack();
}

MyNC::~MyNC()
{
}

extern "C"
{
  ILibsDisplay    *create_lib(const Game &g)
  {
    return new MyNC(g);
  }
}

void 	MyNC::DispMap(Game & g) const
{
  int y = 1;
  int x = 1;
  std::vector<std::vector<int> > map = g.getMap();

  for (std::vector<std::vector<int> >::iterator it = map.begin(); it != map.end(); ++it)
    {
      x = 1;
      for (std::vector<int>::iterator jt = (*it).begin(); jt != (*it).end(); ++jt)
	{
	  if (*jt == Game::SNAKE)
	    mvprintw(y, x, "=");
	  else if (*jt == Game::S_FOOD)
	    mvprintw(y, x, "@");
	  else if (*jt == Game::FOOD)
	    mvprintw(y, x, "o");
	  x++;
	}
      y++;
    }
}

void	MyNC::MyBack()
{
  int 			x;
  int 			y;

  x = 0;
  y = 0;
  _UDbar.push_back('+');
  while (x < _x)
    {
      _UDbar.push_back('-');
      x++;
    }
  _UDbar.push_back('+');
  _Mbar.push_back('|');
  while (y < _x)
    {
      _Mbar.push_back(' ');
      y++;
    }
  _Mbar.push_back('|');
}

void	MyNC::DrawBack() const
{
  int 	y;

  y = 0;
  mvprintw(y++, 0, _UDbar.c_str());
  while (y <= _y)
    mvprintw(y++, 0, _Mbar.c_str());
  mvprintw(y, 0, _UDbar.c_str());
}


int 	MyNC::KeyEvent()
{
  int ch;

  _dir = AHEAD;
  if ((ch = getch()) == KEY_LEFT)
    _dir = LEFT;
  else if (ch == KEY_RIGHT)
    _dir = RIGHT;
  else if (ch == 27)
    { 
      endwin();
      return (-1);
    }
  return (0);
}


void 	MyNC::startGame(Game & g)
{
  while (1) 
    {
      if (KeyEvent() == -1)
	return ;
      refresh();
      DrawBack();
      DispMap(g);
      usleep(75000);
      try
     	{
	  g.updateMap(_dir);
     	}
      catch (const std::exception &e)
     	{
	  endwin();
	  std::cout << e.what() << std::endl;
	  std::cout << "Score: " << g.getScore() << std::endl;
	  return ;
     	}
    }
  endwin();
}
