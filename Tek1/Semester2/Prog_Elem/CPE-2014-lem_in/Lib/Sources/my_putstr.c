/*
** my_putstr.c for my_putstr in /home/moulin_c/rendu/Piscine-C-Jour_04
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Thu Oct  3 18:51:01 2013 moulin_c
** Last update Fri Apr 18 04:23:07 2014 moulin_c
*/

#include "my.h"

void	 my_putstr(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    {
      my_putchar(str[i]);
      i++;
    }
}
