/*
** get_next_line.c for getnextline in /home/moulin_c/rendu/Modules/C_Prog_Elem/GetNextLine/CPE_2013_getnextline
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Sun Nov 24 18:46:42 2013 moulin_c
** Last update Sat Jan  4 13:02:25 2014 moulin_c
*/

#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"
#include "my.h"

char		*my_realloc(char *str)
{
  char		*dest;
  int		i;

  i = 0;
  while (str[i])
    i++;
  dest = NULL;
  if ((dest = malloc(sizeof(char) * ((BUFFER + 1) + i))) == NULL)
    return (NULL);
  dest[BUFFER + i] = '\0';
  my_strcpy(dest, str);
  free(str);
  return (dest);
}

int		buff_read(const int *fd, char *buffer, int *ret_read, int *i)
{
  if (!buffer[*i])
    {
      *i = 0;
      if ((*ret_read = read(*fd, buffer, BUFFER)) < 0)
        return (-1);
      buffer[*ret_read] = '\0';
    }
  return (0);
}

char		*get_next_line(const int fd)
{
  static char	buffer[BUFFER + 1];
  static int	i = 0;
  t_line	line;

  if ((line.str = malloc(BUFFER + 1 *  sizeof(char))) == NULL)
    return (NULL);
  line.str[BUFFER] = '\0';
  line.j = 0;
  line.ret_read = 1;
  if (!i)
    buffer[i] = '\0';
  while (line.ret_read && buffer[i] != '\n')
    {
      if (((buff_read(&fd, buffer, &line.ret_read, &i)) == -1) ||
	  ((line.str = my_realloc(line.str)) == NULL))
        return (NULL);
      while (buffer[i] != '\n' && buffer[i])
        line.str[line.j++] = buffer[i++];
    }
  line.str[line.j] = '\0';
  if (buffer[i] == '\n')
    i++;
  if (!line.ret_read && !line.str[line.j - 1] && !line.str[line.j])
    return (NULL);
  return (line.str);
}
