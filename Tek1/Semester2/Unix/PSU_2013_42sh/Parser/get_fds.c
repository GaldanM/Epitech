/*
** redir.c for 42 in /home/moulin_c/rendu/Semester 2/Modules/Unix/42sh/Minishell1/Parser
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Tue May 13 14:04:46 2014 moulin_c
** Last update Sun Jun  1 18:35:23 2014 doghri_f
*/

#include	<stdlib.h>
#include	<stdio.h>
#include	"shell.h"

t_cmds		*find_next_cmd(t_cmds *cmd)
{
  while (!cmd->root && cmd->separator && my_strcmp(cmd->separator, ";") &&
	 my_strcmp(cmd->separator, "||") && my_strcmp(cmd->separator, "&&"))
    {
      cmd = cmd->next;
      del_cmd(cmd->prev);
    }
  if (!cmd->root)
    {
      cmd = cmd->next;
      del_cmd(cmd->prev);
    }
  return (cmd);
}

t_cmds		*my_exec_func(int i, t_cmds *tmp)
{
  t_cmds	*(*tab[13])();

  tab[0] = my_pipe;
  tab[1] = my_redir_left;
  tab[2] = my_redir_right;
  tab[3] = my_redir_right;
  tab[4] = my_dbl_redir_left;
  tab[5] = my_dbl_redir_right;
  tab[6] = my_redir_err;
  tab[7] = my_redir_both;
  tab[8] = my_redir_both;
  tab[12] = NULL;
  if (i >= 9)
    {
      if (i == 12)
	tmp = find_next_cmd(tmp);
      else
	tmp = tmp->next;
      return (tmp);
    }
  if (tab[i] && (tmp = (*tab[i])(tmp)) == NULL)
    return (NULL);
  return (tmp);
}

void		tab_point(char *tab[15])
{
  tab[0] = my_strdup("|");
  tab[1] = my_strdup("<");
  tab[2] = my_strdup(">");
  tab[3] = my_strdup("1>");
  tab[4] = my_strdup("<<");
  tab[5] = my_strdup(">>");
  tab[6] = my_strdup("2>");
  tab[7] = my_strdup("2>&1");
  tab[8] = my_strdup("1>&2");
  tab[9] = my_strdup(";");
  tab[10] = my_strdup("||");
  tab[11] = my_strdup("&&");
  tab[12] = NULL;
}

t_cmds		*get_fds_exec(char **tab, t_cmds *tmp, int i)
{
  if (!tab[i] || tmp->cmd[0] == '\0' ||
      (i != 0 && i != 9 && tmp->next->root))
    {
      fprintf(stderr, "42sh: syntax error near unexpected token `newline'\n");
      tmp = find_next_cmd(tmp);
      return (tmp);
    }
  else if (tab[i] && !my_strcmp(tmp->separator, tab[i]))
    {
      if ((tmp = my_exec_func(i, tmp)) == NULL)
	return (NULL);
    }
  else if (!tab[i] && i != 12)
    {
      fprintf(stderr, "Strdup failed\n");
      return (NULL);
    }
  return (tmp);
}

int		get_fds(t_cmds *cmds)
{
  t_cmds	*tmp;
  int		i;
  char		(*tab[15]);

  i = 0;
  tmp = cmds->next;
  tab_point(tab);
  while (tab[i] && !tmp->root && tmp->separator)
    {
      i = 0;
      while (tab[i] && my_strcmp(tmp->separator, tab[i]) && !tmp->root)
  	i++;
      if ((tmp = get_fds_exec(tab, tmp, i)) == NULL)
	return (-1);
    }
  return (0);
}
