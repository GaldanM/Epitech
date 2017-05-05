/*
** my_pass_c.c for ftp in /run/media/moulin_c/Fedora/home/Galdan/Projects/Semester_4/Unix/FTP
** 
** Made by Galdan Moulinneuf
** Login   <moulin_c@epitech.net>
** 
** Started on  Sun Mar 29 23:22:02 2015 Galdan Moulinneuf
** Last update Sun Mar 29 23:22:03 2015 Galdan Moulinneuf
*/

#include	       <stdio.h>
#include	       <string.h>
#include	       <unistd.h>
#include	       "client.h"

void			pass_c(char **p, int fd)
{
  char			str[4096];

  if (p[1])
    sprintf(str, "PASS %s\r\n", p[1]);
  else
    sprintf(str, "PASS\r\n");
  write(fd, str, strlen(str));
}
