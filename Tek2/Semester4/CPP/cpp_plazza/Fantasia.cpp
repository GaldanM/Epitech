//
// Fantasia.cpp for e in /home/zaband_b/test/plazza
// 
// Made by Bryan Zabandith
// Login   <zaband_b@epitech.net>
// 
// Started on  Sat Apr 18 15:49:45 2015 Bryan Zabandith
// Last update Sat Apr 25 16:47:20 2015 Bryan Zabandith
//

#include "Fantasia.hpp"

Fantasia::Fantasia(TaillePizza size)
{
  this->time = 4000000;
  this->size = size;
  this->type = FANTASIA;
  this->list.push_back(DOE);
  this->list.push_back(TOMATO);
  this->list.push_back(EGGPLANT);
  this->list.push_back(GOATCHEESE);
  this->list.push_back(CHIEFLOVE);
}

Fantasia::~Fantasia()
{
}
