#include "Woody.h"

Woody::Woody(std::string const &name, std::string const &file) : Toy(WOODY, name, file)
{
	
}

Woody::~Woody()
{
	
}

void		Woody::speak(std::string const &status)
{
	std::cout << "WOODY: " << _name << " \"" << status << "\"" << std::endl;
}

bool		Woody::speak_es(std::string const &status)
{
	if (status == status)
		_error.type = Error::SPEAK;
	return (false);
}