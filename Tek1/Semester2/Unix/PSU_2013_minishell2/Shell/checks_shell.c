/*
** checks_shell1.c for check_shell1 in /home/moulin_c/rendu/Modules/Unix/Minishell/Minishell_1/PSU_2013_minishell1
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Sat Dec 21 00:45:20 2013 moulin_c
** Last update Sun Mar  9 21:35:12 2014 moulin_c
*/

#include <stdlib.h>
#include <unistd.h>
#include "../Includes/shell.h"
#include "../Includes/my.h"
#include "../Includes/parser.h"
#include "../Includes/builts.h"

int		check_builts(char **tab, char ***envp)
{
  if (tab[0])
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
	my_cd(tab, envp);
      else
	return (0);
    }
  return (1);
}

int		check_redirect(char **tab, char ***envp)
{
  int	i;

  i = 0;
  while (tab[i] != 0)
    {
      if (REDIRECT_EG(tab[i][0]) && tab[i + 1] != 0)
	return (1);
      i++;
    }
  return (0);
}

char		*browse_paths(char *str, char **tab_paths, int i)
{
  char		*fpath;

  while (tab_paths[i])
    {
      if ((fpath =
	   malloc(my_strlen(tab_paths[i]) + my_strlen(str) + 2)) == NULL)
	return (NULL);
      fpath = my_strcpy(fpath, tab_paths[i]);
      fpath = my_strcat(fpath, "/");
      fpath = my_strcat(fpath, str);
      if (access(fpath, F_OK) == 0)
	return (fpath);
      i++;
    }
  my_putstr(str);
  my_putstr(": command not found\n");
  return (NULL);
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
  return (browse_paths(str, tab_paths, i));
}
