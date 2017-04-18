/*
** add.c for add in /home/moulin_c/rendu/piscine_cpp_d02m/ex04
** 
** Made by Galdan MOULINNEUF
** Login   <moulin_c@epitech.net>
** 
** Started on  Thu Jan  8 13:21:31 2015 Galdan MOULINNEUF
** Last update Thu Jan  8 16:49:31 2015 Galdan MOULINNEUF
*/

#include	"castmania.h"

int		normal_add(int a, int b)
{
  return (a + b);
}

int		absolute_add(int a, int b)
{
  if (a < 0)
    a = (a * -1);
  if (b < 0)
    b = (b * -1);
  return (a + b);
}

void		exec_add(t_add *operation)
{
  int		(*tab[2])();

  tab[NORMAL] = &normal_add;
  tab[ABSOLUTE] = &absolute_add;
  operation->add_op.res = (*tab[operation->add_type])(operation->add_op.a, operation->add_op.b);
}
