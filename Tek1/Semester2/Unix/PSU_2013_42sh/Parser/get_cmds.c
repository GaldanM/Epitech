/*
** str_to_wordlist.c for 42 in /home/moulin_c/rendu/Semester 2/Modules/Unix/42sh/Minishell1
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Wed May  7 13:14:52 2014 moulin_c
** Last update Sun Jun  1 18:35:15 2014 doghri_f
*/

#include	<stdlib.h>
#include	<string.h>
#include	"shell.h"
#include	"get_next_line.h"

int		malloc_carg(char *line, int i, int flag)
{
  int		nb;

  nb = 0;
  if (flag == 1)
    {
      while (line[i] && !SPACES(line[i]) && !SEP(line, i)
	     && !END(line, i))
	{
	  i++;
	  nb++;
	}
    }
  else
    {
      while (line[i] && !SPACES(line[i]) && !SEP(line, i)
	     && !END(line, i) && line[i] != '-')
	{
	  i++;
	  nb++;
	}
    }
  return (nb);
}

int		recup_cmd(t_cmds *cmds, char *line, int i)
{
  int		j;
  char		*cmd;

  j = 0;
  if ((cmd = malloc(sizeof(char) * (malloc_carg(line, i, 2) + 1))) == NULL)
    return (-1);
  while (line[i] && !SPACES(line[i]) &&
	 !SEP(line, i) && !END(line, i) && line[i] != '-')
    cmd[j++] = line[i++];
  cmd[j] = '\0';
  if (add_cmd(&cmds, cmd) == -1)
    return (-1);
  while (line[i] && SPACES(line[i]))
    i++;
  return (i);
}

int		recup_args(t_cmds *cmds, char *line, int i)
{
  int		j;
  char		*arg;
  t_args	*args;

  if ((args = make_args()) == NULL)
    return (-1);
  while (line[i] && !SEP(line, i) && !END(line, i))
    {
      if ((arg = malloc(sizeof(char) * (malloc_carg(line, i, 1) + 1))) == NULL)
	return (-1);
      j = 0;
      while (line[i] && !SPACES(line[i]) && !SEP(line, i) && !END(line, i))
	arg[j++] = line[i++];
      arg[j] = '\0';
      if (add_arg(&args, arg) == -1)
	return (-1);
      while (line[i] && SPACES(line[i]))
	i++;
    }
  cmds->prev->args = args;
  return (i);
}

int		recup_separ(t_cmds *cmds, char *line, int i)
{
  int		j;
  int		save;
  char		*separ;

  save = i;
  while (line[i] && ((SEP(line, i) || END(line, i)) || SPACES(line[i])))
    i++;
  if ((separ = malloc(sizeof(char) * i - save + 1)) == NULL)
    return (-1);
  i = save;
  j = 0;
  while (line[i] && ((SEP(line, i) || END(line, i)) || SPACES(line[i])))
    separ[j++] = line[i++];
  separ[j] = '\0';
  if (j == 0)
    cmds->prev->separator = NULL;
  else
    if ((cmds->prev->separator = epur_str(separ)) == NULL)
      return (-1);
  return (i);
}

int		get_cmds(t_cmds *cmds, t_env *env)
{
  char		*line;

  if ((line = get_next_line(0)) == NULL)
    {
      my_putchar('\n');
      return (-1);
    }
  if (line[0])
    {
      if ((line = epur_str(line)) == NULL)
	return (-1);
      if ((line = check_syntax(line)) == NULL)
	return (-1);
      while (check_pipe(line))
	if ((line = complete_pipe(line)) == NULL)
	  return (-1);
      if (str_to_wordlist(cmds, line, env) == -1)
	return (-1);
    }
  return (0);
}
