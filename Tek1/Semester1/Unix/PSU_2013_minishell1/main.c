/*
** main.c for mysh in /home/moulin_c/rendu/Modules/Unix/Minishell/Minishell_1/PSU_2013_minishell1
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Wed Dec 11 17:54:20 2013 moulin_c
** Last update Sun Jan  5 19:49:54 2014 moulin_c
*/

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/resource.h>
#include <sys/wait.h>
#include <signal.h>
#include "minishell1.h"
#include "get_next_line.h"
#include "word_tab.h"
#include "my.h"

void	get_signal(pid_t pid)
{
  my_printf("\nMinishell_1 > ");
}

int	my_noenv_shell(char ***envp)
{
  char	**tab;
  char	*str;

  my_printf("Minishell_1 > ");
  if ((str = get_next_line(0)) == NULL)
    return (-1);
  if (!str[0])
    return (-1);
  tab = my_str_to_wordtab(str);
  if (check_builts(tab, envp) == 0)
    my_printf("'%s' : command not found\n", str);
  return (my_free_tab(tab));
}

int	my_fork(char *str, char **tab, char ***envp)
{
  pid_t	ret_pid;
  int	status;

  if ((ret_pid = fork()) == -1)
    return (-1);
  if (ret_pid > 0)
    {
      if ((wait(&status)) == -1)
	return (-1);
    }
  else if (ret_pid == 0)
    if (execve(tab[0], tab, *envp) < 0)
      {
	my_printf("'%s' : command not found", str);
	my_free_tab(tab);
	return (-1);
      }
  return (my_free_tab(tab));
}

int	my_shell(char ***envp)
{
  char	**tab;
  char	*str;

  if (!envp[0][0])
    {
      if (my_noenv_shell(envp) == -1)
	return (-1);
      return (0);
    }
  my_printf("Minishell_1 > ");
  if ((str = get_next_line(0)) == NULL)
    return (-1);
  if (!str[0])
    return (0);
  tab = my_str_to_wordtab(str);
  if (check_builts(tab, envp) != 0)
    return (my_free_tab(tab));
  tab[0] = check_locate(tab[0], *envp);
  if (my_fork(str, tab, envp) == -1)
    return (-1);
  return (0);
}

int	main(int argc, char **argv, char **envp)
{
  if (signal(SIGINT, get_signal) == SIG_ERR)
    return (0);
  if (!envp[0])
    while (42)
      my_noenv_shell(&envp);
  while (42)
    {
      if (my_shell(&envp) == -1)
	{
	  write(1, "\n", 1);
	  return (0);
	}
    }
}
