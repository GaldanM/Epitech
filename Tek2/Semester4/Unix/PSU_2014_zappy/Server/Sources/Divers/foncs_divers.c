/*
** foncs_divers.c for fonc_divers in /home/doghri_f/rendu/PSU_2014_zappy/Server/Sources/Divers
** 
** Made by Fares Doghri
** Login   <doghri_f@epitech.net>
** 
** Started on  Sun Jul  5 23:27:57 2015 Fares Doghri
** Last update Sun Jul  5 23:27:58 2015 Fares Doghri
*/

#include "server.h"

char	*my_strcat(char *dest, char *src)
{
  int	a;
  int	b;
  int	len_d;
  int	len_s;
  char	*new;

  len_d = my_strlen(dest);
  len_s = my_strlen(src);
  if ((new = malloc(sizeof(char) * (len_d + len_s + 1))) == NULL)
    return (NULL);
  a = 0;
  b = 0;
  while (dest && dest[a])
  {
    new[a] = dest[a];
    ++a;
  }
  while (src && src[b])
    new[a++] = src[b++];
  new[a] = '\0';
  free(dest);
  return (new);
}

int		my_strlen(char *s)
{
	int	i;

	i = 0;
	while (s && s[i])
		++i;
	return (i);
}

t_player  *get_player_by_id(t_param *p, int id)
{
  t_player  *tmp;

  tmp = p->players->next;
  while (tmp && tmp->id != id)
    tmp = tmp->next;
  return (tmp);
}

int   get_team_id(char **team_name, char *team)
{
  int i;
  
  i = 0;
  while (team_name[i] && strcmp(team_name[i], team))
    ++i;
  return (i);
}

void      free_tab(char **tab, int nb)
{
  int     i;

  i = 0;
  while (i < nb)
    free(tab[i++]);
  free(tab);
}
