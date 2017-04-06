/*
** minitalk.h for minitalk in /home/moulin_c/rendu/Semester 2/Modules/Unix/Minitalk/PSU_2013_minitalk
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Wed Mar 19 15:39:30 2014 moulin_c
** Last update Thu Mar 20 15:51:14 2014 moulin_c
*/

#ifndef MINITALK_H_
# define MINITALK_H_

int	calcul_getnbr(char *str, int a, int b, int sign);
int	my_getnbr(char *str);
void	my_fill_nbr(char *nbr, int a);
char	*my_get_nbr_base(int nbr, char *base, int a);

void	do_nothing();
void	my_putchar(char d);
void	my_putstr(char *str);
int	my_strlen(char *str);

void	my_send(char c, int pid_serv, int a);
void	send_sig(char c, int pid_serv);
void	send_pid(int pid_cl, int pid_serv);
void	send_text(char *str, int pid_serv);

void	sig_char(int signum);
void	sig_pid(int signum);
int	get_client_pid();
void	check_bit(int *end);
void	aff_text(int pid_cl);

int	my_put_nbr(int nb);
void	calcul_putnbr(int nb);

#endif /* !MINITALK_H_ */
