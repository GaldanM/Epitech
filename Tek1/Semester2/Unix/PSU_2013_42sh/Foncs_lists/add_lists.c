/*
** add_lists.c for lemin in /home/moulin_c/rendu/Semester 2/Modules/C_Prog_Elem/Lem-in/CPE-2014-lem_in
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Thu May  1 19:51:39 2014 moulin_c
** Last update Sun Jun  1 18:32:36 2014 doghri_f
*/

#include	<stdlib.h>
#include	"lists.h"

int		add_cmd(t_cmds **cmds, char *cmd)
{
  t_cmds	*elem;

  elem = malloc(sizeof(*elem));
  if (elem != NULL)
    {
      elem->cmd = cmd;
      elem->args = NULL;
      elem->separator = NULL;
      elem->root = 0;
      elem->fdin = 0;
      elem->fdout = 1;
      elem->fderr = 2;
      elem->ret_exec = 0;
      elem->prev = (*cmds)->prev;
      elem->next = (*cmds);
      (*cmds)->prev->next = elem;
      (*cmds)->prev = elem;
    }
  else
    return (-1);
  return (0);
}

int		add_arg(t_args **args, char *arg)
{
  t_args	*elem;

  elem = malloc(sizeof(*elem));
  if (elem != NULL)
    {
      elem->arg = arg;
      elem->root = 0;
      elem->prev = (*args)->prev;
      elem->next = (*args);
      (*args)->prev->next = elem;
      (*args)->prev = elem;
    }
  else
    return (-1);
  return (0);
}

int		add_env(t_env **env, char *name, char *var)
{
  t_env		*elem;

  elem = malloc(sizeof(t_env));
  if (elem != NULL)
    {
      elem->name = name;
      elem->var = var;
      elem->root = 0;
      elem->prev = (*env)->prev;
      elem->next = (*env);
      (*env)->prev->next = elem;
      (*env)->prev = elem;
    }
  else
    return (-1);
  return (0);
}

int		add_bin(t_bin **bin, char *path)
{
  t_bin		*elem;

  elem = malloc(sizeof(*elem));
  if (elem != NULL)
    {
      elem->path = path;
      elem->root = 0;
      elem->prev = (*bin)->prev;
      elem->next = (*bin);
      (*bin)->prev->next = elem;
      (*bin)->prev = elem;
    }
  else
    return (-1);
  return (0);
}

int		add_syntax(t_syntax **syntax, char *str)
{
  t_syntax	*elem;

  elem = malloc(sizeof(*elem));
  if (elem != NULL)
    {
      elem->str = str;
      elem->root = 0;
      elem->prev = (*syntax)->prev;
      elem->next = (*syntax);
      (*syntax)->prev->next = elem;
      (*syntax)->prev = elem;
    }
  else
    return (-1);
  return (0);
}
