/*
** my_cmds.c for ftp in /home/moulin_c/rendu/PSU_2014_myftp
** 
** Made by Galdan Moulinneuf
** Login   <moulin_c@epitech.net>
** 
** Started on  Sun Mar 29 21:47:45 2015 Galdan Moulinneuf
** Last update Sun Mar 29 21:47:46 2015 Galdan Moulinneuf
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

void		ls_s(char **p, t_user *u)
{
  struct dirent	*ptr_readdir;
  DIR		*dir;
  char		*str;

  (void)p;
  if ((dir = opendir(".")) == NULL)
    {
      send_to_client(u->fd, "400 Failed to open !\r\n");
      return ;
    }
  str = strdup("\0");
  send_to_client(u->fd, "150 File status ok; openning data connection\r\n");
  while ((ptr_readdir = readdir(dir)))
    {
      str = realloc(str, strlen(str) + strlen(ptr_readdir->d_name) + 30);
      strcat(str, ptr_readdir->d_name);
      strcat(str, "\n");
    }
  strcat(str, "226 Transfer complete\r\n");
  usleep(30);
  send_to_client(u->fd, str);
  free(str);
}

void		quit_s(char **p, t_user *u)
{
  (void)p;
  send_to_client(u->fd, "221 Disconnected\r\n");
  if (u->name)
    printf("'%s' disconnect\n", u->name);
}

void		pwd_s(char **p, t_user *u)
{
  char		str[4096];

  if (p[1])
    {
      send_to_client(u->fd, "400 PWD no arguments !\r\n");
      return;
    }
  sprintf(str, "257 %s\r\n", u->pwd);
  send_to_client(u->fd, str);
}

void		user_s(char **p, t_user *u)
{
  (void)p;
  write(u->fd, "400 'Anonymous' already logged.\r\n",
	strlen("400 'Anonymous' already logged.\r\n"));
}

void		pass_s(char **p, t_user *u)
{
  (void)p;
  write(u->fd, "400 'Anonymous' already logged.\r\n",
	strlen("400 'Anonymous' already logged.\r\n"));
}
