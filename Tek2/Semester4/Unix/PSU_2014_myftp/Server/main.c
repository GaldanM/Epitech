/*
** main.c for ftp in /run/media/moulin_c/Fedora/home/Galdan/Projects/Semester_4/Unix/FTP
** 
** Made by Galdan Moulinneuf
** Login   <moulin_c@epitech.net>
** 
** Started on  Sun Mar 29 23:22:59 2015 Galdan Moulinneuf
** Last update Sun Mar 29 23:22:59 2015 Galdan Moulinneuf
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
#include		"server.h"

int			init_socket_s(int argc, struct protoent *pe, int *fd)
{
  if (argc != 2)
    {
      printf("./serveur 'port'\n");
      return (-1);
    }
  if ((pe = getprotobyname("TCP")) == 0)
    {
      printf("TCP problem\n");
      return (-1);
    }
  if ((*fd = socket(AF_INET, SOCK_STREAM, pe->p_proto)) == -1)
    {
      printf("Socket problem\n");
      return (-1);
    }
  return (0);
}

int			main(int argc, char **argv)
{
  struct protoent	*pe;
  struct sockaddr_in	s_in;
  int			fd;
  char			root[1025];

  pe = NULL;
  if (init_socket_s(argc, pe, &fd) == -1)
    return (-1);
  init_sin(&s_in, atoi(argv[1]));
  if (bind(fd, (const struct sockaddr *)&s_in, sizeof(s_in)) == -1)
    {
      printf("Connection failed, port used\n");
      xclose(fd);
    }
  if (listen(fd, 42) == -1)
    {
      printf("Error listen()\n");
      xclose(fd);
    }
  getcwd(root, 1024);
  while (1)
    my_server(fd, root);
  return (0);
}
