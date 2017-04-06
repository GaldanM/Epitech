/*
** bsq.h for bsq in /home/moulin_c/rendu/Modules/C_Prog_Elem/BSQ/CPE-2013-BSQ
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Sun Dec  8 16:54:53 2013 moulin_c
** Last update Sun Dec  8 18:12:32 2013 moulin_c
*/

#ifndef BSQ_H_
# define BSQ_H_

#include <fcntl.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>

# define COMPARE(a, b)  ((a > b) ? (a) : (b))

typedef struct	s_param
{
  int	last;
  int	i;
  int	j;
  int	s_col;
  int	s_line;
  int	check_col;
  int	check_li;
  int	pos_x;
  int	pos_y;
  char	*file;
}		t_param;

void	my_putchar(char d);
void	my_putstr(char *str);
int	calcul_getnbr(char *str, int a, int b, int sign);
int	my_getnbr(char *str);
int	strlen_mod(char *str);
int	my_strlen(char *str);
int	my_show_wordtab(char **tab);
char	**make_tab_lines(int nb_lines, int nb_column, int fd);
int	check_line(char **tab, int line, int column, int nb_check);
int	check_column(char **tab, int line, int column, int nb_check);
t_param	check_obstacle(char **tab, int nb_line, int nb_column, t_param var);
int	more_square(char **tab, int nb_line, int nb_column, t_param var);
int	main(int argc, char **argv);

#endif /* !BSQ_H_ */
