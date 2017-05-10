/*
** str_to_tab.c for str_to_tab in /home/doghri_f/rendu/PSU_2014_zappy/Server/Sources/Divers
** 
** Made by Fares Doghri
** Login   <doghri_f@epitech.net>
** 
** Started on  Sun Jul  5 23:27:44 2015 Fares Doghri
** Last update Sun Jul  5 23:27:45 2015 Fares Doghri
*/

#include	"server.h"

char      **str_to_tab(char *s)
{
  char    **tab;
  int     n;
  int     i;
  int     nb;
  int     wlen;

  i = init_var(&nb, &wlen, &n, s);
  if ((tab = malloc(sizeof(*tab) * (nb + 1))) == NULL)
    return (NULL);
  while (n < nb)
    {
      while (s[i]  && (s[i] == ' ' || s[i] == '\t' || s[i] == '\r'))
        i++;
      wlen = my_wdlen(&s[i]);
      if ((tab[n] = malloc(sizeof(**tab) * (wlen + 1))) == NULL)
        return (NULL);
      strncpy(tab[n], &s[i], wlen);
      tab[n][wlen] = 0;
      while (s[i] && (s[i] != ' ' && s[i] != '\t' && s[i] != '\r'))
        ++i;
      ++n;
    }
  tab[nb] = NULL;
  return (tab);
}

int       init_var(int *nb, int *wlen, int *n, char *s)
{
  *nb = count_word(s);
  *wlen = 0;
  *n = 0;
  (void)nb;
  (void)wlen;
  (void)n;
  return (0);
}

int       count_word(char *s)
{
  int   nb;
  int   n;

  nb = 0;
  n = 0;
  while (s[n])
    {
      if ((n == 0 || s[n - 1] == ' ' || s[n - 1] == '\t'
        || s[n - 1] == '\r')
        && s[n] != ' ' && s[n] != '\t' && s[n] != '\r')
        ++nb;
      ++n;
    }
  return (nb);
}

int       my_wdlen(char *s)
{
  int		n;

  n = 0;
  while (s[n])
    {
      if (s[n] != ' ' && s[n] != '\t' && s[n] != '\r')
        ++n;
      else
        return (n);
    }
  return (n);
}
