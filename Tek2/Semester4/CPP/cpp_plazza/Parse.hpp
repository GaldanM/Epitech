//
// Parse.hpp for e in /home/zaband_b/test/plazza
// 
// Made by Bryan Zabandith
// Login   <zaband_b@epitech.net>
// 
// Started on  Thu Apr 16 02:20:39 2015 Bryan Zabandith
// Last update Tue Apr 21 00:17:53 2015 Bryan Zabandith
//

#ifndef _PARSE_HPP_
#define _PARSE_HPP_

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <ctype.h>
#include <algorithm>
#include <map>
#include "Factory.hpp"

class Parse
{
private:
  std::string	line;
  std::string pizza_t;
  std::string pizza_s;
  std::string pizza_nb;
  std::vector<std::string> type;
  std::vector<std::string> size;
  std::vector<std::string> cmd;
  std::vector<Pizza *> pizza;
  Factory	*factory;
public:
  Parse();
  ~Parse();
  Parse(const Parse &);
  Parse &operator=(const Parse &);

  void	setLine(const std::string &);
  void	init_type();
  void	init_size();
  void	split_string();
  void	fill_pizza();
  void	fill();

  int	nb_word(const std::string &) const;
  int	check_type() const;
  int	check_size() const;
  int	check_nb() const;
  int check_nb(std::string) const;
  int	getnbPizza() const;
  int pizza_max(std::string);
  std::vector<std::string>   split_string(std::string str);

  std::string epur(const std::string &) const;
  std::vector<Pizza *> getPizza(const float &) const;
};

#endif /* !_PARSE_HPP_ */
