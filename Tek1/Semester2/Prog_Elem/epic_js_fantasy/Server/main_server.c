/*
** main_server.c for server.c in /home/js/last_rush/lib
**
** Made by thibau_j
** Login   <thibau_j@epitech.net>
**
** Started on  Sat May 10 04:27:04 2014 thibau_j
** Last update Sun May 11 20:33:35 2014 moulin_c
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	<string.h>
#include	<stdio.h>
#include	"fantasy.h"

t_header	g_header;

char		*my_nextroom(char *buff, int id)
{
  t_rooms	*room;
  int		i;
  char		*str;

  i = 4;
  while (buff[i] == ' ' || buff[i] == '\t')
    i++;
  room = g_header.list_rooms->next;
  str = buff + i;
  str[strlen(str) - 1] = '\0';
  while (room->name)
    {
      if (!strcmp(room->name, str))
	{
	  str[strlen(str)] = '\n';
	  str[strlen(str) + 1] = '\0';
	  return (str);
	}
      room = room->next;
    }
  return (NULL);
}

void		function_read(char *buff, size_t size, int id)
{
  char		*str;

  str = NULL;
  if (!strncmp(buff, "next", 4))
    {
      str = my_nextroom(buff, id);
      if (str == NULL)
	write_on_client("Bad room\n", strlen("Bad room\n"), id);
      else
	write_on_client(str, strlen(str), id);
    }
  else
    write_on_client("Bad command\n", strlen("Bad command\n"), id);
}

int		main(int ac, char **av)
{
  t_header	header;

  if (ac < 2)
    {
      printf("./server port\n");
      return (-1);
    }
  if (ac > 1)
    {
      parser(av[2], &header);
      g_header = header;
      server_loop(atoi(av[1]), &function_read);
    }
  return (1);
}
