/*
** foncs_get_cmds.c for 42 in /home/moulin_c/rendu/Semester 2/Modules/Unix/42sh
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Tue May 20 16:21:24 2014 moulin_c
** Last update Sun Jun  1 17:11:28 2014 moulin_c
*/

#include	<stdlib.h>
#include	<string.h>
#include	"shell.h"
#include	"get_next_line.h"

char		*change_var(char *src, t_env *env)
{
  char		*ret;
  t_env		*tmp;

  tmp = env->next;
  while (!tmp->root)
    {
      if (!my_strcmp(src + 1, tmp->name))
	{
	  if ((ret = my_strdup(tmp->var)) == NULL)
	    return (NULL);
	  return (ret);
	}
      tmp = tmp->next;
    }
  return (NULL);
}

void		replace_arg(t_args *tmp2, t_env *env)
{
  while (!tmp2->root)
    {
      if (tmp2->arg[0] == '$')
	if ((tmp2->arg = change_var(tmp2->arg, env)) == NULL)
	  {
	    tmp2 = tmp2->next;
	    del_arg(tmp2->prev);
	  }
      tmp2 = tmp2->next;
    }
}
void		replace_env(t_cmds *cmds, t_env *env)
{
  t_cmds	*tmp;

  tmp = cmds->next;
  while (!tmp->root)
    {
      if (tmp->cmd[0] == '$')
	if ((tmp->cmd = change_var(tmp->cmd, env)) == NULL)
	  {
	    tmp = tmp->next;
	    del_cmd(tmp->prev);
	  }
      if (tmp->args)
	replace_arg(tmp->args->next, env);
      tmp = tmp->next;
    }
}

int		check_pipe(char *str)
{
  int		i;

  i = 0;
  while (str[i])
    {
      if (str[i] == '|' && str[i + 1] == '|')
	i = i + 2;
      else if (str[i] == '|' && str[i + 1] == '\0' && i != 0)
	return (1);
      else
	i++;
    }
  return (0);
}

char		*complete_pipe(char *str)
{
  char		*n_str;

  my_putstr("> ");
  if ((n_str = get_next_line(0)) == NULL)
    {
      my_putchar('\n');
      return (NULL);
    }
  n_str = check_syntax(n_str);
  if ((n_str = my_strcat(str, n_str)) == NULL)
    return (NULL);
  return (n_str);
}
