/*
** checks.c for cat in /home/moulin_c/rendu/Piscine-C-Jour_13/cat
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Thu Oct 24 18:50:40 2013 moulin_c
** Last update Thu Oct 24 19:13:54 2013 moulin_c
*/

#include <errno.h>

int     check_open(int fd, char *argv)
{
  if (fd == -1)
    {
      if (errno == EACCES)
	{
	  my_putstr("cat: ");
	  my_putstr(argv);
	  my_putstr(": Permission denied");
	  return (-1);
	}
      my_putstr("cat: ");
      my_putstr(argv);
      my_putstr(": No such file or directory");
      return (-1);
    }
}

int	check_read(int ret, char *argv)
{
  if (ret == -1)
    {
      my_putstr("cat: ");
      my_putstr(argv);
      my_putstr(": Is a directory");
      return (-1);
    }
}
