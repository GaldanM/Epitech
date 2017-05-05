/*
** pingpong.c for ftp in /home/moulin_c/rendu/PSU_2014_myftp/Functions
** 
** Made by Galdan Moulinneuf
** Login   <moulin_c@epitech.net>
** 
** Started on  Sun Mar 29 21:36:49 2015 Galdan Moulinneuf
** Last update Sun Mar 29 21:41:08 2015 Galdan Moulinneuf
*/

#include	<unistd.h>
#include	"server.h"

void		my_send(int fd)
{
  write(fd, "send\n", 5);
}

void		my_receive(int fd)
{
  int		nb;
  char		str[4];

  nb = read(fd, str, 3);
  str[nb] = 0;
}
