#include "Master.hh"

int     main()
{
	try 
	{
		Master	master;

		master.run();
	}
	catch (MyError const &error)
	{
		std::cerr << error.what() << std::endl;
	}
	return (0);
}
