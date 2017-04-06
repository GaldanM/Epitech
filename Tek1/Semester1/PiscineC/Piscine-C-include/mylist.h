/*
** mylist.h for mylist in /home/moulin_c/rendu/Piscine-C-include
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Tue Oct 22 15:16:47 2013 moulin_c
** Last update Wed Oct 23 20:22:49 2013 moulin_c
*/

#ifndef MYLIST_H_
# define MYLIST_H_

typedef struct s_list
{
  void *data;
  struct s_list *next;
} t_list;

#endif /*!MYLIST_H_ */
