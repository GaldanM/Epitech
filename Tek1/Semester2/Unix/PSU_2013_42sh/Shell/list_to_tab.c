/*
** list_to_tab.c for 42 in /home/moulin_c/rendu/Semester 2/Modules/Unix/42sh/Minishell1
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Thu May  8 00:22:32 2014 moulin_c
** Last update Sun May 25 17:32:44 2014 moulin_c
*/

#include <stdlib.h>
#include <string.h>
#include "shell.h"

int		count_args(t_cmds *list)
{
  int		i;
  t_cmds	*tmp;
  t_args	*tmp2;

  i = 0;
  tmp = list;
  if (!tmp->root)
    i++;
  tmp2 = tmp->args->next;
  while (!tmp2->root)
    {
      i++;
      tmp2 = tmp2->next;
    }
  return (i);
}

char		**cmd_to_tab(t_cmds *list)
{
  int		i;
  int		nb;
  t_cmds	*tmp;
  t_args	*tmp2;
  char		**tab;

  tmp = list;
  nb = count_args(list);
  if ((tab = malloc(sizeof(char *) * (nb + 1))) == NULL)
    return (NULL);
  tab[0] = tmp->cmd;
  tmp2 = tmp->args->next;
  i = 1;
  while (!tmp2->root)
    {
      tab[i] = tmp2->arg;
      tmp2 = tmp2->next;
      i++;
    }
  tab[i] = NULL;
  return (tab);
}

int		count_env(t_env *list)
{
  int		i;
  t_env		*tmp;

  i = 0;
  tmp = list->next;
  while (!tmp->root)
    {
      i++;
      tmp = tmp->next;
    }
  return (i);
}

char		**env_to_tab(t_env *list)
{
  int		i;
  int		nb;
  t_env		*tmp;
  char		**tab;

  tmp = list->next;
  nb = count_env(list);
  if ((tab = malloc(sizeof(char *) * (nb + 1))) == NULL)
    return (NULL);
  i = 0;
  while (!tmp->root)
    {
      if (tmp->name)
	if ((tab[i] = my_strcat(tmp->name, "=")) == NULL)
	  return (NULL);
      if (tmp->var)
	if ((tab[i] = my_strcat(tab[i], tmp->var)) == NULL)
	  return (NULL);
      tmp = tmp->next;
      i++;
    }
  tab[i] = NULL;
  return (tab);
}
