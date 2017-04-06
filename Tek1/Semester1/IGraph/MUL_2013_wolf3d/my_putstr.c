/*
** my_putstr.c for wolf3d in /home/moulin_c/rendu/Modules/Igraph/Wolf3D/MUL_2013_wolf3d
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Sat Jan 11 18:58:17 2014 moulin_c
** Last update Sun Jan 12 01:40:13 2014 moulin_c
*/

#include "wolf.h"

void	my_putchar(char d)
{
  write(1, &d, 1);
}

void	my_putstr(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    {
      my_putchar(str[i]);
      i++;
    }
}
