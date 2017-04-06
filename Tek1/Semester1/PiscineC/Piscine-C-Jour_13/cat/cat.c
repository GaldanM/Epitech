/*
** cat.c for cat in /home/moulin_c/rendu/Piscine-C-Jour_13/cat
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Thu Oct 24 15:09:37 2013 moulin_c
** Last update Thu Oct 24 19:26:59 2013 moulin_c
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

void	no_arg(char buffer[])
{
  int	ret;
  int	i;
  
  i = 0;
  while (1)
    {
      ret = read(0, buffer, 30720);
      my_putstr_mod(buffer, ret);
    }
}

int	arg(char buffer[],char **argv, int argc)
{
  int	ret;
  int	fd;
  int	i;
  int	k;

  i = 1;
  while(i != argc)
    {
      fd = open(argv[i], O_RDONLY);
      ret = check_open(fd, argv[i]);
      if (ret == -1)
	return (-1);
      ret = read(fd, buffer, 30720);
      k = check_read(ret, argv[i]);
      if (k == -1)
	return (-1);
      my_putstr_mod(buffer, ret);
      close(fd);
      i = i + 1;
    }
}
