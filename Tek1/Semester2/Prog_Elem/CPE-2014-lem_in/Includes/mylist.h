/*
** mylist.h for mylist in /home/moulin_c/rendu/Piscine-C-include
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Tue Oct 22 15:16:47 2013 moulin_c
** Last update Sat Apr 26 13:38:27 2014 medec_o
*/

#ifndef MYLIST_H_
# define MYLIST_H_

# include <stdlib.h>

typedef struct	s_list
{
  char		*line;
  int		i;
  struct s_list	*next;
}		t_list;

t_list	*my_recup_elem(void);

#endif /*!MYLIST_H_ */
