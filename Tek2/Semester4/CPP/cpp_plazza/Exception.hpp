//
// Exception.hpp for except in /home/zaband_b/test/plazza
// 
// Made by Bryan Zabandith
// Login   <zaband_b@epitech.net>
// 
// Started on  Thu Apr 16 00:09:38 2015 Bryan Zabandith
// Last update Mon Apr 20 13:02:55 2015 Bryan Zabandith
//

#ifndef _EXCEPTION_HPP_
# define _EXCEPTION_HPP_

#include <iostream>
#include <exception>

class	Exception : public std::exception
{

private:
  std::string	err;
public:
  Exception(std::string const &error) throw() : err(error) {}
  virtual       ~Exception()  throw() {}
  virtual const char *what() const throw() { return err.c_str(); }
};

#endif /* !EXCEPTION */
