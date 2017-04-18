#include "Fruit.h"

Fruit::Fruit(std::string name, int vita)
{
	_name = name;
	_vitamins = vita;
}

Fruit::~Fruit()
{

}

std::string		Fruit::getName() const
{
	return _name;
}

int						Fruit::getVitamins() const
{
	return _vitamins;
}