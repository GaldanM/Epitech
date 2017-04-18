//
// main.cpp for convert_temp in /home/moulin_c/rendu/piscine_cpp_d06/ex01
// 
// Made by Galdan MOULINNEUF
// Login   <moulin_c@epitech.net>
// 
// Started on  Mon Jan 12 12:39:43 2015 Galdan MOULINNEUF
// Last update Mon Jan 12 16:30:10 2015 Galdan MOULINNEUF
//

#include	<iostream>
#include	<iomanip>

void		my_convert_temp(char flag, double deg, std::string type)
{
  if (!flag)
    deg = ((deg - 32) / 1,8);
  else
    deg = ((deg * 9/5) + 32);
  std::cout << std::fixed << std::setprecision(3);
  std::cout << std::setw(16) << deg << std::setw(16) << type << std::endl;
}

int		main()
{
  double	deg;
  std::string	convert;
  std::string	fahr = ("Fahrenheit");
  std::string	cels = ("Celsius");

  std::cin >> deg >> convert;
  if (convert == fahr)
    my_convert_temp(0, deg, cels);
  else if (convert == cels)
    my_convert_temp(1, deg, fahr);
  return (0);
}
