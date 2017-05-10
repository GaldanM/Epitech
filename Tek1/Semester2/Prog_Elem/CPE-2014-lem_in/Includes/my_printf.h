/*
** printf.h for printf in /home/moulin_c/rendu/tests/printf
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Fri Nov 15 18:37:49 2013 moulin_c
** Last update Fri Apr 18 04:08:05 2014 moulin_c
*/

#ifndef PRINTF_H_
# define PRINTF_H_

# include <stdarg.h>

void    if_d(va_list arg_pos, char *str, int i);
void    if_i(va_list arg_pos, char *str, int i);
void    if_s(va_list arg_pos, char *str, int i);
void    if_bs(va_list arg_pos, char *str, int i);
void    if_c(va_list arg_pos, char *str, int i);

void    if_u(va_list arg_pos, char *str, int i);
void    if_x(va_list arg_pos, char *str, int i);
void    if_bx(va_list arg_pos, char *str, int i);
void    if_o(va_list arg_pos, char *str, int i);
void    if_p(va_list arg_pos, char *str, int i);

void    if_percent(va_list arg_pos, char *str, int i);
void    if_b(va_list arg_pos, char *str, int i);
void	if_no(va_list arg_pos, char *str, int i);
void	if_m(va_list arg_pos, char *str, int i);

int	my_match(char *str, int i);
void	tab_flag(va_list arg_pos, char *str, int i);
int	my_printf(char *str, ...);

void    my_put_zero(char *str, int i);
void    my_putstr_s(char *str);

#endif /* !PRINTF_H_*/
