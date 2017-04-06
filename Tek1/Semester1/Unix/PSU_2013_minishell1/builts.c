/*
** builts.c for minishell1 in /home/moulin_c/rendu/Modules/Unix/Minishell/Minishell_1/PSU_2013_minishell1
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Fri Dec 13 12:37:53 2013 moulin_c
** Last update Sun Jan  5 15:53:16 2014 moulin_c
*/

#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <sys/types.h>
#include "word_tab.h"
#include "my.h"
#include "minishell1.h"

void			my_exit(char **tab)
{
  my_free_tab(tab);
  exit(5);
}

int			my_env(char **envp)
{
  if (envp)
    my_show_wordtab(envp);
  return (1);
}

int			my_unsetenv(char **tab, char ***envp)
{
  int	i;
  int	len;
  int	ret;

  if (!tab[1])
    {
      my_printf("Usage : unsetenv 'name'\n");
      return (1);
    }
  i = 0;
  len = my_strlen(tab[1]);
  while ((envp[0][i]) && (ret = my_strncmp(tab[1], envp[0][i], len) != 0))
    i++;
  if (!ret)
    {
      len = 0;
      len = my_tablen(envp[0]);
      envp[0] = my_tab_realloc(envp[0], i, 1);
    }
  else
    my_printf("'%s' doesn't exist\n", tab[1]);
  return (1);
}
