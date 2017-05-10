/*
** my_putchar.c for my_putchar in /home/moulin_c/rendu/Piscine-C-lib/my
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Mon Oct 21 10:23:30 2013 moulin_c
** Last update Sun May 25 07:43:30 2014 moulin_c
*/

#include <unistd.h>
#include "my.h"

int	my_putchar(char d)
{
  if (write(1, &d, 1) == -1)
    return (-1);
  return (0);
}
