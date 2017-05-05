/*
** func_common.c for ftp in /home/moulin_c/rendu/PSU_2014_myftp/Functions
** 
** Made by Galdan Moulinneuf
** Login   <moulin_c@epitech.net>
** 
** Started on  Sun Mar 29 21:38:31 2015 Galdan Moulinneuf
** Last update Sun Mar 29 21:39:23 2015 Galdan Moulinneuf
*/

#include	<stdlib.h>
#include	<string.h>
#include	<stdio.h>
#include	<sys/stat.h>
#include	"server.h"

char		*get_fname(char *str)
{
  int		i;
  int		nb;
  char		*file_name;
  int		j;

  nb = 0;
  i = strlen(str);
  while (i > 0 && str[i] != '/')
    {
      nb++;
      i--;
    }
  file_name = malloc(sizeof(char) * nb + 1);
  j = 0;
  while (str[i])
    {
      if (str[i] != '/')
	{
          file_name[j] = str[i];
          j++;
        }
      i++;
    }
  file_name[j] = 0;
  return (file_name);
}

int		check_file(char *str)
{
  struct stat	buf;

  if (stat(str, &buf) == -1)
      return (-1);
  if (S_ISREG(buf.st_mode) != 0)
    return (1);
  return (-1);
}
