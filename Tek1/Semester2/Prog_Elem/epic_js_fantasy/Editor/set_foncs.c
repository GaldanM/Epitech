/*
** set_foncs.c for  in /home/medec_o/rendu/rush_game/parser_game
** 
** Made by medec_o
** Login   <medec_o@epitech.net>
** 
** Started on  Sun May 11 10:19:03 2014 medec_o
** Last update Sun May 11 21:47:30 2014 moulin_c
*/

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "editor.h"

void		set_monsters(int fd, char *name)
{
  int		nb;
  int		i;
  char		*type;

  i = 1;
  nb = my_verif_nbr("How many monsters in room %s ?", 1, name);
  if (nb > 0)
    {
      while (i <= nb)
	{
	  type = my_recup_name(i, NULL, "Enter name of monster");
	  my_putnbr_param(12, 1, fd);
	  my_putnbr_param(strlen(type), 1, fd);
	  my_putstr_file(rev_str(type), fd, strlen(type));
	  i++;
	}
    }
}

void		set_connections(int fd, t_rooms *tmp)
{
  if (tmp->next->name != NULL)
    {
      my_putnbr_param(11, 1, fd);
      my_putnbr_param(strlen(tmp->name), 1, fd);
      my_putstr_file(rev_str(tmp->name), fd, strlen(tmp->name));
      my_putnbr_param(16, 1, fd);
      my_putnbr_param(1, 1, fd);
      my_putnbr_param(48, 1, fd);
      my_putnbr_param(17, 1, fd);
      my_putnbr_param(strlen(tmp->next->name), 1, fd);
      my_putstr_file(rev_str(tmp->next->name), fd, strlen(tmp->next->name));
    }
}

void		set_adv(int fd)
{
  char		*name;

  my_putnbr_param(10, 1, fd);
  printf("Choose an advantage for this room (hit enter if no advantage)\n");
  name = get_next_line(0);
  if (name[0] == '\0')
    {
      my_putnbr_param(1, 1, fd);
      my_putnbr_param(30, 1, fd);
    }
  else
    {
      my_putnbr_param(strlen(name), 1, fd);
      my_putstr_file(rev_str(name), fd, strlen(name));
    }
}

void		set_rooms(int fd, t_rooms **rooms)
{
  t_rooms	*tmp;

  tmp = *rooms;
  tmp = tmp->next;
  my_putnbr_param(15, 1, fd);
  printf("\n\n              ==[ ROOMS ] ==\n\n\n");
  while (tmp->root != 1)
    {
      my_putnbr_param(1, 1, fd);
      my_putnbr_param(strlen(tmp->name), 1, fd);
      my_putstr_file(rev_str(tmp->name), fd, strlen(tmp->name));
      printf("                  - Room %d setup - \n", tmp->room_id);
      set_adv(fd);
      set_connections(fd, tmp);
      set_monsters(fd, tmp->name);
      my_putnbr_param(10, 1, fd);
     tmp = tmp->next;
    }
}

void		set_armor(int fd)
{
  char		*name;

  my_putnbr_param(9, 1, fd);
  printf("Set armor : (if no armor, just hit enter)\n");
  name = get_next_line(0);
  if (name[0] == '\0')
    {
      my_putnbr_param(4, 1, fd);
      my_putstr_file(rev_str("none"), fd, 4);
    }
  else
    {
      my_putnbr_param(1, 1, fd);
      my_putnbr_param(strlen(name), 1, fd);
      my_putstr_file(rev_str(name), fd, strlen(name));
    }
}
