/*
** my_setenv.c for my_setenv in /home/di-mam_a/rendu/420blazeit
** 
** Made by di-mam_a
** Login   <di-mam_a@epitech.net>
** 
** Started on  Fri May  9 17:58:25 2014 di-mam_a
** Last update Sun Jun  1 15:40:24 2014 doghri_f
*/

#include	<stdio.h>
#include	<string.h>
#include	"lists.h"
#include	"shell.h"

int		check_env(char *name, t_env **envlist)
{
  t_env		*tmp;

  tmp = (*envlist)->next;
  while (tmp->root != 1)
    {
      if (strcmp(name, tmp->name) == 0)
	{
	  *envlist = tmp;
	  return (0);
	}
      tmp = tmp->next;
    }
  return (-1);
}

int		my_setenv(t_env **envlist, t_cmds *cmds)
{
  t_env		*tmp;

  if (cmds->next->fdout != 1)
    return (-1);
  tmp = *envlist;
  if (cmds->next->args->next->arg)
    {
      if (check_env(cmds->next->args->next->arg, envlist) == 0)
	{
	  (*envlist)->var = cmds->next->args->next->next->arg;
	  while ((*envlist) != tmp)
	    *envlist = (*envlist)->next;
	}
      else
	if (add_env(envlist, cmds->next->args->next->arg,
		    cmds->next->args->next->next->arg) == -1)
	  return (-1);
    }
  else
    {
      printf("Usage : setenv VAR1 (VAR2)\n");
      return (-1);
    }
  return (0);
}
