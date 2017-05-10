/*
** foncs_case_list.c for  in /home/doghri_f/rendu/PSU_2014_zappy/Server/Sources/Lists
** 
** Made by Fares Doghri
** Login   <doghri_f@epitech.net>
** 
** Started on  Sun Jul  5 23:34:26 2015 Fares Doghri
** Last update Sun Jul  5 23:34:35 2015 Fares Doghri
*/

#include	"case.h"

t_case		*init_case_list()
{
  t_case	*root;

  root = malloc(sizeof(t_case));
  if (root != NULL)
    {
      root->root = 1;
      root->next = NULL;
    }
  return (root);
}

e_bool 		push_ressource(t_case **root, e_ressource item)
{
  t_case	*nouv;

  nouv = malloc(sizeof(t_case));
  if (nouv == NULL)
    return (FALSE);
  nouv->root = 0;
  nouv->ressource = item;
  nouv->next = (*root)->next;
  (*root)->next = nouv;
  return (TRUE);
}

e_bool 		delete_ressource(t_case **root, e_ressource item)
{
  t_case	*tmp;
  t_case	*prev;

  tmp = (*root)->next;
  prev = *root;
  while (tmp != NULL && tmp->ressource != item)
    {
      prev = tmp;
      tmp = tmp->next;
    }
  if (!tmp)
    return (FALSE);
  prev->next = tmp->next;
  free(tmp);
  return (TRUE);
}

int 		count_ressource(t_case *root, e_ressource item)
{
  int 	nb;
  t_case	*tmp;

  nb = 0;
  tmp = root->next;
  while (tmp != NULL)
    {
      if (tmp->ressource == item)
	++nb;
      tmp = tmp->next;
    }
  return (nb);
}

e_bool 		check_ressource(t_case *root, e_ressource item)
{
  t_case	*tmp;

  tmp = root->next;
  while (tmp != NULL && tmp->ressource != item)
    tmp = tmp->next;
  if (!tmp)
    return (FALSE);
  return (TRUE);
}
