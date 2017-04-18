#include "Buzz.h"

Buzz::Buzz(std::string const &name, std::string const &file) : Toy(BUZZ, name, file)
{

}

Buzz::~Buzz()
{

}

bool		Buzz::speak(std::string const &status)
{
	std::cout << "BUZZ: " << _name << " \"" << status << "\"" << std::endl;
	return (true);
}

bool		Buzz::speak_es(std::string const &status)
{
	std::cout << "BUZZ: " << _name << " senorita \"" << status << "\" senorita" << std::endl;
	return (true);
}
