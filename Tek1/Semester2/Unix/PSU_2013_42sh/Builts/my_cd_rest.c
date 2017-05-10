/*
** my_cd_rest.c for my_cd_rest in /home/doghri_f/rendu/PSU_2013_42sh/42sh 2.2/Builts
** 
** Made by doghri_f
** Login   <doghri_f@epitech.net>
** 
** Started on  Sat May 31 20:48:38 2014 doghri_f
** Last update Sun Jun  1 15:41:51 2014 doghri_f
*/

#include	<unistd.h>
#include	<string.h>
#include	<stdlib.h>
#include	<stdio.h>
#include	"my.h"
#include	"lists.h"
#include	"shell.h"

char		*get_pwd(t_env **envlist)
{
  while ((*envlist)->root == 0 && strcmp((*envlist)->name, "PWD") != 0)
    (*envlist) = (*envlist)->next;
  if ((*envlist)->root == 0)
    return ((*envlist)->var);
  else
    {
      while ((*envlist)->root == 0)
	(*envlist) = (*envlist)->next;
      (*envlist) = (*envlist)->next;
    }
  return (NULL);
}

char		*get_oldpwd(t_env **envlist)
{
  while ((*envlist)->root == 0 && strcmp((*envlist)->name, "OLDPWD") != 0)
    (*envlist) = (*envlist)->next;
  if ((*envlist)->root == 0)
    return ((*envlist)->var);
  else
    {
      while ((*envlist)->root == 0)
	(*envlist) = (*envlist)->next;
      (*envlist) = (*envlist)->next;
    }
  return (NULL);
}

void		my_cd_m(t_env **envlist, char *oldpwd)
{
  char		*pwd;

  while ((*envlist)->root == 0)
    (*envlist) = (*envlist)->next;
  (*envlist) = (*envlist)->next;
  pwd = get_pwd(envlist);
  (*envlist)->var = oldpwd;
  while (strcmp((*envlist)->name, "OLDPWD") != 0 && (*envlist)->root == 0)
    (*envlist) = (*envlist)->next;
  if ((*envlist)->root == 0)
    (*envlist)->var = pwd;
  while ((*envlist)->root == 0)
    (*envlist) = (*envlist)->next;
  printf("%s\n", oldpwd);
}

char		*concat_pwd(int i, char *str, char *s1)
{
  int		stock;
  int		count;
  char		*s2;
  char		*dest;

  count = 0;
  stock = i + 2;
  while (str[stock])
    {
      stock++;
      count++;
    }
  if ((s2 = malloc(sizeof(char) * count + 1)) == NULL)
    return (NULL);
  stock = i + 2;
  count = 0;
  while (str[stock])
    s2[count++] = str[stock++];
  s2[count] = '\0';
  dest = my_strcat(s1, s2);
  return (dest);
}
