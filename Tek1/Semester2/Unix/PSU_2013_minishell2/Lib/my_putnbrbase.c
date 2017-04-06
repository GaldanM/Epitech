/*
** my_putnbrbase.c for Jour 06 in /home/moulin_c/rendu/Piscine C/Piscine-C-Jour_06/ex_15
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Wed Nov 13 14:04:48 2013 moulin_c
** Last update Sun Mar  9 17:07:09 2014 moulin_c
*/

#include "../Includes/flags.h"

int	check_bin(int nb)
{
  int	k;

  k = 0;
  while (nb != 0)
    {
      nb = nb / 2;
      k = k + 1;
    }
  return (k);
}

int		my_putnbrbase(unsigned int nb, char *base)
{
  unsigned int	reste;
  unsigned int	i;
  int		j;
  char		*str;

  j = 0;
  i = my_strlen(base);
  if (i == 2)
    i = check_bin(nb);
  str = malloc(i * sizeof(char));
  if (str == NULL)
    exit(10);
  if (i != (my_strlen(base)))
    i = 2;
  if (nb == 0)
    my_putchar('0');
  while (nb > 0)
    {
      reste = nb % i;
      nb = nb / i;
      str[j] = base[reste];
      j = j + 1;
    }
  my_putstr_rev(str, j - 1);
  free(str);
}
