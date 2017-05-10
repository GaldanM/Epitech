/*
** my_env.c for env in /home/di-mam_a/rendu/420blazeit
** 
** Made by di-mam_a
** Login   <di-mam_a@epitech.net>
** 
** Started on  Fri May 16 17:52:58 2014 di-mam_a
** Last update Sun Jun  1 15:49:54 2014 doghri_f
*/

#include	<stdlib.h>
#include	<stdio.h>
#include	<string.h>
#include	"lists.h"

int		ooption(t_env **envlist)
{
  t_env		*tmp;

  tmp = (*envlist)->next;
  while (tmp->root != 1)
    {
      if (tmp->var == NULL)
	printf("%s=", tmp->name);
      else
	printf("%s=%s", tmp->name, tmp->var);
      tmp = tmp->next;
    }
  return (0);
}

int		nooption(t_env **envlist)
{
  t_env		*tmp;

  tmp = *envlist;
  tmp = tmp->next;
  while (tmp->root != 1)
    {
      if (tmp->var == NULL)
	printf("%s=\n", tmp->name);
      else
	printf("%s=%s\n", tmp->name, tmp->var);
      tmp = tmp->next;
    }
  return (0);
}

int		check_option(t_cmds *cmds)
{
  char		options[2];
  int		i;

  i = 0;
  options[0] = '0';
  options[1] = '\0';
  if (cmds->next->args->next->arg == NULL)
    return (1);
  else
    {
      if (cmds->next->args->next->arg[0] == '-')
	{
	  while (options[i] && cmds->next->args->next->arg[1] != options[i])
	    i++;
	  if (options[i] == '\0')
	    return (-2);
	  else
	    return (i);
	}
    }
  return (-1);
}

int		my_env(t_env **envlist, t_cmds *cmds)
{
  int		(*option[2])();
  int		n;

  if ((n = check_option(cmds)) == -2)
    {
      printf("env: invalid option -- '%c'\n", cmds->next->args->next->arg[1]);
      return (-1);
    }
  else if (n == -1)
    {
      printf("%s: No such file or directory\n", cmds->next->args->next->arg);
      return (-1);
    }
  else
    {
      option[0] = &ooption;
      option[1] = &nooption;
      option[n](envlist, cmds);
    }
  return (0);
}
