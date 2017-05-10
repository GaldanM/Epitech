/*
** write_to_fd.c for 42 in /home/moulin_c/rendu/Semester 2/Modules/Unix/42sh
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Sun May 25 07:46:01 2014 moulin_c
** Last update Sun May 25 09:21:17 2014 moulin_c
*/

#include	<unistd.h>
#include        "my.h"

int		putstr_fd(char *str, int fd)
{
  if (write(fd, str, my_strlen(str)) == -1)
    return (-1);
  return (0);
}

int		write_to_fd(char c, int fd)
{
  if (write(fd, &c, 1) == -1)
    return (-1);
  return (0);
}
