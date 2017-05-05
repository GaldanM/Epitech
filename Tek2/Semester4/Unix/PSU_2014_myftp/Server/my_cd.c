/*
** my_cd.c for ftp in /home/moulin_c/rendu/PSU_2014_myftp
** 
** Made by Galdan Moulinneuf
** Login   <moulin_c@epitech.net>
** 
** Started on  Sun Mar 29 21:47:35 2015 Galdan Moulinneuf
** Last update Sun Mar 29 21:47:36 2015 Galdan Moulinneuf
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

int			check_cd(char **p, t_user *u)
{
  char			str[4096];

  if (!p[1])
    {
      chdir(u->home);
      u->pwd = u->home;
      sprintf(str, "200 %s okay\r\n", p[0]);
      send_to_client(u->fd, str);
      return (-1);
    }
  return (0);
}

char			*fill_path(char here[1025], char **p)
{
  char			*path;
  char			*go;

  go = p[1];
  getcwd(here, 1024);
  path = malloc(strlen(here) + strlen(go) + 10);
  path = strcpy(path, here);
  path = strcat(path, "/");
  path = strcat(path, go);
  return (path);
}

void			cd_s(char **p, t_user *u)
{
  char			str[4096];
  char			here[1025];
  char			*path;

  if (check_cd(p, u) == -1)
    return;
  path = fill_path(here, p);
  if (chdir(path) == -1)
    {
      sprintf(str, "400 %s failed !\r\n", p[0]);
      send_to_client(u->fd, str);
      return;
    }
  getcwd(here, 1024);
  if (strncmp(here, u->home, strlen(u->home) - 1))
    {
      send_to_client(u->fd, "400 Access forbidden !\r\n");
      chdir(u->home);
      return;
    }
  u->pwd = strdup(here);
  sprintf(str, "250 %s okay !\r\n", p[0]);
  send_to_client(u->fd, str);
}
