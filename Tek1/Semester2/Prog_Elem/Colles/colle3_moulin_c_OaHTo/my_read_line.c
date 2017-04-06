/*
** get_next_line.c for get_next_line in /home/sement_s/rendu/colle3
** 
** Made by Stephen SEMENT
** Login   <sement_s@epitech.net>
** 
** Started on  Mon May 12 19:07:32 2014 Stephen SEMENT
** Last update Mon May 12 20:23:42 2014 Stephen SEMENT
*/

#include	<unistd.h>
#include	<stdlib.h>

#define		BUFF_SIZE 8192

char		*my_buff_line(char *save, char *buffer, int line)
{
  int		i;
  int		i2;
  int		first;

  i = 0;
  i2 = 0;
  first = 0;
  while (buffer[i] != '\0' && line != 0)
    {
      i = i + 1;
      if (buffer[i] == '\n')
	line = line - 1;
      first = 1;
    }
  if (first == 1)
    i = i + 1;
  while (buffer[i] != '\n' && buffer[i] != '\0')
    {
      save[i2] = buffer[i];
      i = i + 1;
      i2 = i2 + 1;
    }
  return (save);
}

int		count_line_char(char *buffer, int line)
{
  int		i;
  int		nb;

  nb = 0;
  i = 0;
  while (buffer[i] != '\0' && line != 0)
    {
      i = i + 1;
      if (buffer[i] == '\n')
	line = line - 1;
    }
  if (buffer[i] == '\0')
    return (0);
  i = i + 1;
  while (buffer[i] != '\n' && buffer[i] != '\0')
    {
      i = i + 1;
      nb = nb + 1;
    }
  return (nb);
}

char		*my_read_line(int fd)
{
  static char	buffer[BUFF_SIZE];
  static int	line;
  int		i;
  char		*save;

  if (line == 0)
    {
      if ((read(fd, buffer, BUFF_SIZE)) == -1)
	my_exitstr("Can't read the file, program must close.\n", -1);
    }
  i = count_line_char(buffer, line);
  if (i == 0)
    return (NULL);
  if ((save = malloc(sizeof(char) * i)) == NULL)
    my_exitstr("Malloc error, program must close.\n", -1);
  save = my_buff_line(save, buffer, line);
  line = line + 1;
  return (save);
}
