/*
** my_dirty_print.c for chiffres in /home/sement_s/rendu/colle4_moulin_c_S4gR1/src
** 
** Made by Stephen SEMENT
** Login   <sement_s@epitech.net>
** 
** Started on  Mon May 19 21:47:29 2014 Stephen SEMENT
** Last update Mon May 19 21:54:11 2014 Stephen SEMENT
*/

void		aff_not_good(int nb, char c, int nb2, int nb3)
{
  my_putstr("Le compte n'est pas bon ! (");
  my_putnbr(nb);
  my_putstr(" - ");
  my_putnbr(nb2);
  my_putstr(" = ");
  my_putnbr(nb3);
  my_putstr(")\n");
}
