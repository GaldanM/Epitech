/*
** my_init_env.c for init env in /home/moulin_c/rendu/Semester 2/Modules/Unix/42sh 2.2
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Sun Jun  1 18:29:30 2014 moulin_c
** Last update Sun Jun  1 18:30:04 2014 moulin_c
*/

#include	<stdlib.h>
#include	<signal.h>
#include	<unistd.h>
#include	"shell.h"

void		set_oldpwd(t_env **env)
{
  *env = (*env)->next;
  while ((*env)->root != 1 && my_strcmp((*env)->name, "OLDPWD") != 0)
    *env = (*env)->next;
  if ((*env)->root == 1)
    add_env(env, "OLDPWD", "/home");
  else
    {
      while ((*env)->root != 1)
	*env = (*env)->next;
    }
}

t_env		*my_init_env(char **envp)
{
  t_env		*env;

  if ((env = make_env()) == NULL)
    return (NULL);
  if (get_env(env, envp) == -1)
    return (NULL);
  if (env->next->root != 1)
    set_oldpwd(&env);
  return (env);
}
