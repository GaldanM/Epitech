/*
** my_user_c.c for ftp in /run/media/moulin_c/Fedora/home/Galdan/Projects/Semester_4/Unix/FTP
** 
** Made by Galdan Moulinneuf
** Login   <moulin_c@epitech.net>
** 
** Started on  Sun Mar 29 23:22:50 2015 Galdan Moulinneuf
** Last update Sun Mar 29 23:22:51 2015 Galdan Moulinneuf
*/

#include	       <stdio.h>
#include	       <string.h>
#include	       <unistd.h>
#include	       "client.h"

void			user_c(char **p, int fd)
{
  char			str[4096];

  if (p[1])
    sprintf(str, "USER %s\r\n", p[1]);
  else
    sprintf(str, "USER\r\n");
  write(fd, str, strlen(str));
}
