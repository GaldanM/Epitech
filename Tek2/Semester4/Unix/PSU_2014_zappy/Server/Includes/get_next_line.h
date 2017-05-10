/*
** get_next_line.h for ftp in /home/moulin_c/rendu/PSU_2014_myftp
** 
** Made by Galdan Moulinneuf
** Login   <moulin_c@epitech.net>
** 
** Started on  Sun Mar 29 21:45:05 2015 Galdan Moulinneuf
** Last update Sun Mar 29 21:45:06 2015 Galdan Moulinneuf
*/

#ifndef GET_NEXT_LINE_H_
# define GET_NEXT_LINE_H_

# define	B_SIZE 1024
# include	<string.h>

char	*make_save(char *, int, int);
char	*concat_str(char *, char *);
char	*clean_buff(char *, int);
int	my_read(char *, char *, int);
char	*get_next_line(int, int*);

#endif /* GET_NEXT_LINE_H_ */
