/*
** my_unsetenv.c for my_unsetenv in /home/di-mam_a/rendu/42sh/42sh/Builts
** 
** Made by di-mam_a
** Login   <di-mam_a@epitech.net>
** 
** Started on  Fri May 23 20:29:40 2014 di-mam_a
** Last update Sun Jun  1 19:13:10 2014 doghri_f
*/

#include	<stdlib.h>
#include	<stdio.h>
#include	<string.h>
#include	"lists.h"

int		my_unsetenv(t_env **envlist, t_cmds *cmds)
{
  t_env		*tmp;
  t_env		*beg;

  beg = *envlist;
  tmp = (*envlist)->next;
  if (cmds->next->args->next->arg == NULL)
    {
      printf("Usage : unsetenv VAR\n");
      return (-1);
    }
  while (tmp->root != 1 && strcmp(tmp->name, cmds->next->args->next->arg) != 0)
    tmp = tmp->next;
  if (tmp->root != 1)
    {
      *envlist = tmp;
      del_env(*envlist);
      *envlist = beg;
    }
  else
    {
      printf("unsetenv: %s does not exist\n", cmds->next->args->next->arg);
      return (-1);
    }
  return (0);
}
