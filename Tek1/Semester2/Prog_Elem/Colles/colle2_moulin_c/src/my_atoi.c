/*
** my_atoi.c for my_mastermind in /home/sement_s/rendu/colle2_moulin_c/src
** 
** Made by Stephen SEMENT
** Login   <sement_s@epitech.net>
** 
** Started on  Mon May  5 20:10:17 2014 Stephen SEMENT
** Last update Mon May  5 22:12:36 2014 moulin_c
*/

int		my_atoi(char *str)
{
  int		nb;
  int		i;
  int		a;

  a = 1;
  nb = 0;
  i = my_strlen(str) - 1;
  while (i >= 0)
    {
      nb = nb + ((str[i] - 48) * a);
      i = i - 1;
      a = a * 10;
    }
  return (nb);
}
