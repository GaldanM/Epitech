/*
** foncs.c for printf in /home/moulin_c/rendu/tests/printf
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Sat Nov 16 10:05:32 2013 moulin_c
** Last update Sun Jan  5 15:25:46 2014 moulin_c
*/

#include "flags.h"

void	my_put_zero(char *str, int i)
{
  if (str[i] >= 0 && str[i] <= 7)
    my_putstr("00");
  else if (str[i] >= 8 && str[i] <= 63)
    my_putchar('0');
}

void	my_putstr_s(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] < 32 || str[i] >= 127)
        {
          my_putchar('\\');
          my_put_zero(str, i);
          my_putnbrbase(str[i], "01234567");
        }
      else
        my_putchar(str[i]);
      i = i + 1;
    }
}
