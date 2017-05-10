/*
** str_to_syntaxlist.c for 42sh in /home/moulin_c/rendu/Semester 2/Modules/Unix/42sh/Parser
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Sat May 24 13:34:09 2014 moulin_c
** Last update Sun Jun  1 18:37:02 2014 doghri_f
*/

#include	<stdlib.h>
#include	"shell.h"

static int	get_cmd(t_syntax *syntax, char *line, int i)
{
  char		*str;
  int		j;

  j = 0;
  if ((str = malloc(sizeof(char) * (my_strlen(line) + 5))) == NULL)
    return (-1);
  while (line[i] && (!SEP(line, i) && !END(line, i)))
    {
      if (line[i] == ' ' && (SEP(line, i + 1) || END(line, i + 1)))
	i++;
      else
	str[j++] = line[i++];
    }
  str[j] = '\0';
  if (str[0])
    {
      if ((str = epur_str(str)) == NULL)
	return (-1);
      if (add_syntax(&syntax, str) == -1)
	return (-1);
    }
  return (i);
}

static int	get_sep(t_syntax *syntax, char *line, int i)
{
  char		*str;
  int		j;

  j = 0;
  if ((str = malloc(sizeof(char) * (my_strlen(line) + 5))) == NULL)
    return (-1);
  while (line[i] && SEP(line, i))
    str[j++] = line[i++];
  str[j] = '\0';
  if (!str[0])
    {
      while (line[i] &&  END(line, i))
	str[j++] = line[i++];
    }
  str[j] = '\0';
  if (str[0])
    {
      if (add_syntax(&syntax, str) == -1)
	return (-1);
    }
  while (SPACES(line[i]))
    i++;
  return (i);
}

static int	get_file(t_syntax *syntax, char *line, int i)
{
  char		*str;
  int		j;

  j = 0;
  if ((str = malloc(sizeof(char) * (my_strlen(line) + 5))) == NULL)
    return (-1);
  while (line[i] && !SPACES(line[i]) && (!SEP(line, i) && !END(line, i)))
    str[j++] = line[i++];
  str[j] = '\0';
  if (str[0])
    {
      if (add_syntax(&syntax, str) == -1)
	return (-1);
    }
  while (SPACES(line[i]))
    i++;
  return (i);
}

static int	get_arg(t_syntax *syntax, char *line, int i)
{
  char		*str;
  int		j;

  j = 0;
  if ((str = malloc(sizeof(char) * (my_strlen(line) + 5))) == NULL)
    return (-1);
  while (line[i] && (!SEP(line, i) && !END(line, i)))
    str[j++] = line[i++];
  str[j] = '\0';
  if ((str = epur_str(str)) == NULL)
    return (-1);
  if (str[0])
    {
      if (add_syntax(&syntax, str) == -1)
	return (-1);
    }
  if (line[i] && line[i + 1] && !SEP(line, i) && !END(line, i))
    i++;
  return (i);
}

int		str_to_syntaxlist(t_syntax *syntax, char *line)
{
  int		i;

  i = 0;
  while (line[i])
    {
      if ((i = get_cmd(syntax, line, i)) == -1)
	return (-1);
      if ((i = get_sep(syntax, line, i)) == -1)
	return (-1);
      if (syntax->prev->str[0] == '>' || syntax->prev->str[0] == '<')
	{
	  if ((i = get_file(syntax, line, i)) == -1)
	    return (-1);
	  if (line[i] && (!SEP(line, i) && !END(line, i)))
	    if ((i = get_arg(syntax, line, i)) == -1)
	      return (-1);
	}
    }
  return (0);
}
