/*
** func.c for my_mastermind in /home/sement_s/rendu/colle2_moulin_c/src
** 
** Made by Stephen SEMENT
** Login   <sement_s@epitech.net>
** 
** Started on  Mon May  5 19:34:02 2014 Stephen SEMENT
** Last update Mon May  5 20:10:00 2014 Stephen SEMENT
*/

#include	<stdlib.h>

void		my_putchar(char c)
{
  write(1, &c, 1);
}

int		my_strlen(char *str)
{
  int		i;

  i = 0;
  while(str[i] != '\0')
    i = i + 1;
  return (i);
}

void		my_putstr(char *str)
{
  if (str == NULL)
    write(1, "null", 4);
  else
    write(1, str, my_strlen(str));
}

int		my_strcmp(char *s1, char *s2)
{
  int		i;

  i = 0;
  while (s1[i] != '\0')
    {
      if (s1[i] != s2[i])
	return (-1);
      i = i + 1;
    }
  if (s2[i] == '\0')
    return (1);
  else
    return (-1);
}

int		my_exitstr(char *str, int i)
{
  if (str == NULL)
    write(1, "null", 4);
  else
    write(1, str, my_strlen(str));
  if (i <= 0)
    exit(EXIT_FAILURE);
  else
    exit(EXIT_SUCCESS);
}
