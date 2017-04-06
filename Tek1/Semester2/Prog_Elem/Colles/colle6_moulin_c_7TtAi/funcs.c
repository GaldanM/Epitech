/*
** funcs.c for my_boogle in /home/sement_s/rendu/colle6_moulin_c_7TtAi
** 
** Made by Stephen SEMENT
** Login   <sement_s@epitech.net>
** 
** Started on  Mon Jun  2 19:49:24 2014 Stephen SEMENT
** Last update Mon Jun  2 20:08:42 2014 Stephen SEMENT
*/

#include	<stdlib.h>
#include	<unistd.h>

int		my_putchar(char c)
{
  if (write(1, &c, 1) == -1)
    return (-1);
  return (0);
}

int		my_strlen(char *str)
{
  int		i;

  i = 0;
  while (str[i] != '\0')
    i = i + 1;
  return (i);
}

int		my_putstr(char *str)
{
  if (str == NULL || str[0] == '\0')
    {
      if (write(1, "null", 4) == -1)
	return (-1);
    }
  else
    {
      if (write(1, str, my_strlen(str)) == -1)
	return (-1);
    }
  return (0);
}

int		my_strcmp(char *s1, char *s2)
{
  int		i;

  i = 0;
  while (s1[i] != '\0' || s2[i] != '\0')
    {
      if (s1[i] != s2[i])
	return (-1);
      i = i + 1;
    }
  if (s1[i] == '\0' && s2[i] == '\0')
    return (0);
  return (-1);
}
