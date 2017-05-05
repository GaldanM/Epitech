/*
** my_cd_c.c for ftp in /run/media/moulin_c/Fedora/home/Galdan/Projects/Semester_4/Unix/FTP
** 
** Made by Galdan Moulinneuf
** Login   <moulin_c@epitech.net>
** 
** Started on  Sun Mar 29 23:21:50 2015 Galdan Moulinneuf
** Last update Sun Mar 29 23:21:51 2015 Galdan Moulinneuf
*/

#include		<stdio.h>
#include		<unistd.h>
#include		<string.h>
#include		"client.h"

void			cd_c(char **p, int fd)
{
  char			str[4096];

  if (p[0] && !p[1])
    {
      write(fd, "CDUP\r\n", strlen("CDUP\r\n"));
      return ;
    }
  else if (p[0] && p[1] && !p[2])
    {
      sprintf(str, "CWD %s\r\n", p[1]);
      write(fd, str, strlen(str));
      return ;
    }
  sprintf(str, "%s\r\n", p[0]);
  write(fd, str, strlen(str));
}
