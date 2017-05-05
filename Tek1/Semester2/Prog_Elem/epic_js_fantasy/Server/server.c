/*
** server.c for fantasy in /home/moulin_c/rendu/epic_js_fantasy/Server
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Sat May 10 17:53:32 2014 moulin_c
** Last update Sun May 11 20:32:38 2014 moulin_c
*/

#include	<sys/types.h>
#include	<sys/stat.h>
#include	<fcntl.h>
#include	<unistd.h>
#include	<stdlib.h>
#include	<stdio.h>
#include	"fantasy.h"

void		my_exitstr(char *error)
{
  puts(error);
  exit(1);
}

void		init_header(t_header *header)
{
  header->name = NULL;
  header->start = NULL;
  header->end = NULL;
  header->list_rooms = make_rooms();
  header->list_champs = make_champs();
  header->list_monsts = make_monsts();
}

void		analyse_line(char *line, t_header *header)
{
  static int	f = 0;
  int		i;

  i = 0;
  if (line[0] == 123)
    i++;
  else if (f == 0)
    my_exitstr("Magic nb missing");
  f = 1;
  if (line[i] == 13)
    fill_header(header, line, ++i);
  else if (line[i] == 12)
    fill_champ(header, line, ++i);
  else if (line[i] == 14)
    fill_monster(header, line, ++i);
  else if (line[i] == 15)
    fill_room(header, line, ++i);
  else
    my_exitstr("Wrong file");
}

void		parser(char *file, t_header *header)
{
  char		*str;
  int		fd;

  if ((fd = open(file, O_RDONLY)) == -1)
    my_exitstr("Wrong file");
  init_header(header);
  while ((str = get_next_line(fd)))
    analyse_line(str, header);
}
