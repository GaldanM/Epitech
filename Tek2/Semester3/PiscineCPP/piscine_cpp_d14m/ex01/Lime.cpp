#include "Lime.h"

Lime::Lime() : Lemon()
{
	_name = "lime";
	_vitamins = 2;
}

Lime::~Lime()
{

}

std::string const&		Lime::getName() const
{
	return _name;
}