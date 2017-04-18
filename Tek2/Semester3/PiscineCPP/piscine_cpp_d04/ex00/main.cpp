//
// main.cpp for my_cat in /home/moulin_c/rendu/piscine_cpp_d04
// 
// Made by Galdan MOULINNEUF
// Login   <moulin_c@epitech.net>
// 
// Started on  Mon Jan 12 11:51:34 2015 Galdan MOULINNEUF
// Last update Mon Jan 12 12:22:57 2015 Galdan MOULINNEUF
//

#include	<iostream>
#include	<fstream>

void		my_cat(char **files)
{
  int		i = 1;
  char		chara;

  while (files[i])
    {
      std::ifstream fd(files[i], std::ios::in);
      if (fd)
	{
	  while (fd.get(chara))
	    std::cout << chara;
	}
      else
	std::cout << "my_cat: " << files[i] << ": No such file or directory" << std::endl;
      fd.close();
      i++;
    }
}

int		main(int argc, char **argv)
{
  if (argc < 2)
    std::cout << "my_cat: Usage ./my_cat file [...]" << std::endl;
  else
    my_cat(argv);
  return (0);
}
