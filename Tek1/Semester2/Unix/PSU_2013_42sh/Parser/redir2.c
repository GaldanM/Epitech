/*
** redir2.c for 42 in /home/moulin_c/rendu/Semester 2/Modules/Unix/42sh
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Sat May 17 14:21:19 2014 moulin_c
** Last update Sat May 31 15:42:29 2014 moulin_c
*/

#include	<unistd.h>
#include	<stdlib.h>
#include	<sys/types.h>
#include	<sys/stat.h>
#include	<fcntl.h>
#include	"shell.h"

t_cmds		*my_redir_err(t_cmds *cmd)
{
  int		fd;
  mode_t	mode;

  mode = S_IWUSR | S_IRGRP | S_IRUSR | S_IROTH;
  if (!cmd->next->root)
    {
      if ((fd = open(cmd->next->cmd, O_CREAT | O_RDWR | O_TRUNC, mode)) == -1)
	return (NULL);
      cmd->fderr = fd;
      cmd->separator = my_strcpy(cmd->separator, cmd->next->separator);
      del_cmd(cmd->next);
    }
  return (cmd);
}

t_cmds		*my_redir_both(t_cmds *cmd)
{
  int		fd;
  mode_t	mode;

  mode = S_IWUSR | S_IRGRP | S_IRUSR | S_IROTH;
  if (!cmd->next->root)
    {
      if ((fd = open(cmd->next->cmd, O_CREAT | O_RDWR | O_TRUNC, mode)) == -1)
	return (NULL);
      cmd->fderr = fd;
      cmd->fdout = fd;
      cmd->separator = my_strcpy(cmd->separator, cmd->next->separator);
      del_cmd(cmd->next);
    }
  return (cmd);
}
