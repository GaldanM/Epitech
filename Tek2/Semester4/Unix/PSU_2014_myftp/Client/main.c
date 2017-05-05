/*
** main.c for ftp in /run/media/moulin_c/Fedora/home/Galdan/Projects/Semester_4/Unix/FTP
** 
** Made by Galdan Moulinneuf
** Login   <moulin_c@epitech.net>
** 
** Started on  Sun Mar 29 23:21:41 2015 Galdan Moulinneuf
** Last update Sun Mar 29 23:21:42 2015 Galdan Moulinneuf
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
#include		"client.h"

extern			int g_fd;

int			init_socket_c(int argc, struct protoent *pe, int *fd)
{
  if (argc != 3)
    {
      printf("./client 'adress' 'port'\n");
      return (-1);
    }
  if ((pe = getprotobyname("TCP")) == 0)
    {
      printf("Error TCP\n");
      return (-1);
    }
  if ((*fd = socket(AF_INET, SOCK_STREAM, pe->p_proto)) == -1)
    {
      printf("Error socket\n");
      return (-1);
    }
  return (0);
}

void			catch_sig()
{
  int			isLog;

  isLog = 0;
  write(g_fd, "QUIT\r\n", strlen("QUIT\r\n"));
  receive_from_server(g_fd, &isLog);
}

int			main(int argc, char **argv)
{
  struct protoent	*pe;
  struct sockaddr_in	s_in;
  int			fd;

  pe = NULL;
  if (init_socket_c(argc, pe, &fd) == -1)
    return (-1);
  g_fd = fd;
  s_in.sin_family = AF_INET;
  s_in.sin_port = htons(atoi(argv[2]));
  s_in.sin_addr.s_addr = inet_addr(argv[1]);
  if (connect(fd, (struct sockaddr *)&s_in, sizeof(s_in)) == -1)
    {
      printf("Failed to connect to port %s\n", argv[2]);
      close(fd);
      return (-1);
    }
  signal(SIGINT, catch_sig);
  receive_from_server(fd, &fd);
  send_to_server(fd);
  close(fd);
  return (0);
}
