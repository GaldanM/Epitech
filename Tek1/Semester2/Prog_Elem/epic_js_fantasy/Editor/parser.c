/*
** parser.c for parser in /home/di-mam_a/rendu/Rush 2/lib
** 
** Made by di-mam_a
** Login   <di-mam_a@epitech.net>
** 
** Started on  Sat May 10 13:19:33 2014 di-mam_a
** Last update Sun May 11 21:46:21 2014 moulin_c
*/

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "editor.h"

void		set_weapon(int fd)
{
  char		*name;

  my_putnbr_param(8, 1, fd);
  printf("Set weapon : (if no weapon, just hit enter) \n");
  name = get_next_line(0);
  if (name[0] == '\0')
    {
      my_putnbr_param(4, 1, fd);
      my_putstr_file(rev_str("none"), fd, 4);
    }
  else
    {
      my_putnbr_param(strlen(name), 1, fd);
      my_putstr_file(rev_str(name), fd, strlen(name));
    }
}

void		set_stats(int fd)
{
  int		nb;

  nb = my_verif_nbr("Set hp", 0, NULL);
  my_putnbr_param(5, 1, fd);
  my_putnbr_param(nb, 1, fd);
  nb = my_verif_nbr("Set spe", 0, NULL);
  my_putnbr_param(20, 1, fd);
  my_putnbr_param(nb, 1, fd);
  nb = my_verif_nbr("Set speed", 0, NULL);
  my_putnbr_param(6, 1, fd);
  my_putnbr_param(nb, 1, fd);
  nb = my_verif_nbr("Set damages", 0, NULL);
  my_putnbr_param(7, 1, fd);
  my_putnbr_param(nb, 1, fd);
  set_weapon(fd);
  set_armor(fd);
}

void		make_map(t_rooms **rooms, int fd)
{
  int		nb;
  int		i;

  i = 0;
  printf("\n\n              ==[ ROOMS ] ==\n\n\n");
  nb = my_verif_nbr("How much rooms do you want? ", 0, NULL);
  *rooms = make_rooms();
  *rooms = (*rooms)->next;
  while (i < nb)
    {
      i++;
      get_rooms(rooms, i, fd);
    }
}

int		my_put_header(t_rooms **rooms, int mode)
{
  char		*name;
  int		fd;
  int		flag;

  flag = 0;
  name = my_recup_name(0,  NULL, "Enter the name of the game");
  fd = open(name, O_CREAT | O_RDWR | O_TRUNC, mode);
  header_file(name, rooms, fd);
  get_data(rooms, fd);
}

int		main(int argc, char **argv)
{
  t_rooms	*rooms;
  int		mode;

  rooms = NULL;
  mode = S_IWUSR | S_IRGRP | S_IRUSR | S_IROTH;
  my_put_header(&rooms, mode);
}
