/*
** my_echo_rest.c for my_echo_rest in /home/doghri_f/42sh/Builts
** 
** Made by doghri_f
** Login   <doghri_f@epitech.net>
** 
** Started on  Sun May 25 17:20:08 2014 doghri_f
** Last update Sun May 25 19:04:47 2014 doghri_f
*/

#include	<stdio.h>
#include	"shell.h"

int		check_echo_option(t_cmds *cmds)
{
  char		options[4];
  int		i;

  i = 0;
  options[0] = 'n';
  options[1] = 'e';
  options[2] = 'E';
  options[3] = '\0';
  if (cmds->next->args->next->arg == NULL)
    return (3);
  else
    {
      if (cmds->next->args->next->arg[0] == '-')
	{
	  while (options[i] && cmds->next->args->next->arg[1] != options[i])
	    i++;
	  if (options[i] == '\0')
	    return (-2);
	  else
	    return (i);
	}
    }
  return (-1);
}

int		noption(t_cmds *cmds)
{
  char		*str;

  str = cmds->next->args->next->next->arg;
  if (str)
    if (putstr_fd(str, cmds->next->fdout) == -1)
      return (-1);
  return (0);
}

int		eoption_rest(t_cmds *cmds, char *tmp)
{
  char		*str;
  int		i;

  i = 0;
  if ((str = my_strdup("abtnvfrce\\\0")) == NULL)
    return (-1);
  while (tmp[i])
    {
      if (tmp[i] == '\\')
	if ((i = put_backslash_char(cmds, tmp, i, str)) == -1)
	  return (-1);
      if (tmp[i])
	{
	  if (write_to_fd(tmp[i], cmds->next->fdout) == -1)
	    return (-1);
	  i++;
	}
    }
  return (0);
}

int		eoption(t_cmds *cmds)
{
  char		*tmp;
  tmp = cmds->next->args->next->next->arg;
  if (tmp)
    eoption_rest(cmds, tmp);
  else if (cmds->next->args->next->next->arg)
    if (write_to_fd('\n', cmds->next->fdout) == -1)
      return (-1);
  return (0);
}

int		beoption(t_cmds *cmds)
{
  char		*str;

  str = cmds->next->args->next->next->arg;
  if (str)
    {
      if (putstr_fd(str, cmds->next->fdout) == -1)
	return (-1);
    }
  else if (cmds->next->args->next->next->arg)
    if (write_to_fd('\n', cmds->next->fdout) == -1)
      return (-1);
  return (0);
}
