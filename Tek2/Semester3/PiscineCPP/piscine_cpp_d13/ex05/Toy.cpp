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

Toy::Toy(Toy const &cpy)
{
	_picture = cpy._picture->copy();
	_type = cpy._type;
	_name = cpy._name;
}

Toy::~Toy()
{
	delete _picture;
}

Toy&				Toy::operator=(Toy const &cpy)
{
	if (&cpy != this)
	{
		if (_picture)
			delete _picture;
		_picture = cpy._picture->copy();
		_type = cpy._type;
		_name = cpy._name;
	}
	return (*this);
}


/* GETTERS */


Toy::Error		Toy::getLastError()
{
	return (_error);
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


/* SETTERS */


void				Toy::setName(std::string const &name)
{
	_name = name;
}


bool				Toy::setAscii(std::string const &file)
{
	bool			check;

	check = _picture->getPictureFromFile(file);
	if (check == false)
	{
		_error.type = Error::PICTURE;
	}
	return (check);
}


void				Toy::speak(std::string const &status)
{
	std::cout << _name << " \"" << status << "\"" << std::endl;
}


/* OPERATORS */


Toy&				Toy::operator<<(std::string const &str)
{
	_picture->data = str;
	return (*this);
}

std::ostream&		operator<<(std::ostream& os, Toy const &dildo)
{
	os << dildo.getName() << std::endl << dildo.getAscii() << std::endl;
	return os;
}


/* INIT ERROR */


Toy::Error::Error() : type(UNKNOWN)
{

}


Toy::Error::~Error()
{

}


/* WHAT-WHERE */


std::string 	Toy::Error::what() const
{
	if (this->type == Toy::Error::PICTURE)
		return ("bad new illustration");
	else if (this->type == Toy::Error::SPEAK)
		return ("wrong mode");
	else
		return ("");
}


std::string		Toy::Error::where() const
{
	if (this->type == Toy::Error::PICTURE)
		return ("setAscii");
	else if (this->type == Toy::Error::SPEAK)
		return ("speak_es");
	else
		return ("");
}