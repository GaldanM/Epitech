/*
** execserv.c for ftp in /home/moulin_c/rendu/PSU_2014_myftp
** 
** Made by Galdan Moulinneuf
** Login   <moulin_c@epitech.net>
** 
** Started on  Sun Mar 29 21:46:39 2015 Galdan Moulinneuf
** Last update Sun Mar 29 21:47:15 2015 Galdan Moulinneuf
*/

#include		<sys/stat.h>
#include		<sys/types.h>
#include		<sys/socket.h>
#include		<netdb.h>
#include		<stdlib.h>
#include		<netinet/in.h>
#include		<arpa/inet.h>
#include		<unistd.h>
#include		<string.h>
#include		<stdio.h>
#include		<signal.h>
#include		"get_next_line.h"
#include		"server.h"

static t_cmd            g_cmd[17] =
  {
    {"cd", &cd_s},
    {"CWD", &cd_s},
    {"CDUP", &cd_s},
    {"quit", &quit_s},
    {"QUIT", &quit_s},
    {"pwd", &pwd_s},
    {"PWD", &pwd_s},
    {"ls", &ls_s},
    {"LIST", &ls_s},
    {"get", &get_s},
    {"RETR", &get_s},
    {"put", &put_s},
    {"STOR", &put_s},
    {"user", &user_s},
    {"USER", &user_s},
    {"pass", &pass_s},
    {"PASS", &pass_s}
  };

int			send_to_client(int client_fd, char *str)
{
  if (write(client_fd, str, strlen(str)) == -1)
    return (-1);
  return (0);
}

void			exec_server(char **p, t_user *u)
{
  int			i;
  char			str[1024];

  i = 0;
  while (i < 17)
    {
      if (!strcmp(p[0], g_cmd[i].cmd))
	{
	  g_cmd[i].func(p, u);
	  return ;
	}
      i++;
    }
  sprintf(str, "400 Bad command !\r\n");
  send_to_client(u->fd, str);
}

void			isLogPass(char **p, t_user *u)
{
  if (p[0] && (!strcmp(p[0], "PASS") ||
	       !strcmp(p[0], "pass"))
      && !p[1])
    u->isPass++;
  if (!u->isUser)
    {
      write(u->fd, "332 Need account for login.\r\n",
	    strlen("332 Need account for login.\r\n"));
      u->isPass = 0;
      return ;
    }
  if (u->isPass == 0)
    {
      write(u->fd, "400 Need empty password!\r\n",
	    strlen("400 Need empty password!\r\n"));
      return ;
    }
  write(u->fd, "230 User logged in, proceed.\r\n",
	strlen("230 User logged in, proceed.\r\n"));
}

void			isLogUser(char **p, t_user *u, char *user)
{
  if (p[0] && (!strcmp(p[0], "USER") ||
	       !strcmp(p[0], "user")) &&
      p[1] && !strcmp(p[1], user))
    u->isUser++;
  if (u->isUser == 0)
    {
      write(u->fd, "400 Need 'Anonymous' USER !\r\n",
	    strlen("400 Need 'Anonymous' USER !\r\n"));
      return ;
    }
  else if (u->isUser == 1)
    {
      write(u->fd, "331 User name okay, need password.\r\n",
	    strlen("331 User name okay, need password.\r\n"));
      return ;
    }
}

void			receive_from_client(t_user *u)
{
  char			*buf;
  char			**p;

  while ((buf = get_next_line(u->fd)))
    {
      p = my_strtotab(buf);
      write(1, p[0], strlen(p[0]));
      write(1, "\n", 1);
      if (!u->isPass && (!strcmp(p[0], "PASS") || !strcmp(p[0], "pass")))
	isLogPass(p, u);
      else if (!u->isUser && strcmp(p[0], "QUIT"))
	isLogUser(p, u, "Anonymous");
      else if (!strcmp(p[0], "QUIT") || (u->isUser && u->isPass))
	exec_server(p, u);
      else
	write(u->fd, "400 Need password, use 'pass' to connect.\r\n",
	      strlen("400 Need password, use 'pass' to connect.\r\n"));
      free(buf);
    }
}
