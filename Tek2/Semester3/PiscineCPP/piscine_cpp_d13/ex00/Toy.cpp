#include "Toy.h"

Toy::Toy() : _type(Toy::BASIC_TOY), _name("toy")
{
	_picture = new Picture;
	_picture->data = "";
}

Toy::Toy(ToyType type, std::string const &name, std::string const &file) : _type(type), _name(name)
{
	_picture = new Picture(file);
}

Toy::~Toy()
{
	delete _picture;
}

Toy::ToyType		Toy::getType() const
{
	return (_type);
}

std::string const&	Toy::getName() const
{
	return (_name);
}

std::string const&	Toy::getAscii() const
{
	return (_picture->getData());
}

void				Toy::setName(std::string const &name)
{
	_name = name;
}

bool				Toy::setAscii(std::string const &file)
{
	return (_picture->getPictureFromFile(file));
}