/*
** func.c for chiffres in /home/sement_s/rendu/colle4_moulin_c_S4gR1/src
** 
** Made by Stephen SEMENT
** Login   <sement_s@epitech.net>
** 
** Started on  Mon May 19 19:40:34 2014 Stephen SEMENT
** Last update Mon May 19 19:52:20 2014 Stephen SEMENT
*/

#include	<stdlib.h>

int		my_putchar(char c)
{
  if (write(1, &c, 1) == -1)
    exit(EXIT_FAILURE);
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
  if (str[0] == '\0')
    {
      if (write(1, "null", 4) == -1)
	exit(EXIT_FAILURE);
    }
    else
      {
	if (write(1, str, my_strlen(str)) == -1)
	  exit(EXIT_FAILURE);
      }
  return (0);
}

void		my_exitstr(char *str, int ex)
{
  my_putstr(str);
  if (ex < 0)
    exit(EXIT_FAILURE);
  else
    exit(EXIT_SUCCESS);
}
