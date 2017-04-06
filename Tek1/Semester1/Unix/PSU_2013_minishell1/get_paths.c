/*
** get_paths.c for get_paths in /home/moulin_c/rendu/Modules/Unix/Minishell/Minishell_1/PSU_2013_minishell1
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Sat Dec 21 00:46:18 2013 moulin_c
** Last update Sun Jan  5 14:19:07 2014 moulin_c
*/

#include "my.h"
#include "minishell1.h"

int	get_path_home(char **envp)
{
  int	i;

  i = 0;
  while (envp[i] && (my_strncmp("HOME", envp[i], 4) != 0))
    i++;
  if (!envp[i])
    {
      my_putstr("No HOME in environnement, restart program please\n");
      return (-1);
    }
  return (i);
}

char	*get_path(char **envp)
{
  int	i;

  i = 0;
  while (envp[i] && (my_strncmp("PATH", envp[i], 4) != 0))
    i++;
  if (!envp[i])
    {
      my_putstr("No PATH in environnement, restart program please\n");
      return (NULL);
    }
  return (my_strcat(envp[i] + 5, "/"));
}
