//
// Factory.hpp for Factoryu in /home/zaband_b/test/plazza
// 
// Made by Bryan Zabandith
// Login   <zaband_b@epitech.net>
// 
// Started on  Mon Apr 20 18:21:13 2015 Bryan Zabandith
// Last update Fri Apr 24 00:28:15 2015 Bryan Zabandith
//

#ifndef _FACTORY_HPP_
#define _FACTORY_HPP_

#include <iostream>
#include <string>
#include <map>
#include "Margarita.hpp"
#include "Regina.hpp"
#include "Americaine.hpp"
#include "Fantasia.hpp"

class Factory
{
private:
  std::map<std::string, TaillePizza> size_pizza;
  typedef Pizza *(Factory::*ptr)(const TaillePizza &);
  std::map<std::string , Factory::ptr> create;
public:
  Factory();
  ~Factory();
  Factory(const Factory &);
  Factory &operator=(const Factory &);

  std::string Pack(Pizza *) const;
  Pizza *UnPack(std::string);

  Pizza *fill(const std::string &, const std::string &);
  Pizza *create_margarita(const TaillePizza &);
  Pizza *create_regina(const TaillePizza &);
  Pizza *create_americaine(const TaillePizza &);
  Pizza *create_fantasia(const TaillePizza &);
};

#endif /* ! _FACTORY_HPP_ */
