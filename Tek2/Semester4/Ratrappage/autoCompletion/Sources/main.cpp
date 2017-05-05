#include "Dictionnary.hh"

int main(int ac, char **av)
{
	Dictionnary 	*dictionnary;

	try
	{
		if (ac > 1)
		{
			dictionnary = new Dictionnary(av[1]);
			dictionnary->searchAddress();
			delete dictionnary;
		}
		else
			throw MyError("Argument invalide");
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		return (1);
	}
	return (0);
}