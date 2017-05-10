/*
** my_find_prime_sup.c for my_find_prime_sup in /home/moulin_c/rendu/Piscine-C-Jour_05
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Thu Oct 17 12:51:02 2013 moulin_c
** Last update Fri Apr 18 04:42:19 2014 moulin_c
*/

#include "my.h"

int	my_find_prime_sup(int nb)
{
  int	i;

  if (nb == 1 || nb == 0)
    return (nb = 2);
  i = 2;
  while (i != nb)
    {
      if (nb % i == 0)
	nb++;
      i++;
    }
  return (nb);
}
