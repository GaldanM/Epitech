/*
** displays.c for 42 in /home/moulin_c/rendu/Semester 2/Modules/Unix/42sh/Minishell1
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Tue May 13 18:45:28 2014 moulin_c
** Last update Sun Jun  1 17:46:20 2014 moulin_c
*/

#include	"shell.h"

void		disp_cmds(t_cmds *cmds)
{
  t_cmds	*tmp;
  t_args	*tmp2;
  int		i;
  int		j;

  tmp = cmds->next;
  i = 1;
  while (!tmp->root)
    {
      printf("Cmd[%d] = '%s'\tin = %d\tout = %d\err = %d\tsep = '%s'\n",
	     i, tmp->cmd, tmp->fdin, tmp->fdout, tmp->fderr, tmp->separator);
      tmp2 = tmp->args->next;
      j = 1;
      while (!tmp2->root)
	{
	  printf("\tArg[%d] = '%s'\n", j, tmp2->arg);
	  tmp2 = tmp2->next;
	  j++;
	}
      tmp = tmp->next;
      i++;
    }
}
