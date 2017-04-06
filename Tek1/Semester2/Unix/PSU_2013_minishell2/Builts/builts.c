/*
** builts.c for minishell1 in /home/moulin_c/rendu/Modules/Unix/Minishell/Minishell_1/PSU_2013_minishell1
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Fri Dec 13 12:37:53 2013 moulin_c
** Last update Sun Mar  9 16:36:19 2014 moulin_c
*/

#include <stdlib.h>
#include "../Includes/parser.h"
#include "../Includes/my.h"
#include "../Includes/builts.h"

void	my_exit(char **tab)
{
  my_free_tab(tab);
  exit(5);
}

int	my_env(char **envp)
{
  if (envp)
    my_show_wordtab(envp);
  return (1);
}

int	my_unsetenv(char **tab, char ***env)
{
  int	i;
  int	len;
  int	ret;

  ret = 1;
  if (!tab[1])
    {
      my_putstr("Usage : unsetenv 'name'\n");
      return (1);
    }
  i = 0;
  len = my_strlen(tab[1]);
  while (env[0] && env[0][i] && (ret = my_strncmp(tab[1], env[0][i], len) != 0))
    i++;
  if (!ret)
    {
      len = 0;
      len = my_tablen(env[0]);
      env[0] = my_tab_realloc(env[0], i, 1);
    }
  else
    my_printf("'%s' doesn't exist\n", tab[1]);
  return (1);
}
