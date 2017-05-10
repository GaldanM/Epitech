/*
** redir_foncs.c for 42 in /home/moulin_c/rendu/Semester 2/Modules/Unix/42sh 2.2
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Sun Jun  1 17:37:09 2014 moulin_c
** Last update Sun Jun  1 17:42:03 2014 moulin_c
*/

#include	<unistd.h>
#include	<stdlib.h>
#include	<sys/types.h>
#include	<sys/stat.h>
#include	<fcntl.h>
#include	<string.h>
#include	<errno.h>
#include	"shell.h"

t_cmds		*my_pipe(t_cmds *cmd)
{
 int		pipefd[2];

  if (pipe(pipefd) == -1)
    {
      fprintf(stderr, "Error pipe : '%s'\n", strerror(errno));
      return (NULL);
    }
  cmd->fdout = pipefd[1];
  cmd->next->fdin = pipefd[0];
  return (cmd->next);
}

int		check_bad(char *str)
{
  int		i;

  i = 0;
  while (str[i])
    {
      if (str[i] < 32)
	return (-1);
      i++;
    }
  return (0);
}

t_cmds		*redir_error(t_cmds *cmd)
{
  fprintf(stderr, "Error %s: %s\n", cmd->next->cmd, strerror(errno));
  return (find_next_cmd(cmd));
}
