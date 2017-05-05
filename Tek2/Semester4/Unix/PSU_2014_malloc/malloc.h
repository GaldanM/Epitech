/*
** malloc.h for malloc in /home/moulin_c/rendu/PSU_2014_malloc
** 
** Made by Galdan MOULINNEUF
** Login   <moulin_c@epitech.net>
** 
** Started on  Tue Feb  3 21:24:11 2015 Galdan MOULINNEUF
** Last update Fri Feb 13 15:31:23 2015 Galdan MOULINNEUF
*/

#ifndef MALLOC_H_
# define MALLOC_H_

typedef struct	s_mdata
{
  struct s_mdata	*prev;
  struct s_mdata	*next;
  void			*end;
  size_t		size;
  int			used;
  int			root;
  char		        padd[8];
  char			end_mdata[0];
}		t_mdata;

void		*malloc(size_t);

void		free(void *);

t_mdata		*find_ptr(void *);
void		*realloc(void *, size_t);

void		show_alloc_mem();

#endif /* !MALLOC_H_ */
