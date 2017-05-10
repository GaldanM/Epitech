/*
** my_tab_realloc.c for  in /home/moulin_c/rendu/Semester 2/Modules/C_Prog_Elem/Lem-in/CPE-2014-lem_in
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Sat Apr 26 16:52:25 2014 moulin_c
** Last update Sat Apr 26 19:34:01 2014 moulin_c
*/

#include <stdlib.h>
#include "graph.h"
#include "my.h"

int	my_tablen(char **tab)
{
  int	i;

  i = 0;
  if (!tab)
    return (0);
  while (tab[i])
    i++;
  return (i);
}

char	**my_tabcpy(char **old, char **new)
{
  int	i;

  i = 0;
  if ((new = malloc(sizeof(char *) * (my_tablen(old) + 1))) == NULL)
    {
      write(2, "In my_tabcpy function malloc failed\n", 36);
      exit(1);
    }
  while (old[i])
    {
      if ((new[i] = malloc(my_strlen(old[i]) + 1 * sizeof(char))) == NULL)
	{
	  write(2, "In my_tabcpy function malloc failed\n", 36);
	  exit(1);
	}
      new[i] = my_strcpy(new[i], old[i]);
      i++;
    }
  new[i] = NULL;
  return (new);
}

char	**my_tab_realloc(char **old, int size, char *line)
{
  char	**new;
  int	len;

  if (!old)
    {
      if ((old = my_malloc_tab(line)) == NULL)
	exit(1);
      return (old);
    }
  len = my_tablen(old);
  new = my_tabcpy(old, new);
  return (new);
}

char	**my_str_to_word_tab(char *line, char **tab)
{
  int	i;
  int	j;
  int	k;

  i = 0;
  k = 0;
  j = 0;
  check_function(line, tab);
  while (line[i])
    {
      if (line[i] == '-')
	{
	  tab[j][k] = '\0';
	  k = 0;
	  j++;
	  i++;
	}
      tab[j][k++] = line[i++];
    }
  tab[j][k] = '\0';
  j++;
  tab[j] = NULL;
  return (tab);
}
