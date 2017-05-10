/*
** my_recup_elem.c for  in /home/moulin_c/rendu/code_tek
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Fri Apr 25 15:30:06 2014 moulin_c
** Last update Sat Apr 26 16:30:58 2014 moulin_c
*/

#include <stdlib.h>
#include "mylist.h"
#include "get_next_line.h"

t_list	*my_recup_elem(void)
{
  t_list	*p;
  int		i;
  char		*str;

  i = 0;
  p = NULL;
  while ((str = get_next_line(0)))
    {
      my_put_in_list_end(&p, str, i);
      i++;
    }
  return (p);
}
