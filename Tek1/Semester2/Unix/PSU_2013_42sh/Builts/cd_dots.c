/*
** cd_dots.c for cd_dots in /home/doghri_f/rendu/PSU_2013_42sh/42sh 2.2/Builts
** 
** Made by doghri_f
** Login   <doghri_f@epitech.net>
** 
** Started on  Sat May 31 20:52:16 2014 doghri_f
** Last update Sun Jun  1 15:46:48 2014 doghri_f
*/

#include	<unistd.h>
#include	<string.h>
#include	<stdlib.h>
#include	<stdio.h>
#include	"my.h"
#include	"lists.h"
#include	"shell.h"

char		*erase_dots(char *str, int i)
{
  int		stock;
  int		count;
  char		*s1;
  char		*dest;

  s1 = NULL;
  stock = i - 2;
  count = 0;
  if (stock < 0)
    stock = 0;
  while (str[stock] && str[stock] != '/')
    stock--;
  while (count != stock)
    count++;
  s1 = my_strncpy(s1, str, count);
  s1[count] = '\0';
  dest = concat_pwd(i, str, s1);
  return (dest);
}

char		*epur_dots(char *str)
{
  int		i;

  i = 0;
  while (str[i])
    {
      if (str[i] == '.' && str[i + 1] == '.')
	{
	  str = erase_dots(str, i);
	  i = 0;
	}
      else
	i++;
    }
  return (str);
}

int		strcat_pwd(t_env **envlist, t_cmds *cmds)
{
  char		*str;

  if ((str = my_strcat((*envlist)->var, "/")) == NULL)
    return (-1);
  if ((str = my_strcat(str, cmds->next->args->next->arg)) == NULL)
    return (-1);
  str = epur_dots(str);
  (*envlist)->var = str;
  return (0);
}

int		set_env(t_env **envlist, t_cmds *cmds)
{
  char		*pwd;

  (*envlist) = (*envlist)->next;
  if ((pwd = get_pwd(envlist)) == NULL)
    return (-1);
  if (cmds->next->args->next->arg)
    {
      if (cmds->next->args->next->arg[0] != '/')
	{
	  if (strcat_pwd(envlist, cmds) == -1)
	    return (-1);
	}
      else
	(*envlist)->var = cmds->next->args->next->arg;
    }
  while ((*envlist)->root == 0 && strcmp((*envlist)->name, "OLDPWD") != 0)
    (*envlist) = (*envlist)->next;
  if ((*envlist)->root == 0)
    (*envlist)->var = pwd;
  while ((*envlist)->root == 0)
    (*envlist) = (*envlist)->next;
  return (0);
}
