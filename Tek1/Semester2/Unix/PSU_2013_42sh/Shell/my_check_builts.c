/*
** my_check_builts.c for check_builts in /home/doghri_f/rendu/BACKUP_42/42sh/Shell
** 
** Made by doghri_f
** Login   <doghri_f@epitech.net>
** 
** Started on  Sat May 24 17:17:17 2014 doghri_f
** Last update Fri May 30 17:35:51 2014 moulin_c
*/

#include	<unistd.h>
#include	<stdlib.h>
#include	"shell.h"

void		do_builts_child(t_cmds *cmd, t_env **env)
{
  int		ret;

  ret = 0;
  if (!my_strcmp(cmd->cmd, "setenv"))
    ret = my_setenv(env, cmd->prev);
  else if (!my_strcmp(cmd->cmd, "env"))
    ret = my_env(env, cmd->prev);
  else if (!my_strcmp(cmd->cmd, "cd"))
    ret = my_cd(env, cmd->prev);
  else if (!my_strcmp(cmd->cmd, "unsetenv"))
    ret = my_unsetenv(env, cmd->prev);
  else if (!my_strcmp(cmd->cmd, "echo"))
    ret = my_echo(cmd->prev);
  if (ret == -1)
    exit(2);
}

t_cmds		*do_builts_father(t_cmds *cmd, t_env **env)
{
  int		ret;

  ret = 0;
  if (!my_strcmp(cmd->cmd, "setenv"))
    ret = my_setenv(env, cmd->prev);
  else if (!my_strcmp(cmd->cmd, "env"))
    ret = my_env(env, cmd->prev);
  else if (!my_strcmp(cmd->cmd, "cd"))
    ret = my_cd(env, cmd->prev);
  else if (!my_strcmp(cmd->cmd, "unsetenv"))
    ret = my_unsetenv(env, cmd->prev);
  else if (!my_strcmp(cmd->cmd, "echo"))
    ret = my_echo(cmd->prev);
  if (ret == -1)
    cmd->ret_exec = -1;
  return (cmd);
}

  int		my_check_builts(t_cmds *cmd)
  {
    if (my_strcmp(cmd->cmd, "env") == 0)
      return (0);
    else if (my_strcmp(cmd->cmd, "setenv") == 0)
      return (0);
    else if (my_strcmp(cmd->cmd, "cd") == 0)
      return (0);
    else if (my_strcmp(cmd->cmd, "unsetenv") == 0)
      return (0);
    else if (my_strcmp(cmd->cmd, "echo") == 0)
      return (0);
    else
      return (-1);
    return (0);
  }
