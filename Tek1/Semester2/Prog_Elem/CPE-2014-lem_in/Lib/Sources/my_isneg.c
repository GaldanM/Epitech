/*
** my_isneg.c for my_isneg in /home/moulin_c/rendu/A check
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Fri Oct 11 13:58:33 2013 moulin_c
** Last update Fri Apr 18 04:22:20 2014 moulin_c
*/

#include "my.h"

int	my_isneg(int n)
{
  if (n < 0)
    my_putchar('N');
  else if (n >= 0)
    my_putchar('P');
  return (0);
}
