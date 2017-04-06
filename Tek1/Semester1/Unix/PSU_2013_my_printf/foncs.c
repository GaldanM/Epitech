/*
** foncs.c for printf in /home/moulin_c/rendu/tests/printf
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Sat Nov 16 10:05:32 2013 moulin_c
** Last update Sat Nov 16 18:24:05 2013 moulin_c
*/

#include "flags.h"

void	my_putchar(char d)
{
  write(1, &d,1);
}

void	my_putstr(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      my_putchar(str[i]);
      i = i + 1;
    }
}

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
  int	nb;

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

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    i = i + 1;
  return (i);
}
