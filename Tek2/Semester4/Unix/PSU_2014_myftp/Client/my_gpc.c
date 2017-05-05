/*
** my_gpc.c for ftp in /home/moulin_c/rendu/PSU_2014_myftp
** 
** Made by Galdan Moulinneuf
** Login   <moulin_c@epitech.net>
** 
** Started on  Sun Mar 29 21:42:31 2015 Galdan Moulinneuf
** Last update Sun Mar 29 21:44:50 2015 Galdan Moulinneuf
*/

#include		<sys/types.h>
#include		<sys/socket.h>
#include		<netdb.h>
#include		<stdlib.h>
#include		<netinet/in.h>
#include		<arpa/inet.h>
#include		<unistd.h>
#include		<string.h>
#include		<stdio.h>
#include		<sys/stat.h>
#include		<fcntl.h>
#include		"get_next_line.h"
#include		"client.h"

int			check_getc(int fd, char **p)
{
  char			buf[4096];
  char			str[4096];
  char			**ret;

  if (p[1])
    sprintf(str, "RETR %s\r\n", p[1]);
  else
    sprintf(str, "RETR\r\n");
  write(fd, str, strlen(str));
  xread(fd, buf);
  ret = my_strtotab(buf);
  if (ret[0] && !strcmp(ret[0], "400"))
    {
      printf("fin\n");
      write(1, buf, strlen(buf));
      return (-1);
    }
  write(1, buf, strlen(buf));
  return (0);
}

void			get_c(char **p, int fd)
{
  char			buf[1025];
  int			nb;
  int			fdfile;
  char			*file_name;

  if (check_getc(fd, p) == -1)
    return ;
  file_name = get_fname(p[1]);
  if ((fdfile = open(file_name, O_CREAT | O_RDWR | O_TRUNC,
		     S_IWUSR | S_IRGRP | S_IRUSR | S_IROTH)) == -1)
    return ;
  nb = 1;
  my_send(fd);
  while (nb > 0)
    {
      nb = read(fd, buf, 1024);
      buf[nb] = 0;
      write(fdfile, buf, nb);
      if (nb < 1024)
	nb = 0;
      my_send(fd);
    }
  xread(fd, buf);
  write(1, buf, strlen(buf));
  close(fdfile);
}

int			check_putc(char **p, int fd)
{
  char			buf[4096];
  char			str[4096];
  char			**ret;

  if (p[1])
    sprintf(str, "STOR %s\r\n", p[1]);
  else
    sprintf(str, "STOR\r\n");
  write(fd, str, strlen(str));
  xread(fd, buf);
  ret = my_strtotab(buf);
  if (ret[0] && !strcmp(ret[0], "400"))
    {
      write(1, buf, strlen(buf));
      return (-1);
    }
  write(1, buf, strlen(buf));
  return (0);
}

void			put_c(char **p, int fd)
{
  int			fdfile;
  char			buf[1025];
  int			nb;

  if (check_putc(p, fd) == -1)
    return ;
  if ((fdfile = open(p[1], O_RDONLY)) == -1)
    return ;
  my_receive(fd);
  while ((nb = read(fdfile, buf, 1024)) > 0)
    {
      buf[nb] = 0;
      write(fd, buf, nb);
      my_receive(fd);
    }
  xread(fd, buf);
  write(1, buf, strlen(buf));
  close(fdfile);
}
