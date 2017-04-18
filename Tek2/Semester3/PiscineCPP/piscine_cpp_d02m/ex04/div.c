/*
** div.c for div in /home/moulin_c/rendu/piscine_cpp_d02m/ex04
** 
** Made by Galdan MOULINNEUF
** Login   <moulin_c@epitech.net>
** 
** Started on  Thu Jan  8 13:21:31 2015 Galdan MOULINNEUF
** Last update Thu Jan  8 17:16:28 2015 Galdan MOULINNEUF
*/

#include	"castmania.h"

int		integer_div(int a, int b)
{
  if (!b)
    return (b);
  return (a / b);
}

float		decimale_div(int a, int b)
{
  float		i;
  float		j;

  i = a;
  j = b;
  if (!b)
    return (b);
  return (i / j);
}

void		exec_div(t_div *operation)
{
  if (operation->div_type == INTEGER)
    ((t_integer_op *)operation->div_op)->res = integer_div(((t_integer_op *)operation->div_op)->a, ((t_integer_op *)operation->div_op)->b);
  else if (operation->div_type == DECIMALE)
    ((t_decimale_op *)operation->div_op)->res = decimale_div(((t_integer_op *)operation->div_op)->a, ((t_integer_op *)operation->div_op)->b);
}
