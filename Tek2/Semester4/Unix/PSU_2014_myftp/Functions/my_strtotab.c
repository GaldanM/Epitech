/*
** my_strtotab.c for ftp in /home/moulin_c/rendu/PSU_2014_myftp/Functions
** 
** Made by Galdan Moulinneuf
** Login   <moulin_c@epitech.net>
** 
** Started on  Sun Mar 29 21:27:51 2015 Galdan Moulinneuf
** Last update Sun Mar 29 21:33:49 2015 Galdan Moulinneuf
*/

#include	<string.h>
#include	<stdlib.h>

int		calc_lenght_word(char *str)
{
  int		i;

  i = 0;
  while (str[i])
    {
      if (str[i] != ' ' && str[i] != '\t' && str[i] != '\r')
        ++i;
      else
        return (i);
    }
  return (i);
}

int		count_nb_words(char *str)
{
  int		i;
  int		count;

  count = 0;
  i = 0;
  while (str[i])
    {
      if ((i == 0 || str[i - 1] == ' ' || str[i - 1] == '\t' ||
	   str[i - 1] == '\r') &&
	  str[i] != ' ' && str[i] != '\t' && str[i] != '\r')
        ++count;
      ++i;
    }
  return (count);
}

char		**my_strtotab(char *str)
{
  int		i;
  int		j;
  int		nb;
  int		len;
  char		**tab;

  nb = count_nb_words(str);
  len = 0;
  i = 0;
  j = 0;
  tab = malloc(sizeof(*tab) * (nb + 1));
  while (j < nb)
    {
      while (str[i]  && (str[i] == ' ' || str[i] == '\t' || str[i] == '\r'))
        ++i;
      len = calc_lenght_word(&str[i]);
      tab[j] = malloc(sizeof(**tab) * (len + 1));
      strncpy(tab[j], &str[i], len);
      tab[j][len] = 0;
      while (str[i] && (str[i] != ' ' && str[i] != '\t' && str[i] != '\r'))
        ++i;
      ++j;
    }
  tab[nb] = NULL;
  return (tab);
}
