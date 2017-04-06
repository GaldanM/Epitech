/*
** foncs.c for Morse in /home/moulin_c/rendu/CPE_2013_Rush1
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Sat Dec 14 02:05:00 2013 moulin_c
** Last update Sun Dec 15 21:08:02 2013 moulin_c
*/

#include "morse.h"

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    i++;
  return (i);
}

char    *my_strcpy(char *dest, char *src)
{
  int	a;

  a = 0;
  if ((dest = malloc(sizeof(char) * (my_strlen(src) + 1))) == NULL)
    return (NULL);
  while (src[a] != '\0')
    {
      dest[a] = src[a];
      a++;
    }
  dest[a] = '\0';
  return (dest);
}

void	my_putchar(char d)
{
  write(1, &d, 1);
}

void	my_putstr(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    my_putchar(str[i++]);
}
