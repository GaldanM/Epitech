/*
** foncs_tab.c for foncs_tab in /home/moulin_c/rendu/Modules/Unix/Minishell/Minishell_1/PSU_2013_minishell1
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Mon Dec 23 10:42:33 2013 moulin_c
** Last update Tue Dec 31 09:23:07 2013 moulin_c
*/

#include <stdlib.h>
#include "my.h"

int	my_tablen(char **tab)
{
  int	i;

  i = 0;
  while (tab[i] != NULL)
    i++;
  return (i);
}

char	**my_tabcpy(char **old, char **new, int name, int check)
{
  int	len;
  int	i;
  int	j;

  i = 0;
  j = 0;
  len = my_tablen(old);
  if ((new = malloc(sizeof(*old) * (len + 1))) == NULL)
    return (NULL);
  while (i < len)
    {
      if ((check == 1 && i != name) || check == 0)
	{
	  if ((new[j] = malloc(sizeof(char) * ((my_strlen(old[i])) + 1))) == NULL)
	    return (NULL);
	  new[j] = my_strcpy(new[j], old[i]);
	  i++;
	  j++;
	}
      else
	i++;
    }
  return (new);
}

char	**my_tab_realloc(char **old, int name, int check)
{
  char	**new;
  int	len;

  len = my_tablen(old);
  if (check == 1)
    {
      if ((new = malloc(sizeof(*old) * (len - 2))) == NULL)
	return (NULL);
      new = my_tabcpy(old, new, name, check);
      new[len - 1] = 0;
    }
  else
    {
      if ((new = malloc(sizeof(*old) * (len + 2))) == NULL)
	return (NULL);
      new = my_tabcpy(old, new, name, check);
      new[len + 1] = 0;
    }
  return (new);
}
