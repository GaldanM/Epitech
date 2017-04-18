#include "Coconut.h"

Coconut::Coconut() : Fruit("coconut", 15)
{

}

Coconut::~Coconut()
{

}

std::string	Coconut::getName() const
{
	return _name;
}