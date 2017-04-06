/*
** push.h for push in /home/moulin_c/mbin
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Mon Jan  6 04:12:34 2014 moulin_c
** Last update Mon Jan  6 18:10:01 2014 moulin_c
*/

#ifndef PUSH_H_
# define PUSH_H_

typedef struct	s_var
{
  int		rra;
  int		ra;
  int		va;
  int		check;
  int		key;
}		t_var;

void	my_sa(t_list **list_a, t_list **list_b, t_var *var);
void	my_sb(t_list **list_a, t_list **list_b, t_var *var);
void	my_ss(t_list **list_a, t_list **list_b, t_var *var);
void	my_pa(t_list **list_a, t_list **list_b, t_var *var);
void	my_pb(t_list **list_a, t_list **list_b, t_var *var);
void	my_ra(t_list **list_a, t_list **list_b, t_var *var);
void	my_rb(t_list **list_a, t_list **list_b, t_var *var);
void	my_rr(t_list **list_a, t_list **list_b, t_var *var);
void	my_rra(t_list **list_a, t_list **list_b, t_var *var);
void	my_rrb(t_list **list_a, t_list **list_b, t_var *var);
void	my_rrr(t_list **list_a, t_list **list_b, t_var *var);
void	bsort_to_a(t_list **list_a, t_list **list_b, t_var *var);
void	check_swap(t_list **list_a, t_list **list_b, t_var *var);
int	*check_first_size(t_list **list_a);
void	my_compare_ra(t_list **list_a, t_list **list_b, t_var *var);
void	my_rotate(t_list **list_a, t_list **list_b, t_var *var);
int	check_sort_list(t_list **list_a, t_list **list_b, t_var *var);
int	main(int argc, char **argv);

#endif	/* !PUSH_H_ */
