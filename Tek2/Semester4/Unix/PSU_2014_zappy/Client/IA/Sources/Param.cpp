//
// Param.cpp for Param in /home/doghri_f/Downloads/ClientQuiMarche
// 
// Made by Fares Doghri
// Login   <doghri_f@epitech.net>
// 
// Started on  Sun Jul  5 20:56:02 2015 Fares Doghri
// Last update Sun Jul  5 20:57:13 2015 Fares Doghri
//

#include	"Param.h"
#include	<cstdlib>
#include	<sstream>

Param::Param() : _teamName(""), _port(0), _host("localhost"), _op(0)
{
}

Param::~Param()
{
}

bool		Param::countOp(char **argv)
{
  int		i;

  i = 0;
  while (argv[i])
    {
      if (argv[i][0] == '-')
	_op += 1;
      ++i;
    }
  if (_op < 2 )
    {
      std::cout << "None valid number of option in parameter."
		<< std::endl;
      return false;
    }
  return true;
}

bool		Param::setAll(char **argv)
{
  int		i;
  std::string	param;

  i = 1;
  while (argv[i])
    {
      param = argv[i];
      if (param == "-n")
	if (setTeamName(argv[i + 1]) == false)
	  return false;;
      if (param == "-p")
	if (setPort(argv[i + 1]) == false)
	  return false;
      if (param == "-h")
	if (setHost(argv[i + 1]) == false)
	  return false;
      ++i;
    }
  return true;
}

bool		Param::setTeamName(char *argv)
{
  if (argv == NULL)
    return false;
  if (argv[0] == '-')
    {
      std::cout << " Team's name can not use '-' character"
		<< std::endl;
      return false;
    }
  _teamName = argv;
  return true;
}

bool		Param::setPort(char *argv)
{
  int		i;

  i = 0;
  if (argv == NULL)
    return false;
  while (argv[i])
    {
      if (argv[i] < '0' || argv[i] > '9')
	{
	  std::cout << "Port uses only numerical character [0->9]"
		    << std::endl;
	  return false;
	}
      ++i;
    }
  std::istringstream	port(argv);
  port >> _port;
  if (_port <= 1023 || _port > 65535)
    {
      std::cout << "Your port is not valid"
		<< std::endl;
      return false;
    }
  return true;
}

bool		Param::setHost(char *argv)
{
  if (argv == NULL)
    return true;
  if (argv[0] == '-')
    {
      std::cout << "Host's name can not use '-' character"
		<< std::endl;
      return false;
    }
  _host = argv;
  return true;
}

std::string	Param::getTeamName() const
{
  return _teamName;
}

int		Param::getPort() const
{
  return _port;
}

std::string	Param::getHost() const
{
  return _host;
}
