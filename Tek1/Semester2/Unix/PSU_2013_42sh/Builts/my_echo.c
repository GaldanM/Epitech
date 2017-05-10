/*
** my_echo.c for my_echo in /home/di-mam_a/rendu/420blazeit
** 
** Made by di-mam_a
** Login   <di-mam_a@epitech.net>
** 
** Started on  Fri May 16 18:52:16 2014 di-mam_a
** Last update Sun May 25 22:16:20 2014 doghri_f
*/

#include	<stdio.h>
#include	"shell.h"

int		put_backslash_char(t_cmds *cmd, char *towrite, int i, char *base)
{
  int		count;

  count = 0;
  while (base[count] && base[count] != towrite[i + 1])
    count++;
  if (count < 7)
    {
      if (write_to_fd(count + 7, cmd->next->fdout) == -1)
	return (-1);
    }
  else if (count == 7)
    return (-1);
  else if (count == 8)
    {
      if (write_to_fd(27, cmd->next->fdout) == -1)
	return (-1);
    }
  else if (count == 9)
    {
      if (write_to_fd('\\', cmd->next->fdout) == -1)
	return (-1);
    }
  else
    return (i);
  return (i + 2);
}

int		check_echo_args_option(t_cmds *cmds, int n)
{
  int		(*option[3])();

  if (n == -1 || n == -2)
    {
      if (putstr_fd(cmds->next->args->next->arg, cmds->next->fdout) == -1)
	return (-1);
    }
  else
    {
      option[0] = &noption;
      option[1] = &eoption;
      option[2] = &beoption;
      option[n](cmds);
    }
  if (check_echo_args_space(cmds) == -1)
    return (-1);
  return (0);
}

int		check_echo_args_space(t_cmds *cmds)
{
  if (cmds->next->args->next)
    {
      if (cmds->next->args->next->next->arg)
	if (write_to_fd(' ', cmds->next->fdout) == -1)
	  return (-1);
      cmds->next->args = cmds->next->args->next;
    }
  return (0);
}

int		check_echo_args(t_cmds *cmds)
{
  int		n;

  n = 3;
  while (cmds->next->args->next->arg)
    {
      if (!cmds->next->args->next->arg)
	if (write_to_fd('\n', cmds->next->fdout) == -1)
	  return (-1);
      if (n == 3)
	n = check_echo_option(cmds);
      if (check_echo_args_option(cmds, n) == -1)
	return (-1);
    }
  if (n != 0)
    if (write_to_fd('\n', cmds->next->fdout) == -1)
      return (-1);
  return (0);
}

int		my_echo(t_cmds *cmds)
{
  if (check_echo_args(cmds) == -1)
    return (-1);
  return (0);
}
