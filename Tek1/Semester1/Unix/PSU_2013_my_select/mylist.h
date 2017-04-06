/*
** mylist.h for mylist in /home/moulin_c/rendu/Piscine-C-include
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Tue Oct 22 15:16:47 2013 moulin_c
** Last update Sun Jan 19 17:56:13 2014 moulin_c
*/

#ifndef MYLIST_H_
# define MYLIST_H_

typedef struct	s_list
{
  struct s_list	*prev;
  int		id;
  char		*data;
  int		select;
  struct s_list	*next;
}		t_list;

t_list	*make_list_circ(void);
void	add_elem_circ_end(t_list **list, char *str, int id);

#endif /*!MYLIST_H_ */
