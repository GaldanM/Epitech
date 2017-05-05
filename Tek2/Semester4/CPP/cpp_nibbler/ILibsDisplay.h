//
// Created by Galdan on 23/03/15.
//

#ifndef _ILIBSDISPLAY_H_
# define _ILIBSDISPLAY_H_

# include "Game.h"

class ILibsDisplay
{
 public:
  virtual ~ILibsDisplay() {}

  virtual void        startGame(Game&) = 0;
};

#endif //_ILIBSDISPLAY_H_
