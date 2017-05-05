//
// Regina.cpp for regine in /home/zaband_b/test/plazza
// 
// Made by Bryan Zabandith
// Login   <zaband_b@epitech.net>
// 
// Started on  Sat Apr 18 15:20:34 2015 Bryan Zabandith
// Last update Sat Apr 25 16:47:48 2015 Bryan Zabandith
//

#include "Regina.hpp"

Regina::Regina(TaillePizza size)
{
  this->time = 2000000;
  this->size = size;
  this->type = REGINA;
  this->list.push_back(DOE);
  this->list.push_back(TOMATO);
  this->list.push_back(GRUYERE);
  this->list.push_back(HAM);
  this->list.push_back(MUSHROOMS);
}

Regina::~Regina()
{
}