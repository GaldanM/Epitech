#include "Lemon.h"

Lemon::Lemon() : Fruit("lemon", 3)
{
	
}

Lemon::~Lemon()
{

}

std::string		Lemon::getName() const
{
	return (_name);
}