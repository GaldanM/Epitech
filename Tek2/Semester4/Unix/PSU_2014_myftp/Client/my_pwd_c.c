/*
** my_pwd_c.c for ftp in /run/media/moulin_c/Fedora/home/Galdan/Projects/Semester_4/Unix/FTP
** 
** Made by Galdan Moulinneuf
** Login   <moulin_c@epitech.net>
** 
** Started on  Sun Mar 29 23:22:28 2015 Galdan Moulinneuf
** Last update Sun Mar 29 23:22:29 2015 Galdan Moulinneuf
*/

#include	       <stdio.h>
#include	       <string.h>
#include	       <unistd.h>
#include	       "client.h"

void			pwd_c(char **p, int fd)
{
  (void)p;
  write(fd, "PWD\r\n", strlen("PWD\r\n"));
  return ;
}
