/*
** recup_info.c for my_reader in /home/sement_s/rendu/colle3
** 
** Made by Stephen SEMENT
** Login   <sement_s@epitech.net>
** 
** Started on  Mon May 12 20:54:31 2014 Stephen SEMENT
** Last update Mon May 12 21:01:38 2014 Stephen SEMENT
*/

char		*recup_info(char *str, int len)
{
  char		*info;
  int		i;
  int		k;

  i = 0;
  while (str[i] != '\0')
    i = i + 1;
  k = i;
  if ((info = malloc(sizeof(char) * i)) == NULL)
    my_exitstr("Malloc error, program must close.\n", -1);
  i = len;
  while (i <= (k - len))
    {
      info[i] = str[i];
      i = i + 1;
    }
  return (info);
}
