/*
** ls_sort_alpha_rev.c for tri in /home/moulin_c/rendu/Modules/Unix/My_ls/PSU_2013_my_ls
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Fri Nov 29 16:56:27 2013 moulin_c
** Last update Sun Dec  1 18:34:32 2013 moulin_c
*/

#include "my_ls.h"

char	**my_sort_alpha_rev(int nb_files, char **name_file)
{
  int	i;
  int	j;
  char	*str;

  i = 0;
  while (i < nb_files)
    {
      j = i + 1;
      while (j < nb_files)
	{
	  if (my_strcmp(name_file[i], name_file[j]) < 0)
	    {
	      str = name_file[i];
	      name_file[i] = name_file[j];
	      name_file[j] = str;
	    }
	  j++;
	}
      i++;
    }
  return (name_file);
}
