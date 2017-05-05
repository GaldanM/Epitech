/*
** sudoku.h for sud-au-cul in /home/moulin_c/rendu/Semester 2/Modules/C_Prog_Elem/Rush_Sudo
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Sat Mar  1 01:03:44 2014 moulin_c
** Last update Sun Mar  2 15:58:13 2014 moulin_c
*/

#ifndef SUDOKU_H_
# define SUDOKU_H_

typedef struct	s_sudo
{
  int	num;
  int	key;
}		t_sudo;

typedef struct	s_param
{
  int	i;
  int	j;
  int	k;
}		t_param;

void	my_putchar(char d);
void	my_putstr(char *str);

int	parsing(t_sudo ***tab, char *str, int i);
int	parser(t_sudo ***tab, char *str);

void	display_tab(t_sudo **tab);

int	test_line(t_sudo **tab, t_param *var);
int	test_column(t_sudo **tab, t_param *var);
int	test_square(t_sudo **tab, int i, int j, int k);
int	test_k(t_sudo **tab, t_param *var);

void	on_hard_key(t_sudo **tab, t_param *var);
void	find_good(t_sudo **tab, t_param *var);
int	decrem(t_param *var);
int	whle_hard(t_sudo **tab, t_param *var);

int	resolve_it(t_sudo **tab, t_param *var);
int	resolve(t_sudo **tab, t_param *var);

int	main(void);

#endif /* !SUDOKU_H_ */
