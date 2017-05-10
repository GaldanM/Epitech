/*
** sort_syntax.c for 42sh in /home/moulin_c/rendu/Semester 2/Modules/Unix/42sh/Parser
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Sat May 24 18:03:04 2014 moulin_c
** Last update Sun Jun  1 17:43:48 2014 moulin_c
*/

#include	"shell.h"

t_syntax	*find_good_redir(t_syntax *tmp)
{
  while (!tmp->root)
    {
      if (!my_strcmp(tmp->str, ">") || !my_strcmp(tmp->str, ">>") ||
	  !my_strcmp(tmp->str, "1>"))
	return (tmp);
      tmp = tmp->prev;
    }
  return (NULL);
}

t_syntax	*swap_redir(t_syntax *tmp)
{
  char		*s1;
  char		*s2;

  if (!tmp->next->next->root && !SEP(tmp->next->next->str, 0) &&
      !END(tmp->next->next->str, 0))
    {
      s1 = tmp->str;
      s2 = tmp->next->next->str;
      tmp->str = s2;
      tmp->next->next->str = s1;
      s1 = tmp->next->str;
      s2 = tmp->next->next->str;
      tmp->next->str = s2;
      tmp->next->next->str = s1;
      if (!tmp->next->next->root)
	tmp = tmp->next->next;
    }
  return (tmp);
}

t_syntax	*swap_both(t_syntax *tmp)
{
  char		*s1;
  char		*s2;
  t_syntax	*tmp2;

  s1 = tmp->str;
  if ((tmp2 = find_good_redir(tmp)))
    {
      s2 = tmp2->str;
      tmp2->str = s1;
      tmp->str = s2;
    }
  del_syntax(tmp);
  return (tmp);
}

void		sort_syntax(t_syntax *syntax)
{
  t_syntax	*tmp;

  tmp = syntax->next;
  while (!tmp->root)
    {
      if (!tmp->next->root && (tmp->str[0] == '>' || tmp->str[0] == '<'))
	tmp = swap_redir(tmp);
      else if (tmp->str && (!my_strcmp(tmp->str, "2>&1") ||
			    !my_strcmp(tmp->str, "1>&2")))
	tmp = swap_both(tmp);
      tmp = tmp->next;
    }
}
