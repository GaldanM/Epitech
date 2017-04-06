/*
** my_put_nbr.c for my_put_nbr in /home/moulin_c/rendu/Piscine-C-Jour_03
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Fri Oct  4 10:56:17 2013 moulin_c
** Last update Sun Apr 13 22:55:16 2014 moulin_c
*/

#include "../Includes/flags.h"

int		my_put_nbr(int nb)
{
  if (nb == -2147483648)
    {
      my_putstr("-2147483648");
      return (0);
    }
  if (nb < 0)
    {
      nb = nb * -1;
      my_putchar('-');
    }
  if (nb == 0)
    my_putchar(48);
  else if (nb > 0)
    calcul_putnbr(nb);
}

int		calcul_putnbr(int nb)
{
  long long	modulo;
  int		reste;
  int		result;

  modulo = 1;
  while (reste != nb)
    {
      modulo  = modulo * 10;
      reste = nb % modulo;
    }
  while (modulo != 1)
    {
      modulo = modulo / 10;
      result = nb / modulo;
      my_putchar(result + 48);
      nb = nb % modulo;
    }
}
