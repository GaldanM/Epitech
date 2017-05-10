/*
** syntax_invers.c for 42sh in /home/moulin_c/rendu/Semester 2/Modules/Unix/42sh/Parser
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Fri May 23 12:38:48 2014 moulin_c
** Last update Sat May 31 16:33:12 2014 moulin_c
*/

#include	<stdlib.h>
#include	"shell.h"

char		*concat_syntax(t_syntax *syntax)
{
  char		*line;
  t_syntax	*tmp;

  tmp = syntax->next;
  if ((line = malloc(sizeof(char) * 200)) == NULL)
    return (NULL);
  line[0] = '\0';
  while (!tmp->root)
    {
      if ((line = my_strcat(line, tmp->str)) == NULL)
      	return (NULL);
      if (!tmp->next->root)
      	if ((line = my_strcat(line, " ")) == NULL)
      	  return (NULL);
      tmp = tmp->next;
    }
  return (line);
}

char		*check_syntax(char *line)
{
  t_syntax	*syntax;
  char		*new;

  if ((syntax = make_syntax()) == NULL)
    return (NULL);
  if (str_to_syntaxlist(syntax, line) == -1)
    return (NULL);
  sort_syntax(syntax);
  if ((new = concat_syntax(syntax)) == NULL)
    return (NULL);
  return (new);
}
