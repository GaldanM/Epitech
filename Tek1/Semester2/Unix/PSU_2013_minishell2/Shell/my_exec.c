/*
** my_exec.c for shell in /home/moulin_c/rendu/Semester 2/Modules/Unix/Minishell/Minishell_2/PSU_2013_minishell2
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Fri Feb 28 16:28:44 2014 moulin_c
** Last update Sun Mar  9 21:36:02 2014 moulin_c
*/

#include <stdlib.h>
#include "../Includes/shell.h"
#include "../Includes/parser.h"
#include "../Includes/my.h"

int	my_execve(char **tab, char ***envp)
{
  if ((tab[0] = check_locate(tab[0], *envp)) == NULL)
    exit(5);
  execve(tab[0], tab, envp[0]);
  exit(7);
}

int	my_exec(t_cmd *tab_p, int j, char ***envp)
{
  int	ret;
  int	status;

  if (check_builts(tab_p[j].cmd, envp) != 0)
    return (-1);
  ret = fork();
  if (ret == 0)
    {
      if (tab_p[j].fdin != 0)
	dup2(tab_p[j].fdin, 0);
      if (tab_p[j].fdout != 1)
	dup2(tab_p[j].fdout, 1);
      my_execve(tab_p[j].cmd, envp);
    }
  else if (ret > 0)
    {
      if (tab_p[j].fdin != 0)
	close(tab_p[j].fdin);
      if (tab_p[j].fdout != 1)
	close(tab_p[j].fdout);
      if (waitpid(ret, &status, 0) == -1)
	exit(2);
    }
  return (0);
}

int	exec_loop(t_cmd *tab_p, char ***envp)
{
  int	j;

  j = 0;
  while (tab_p[j].cmd != 0)
    {
      my_exec(tab_p, j, envp);
      j++;
    }
}
