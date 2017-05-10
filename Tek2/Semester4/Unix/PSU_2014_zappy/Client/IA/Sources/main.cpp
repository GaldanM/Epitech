//
// main.cpp for Main in /home/doghri_f/Downloads/ClientQuiMarche
// 
// Made by Fares Doghri
// Login   <doghri_f@epitech.net>
// 
// Started on  Sun Jul  5 21:09:32 2015 Fares Doghri
// Last update Sun Jul  5 21:09:34 2015 Fares Doghri
//

# include "IA.hpp"
# include "Param.h"


int main(int , char **argv)
{
  Param		ptr;

  if (ptr.countOp(argv) == false)
    {
      std::cout	<< "Usage : ./client -n [TEAM_NAME] -p [PORT] -h [HOST]"
		<< std::endl;
      return -1;
    }
  if (ptr.setAll(argv) == false)
    {
      std::cout	<< "Usage : ./client -n [TEAM_NAME] -p [PORT] -h [HOST]"
		<< std::endl;
      return -1;
    }
  try
    {
      IA ia(ptr.getHost(), ptr.getPort(), ptr.getTeamName());

      ia.handleSelect();
    }
  catch (MyError const &error)
    {
      std::cerr << "ERROR = " << error.what() << std::endl;
    }
  return (0);
}
