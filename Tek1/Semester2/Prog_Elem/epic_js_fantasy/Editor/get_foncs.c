/*
** get_foncs.c for  in /home/medec_o/rendu/rush_game/parser_game
** 
** Made by medec_o
** Login   <medec_o@epitech.net>
** 
** Started on  Sun May 11 10:17:59 2014 medec_o
** Last update Sun May 11 21:35:19 2014 moulin_c
*/

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "editor.h"

void		get_monsters(int charnb, int fd)
{
  char		*name;
  char		*rev;
  int		i;

  name = my_recup_name(charnb, NULL, "Monster's name :");
  my_putnbr_param(4, 1, fd);
  my_putnbr_param(strlen(name), 1, fd);
  rev = rev_str(name);
  i = strlen(name);
  my_putstr_file(rev, fd, i);
  set_stats(fd);
  my_putnbr_param(10, 1, fd);
}

void		get_chars(int charnb, int fd)
{
  char		*name;

  name = my_recup_name(charnb, NULL, "Character's name : n°");
  printf("Le nom est : %s\n", name);
  my_putnbr_param(1, 1, fd);
  my_putnbr_param(strlen(name), 1, fd);
  my_putstr_file(rev_str(name), fd, strlen(name));
  printf("\nChoose %s's class : (warrior, wizard or templar)\n", name);
  name = get_next_line(0);
  my_putnbr_param(4, 1, fd);
  my_putnbr_param(strlen(name), 1, fd);
  my_putstr_file(rev_str(name), fd, strlen(name));
  set_stats(fd);
  my_putnbr_param(10, 1, fd);
}

int		get_data(t_rooms **rooms, int fd)
{
  int		nb;
  int		i;

  i = 0;
  my_putnbr_param(12, 1, fd);
  printf("\n\n              ==[ CHARACTERS ] ==\n\n\n");
  nb = my_verif_nbr("How many character(s) do you want?\n", 0, NULL);
  printf("Vous voulez %d persos\n", nb);
  while (i < nb)
    {
      get_chars(i + 1, fd);
      i++;
    }
  my_putnbr_param(14, 1, fd);
  printf("              ==[ MONSTERS ] ==\n\n\n");
  i = 0;
  nb = my_verif_nbr("How many different monster(s) do you want ?", 1, NULL);
  while (i < nb)
    {
      get_monsters(i + 1, fd);
      i++;
    }
  set_rooms(fd, rooms);
}

void		get_rooms(t_rooms **rooms, int i, int fd)
{
  char		*str;

  str = my_recup_name(i, NULL, "Choose the room name of the room");
  add_room(rooms, i, str);
  printf("The room name is : %s\n", (*rooms)->name);
}
