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