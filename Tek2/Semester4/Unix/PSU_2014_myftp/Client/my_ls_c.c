/*
** my_ls_c.c for ftp in /run/media/moulin_c/Fedora/home/Galdan/Projects/Semester_4/Unix/FTP
** 
** Made by Galdan Moulinneuf
** Login   <moulin_c@epitech.net>
** 
** Started on  Sun Mar 29 23:22:17 2015 Galdan Moulinneuf
** Last update Sun Mar 29 23:22:18 2015 Galdan Moulinneuf
*/

#include		<stdio.h>
#include		<unistd.h>
#include		<string.h>
#include		"client.h"

void			ls_c(char **p, int fd)
{
  char			str[4096];
  char			buf[4096];
  char			**ret;

  if (!p[1])
    write(fd, "LIST\r\n", strlen("LIST\r\n"));
  else
    {
      sprintf(str, "LIST %s\r\n", p[1]);
      write(fd, str, strlen(str));
    }
  xread(fd, buf);
  ret = my_strtotab(buf);
  write(1, buf, strlen(buf));
  if (ret[0] && !strcmp(ret[0], "400"))
    return;
}
