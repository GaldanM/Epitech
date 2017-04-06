/*
** mylist.h for mylist in /home/moulin_c/rendu/Piscine-C-include
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Tue Oct 22 15:16:47 2013 moulin_c
** Last update Sun Apr 13 16:53:12 2014 moulin_c
*/

#ifndef MYLIST_H_
# define MYLIST_H_

# include <stdlib.h>

typedef struct		s_instr
{
  struct s_instr		*prev;
  char				**inst;
  unsigned char			nb_octet;
  int				pos;
  struct s_instr		*next;
}			t_instr;

typedef struct		s_labels
{
  struct s_labels		*prev;
  struct s_instr		*instr;
  char				*name;
  unsigned int			nb_octet;
  int				pos;
  struct s_labels		*next;
}			t_labels;












typedef struct		s_ins
{
  int				pos;
  char				**instr;
  unsigned char			nb_octet_instr;
 }			t_ins;

typedef struct		s_lab
{
  int				pos;
  char				*name;
  t_ins				*inst;
  unsigned int			nb_octet_label;
}			t_lab;


t_labels	*make_doublelist_labels(void);
t_instr		*make_doublelist_instr(void);

#endif /* !MYLIST_H_ */
