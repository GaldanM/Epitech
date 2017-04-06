/*
** lists.h for lists in /home/moulin_c/rendu/colle3_moulin_c_OaHTo/test_term
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Mon May 12 19:41:50 2014 moulin_c
** Last update Mon May 12 20:10:01 2014 moulin_c
*/

#ifndef LISTS_H_
# define LISTS_H_

typedef struct	s_items
{
  struct s_items	*prev;
  int			nbr;
  char			*title;
  char			*link;
  char			*desc;
  struct s_items	*next;
}		t_items;

typedef struct		s_file
{
  char			*file_name;
  t_items		*list_items;
}			t_file;

#endif /* !LISTS_H_ */
