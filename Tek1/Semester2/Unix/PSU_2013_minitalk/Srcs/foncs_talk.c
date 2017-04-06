/*
** foncs_talk.c for minitalk in /home/moulin_c/rendu/Semester 2/Modules/Unix/Minitalk/PSU_2013_minitalk
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Wed Mar 19 22:38:44 2014 moulin_c
** Last update Thu Mar 20 11:53:57 2014 moulin_c
*/

#include <unistd.h>
#include "../minitalk.h"

void	do_nothing()
{

}

void	my_putchar(char d)
{
  write(1, &d, 1);
}

void	my_putstr(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    {
      my_putchar(str[i]);
      i++;
    }
}

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    i++;
  return (i);
}
