//
// Margarita.cpp for e in /home/zaband_b/test/plazza
// 
// Made by Bryan Zabandith
// Login   <zaband_b@epitech.net>
// 
// Started on  Sat Apr 18 15:38:24 2015 Bryan Zabandith
// Last update Sat Apr 25 16:48:04 2015 Bryan Zabandith
//

#include "Margarita.hpp"

Margarita::Margarita(TaillePizza size)
{
  this->time = 1000000;
  this->size = size;
  this->type = MARGARITA;
  this->list.push_back(DOE);
  this->list.push_back(TOMATO);
  this->list.push_back(GRUYERE);
}

Margarita::~Margarita()
{
}
