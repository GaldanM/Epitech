/*
** my_putnbr.c for chiffres in /home/sement_s/rendu/colle4_moulin_c_S4gR1/src
** 
** Made by Stephen SEMENT
** Login   <sement_s@epitech.net>
** 
** Started on  Mon May 19 19:47:55 2014 Stephen SEMENT
** Last update Mon May 19 20:37:04 2014 Stephen SEMENT
*/

#include	<stdlib.h>

int		my_putnbr(int nb)
{
  int		a;
  a = 1;
  if (nb == 0)
    return (my_putchar('0'));
  if (nb < 0)
    {
      my_putchar('-');
      nb = nb * (-1);
    }
  while (a < nb)
    a = a * 10;
  a = a / 10;
  while (nb > 0)
    {
      my_putchar((nb / a) + 48);
      nb = nb % a;
      a = a / 10;
    }
  return (0);
}
