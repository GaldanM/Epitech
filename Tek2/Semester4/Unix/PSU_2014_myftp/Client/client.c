/*
** client.c for ftp in /home/moulin_c/rendu/PSU_2014_myftp
** 
** Made by Galdan Moulinneuf
** Login   <moulin_c@epitech.net>
** 
** Started on  Sun Mar 29 21:45:22 2015 Galdan Moulinneuf
** Last update Sun Mar 29 21:45:58 2015 Galdan Moulinneuf
*/

#include		<signal.h>
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

int			g_fd;

static t_cmd		g_cmd[17] =
  {
    {"cd", &cd_c},
    {"CWD", &cd_c},
    {"CDUP", &cd_c},
    {"quit", &quit_c},
    {"QUIT", &quit_c},
    {"pwd", &pwd_c},
    {"PWD", &pwd_c},
    {"ls", &ls_c},
    {"LIST", &ls_c},
    {"get", &get_c},
    {"RETR", &get_c},
    {"put", &put_c},
    {"STOR", &put_c},
    {"user", &user_c},
    {"USER", &user_c},
    {"pass", &pass_c},
    {"PASS", &pass_c}
  };

void			receive_from_server(int fd, int *isLog)
{
  char			buf[4096];
  char			**ret;

  xread(fd, buf);
  ret = my_strtotab(buf);
  write(1, buf, strlen(buf));
  if (ret[0] && !strcmp(ret[0], "221"))
    {
      close(fd);
      exit(1);
    }
  if (ret[0] && !strcmp(ret[0], "230"))
    *isLog = 1;
}

void			exec_client(int fd, char **p)
{
  int			i;

  i = 0;
  while (i < 17)
    {
      if (strcmp(p[0], g_cmd[i].cmd) == 0)
        {
          g_cmd[i].func(p, fd);
          return ;
        }
      i++;
    }
  write(fd, p[0], strlen(p[0]));
}

void			send_nolog(int fd, char **p)
{
  char			str[4096];

  if (!p[1])
    sprintf(str, "%s\r\n", p[0]);
  else
    sprintf(str, "%s %s\r\n", p[0], p[1]);
  write(fd, str, strlen(str));
}

void			send_to_server(int fd)
{
  char			**p;
  char			*buf;
  int			isLog;

  isLog = 0;
  while ((buf = get_next_line(1)))
    {
      if (buf[500])
	buf[500] = 0;
      p = my_strtotab(buf);
      if (p[0])
	{
	  if (isLog)
	    exec_client(fd, p);
	  else
	    send_nolog(fd, p);
	  if (strcmp(p[0], "get") && strcmp(p[0], "put") &&
	      strcmp(p[0], "RETR") && strcmp(p[0], "STOR"))
	    receive_from_server(fd, &isLog);
	}
      free(buf);
    }
}
