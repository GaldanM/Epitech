#include "Buzz.h"

Buzz::Buzz(std::string const &name, std::string const &file) : Toy(BUZZ, name, file)
{

}

Buzz::~Buzz()
{

}

void		Buzz::speak(std::string const &status)
{
	std::cout << "BUZZ: " << _name << " \"" << status << "\"" << std::endl;
}