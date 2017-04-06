/*
** verif.c for my_mastermind in /home/sement_s/rendu/colle2_moulin_c/src
** 
** Made by Stephen SEMENT
** Login   <sement_s@epitech.net>
** 
** Started on  Mon May  5 20:01:19 2014 Stephen SEMENT
** Last update Mon May  5 20:04:29 2014 Stephen SEMENT
*/

int		verif_int(char *av)
{
  int		i;

  i = 0;
  while (av[i] != '\0')
    {
      if (av[i] >= '0' && av[i] <= '9')
	i = i + 1;
      else
	return (-1);
    }
  return (0);
}
