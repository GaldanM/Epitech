/*
** make_lists.c for lemin in /home/moulin_c/rendu/Semester 2/Modules/C_Prog_Elem/Lem-in/CPE-2014-lem_in
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Thu May  1 19:41:14 2014 moulin_c
** Last update Sun Jun  1 18:32:10 2014 doghri_f
*/

#include	<stdlib.h>
#include	"lists.h"

t_cmds		*make_cmds(void)
{
  t_cmds	*root;

  root = malloc(sizeof(*root));
  if (root != NULL)
    {
      root->prev = root;
      root->cmd = NULL;
      root->args = NULL;
      root->separator = NULL;
      root->fdin = -1;
      root->fdout = -1;
      root->fderr = -1;
      root->ret_exec = 0;
      root->root = 1;
      root->next = root;
    }
  else
    return (NULL);
  return (root);
}

t_args		*make_args(void)
{
  t_args	*root;

  root = malloc(sizeof(*root));
  if (root != NULL)
    {
      root->prev = root;
      root->arg = NULL;
      root->root = 1;
      root->next = root;
    }
  else
    return (NULL);
  return (root);
}

t_env		*make_env(void)
{
  t_env		*root;

  root = malloc(sizeof(*root));
  if (root != NULL)
    {
      root->prev = root;
      root->name = NULL;
      root->var = NULL;
      root->root = 1;
      root->next = root;
    }
  else
    return (NULL);
  return (root);
}

t_bin		*make_bin(void)
{
  t_bin		*root;

  root = malloc(sizeof(*root));
  if (root != NULL)
    {
      root->prev = root;
      root->path = NULL;
      root->root = 1;
      root->next = root;
    }
  else
    return (NULL);
  return (root);
}

t_syntax	*make_syntax(void)
{
  t_syntax	*root;

  root = malloc(sizeof(*root));
  if (root != NULL)
    {
      root->prev = root;
      root->str = NULL;
      root->root = 1;
      root->next = root;
    }
  else
    return (NULL);
  return (root);
}
