/*
** fill_function.c for  in /home/medec_o/rendu/lem_in
** 
** Made by medec_o
** Login   <medec_o@epitech.net>
** 
** Started on  Fri Apr 25 18:23:41 2014 medec_o
** Last update Sat Apr 26 19:24:31 2014 moulin_c
*/

#include <stdlib.h>
#include "mylist.h"
#include "graph.h"

int	check_line(char *line)
{
  int	i;

  i = 0;
  while (line[i])
    {
      if (line[i] == '-')
	return (1);
      i++;
    }
  return (0);
}

int	count_letters(char *line)
{
  static int	i = 0;
  int		cmt;

  cmt = 0;
  while (line[i])
    {
      cmt++;
      if (line[i] == '-')
	{
	  i++;
	  return (cmt);
	}
      i++;
    }
  return (cmt);
}

char	**my_malloc_tab(char *line)
{
  char	**tab;
  int	i;

  i = 0;
  if ((tab = malloc(3 * sizeof(char *))) == NULL)
    {
      write(2, "In my_malloc_tab function malloc failed\n", 40);
      return (NULL);
    }
  while (i < 3)
    {
      if ((tab[i] = malloc(count_letters(line) * sizeof(char))) == NULL)
	{
	  write(2, "In my_malloc_tab function malloc failed\n", 40);
	  return (NULL);
	}
      i++;
    }
  return (tab);
}

int	my_show_tab(char **tab)
{
  int	i;

  i = 0;
  while (tab[i] != NULL)
    {
      my_printf("Adj[%d] = %s\n", i, tab[i]);
      i++;
    }
}
