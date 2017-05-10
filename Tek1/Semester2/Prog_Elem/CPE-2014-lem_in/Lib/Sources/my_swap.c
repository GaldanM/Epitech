/*
** my_swap.c for my_swap in /home/moulin_c/rendu/Piscine-C-Jour_04
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Thu Oct  3 12:02:51 2013 moulin_c
** Last update Fri Apr 18 04:21:11 2014 moulin_c
*/

#include "my.h"

void	my_swap(char *a, char *b)
{
  int	stock;

  stock = *a;
  *a = *b;
  *b = stock;
}
