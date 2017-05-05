/*
** my_putstr_file.c for my_putstr_file in /home/ounajj_k/rendu/BACKUPASM/Write
** 
** Made by khamled
** Login   <ounajj_k@epitech.net>
** 
** Started on  Sun Apr 13 21:45:23 2014 khamled
** Last update Sun May 11 21:09:47 2014 moulin_c
*/

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

void	my_putchar_file(int d, int fd)
{
  write(fd, &d, 1);
}

int	my_putstr_file(char *str, int fd, int oct)
{
  int	i;

  i = oct - 1;
  while (i >= 0)
    {
      my_putchar_file(str[i], fd);
      i--;
    }
  return (0);
}
