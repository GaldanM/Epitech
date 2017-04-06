/*
** displays.c for mastermind in /home/moulin_c/rendu/colle2_moulin_c
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Mon May  5 20:26:04 2014 moulin_c
** Last update Mon May  5 22:48:15 2014 moulin_c
*/

#include	"my.h"

void		print_round(int i, int try)
{
  my_putstr("Round ");
  my_putnbr(i);
  my_putstr(" sur ");
  my_putnbr(try);
  my_putstr("\n\n");
}

void		disp_prompt(char *pions, int slot)
{
  my_putstr("Caractères autorisés : '");
  my_putstr(pions);
  my_putstr("'\n\nVotre choix (");
  my_putnbr(slot);
  my_putstr(" caractères) : ");
}

int		disp_pions(t_param *param)
{
  if (param->good == my_strlen(param->code))
    {
      my_putstr("\nBravo ! Tu es le meilleur du monde mon gars !\n");
      param->win = 1;
      return (1);
    }
  my_putstr("Pions bien placés : ");
  my_putnbr(param->good);
  my_putstr("\nPions mal placés : ");
  my_putnbr(param->bad);
  my_putchar('\n');
  return (0);
}
