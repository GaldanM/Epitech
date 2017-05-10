/*
** get_env.c for 42 in /home/moulin_c/rendu/Semester 2/Modules/Unix/42sh/Minishell1
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Wed May  7 16:17:13 2014 moulin_c
** Last update Thu May 29 13:16:10 2014 moulin_c
*/

#include	<stdlib.h>
#include	"shell.h"

char		*get_name_env(char *env)
{
  int	i;
  char	*name;

  i = 0;
  while (env[i] != '=')
    i++;
  if ((name = malloc(sizeof(char) * i + 1)) == NULL)
    return (NULL);
  i = 0;
  while (env[i] != '=')
    {
      name[i] = env[i];
      i++;
    }
  name[i] = '\0';
  return (name);
}

char		*get_var_env(char *env)
{
  int	i;
  int	j;
  char	*var;

  i = 0;
  while (env[i] != '=')
    i++;
  j = i + 1;
  while (env[i])
    i++;
  if ((var = malloc(sizeof(char) * (i - j + 1))) == NULL)
    return (NULL);
  i = j;
  j = 0;
  while (env[i])
    var[j++] = env[i++];
  var[j] = '\0';
  return (var);
}

int		get_env(t_env *env, char **envp)
{
  int	i;
  char	*var;
  char	*name;

  i = 0;
  while (envp[i])
    {
      if ((name = get_name_env(envp[i])) == NULL)
	return (-1);
      if ((var = get_var_env(envp[i])) == NULL)
	return (-1);
      if (add_env(&env, name, var) == -1)
	return (-1);
      i++;
    }
  return (0);
}
