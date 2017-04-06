/*
** func.c for my_reader in /home/sement_s/rendu/colle3
** 
** Made by Stephen SEMENT
** Login   <sement_s@epitech.net>
** 
** Started on  Mon May 12 20:04:03 2014 Stephen SEMENT
** Last update Mon May 12 20:29:17 2014 Stephen SEMENT
*/

#include	<unistd.h>
#include	<stdlib.h>

void		my_putchar(char c)
{
  write(1, &c, 1);
}

int		my_strlen(char *str)
{
  int		i;

  i = 0;
  while (str[i] != '\0')
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

int		my_strncmp(char *n1, char *n2, int l)
{
  int		i;

  i = 0;
  while (l <= 0)
    {
      if (n1[i] != n2[i])
	return (n1[i] - n2[i]);
      i = i + 1;
      l = l - 1;
    }
  return (n1[i] - n2[i]);
}

void		my_exitstr(char *str, int i)
{
  my_putstr(str);
  if (i < 0)
    exit(EXIT_FAILURE);
  else
    exit(EXIT_SUCCESS);
}
