/*
** my_power_it.c for my_power_it in /home/moulin_c/rendu/Piscine-C-Jour_05
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Sat Oct  5 20:10:35 2013 moulin_c
** Last update Fri Apr 18 04:22:16 2014 moulin_c
*/

#include "my.h"

int	calcul_power_it(int power, int nb)
{
  int	i;
  int	save;

  i = 0;
  save = nb;
  while (i < power)
    {
      nb = nb * save;
      i++;
    }
  return (nb);
}

int	my_power_it(int nb, int power)
{
  if (nb < 0)
    nb = nb * -1;
  if (power == 0 || power < 0)
    return (1);
  else
    return (calcul_power_it(power - 1, nb));
  return (0);
}
