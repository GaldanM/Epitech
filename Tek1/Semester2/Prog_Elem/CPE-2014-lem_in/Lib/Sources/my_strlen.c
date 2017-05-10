/*
** my_strlen.c for my_strlen in /home/moulin_c/rendu/Piscine-C-Jour_04
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Thu Oct  3 19:53:33 2013 moulin_c
** Last update Fri Apr 18 04:21:40 2014 moulin_c
*/

#include "my.h"

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    i++;
  return (i);
}
