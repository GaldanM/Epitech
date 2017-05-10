/*
** check_exec.c for 42sh in /home/moulin_c/rendu/Semester 2/Modules/Unix/42sh
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Sun May 25 01:06:13 2014 moulin_c
** Last update Sun Jun  1 17:09:12 2014 moulin_c
*/

#include	<dirent.h>
#include	<stdlib.h>
#include	<unistd.h>
#include	<sys/types.h>
#include	<sys/wait.h>
#include	"shell.h"

t_cmds		*find_next_cmd_exec(t_cmds *cmd)
{
  while (!cmd->root && cmd->separator && my_strcmp(cmd->separator, ";") &&
	 my_strcmp(cmd->separator, "||") && my_strcmp(cmd->separator, "&&"))
    cmd = cmd->next;
  if (!cmd->root)
    cmd = cmd->next;
  return (cmd);
}

int		check_exec(t_cmds *cmd)
{
  if (cmd->prev->root)
    return (1);
  if (cmd->prev->ret_exec == 0)
    {
      if (!my_strcmp(cmd->prev->separator, "&&"))
	return (1);
      else if (!my_strcmp(cmd->prev->separator, "||"))
	return (0);
    }
  else
    {
      if (!my_strcmp(cmd->prev->separator, "&&"))
	return (0);
      else if (!my_strcmp(cmd->prev->separator, "||"))
	return (1);
    }
  return (1);
}

int		my_father(t_cmds *cmd, t_env *env, pid_t ret)
{
  int		status;

  if (my_strcmp(cmd->separator, "|") && check_exec(cmd))
    cmd = do_builts_father(cmd, &env);
  if (my_closes(cmd) == -1)
    return (-1);
  if (!cmd->next->root && !my_strcmp(cmd->separator, "|")
      && check_exec(cmd->next) == 1)
    {
      if (my_exec(cmd->next, env) == -1)
	return (-1);
    }
  if (waitpid(ret, &status, 0))
    if (WIFSIGNALED(status))
      gere_sig_shell(status);
  if (WEXITSTATUS(status) == 2)
    my_ret_exec(cmd, cmd->separator);
  return (0);
}

int		my_exec(t_cmds *cmd, t_env *env)
{
  pid_t		ret;

  if ((ret = fork()) == -1)
    return (-1);
  setsid();
  if (ret == 0)
    my_child(cmd, env);
  else if (ret > 0)
    if (my_father(cmd, env, ret) == -1)
      return (0);
  return (0);
}
