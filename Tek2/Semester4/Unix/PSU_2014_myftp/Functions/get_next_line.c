/*
** get_next_line.c for ftp in /home/moulin_c/rendu/PSU_2014_myftp/Functions
** 
** Made by Galdan Moulinneuf
** Login   <moulin_c@epitech.net>
** 
** Started on  Sun Mar 29 21:25:54 2015 Galdan Moulinneuf
** Last update Sun Mar 29 21:26:34 2015 Galdan Moulinneuf
*/

#include	<unistd.h>
#include	<stdlib.h>
#include	"get_next_line.h"

char		*concat_str(char *s1, char *s2)
{
  int		i;
  int		j;
  int		len;
  char		*str;

  if (s2 == NULL)
    len = strlen(s1);
  else
    len = strlen(s1) + strlen(s2);
  if ((str = malloc(sizeof(char) * len + 1)) == NULL)
    return (str);
  j = 0;
  i = 0;
  while (s1[i])
    str[j++] = s1[i++];
  i = 0;
  if (s2 != NULL)
    {
      while (s2[i])
	str[j++] = s2[i++];
      free(s2);
    }
  str[j] = 0;
  return (str);
}

char		*make_save(char *buff, int ret, int i)
{
  int		j;
  char		*rest;

  if ((rest = malloc(sizeof(char) * (ret - i + 1))) == NULL)
    return (NULL);
  j = 0;
  while (i < ret)
    {
      rest[j++] = buff[i];
      buff[i++] = 0;
    }
  rest[j] = 0;
  return (rest);
}

char		*clean_buff(char *buff, int ret)
{
  int		i;

  i = 0;
  while (i < ret)
    {
      if (buff[i] == '\n')
	{
	  buff[i++] = 0;
	  if (i < ret)
	    return (make_save(buff, ret, i));
	}
      i++;
    }
  buff[ret] = 0;
  return (NULL);
}

int		my_read(char *buff, char *rest, int fd)
{
  int		i;
  int		ret;
  int		save;
  char		tmp[B_SIZE + 1];

  i = 0;
  while (rest[i] && i < B_SIZE)
    {
      buff[i] = rest[i];
      i++;
    }
  buff[i] = 0;
  if (rest[i] == 0)
    free(rest);
  save = i;
  if (i < B_SIZE)
    {
      if ((ret = read(fd, tmp, B_SIZE - i)) == -1)
	return (-1);
      tmp[ret] = 0;
      ret = 0;
      while (tmp[ret])
	buff[i++] = tmp[ret++];
    }
  return (ret + save);
}

char		*get_next_line(int fd)
{
  int		ret;
  char		buff[B_SIZE + 1];
  static char	*rest;

  write(1, "$> ", 3);
  if (rest != NULL)
    {
      if ((ret = my_read(buff, rest, fd)) == -1)
	return (NULL);
    }
  else
    if ((ret = read(fd, buff, B_SIZE)) == -1)
      return (NULL);
  if (ret == 0)
    return (NULL);
  rest = clean_buff(buff, ret);
  if (ret == B_SIZE && buff[ret - 1] != 0 && rest == NULL)
    return (concat_str(buff, get_next_line(fd)));
  return (concat_str(buff, NULL));
}
