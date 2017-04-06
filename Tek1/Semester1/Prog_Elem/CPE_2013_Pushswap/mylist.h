/*
** mylist.h for mylist in /home/moulin_c/rendu/Piscine-C-include
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Tue Oct 22 15:16:47 2013 moulin_c
** Last update Mon Jan  6 16:38:54 2014 moulin_c
*/

#ifndef MYLIST_H_
# define MYLIST_H_

typedef struct	s_list
{
  struct s_list	*prev;
  char		*name;
  int		nb;
  struct s_list	*next;
}		t_list;

t_list	*make_list_circ(void);
void	add_elem_circ_begin(t_list **list, int data);
void	add_elem_circ_end(t_list **list, int data);
void	del_elem_circ_begin(t_list **list);
void	del_elem_circ_end(t_list **list);
void	my_show_list_circ(t_list *list);

#endif /*!MYLIST_H_ */
