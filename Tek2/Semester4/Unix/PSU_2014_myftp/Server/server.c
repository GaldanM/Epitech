/*
** server.c for ftp in /home/moulin_c/rendu/PSU_2014_myftp
** 
** Made by Galdan Moulinneuf
** Login   <moulin_c@epitech.net>
** 
** Started on  Sun Mar 29 21:48:04 2015 Galdan Moulinneuf
** Last update Sun Mar 29 21:48:04 2015 Galdan Moulinneuf
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

void			init_user(t_user *u, int client_fd)
{
  char			*n;

  u->home = malloc(1024);
  getcwd(u->home, 1024);
  n = get_fname(u->home);
  u->fd = client_fd;
  u->name = strdup("Anonymous");
  if (strcmp(n, "Anonymous"))
    u->home = strcat(u->home, "/Anonymous/");
  u->pwd = strdup(u->home);
  if (strcmp(n, "Anonymous"))
    mkdir("./Anonymous/", 0700);
  chdir("./Anonymous/");
  u->isUser = 0;
  u->isPass = 0;
}

void			my_server(int fd, char root[1025])
{
  struct sockaddr_in	s_cl;
  int			c_fd;
  pid_t			pid;
  t_user		u;
  socklen_t		s_in_size;

  s_in_size = sizeof(s_cl);
  if ((c_fd = accept(fd, (struct sockaddr *)&s_cl, &s_in_size)) == -1)
    {
      close(fd);
      exit(1);
    }
  pid = fork();
  if (pid == 0)
    {
      printf("-> Connection %s:%d\n", inet_ntoa(s_cl.sin_addr), s_cl.sin_port);
      send_to_client(c_fd,
		     "220 Connection established\nPlease connect with user & pass\r\n");
      u.root = root;
      init_user(&u, c_fd);
      receive_from_client(&u);
    }
  else if (pid > 0)
    close(c_fd);
}

void			init_sin(struct sockaddr_in *s_in, int port)
{
  s_in->sin_family = AF_INET;
  s_in->sin_port = htons(port);
  s_in->sin_addr.s_addr = INADDR_ANY;
}

void			xclose(int fd)
{
  close(fd);
  exit(1);
}
