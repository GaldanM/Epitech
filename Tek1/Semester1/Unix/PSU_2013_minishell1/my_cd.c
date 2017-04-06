/*
** my_cd.c for shell_1 in /home/moulin_c/rendu/Modules/Unix/Minishell/Minishell_1/PSU_2013_minishell1
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Sun Dec 29 23:38:04 2013 moulin_c
** Last update Sun Jan  5 14:22:13 2014 moulin_c
*/

#include <stdlib.h>
#include <unistd.h>
#include "my.h"
#include "minishell1.h"

char		*choose_dir(char **tab, char **envp)
{
  char		*dir;
  int		pos;

  dir = NULL;
  if (!tab[1])
    {
      if ((pos = get_path_home(envp)) == -1)
	return (NULL);
      dir = my_strcat(envp[pos] + 5, "/");
    }
  else if (my_strcmp("..", tab[1]) == 0)
    dir = my_strdup("..");
  else if (tab[1][0] == '/')
    dir = my_strcpy(dir, tab[1]);
  else
    dir = my_strcat("./", tab[1]);
  return (dir);
}

int		my_cd(char **tab, char **envp)
{
  char		*dir;

  dir = NULL;
  if ((dir = choose_dir(tab, envp)) == NULL)
    return (-1);
  if (chdir(dir) < 0)
    {
      my_printf("'%s' : No such directory\n", dir + 2);
      return (-1);
    }
  return (1);
}
