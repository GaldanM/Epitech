/*
** my_put.c for ftp in /home/moulin_c/rendu/PSU_2014_myftp
** 
** Made by Galdan Moulinneuf
** Login   <moulin_c@epitech.net>
** 
** Started on  Sun Mar 29 21:43:15 2015 Galdan Moulinneuf
** Last update Sun Mar 29 21:43:36 2015 Galdan Moulinneuf
*/

#include		<stdlib.h>
#include		<sys/types.h>
#include		<sys/stat.h>
#include		<fcntl.h>
#include		<dirent.h>
#include		<stdio.h>
#include		<string.h>
#include		<unistd.h>
#include		"server.h"

char			*fill_put(char **p, t_user *u)
{
  char			*file_name;

  file_name = malloc(strlen(u->pwd) + strlen(p[1]) + 15);
  file_name = strcpy(file_name, u->pwd);
  file_name = strcat(file_name, "/");
  file_name = strcat(file_name, get_fname(p[1]));
  return (file_name);
}

int			check_transf(char **p, t_user *u)
{
  char			str[4096];
  char			path[4096];

  if (!p[1])
    {
      sprintf(str, "400 Need arguments !\r\n");
      write(u->fd, str, strlen(str));
      return (-1);
    }
  strcpy(path, "../");
  strcat(path, p[1]);
  if (check_file(path) == -1)
    {
      sprintf(str, "400 Bad file !\r\n");
      write(u->fd, str, strlen(str));
      return (-1);
    }
  else
    {
      sprintf(str, "150 File status ok; openning data connection..\r\n");
      write(u->fd, str, strlen(str));
    }
  return (0);
}

void			put_s(char **p, t_user *u)
{
  char			*file_name;
  int			fdfile;
  int			nb;
  char			buf[1025];

  if (check_transf(p, u) == -1)
    return;
  file_name = fill_put(p, u);
  if ((fdfile = open(file_name, O_CREAT | O_RDWR | O_TRUNC,
		     S_IWUSR | S_IRGRP | S_IRUSR | S_IROTH)) == -1)
    return;
  nb = 1;
  my_send(u->fd);
  while (nb > 0)
    {
      nb = read(u->fd, buf, 1024);
      buf[nb] = 0;
      write(fdfile, buf, nb);
      if (nb < 1024)
	nb = 0;
      my_send(u->fd);
    }
  send_to_client(u->fd, "226 Transfer ok !\r\n");
  close(fdfile);
}
