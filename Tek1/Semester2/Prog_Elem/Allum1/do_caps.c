/*
** do_caps.c for select in /home/moulin_c/rendu/Modules/Unix/My_select/PSU_2013_my_select
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Sun Jan 19 14:13:42 2014 moulin_c
** Last update Wed Feb  5 13:43:37 2014 moulin_c
*/

#include "alum.h"

int	do_it(int nb)
{
  write(1, &nb, 1);
}

int	do_caps(char *str)
{
  char	*g_str;

  if ((g_str = tgetstr(str, NULL)) == NULL)
    return (-1);
  if (tputs(g_str, 1, do_it) == -1)
    return (-1);
}
