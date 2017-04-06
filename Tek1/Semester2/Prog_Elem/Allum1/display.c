/*
** display.c for alum in /home/moulin_c/rendu/Semester 2/Modules/C_Prog_Elem/Alum_1/Allum1
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Thu Feb  6 14:19:54 2014 moulin_c
** Last update Mon Feb 10 14:07:27 2014 moulin_c
*/

#include "alum.h"

void	display(t_param *var, t_alum **tabl)
{
  do_caps("cl");
  my_putstr("\tALUM_1 for {EPITECH.} by moulin_c\n\n");
  my_putstr("Select the matches you want to take (only on one row) :\n\n");
  my_putstr("It's ");
  if (var->turn == 1)
    my_putstr(var->player1);
  else if (var->turn == 2)
    my_putstr(var->player2);
  else if (var->turn == 3)
    my_putstr("Computer");
  my_putstr("'s turn !\n\n\t");
  disp_matches(var, tabl);
  my_putstr("\n\nMove : Arrows\nSelect : Space\nSelect line : S\n");
  my_putstr("Remove selected match(es) : Enter\nQuit : Q");
}

void	disp_error(void)
{
  do_caps("cl");
  my_putstr("Error : Enter 's' or 'm' please\n");
  sleep(2);
  do_caps("cl");
}

int	disp_lost(t_param *var)
{
  usleep(500000);
  do_caps("cl");
  if (var->turn == 3)
    my_putstr(var->player1);
  else
    {
      if (var->turn == 1)
	my_putstr(var->player2);
      else if (var->turn == 2)
	my_putstr(var->player1);
    }
  my_putstr(" won the game !\n");
  sleep(4);
  return (1);
}
