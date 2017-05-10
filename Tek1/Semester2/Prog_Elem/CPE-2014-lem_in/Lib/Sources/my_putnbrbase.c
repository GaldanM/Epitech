/*
** my_putnbrbase.c for lib in /home/moulin_c/rendu/Lib/Piscine-C-lib/my
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Fri Apr 18 03:22:00 2014 moulin_c
** Last update Fri Apr 18 04:23:03 2014 moulin_c
*/

#include <stdlib.h>
#include "my.h"

int	put_converted(unsigned int nb, unsigned int save, int i, char *base)
{
  char	*str;
  int	reste;
  int	j;

  j = 0;
  while (nb > 0)
    {
      reste = nb % i;
      nb = nb / i;
      j++;
    }
  if ((str = malloc(sizeof(char) * j + 1)) == NULL)
    return (-1);
  j = 0;
  while (save > 0)
    {
      reste = save % i;
      save = save / i;
      str[j] = base[reste];
      j++;
    }
  str[j] = '\0';
  my_putstr_rev(str);
  free(str);
  return (0);
}

int	my_putnbrbase(unsigned int nb, char *base)
{
  int	i;

  i = my_strlen(base);
  if (i != 10)
    {
      if (put_converted(nb, nb, i, base) == -1)
	{
	  my_putstr("Malloc failed\n");
	  return (-1);
	}
    }
  else if (nb == 0)
    my_putchar('0');
  else
    my_put_nbr(nb);
  return (nb);
}
