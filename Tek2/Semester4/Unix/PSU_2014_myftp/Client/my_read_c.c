/*
** func_client.c for ftp in /home/moulin_c/rendu/PSU_2014_myftp
** 
** Made by Galdan Moulinneuf
** Login   <moulin_c@epitech.net>
** 
** Started on  Sun Mar 29 21:46:13 2015 Galdan Moulinneuf
** Last update Sun Mar 29 21:46:27 2015 Galdan Moulinneuf
*/

#include		<stdio.h>
#include		<unistd.h>
#include		<string.h>
#include		"get_next_line.h"
#include		"client.h"

void			xread(int fd, char buf[4096])
{
  int			nb;

  nb = 1;
  while (nb > 0)
    {
      if ((nb = read(fd, buf, 4096)) == -1)
	{
	  close(fd);
	}
      buf[nb] = 0;
      if (nb < 4096)
	nb = 0;
    }
}
