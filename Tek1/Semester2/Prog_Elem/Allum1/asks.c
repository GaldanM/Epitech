/*
** asks.c for alum in /home/moulin_c/rendu/Allum1
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Fri Feb  7 15:47:24 2014 moulin_c
** Last update Fri Feb  7 16:20:20 2014 moulin_c
*/

#include "alum.h"

int	ask_lines(t_param *var)
{
  char	buffer[100];
  int	ret;

  do_caps("cl");
  my_putstr("Choose number of lines please : ");
  if ((ret = read(0, buffer, 100) - 1) == - 1)
    return (-1);
  buffer[ret] = '\0';
  while (check_read(buffer) == 1)
    {
      my_putstr("Only alphanumeric characters (0-9) please");
      sleep(2);
      do_caps("cl");
      my_putstr("Choose number of lines please : ");
      if ((ret = read(0, buffer, 100) - 1) == - 1)
	return (-1);
      buffer[ret] = '\0';
    }
  var->lines_max = my_getnbr(buffer);
  if (var->lines_max < 2)
    {
      var->lines_max = 2;
      my_putstr("2 lines is minimum so it has been put instead\n");
      sleep(2);
    }
}

int	ask_players_2(t_param *var, char *buffer)
{
  int	ret;

  if (buffer[0] == 'm')
    {
      my_putstr("Enter the name of player 1 : ");
      if ((ret = read(0, var->player1, 100)) == - 1)
	return (-1);
      var->player1[ret - 1] = '\0';
      my_putstr("Enter the name of player 2 : ");
      if ((ret = read(0, var->player2, 100)) == - 1)
	return (-1);
      var->player2[ret - 1] = '\0';
      var->mode = 1;
    }
  else if (buffer[0] == 's')
    {
      my_putstr("Enter the name of the player : ");
      if ((ret = read(0, var->player1, 100)) == - 1)
	return (-1);
      var->player1[ret - 1] = '\0';
      var->mode = 2;
    }
  else
    disp_error();
  return (0);
}

int	ask_players(t_param *var)
{
  char	buffer[100];

  do_caps("cl");
  var->mode = 0;
  while (var->mode == 0)
    {
      my_putstr("Solo (s) or Multiplayer (m) ? ");
      if (read(0, buffer, 100) == - 1)
	return (-1);
      if (ask_players_2(var, buffer) == - 1)
	return (-1);
    }
  return (0);
}
