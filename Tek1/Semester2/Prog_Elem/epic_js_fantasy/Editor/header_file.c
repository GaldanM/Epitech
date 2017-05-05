/*
** header_file.c for  in /home/di-mam_a/rendu/Rush 2/lib
** 
** Made by di-mam_a
** Login   <di-mam_a@epitech.net>
** 
** Started on  Sun May 11 03:20:46 2014 di-mam_a
** Last update Sun May 11 21:35:40 2014 moulin_c
*/

#include <string.h>
#include "editor.h"

void	header_file(char *name, t_rooms **rooms, int fd)
{
  my_putnbr_param(123, 1, fd);
  my_putnbr_param(13, 1, fd);
  my_putnbr_param(1, 1, fd);
  my_putnbr_param(strlen(name), 1, fd);
  my_putstr_file(rev_str(name), fd, strlen(name));
  make_map(rooms, fd);
  my_putnbr_param(1, 1, fd);
  my_putnbr_param(strlen((*rooms)->prev->name), 1, fd);
  my_putstr_file(rev_str((*rooms)->prev->name), fd, strlen((*rooms)->prev->name));
  my_putnbr_param(1, 1, fd);
  my_putnbr_param(strlen((*rooms)->next->name), 1, fd);
  my_putstr_file(rev_str((*rooms)->next->name), fd, strlen((*rooms)->next->name));
  my_putnbr_param(10, 1, fd);
}
