//
// Command.hpp for cmd in /home/zaband_b/test/plazza
// 
// Made by Bryan Zabandith
// Login   <zaband_b@epitech.net>
// 
// Started on  Thu Apr 16 01:55:58 2015 Bryan Zabandith
// Last update Sun Apr 26 19:39:18 2015 Khaled Ounajjar
//

#ifndef _COMMAND_HPP_
#define _COMMAND_HPP_

#include <iostream>
#include <sstream>
#include <string>
#include <cstddef>
#include <vector>
#include "Pizza.hpp"
#include "Kitchen.h"
#include "Factory.hpp"
#include "win.h"

#define PIPE_OPEN         "fifo_read"
#define PIPE_WRITE        "fifo_open"

class Win;

class Command
{
private:
  std::string             cmd;
  float			              mul;
  int			                ms;
  int			                nbcook;
  std::vector<Pizza *>    pizza;
  int			                id;
  std::vector<Kitchen *>  kitchen;
  Factory                 *factor;
  Win                     *_win;

public:
  explicit Command(char **);
  ~Command();
  Command(const Command &);
  Command &operator=(const Command &);

  void                    freeKitchen();
  void                    update(unsigned int );
  void                    send(int);
  void                    start_cook();
  int                     start(const std::string &);
  void                    fill_pizza(const std::vector<Pizza *> &);
  int                     check_arg(char **) const;
  int                     find_pnt(const std::string &) const;
  std::vector<Pizza *>    getPizza() const;
  void                    setPizza(std::vector<Pizza *>);
  void                    setWin(Win *win);
};

#endif /* !_COMMMAND_HPP_ */
