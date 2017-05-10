/*
** fill_list.c for lemin in /home/moulin_c/rendu/code_tek/make_list
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Fri Apr 25 17:12:29 2014 moulin_c
** Last update Sat Apr 26 19:25:54 2014 moulin_c
*/

#include "graph.h"
#include "mylist.h"
#include "my.h"

int	find_pipe(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    {
      if (str[i] == '-')
	return (1);
      i++;
    }
  return (0);
}

int	add_room(t_adj **list, char *line, int flag)
{
  int	i;
  char	*name;

  line = epur_str(line);
  i = 0;
  while (line[i] && (!SPACES(line[i])))
    i++;
  name = my_strndup(line, i);
  if (add_elem(list, name, flag) == -1)
    return (-1);
  return (0);
}

int	new_room(char *str)
{
  if (find_pipe(str) == 1)
    return (-1);
  if (!my_strncmp(str, "##start", 7))
    return (1);
  if (!my_strncmp(str, "##end", 5))
    return (2);
  else
    return (0);
}

int	fill_list(t_adj **list, t_list **lines)
{
  t_list	*tmp;
  int		ret;

  tmp = *lines;
  while (tmp != NULL)
    {
      ret = new_room(tmp->line);
      if (ret != -1)
	{
	  if (tmp->next != NULL && (ret == 1 || ret == 2))
	    tmp = tmp->next;
	  add_room(list, tmp->line, ret);
	}
      tmp = tmp->next;
    }
  return (0);
}

void	get_nb_adj(t_adj **list)
{
  int	nb;
  t_adj *tmp;

  tmp = *list;
  while (tmp != NULL)
    {
      nb = 0;
      while (tmp->adjacents[nb])
	nb++;
      tmp->nb_adj = nb;
      tmp = tmp->next;
    }
}

int	main()
{
  t_adj		*list;
  t_list	*lines;

  lines = my_recup_elem();
  lines = lines->next;
  fill_list(&list, &lines);
  my_show_list(lines);
  fill_pipes(&list, &lines);
  get_nb_adj(&list);
  while (list != NULL)
    {
      my_printf("Nom = '%s'\tFlag = %d\tNb_room = %d\n", list->name, list->flag, list->nb_adj);
      if (list->adjacents)
	my_show_tab(list->adjacents);
      my_putchar('\n');
      list = list->next;
    }
}
