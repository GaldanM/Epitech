/*
** my_cd.c for my_cd in /home/di-mam_a/rendu/PSU_2013_minishell2
** 
** Made by di-mam_a
** Login   <di-mam_a@epitech.net>
** 
** Started on  Fri May  9 17:56:42 2014 di-mam_a
** Last update Sun Jun  1 19:06:23 2014 doghri_f
*/

#include	<unistd.h>
#include	<string.h>
#include	<stdlib.h>
#include	<stdio.h>
#include	<errno.h>
#include	"my.h"
#include	"lists.h"
#include	"shell.h"

char		*get_home(t_env *envlist)
{
  while (envlist->root != 1 && strcmp(envlist->name, "HOME") != 0)
    envlist = envlist->next;
  if (envlist->root == 1)
    return (NULL);
  return (envlist->var);
}

int		mcd(t_env **envlist, t_cmds *cmds)
{
  if (chdir(cmds->next->args->next->arg) == -1)
    {
      fprintf(stderr, "%s\n", strerror(errno));
      return (-1);
    }
  else
    set_env(envlist, cmds);
  return (0);
}

int		my_cd_rest(t_env **envlist)
{
  char		*oldpwd;

  if ((oldpwd = get_oldpwd(envlist)) == NULL)
    printf("42sh: cd: OLDPWD not set\n");
  else if (chdir(oldpwd) == -1)
    {
      printf("42sh: cd: %s: No such file or directory\n", oldpwd);
      return (-1);
    }
  else
    my_cd_m(envlist, oldpwd);
  return (0);
}

int		my_cd(t_env **envlist, t_cmds *cmds)
{
  char		*home;

  if (cmds->next->fdout != 1)
    return (-1);
  home = get_home((*envlist)->next);
  (*envlist) = (*envlist)->next;
  if (!cmds->next->args->next->arg)
    {
      if (home == NULL)
      	printf("HOME variable not set, can't find home\n");
      else if (chdir(home) == -1)
      	return (-1);
      else
      	set_env(envlist, cmds);
    }
  else if (strcmp(cmds->next->args->next->arg, "-") == 0)
    {
      if (my_cd_rest(envlist) == -1)
	return (-1);
    }
  else
    return (mcd(envlist, cmds));
  return (0);
}
