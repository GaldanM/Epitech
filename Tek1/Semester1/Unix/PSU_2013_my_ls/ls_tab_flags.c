/*
** ls_tab_flags.c for my_ls in /home/moulin_c/rendu/Modules/Unix/My_ls/PSU_2013_my_ls
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Fri Nov 29 16:08:19 2013 moulin_c
** Last update Sun Dec  1 19:23:39 2013 moulin_c
*/

#include "my_ls.h"

int	ls_match(char *str, int i)
{
  char	flags[6];
  int	n;

  n = 0;
  flags[0] = 'l';
  flags[1] = 'R';
  flags[2] = 'd';
  flags[3] = 'r';
  flags[4] = 't';
  flags[5] = 'a';
  flags[6] = '\0';
  while (flags[n] != str[i] && flags[n] != '\0')
    n++;
  return (n);
}

void	tab_flag_ls(char *str, int i)
{
  void	(*tab[7])(char *str, int i);

  tab[0] = &my_ls_l;
  tab[1] = &my_ls_big_r;
  tab[2] = &my_ls_d;
  tab[3] = &my_ls_r;
  tab[4] = &my_ls_t;
  tab[5] = &my_ls_a;
  tab[6] = &my_ls_other;
  tab[ls_match(str, i)](str, i);
}
