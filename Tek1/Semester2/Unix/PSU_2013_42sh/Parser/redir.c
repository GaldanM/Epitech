/*
** redir.c for 42 in /home/moulin_c/rendu/Semester 2/Modules/Unix/42sh/Minishell1/Parser
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Tue May 13 15:40:26 2014 moulin_c
** Last update Sun Jun  1 18:59:07 2014 doghri_f
*/

#include	<unistd.h>
#include	<stdlib.h>
#include	<sys/types.h>
#include	<sys/stat.h>
#include	<fcntl.h>
#include	<string.h>
#include	<errno.h>
#include	"shell.h"
#include	"get_next_line.h"

t_cmds		*my_redir_left(t_cmds *cmd)
{
  int		fd;
  mode_t	mode;

  mode = S_IWUSR | S_IRGRP | S_IRUSR | S_IROTH;
  if (!cmd->next->root)
    {
      if ((fd = open(cmd->next->cmd, O_RDWR | O_APPEND, mode)) == -1)
	return (redir_error(cmd));
      else
	{
	  cmd->fdin = fd;
	  if (cmd->next->separator)
	    {
	      if ((cmd->separator = my_strcpy(cmd->separator,
					      cmd->next->separator)) == NULL)
		return (NULL);
	    }
	  else
	    cmd->separator = NULL;
	  del_cmd(cmd->next);
	}
    }
  return (cmd);
}

t_cmds		*my_redir_right(t_cmds *cmd)
{
  int		fd;
  mode_t	mode;

  mode = S_IWUSR | S_IRGRP | S_IRUSR | S_IROTH;
  if (!cmd->next->root)
    {
      if ((fd = open(cmd->next->cmd, O_CREAT | O_RDWR | O_TRUNC, mode)) == -1)
	return (redir_error(cmd));
      if (cmd->fdout != 1)
	close(cmd->fdout);
      cmd->fdout = fd;
      if (cmd->next->separator)
	{
	  if ((cmd->separator = my_strcpy(cmd->separator,
					  cmd->next->separator)) == NULL)
	    return (NULL);
	}
      else
	cmd->separator = NULL;
      del_cmd(cmd->next);
    }
  return (cmd);
}

t_cmds		*my_dbl_left(t_cmds *cmd, int pipefd[2])
{
  cmd->fdin = pipefd[0];
  if (close(pipefd[1]) == -1)
    return (NULL);
  if (cmd->next->separator)
    {
      if ((cmd->separator = my_strcpy(cmd->separator,
				      cmd->next->separator)) == NULL)
	return (NULL);
    }
  else
    cmd->separator = NULL;
  del_cmd(cmd->next);
  return (cmd);
}

t_cmds		*my_dbl_redir_left(t_cmds *cmd)
{
  int		pipefd[2];
  char		*tmp;

  if (pipe(pipefd) == -1)
    {
      fprintf(stderr, "Error pipe : '%s'\n", strerror(errno));
      return (NULL);
    }
  if (check_bad(cmd->next->cmd) == -1)
    return (find_next_cmd(cmd));
  write(1, "> ", 2);
  while (my_strcmp((tmp = get_next_line(0)), cmd->next->cmd))
    {
      if (tmp == NULL)
      	{
      	  my_putchar('\n');
      	  return (NULL);
      	}
      tmp = check_syntax(tmp);
      write(pipefd[1], tmp, my_strlen(tmp));
      write(pipefd[1], "\n", 1);
      write(1, "> ", 2);
    }
  cmd = my_dbl_left(cmd, pipefd);
  return (cmd);
}

t_cmds		*my_dbl_redir_right(t_cmds *cmd)
{
  int		fd;
  mode_t	mode;

  mode = S_IWUSR | S_IRGRP | S_IRUSR | S_IROTH;
  if (!cmd->next->root)
    {
      if ((fd = open(cmd->next->cmd, O_CREAT | O_RDWR | O_APPEND, mode)) == -1)
	return (redir_error(cmd));
      if (cmd->fdout != 1)
	close(cmd->fdout);
      cmd->fdout = fd;
      if (cmd->next->separator)
	{
	  if ((cmd->separator = my_strcpy(cmd->separator,
					  cmd->next->separator)) == NULL)
	    return (NULL);
	}
      else
	cmd->separator = NULL;
      del_cmd(cmd->next);
    }
  return (cmd);
}
