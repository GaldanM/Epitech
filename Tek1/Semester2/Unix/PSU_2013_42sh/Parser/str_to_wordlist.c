/*
** str_to_wordlist.c for 42 in /home/moulin_c/rendu/Semester 2/Modules/Unix/42sh 2.2
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Sun Jun  1 17:11:01 2014 moulin_c
** Last update Sun Jun  1 17:11:26 2014 moulin_c
*/

#include	"shell.h"

int		str_to_wordlist(t_cmds *cmds, char *line, t_env *env)
{
  int		i;

  i = 0;
  while (line[i])
    {
      if ((i = recup_cmd(cmds, line, i)) == -1)
	return (-1);
      if ((i = recup_args(cmds, line, i)) == -1)
	return (-1);
      replace_env(cmds, env);
      if ((i = recup_separ(cmds, line, i)) == -1)
	return (-1);
    }
  return (0);
}
