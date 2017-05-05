//
// Pizza.hpp for Pizza in /home/zaband_b/test/plazza
// 
// Made by Bryan Zabandith
// Login   <zaband_b@epitech.net>
// 
// Started on  Sat Apr 18 15:00:51 2015 Bryan Zabandith
// Last update Sat Apr 25 22:35:01 2015 Bryan Zabandith
//

#ifndef _PIZZA_HPP_
#define _PIZZA_HPP_

#include <iostream>
#include <string>
#include <vector>
#include <map>

enum TypePizza
  {
    REGINA = 1,
    MARGARITA = 2,
    AMERICAINE = 4,
    FANTASIA = 8
  };

enum TaillePizza
  {
    S = 1,
    M = 2,
    L = 4,
    XL = 8,
    XXL = 16
  };

enum Ingredient
  {
    DOE,
    TOMATO,
    GRUYERE,
    HAM,
    MUSHROOMS,
    STEAK,
    EGGPLANT,
    GOATCHEESE,
    CHIEFLOVE,
  };

class Pizza
{
protected:
  TaillePizza size;
  TypePizza type;
  std::vector<Ingredient> list;
  std::map<TypePizza, std::string> my_type;
  int time;
  float multiple;
  std::map<TaillePizza, std::string> my_size;
public:
  Pizza();
  Pizza(const Pizza &);
  Pizza &operator=(const Pizza &);
  virtual ~Pizza() {}
  void setMultiple(const float &);
  std::vector<Ingredient> getIngredient() const;
  TypePizza getType() const;
  TaillePizza getSize() const;
  std::string getStrPizza();
  std::string getStrSize();
  int	      getTime () const;
};

#endif /* !_PIZZA_HPP_ */
