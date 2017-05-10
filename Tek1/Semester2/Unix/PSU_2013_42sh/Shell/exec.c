/*
** exec_loop.c for 42 in /home/moulin_c/rendu/Semester 2/Modules/Unix/42sh/Minishell1/Shell
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Wed May  7 14:35:01 2014 moulin_c
** Last update Sun Jun  1 16:57:36 2014 moulin_c
*/

#include	<dirent.h>
#include	<stdlib.h>
#include	<unistd.h>
#include	<sys/types.h>
#include	<sys/wait.h>
#include	"shell.h"

int		my_execve(char **tab, char **envp)
{
  char *cmd;

  cmd = tab[0];
  if (tab[0][0] != '/')
    if ((tab[0] = get_bin_path(tab[0], envp)) == NULL)
      exit(2);
  if (execve(tab[0], tab, envp) == -1)
    {
      if (tab[0][my_strlen(tab[0]) - 1] == '/')
	{
	  if (opendir(tab[0]) == NULL)
	    fprintf(stderr, "No such file or directory\n");
	  else
	    fprintf(stderr, "Is a directory\n");
	}
      else
	fprintf(stderr, "%s : command not found\n", cmd);
    }
  exit(2);
}

int		my_dups(t_cmds *cmd)
{
  if (cmd->fdin != 0)
    {
      if (dup2(cmd->fdin, 0) == -1)
	return (-1);
    }
  if (cmd->fdout != 1)
    {
      if (dup2(cmd->fdout, 1) == -1)
	return (-1);
    }
  if (cmd->fderr != 2)
    {
      if (dup2(cmd->fderr, 2) == -1)
	return (-1);
    }
  return (0);
}

int		my_closes(t_cmds *cmd)
{
  if (cmd->fdin != 0)
    {
      if (close(cmd->fdin) == -1)
	return (-1);
    }
  if (cmd->fdout != 1)
    {
      if (close(cmd->fdout) == -1)
	return (-1);
    }
  if (cmd->fderr != 2 && cmd->fderr != cmd->fdout)
    {
      if (close(cmd->fderr) == -1)
	return (-1);
    }
  return (0);
}

void		my_ret_exec(t_cmds *cmd, char *sep)
{
  t_cmds	*tmp;

  tmp = cmd;
  tmp->ret_exec = -1;
  if (!my_strcmp(sep, "&&"))
    {
      while (!tmp->root && !my_strcmp(tmp->separator, sep))
	{
	  tmp->ret_exec = -1;
	  tmp = tmp->next;
	}
      if (!tmp->root)
	tmp->ret_exec = -1;
    }
}

void		my_child(t_cmds *cmd, t_env *env)
{
  if (!cmd->next->root)
    {
      if (my_closes(cmd->next) == -1)
	exit(2);
    }
  if (my_dups(cmd) == -1)
    exit(2);
  if (my_check_builts(cmd) == -1)
    {
      my_execve(cmd_to_tab(cmd), env_to_tab(env));
      exit(2);
    }
  if (!my_strcmp(cmd->separator, "|") && check_exec(cmd))
    do_builts_child(cmd, &env);
  exit(0);
}
