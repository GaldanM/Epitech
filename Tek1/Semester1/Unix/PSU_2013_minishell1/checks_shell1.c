/*
** checks_shell1.c for check_shell1 in /home/moulin_c/rendu/Modules/Unix/Minishell/Minishell_1/PSU_2013_minishell1
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Sat Dec 21 00:45:20 2013 moulin_c
** Last update Sun Jan  5 15:26:35 2014 moulin_c
*/

#include <dirent.h>
#include <stdlib.h>
#include <sys/types.h>
#include "minishell1.h"
#include "my.h"

int		check_builts(char **tab, char ***envp)
{
  if (my_strcmp("exit", tab[0]) == 0)
    my_exit(tab);
  else if (my_strcmp("setenv", tab[0]) == 0)
    my_setenv(tab, envp);
  else if (my_strcmp("unsetenv", tab[0]) == 0)
    my_unsetenv(tab, envp);
  else if (my_strcmp("env", tab[0]) == 0)
    return (my_env(*envp));
  else if (my_strcmp("cd", tab[0]) == 0)
    my_cd(tab, *envp);
  else
    return (0);
  return (1);
}

char		*browse_paths(char *str, char **tab_paths, int i)
{
  while (tab_paths[i])
    {
      tab_paths[i] = my_strcat(tab_paths[i], "/");
      tab_paths[i] = my_strcat(tab_paths[i], str);
      if (access(tab_paths[i], F_OK) == 0)
	return (tab_paths[i]);
      i++;
    }
  return (str);
}

char		*check_locate(char *str, char **envp)
{
  char		**tab_paths;
  char		*path;
  int		i;

  i = 0;
  if ((path = get_path(envp)) == NULL)
    return (NULL);
  tab_paths = my_str_to_tabpaths(path);
  str = browse_paths(str, tab_paths, i);
  return (str);
}
