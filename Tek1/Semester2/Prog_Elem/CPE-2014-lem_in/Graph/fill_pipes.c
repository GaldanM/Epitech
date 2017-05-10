/*
** fill_pipes.c for  in /home/medec_o/rendu/lem_in
** 
** Made by medec_o
** Login   <medec_o@epitech.net>
** 
** Started on  Fri Apr 25 16:48:01 2014 medec_o
** Last update Sat Apr 26 19:23:54 2014 moulin_c
*/

#include <stdlib.h>
#include "mylist.h"
#include "graph.h"

# define BIN(Value) (((Value) == 1) ? (Value = 0) : (Value = 1))

void	check_function(char *line, char **tab)
{
  if (!tab)
    {
      write(2, "Problem tab is NULL in check function\n", 38);
      exit(1);
    }
  if (!line)
    {
      write(2, "Problem line is NULL in check function\n", 39);
      exit(1);
    }
}

char	**my_malloc_adj(char *name)
{
  int	i;
  char	**tab;

  i = 0;
  if ((tab = malloc(3 * sizeof(char *))) == NULL)
    {
      write(2, "In my_malloc_adj function malloc failed\n", 40);
      return (NULL);
    }
  while (i < 2)
    {
      if ((tab[i] = malloc(my_strlen(name) + 1 * sizeof(char))) == NULL)
	{
	  write(2, "In my_malloc_adj function malloc failed\n", 40);
	  return (NULL);
	}
      i++;
    }
  return (tab);
}

int	fill_adj(t_adj **galdan, char **tab, char *line, int flag)
{
  t_adj	*tmp;
  int	i;

  i = 0;
  tmp = *galdan;
  while (tmp && my_strcmp(tab[flag], tmp->name))
    tmp = tmp->next;
  if (tmp->adjacents)
    {
      while (tmp->adjacents[i])
	{
	  if (!my_strcmp(tmp->adjacents[i], tab[0]))
	    return (-1);
	  i++;
	}
    }
  tmp->adjacents = my_tab_realloc(tmp->adjacents, 2, line);
  flag = BIN(flag);
  tmp->adjacents[i] = tab[flag];
  tmp->adjacents[++i] = NULL;
  return (0);
}

int	add_adjacent(t_adj **galdan, char *line)
{
  char	**tab;

  tab = my_malloc_tab(line);
  tab = my_str_to_word_tab(line, tab);
  if (!my_strcmp(tab[0], tab[1]))
    return (-1);
  if (fill_adj(galdan, tab, line, 1) == -1)
    return (-1);
  fill_adj(galdan, tab, line, 0);
  return (0);
}

void	fill_pipes(t_adj **galdan, t_list **olivier)
{
  t_list *tmp;

  tmp = *olivier;
  while (tmp != NULL)
    {
      if (check_line(tmp->line))
	add_adjacent(galdan, tmp->line);
      tmp = tmp->next;
    }
}
