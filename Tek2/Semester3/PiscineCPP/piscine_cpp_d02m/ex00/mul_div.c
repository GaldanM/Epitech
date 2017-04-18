/*
** mul_div.c for mul_div in /home/moulin_c/rendu/piscine_cpp_d02m/ex00
** 
** Made by Galdan MOULINNEUF
** Login   <moulin_c@epitech.net>
** 
** Started on  Thu Jan  8 09:58:14 2015 Galdan MOULINNEUF
** Last update Thu Jan  8 10:06:24 2015 Galdan MOULINNEUF
*/

void		add_mul_4param(int first, int second, int *add, int *mul)
{
  *add = first + second;
  *mul = first * second;
}

void		add_mul_2param(int *first, int *second)
{
  int		save;

  save = *first;
  *first = *first + *second;
  *second = save * *second;
}
