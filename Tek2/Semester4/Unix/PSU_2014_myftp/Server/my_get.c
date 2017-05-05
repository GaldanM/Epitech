/*
** my_get.c for ftp in /home/moulin_c/rendu/PSU_2014_myftp
** 
** Made by Galdan Moulinneuf
** Login   <moulin_c@epitech.net>
** 
** Started on  Sun Mar 29 21:47:55 2015 Galdan Moulinneuf
** Last update Sun Mar 29 21:47:55 2015 Galdan Moulinneuf
*/

#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "server.h"

char			*fill_get(char **p, t_user *u)
{
  char			*file_name;

  file_name = malloc(strlen(u->pwd) + strlen(p[1]) + 15);
  file_name = strcpy(file_name, u->pwd);
  file_name = strcat(file_name, "/");
  file_name = strcat(file_name, p[1]);
  return (file_name);
}

void			get_s(char **p, t_user *u)
{
  int			fd;
  char			buf[1025];
  int			nb;
  char			*file_name;

  if (check_transf(p, u) == -1)
    return;
  file_name = fill_get(p, u);
  if ((fd = open(file_name, O_RDONLY)) == -1)
    {
      send_to_client(u->fd, "400 [get] : Open failed !\r\n");
      close(fd);
      return;
    }
  my_receive(u->fd);
  while ((nb = read(fd, buf, 1024)) > 0)
    {
      buf[nb] = 0;
      write(u->fd, buf, nb);
      my_receive(u->fd);
    }
  send_to_client(u->fd, "226 Transfer ok !\r\n");
  printf("[get] : Success\n");
  close(fd);
}
