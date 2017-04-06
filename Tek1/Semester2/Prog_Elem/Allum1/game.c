/*
** game.c for alum in /home/moulin_c/rendu/Semester 2/Modules/C_Prog_Elem/Alum_1/Allum1
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Wed Feb  5 12:36:17 2014 moulin_c
** Last update Fri Feb  7 15:37:51 2014 moulin_c
*/

#include "alum.h"

int	game_computer(t_param *var, t_alum **tabl)
{
  char	ret;

  while (42)
    {
      display(var, tabl);
      ret = read_key(var, tabl);
      if (ret == 1 && check_select(var, tabl) == 1)
  	{
	  unselect_tabl(var, tabl);
	  var->turn = TURN_CMP(var->turn);
	  if (check_last(var, tabl) == 1)
	    return (disp_lost(var));
  	}
      else if (ret == 2 || ret == -1)
	return (1);
      if (var->turn == 3)
	{
	  computer_turn(var, tabl);
	  var->turn = 1;
	  if (check_last(var, tabl) == 1)
	    return (disp_lost(var));
	}
    }
}

int	game_players(t_param *var, t_alum **tabl)
{
  char	ret;

  while (42)
    {
      display(var, tabl);
      ret = read_key(var, tabl);
      if (ret == 1 && check_select(var, tabl) == 1)
	{
	  unselect_tabl(var, tabl);
	  var->turn = TURN_PLYR(var->turn);
	  if (check_last(var, tabl) == 1)
	    return (disp_lost(var));
	}
      else if (ret == -1 || ret == 2)
	return (1);
    }
}

int	game(t_param *var, t_alum **tabl)
{
  if (var->mode == 1)
    {
      if (game_players(var, tabl) == 1)
	return (0);
    }
  else
    if (game_computer(var, tabl) == 1)
      return (0);
 }

