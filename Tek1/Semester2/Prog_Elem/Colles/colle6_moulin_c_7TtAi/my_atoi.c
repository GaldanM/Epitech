/*
** my_atoi.c for my_boogle in /home/sement_s/rendu/colle6_moulin_c_7TtAi
** 
** Made by Stephen SEMENT
** Login   <sement_s@epitech.net>
** 
** Started on  Mon Jun  2 20:30:37 2014 Stephen SEMENT
** Last update Mon Jun  2 20:33:38 2014 Stephen SEMENT
*/

int		my_atoi(char *nb)
{
  int		i;
  int		a;
  int		res;

  i = my_strlen(nb) - 1;
  a = 1;
  res = 0;
  while (i >= 0)
    {
      res = res + ((nb[i] - 48) * a);
      i = i - 1;
      a = a * 10;
    }
  return (res);
}
