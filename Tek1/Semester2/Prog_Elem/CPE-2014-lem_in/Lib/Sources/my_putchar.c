/*
** my_putchar.c for my_putchar in /home/moulin_c/rendu/Piscine-C-lib/my
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Mon Oct 21 10:23:30 2013 moulin_c
** Last update Fri Apr 18 04:22:13 2014 moulin_c
*/

#include "my.h"

void	my_putchar(char d)
{
  write(1, &d, 1);
}
