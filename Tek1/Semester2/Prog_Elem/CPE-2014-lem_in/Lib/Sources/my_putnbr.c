/*
** my_putnbr.c for lib in /home/moulin_c/rendu/Lib/Piscine-C-lib/my
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Fri Apr 18 03:23:10 2014 moulin_c
** Last update Fri Apr 18 04:22:10 2014 moulin_c
*/

#include "my.h"

void	calcul_putnbr(int nb)
{
  long	modulo;
  int	reste;
  int	result;

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

void	my_put_nbr(int nb)
{
  if (nb == -2147483648)
    my_putstr("-2147483648");
  else if (nb < 0)
    {
      nb = nb * -1;
      my_putchar('-');
      calcul_putnbr(nb);
    }
  else if (nb == 0)
    my_putchar('0');
  else if (nb > 0)
    calcul_putnbr(nb);
}
