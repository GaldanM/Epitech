//
// Americaine.cpp for e in /home/zaband_b/test/plazza
// 
// Made by Bryan Zabandith
// Login   <zaband_b@epitech.net>
// 
// Started on  Sat Apr 18 15:39:23 2015 Bryan Zabandith
// Last update Sat Apr 25 22:35:26 2015 Bryan Zabandith
//

#include "Americaine.hpp"

Americaine::Americaine(TaillePizza size)
{
  this->time = 2000000;
  this->size = size;
  this->type = AMERICAINE;
  this->list.push_back(DOE);
  this->list.push_back(GRUYERE);
  this->list.push_back(STEAK);
  this->list.push_back(TOMATO);
}

Americaine::~Americaine()
{
}
