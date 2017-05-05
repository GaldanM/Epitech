/*
** get_next_line.h for getnextline in /home/moulin_c/rendu/Modules/C_Prog_Elem/GetNextLine/CPE_2013_getnextline
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Sun Nov 24 15:34:47 2013 moulin_c
** Last update Sat Apr 26 16:37:22 2014 moulin_c
*/

#ifndef	GET_NEXT_LINE_H_
# define GET_NEXT_LINE_H_
# define BUFFER 100

#include <stdlib.h>

typedef struct	s_line
{
  char	*str;
  int	j;
  int	ret_read;
}		t_line;

char	*strcpy_getnextline(char *dest, char *src);
char	*my_realloc_line(char *str);
int	buff_read(const int *fd, char *buffer, int *ret_read, int *i);
char	*get_next_line(const int fd);

#endif /* !GET_NEXT_LINE_H_ */
