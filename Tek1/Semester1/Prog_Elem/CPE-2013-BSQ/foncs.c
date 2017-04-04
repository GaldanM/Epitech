/*
** foncs.c for bsq in /home/moulin_c/rendu/Modules/C_Prog_Elem/BSQ/CPE-2013-BSQ
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Sun Dec  8 18:14:53 2013 moulin_c
** Last update Sun Dec  8 18:16:04 2013 moulin_c
*/

#include "bsq.h"

void	my_putchar(char d)
{
  write(1, &d, 1);
}

void	my_putstr(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    my_putchar(str[i++]);
}

int	strlen_mod(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\n')
    i++;
  return (i);
}

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    i++;
  return (i);
}
