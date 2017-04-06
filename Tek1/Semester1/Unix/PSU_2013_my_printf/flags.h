/*
** flags.h for printf in /home/moulin_c/rendu/tests/printf
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Fri Nov 15 18:37:49 2013 moulin_c
** Last update Sat Nov 16 18:27:47 2013 moulin_c
*/

#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#ifndef __FLAGS_H__
# define FLAGS_H_

void    if_i(va_list arg_pos, char *str, int i);

void    if_d(va_list arg_pos, char *str, int i);

void    if_s(va_list arg_pos, char *str, int i);

void    if_bs(va_list arg_pos, char *str, int i);

void    if_b(va_list arg_pos, char *str, int i);

void    if_c(va_list arg_pos, char *str, int i);

void    if_u(va_list arg_pos, char *str, int i);

void    if_x(va_list arg_pos, char *str, int i);

void    if_bx(va_list arg_pos, char *str, int i);

void    if_o(va_list arg_pos, char *str, int i);

void    if_p(va_list arg_pos, char *str, int i);

void    if_percent(va_list arg_pos, char *str, int i);

void	if_no(va_list arg_pos, char *str, int i);

void	if_m(va_list arg_pos, char *str, int i);

int	my_match(char *str, int i);

void	tab_flag(va_list arg_pos, char *str, int i);

int	my_printf(char *str, ...);

void	my_putstr_rev(char *str, int i);

void    my_put_zero(char *str, int i);

void    my_putstr_s(char *str);

int     check_bin(int nb);

int     check_malloc(char *str, int i);

#endif /*!FLAGS_H_*/
