/*
** ls_tab_name_rev.c for my_ls in /home/moulin_c/rendu/Modules/Unix/My_ls/PSU_2013_my_ls
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Sat Nov 30 17:13:03 2013 moulin_c
** Last update Sun Dec  1 19:23:38 2013 moulin_c
*/

#include "my_ls.h"

char	**tab_name_rev()
{
  struct dirent	*ptr;
  char		**tab;
  DIR		*dir;
  int		j;
  int		c;

  j = 0;
  c = count_files();
  if ((tab = malloc(sizeof(char *) * (c + 1))) == NULL)
    return (NULL);
  while (j < c)
    if ((tab[j++] = malloc(256 * sizeof(char))) == NULL)
      return (NULL);
  j = 0;
  if ((dir = opendir(".")) == NULL)
    exit(1);
  while ((ptr = readdir(dir)))
    tab[j] = my_strcpy(tab[j++], ptr->d_name);
  tab[j] = 0;
  tab = my_sort_alpha_rev(j, tab);
  if ((closedir(dir)) == -1)
    exit(1);
  return (tab);
}
