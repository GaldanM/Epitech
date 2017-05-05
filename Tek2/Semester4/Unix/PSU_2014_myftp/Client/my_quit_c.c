/*
** my_quit_c.c for ftp in /run/media/moulin_c/Fedora/home/Galdan/Projects/Semester_4/Unix/FTP
** 
** Made by Galdan Moulinneuf
** Login   <moulin_c@epitech.net>
** 
** Started on  Sun Mar 29 23:22:36 2015 Galdan Moulinneuf
** Last update Sun Mar 29 23:22:39 2015 Galdan Moulinneuf
*/

#include	       <unistd.h>
#include	       <string.h>
#include	       "client.h"

void			quit_c(char **p, int fd)
{
  (void)p;
  write(fd, "QUIT\r\n", strlen("QUIT\r\n"));
}
