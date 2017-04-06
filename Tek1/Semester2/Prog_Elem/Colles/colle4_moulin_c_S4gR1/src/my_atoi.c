/*
** my_atoi.c for chiffres in /home/sement_s/rendu/colle4_moulin_c_S4gR1/src
** 
** Made by Stephen SEMENT
** Login   <sement_s@epitech.net>
** 
** Started on  Mon May 19 20:45:57 2014 Stephen SEMENT
** Last update Mon May 19 21:21:28 2014 Stephen SEMENT
*/

int		my_atoi(char *nb)
{
  int		res;
  int		i;
  int		a;

  a = 1;
  i = my_strlen(nb) - 1;
  if ((nb[0] >= 48 && nb[0] <= 57) || nb[0] == '-')
    res = 0;
  else
    my_exitstr("Wrong parameters. Please refer to the README.\n", -1);
  while (i >= 0)
    {
      if (nb[i] == '-')
	return (res * (-1));
      if (nb[i] < 48 || nb[i] > 57)
	my_exitstr("Wrong parameters. Please refer to the README.\n", -1);
      res = res + ((nb[i] - 48) * a);
      a = a * 10;
      i = i - 1;
    }
  return (res);
}
