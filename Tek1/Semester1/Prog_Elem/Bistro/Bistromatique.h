/*
** Bistromathique.h for Bistro in /home/moulin_c/rendu/Modules/C_Prog_Elem/Bistro/operations
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Sun Nov 10 16:07:56 2013 moulin_c
** Last update Sun Nov 10 16:30:27 2013 moulin_c
*/
#ifndef	__BISTROMATIQUE_H__
# define					__BISTROMATIQUE_H__
# include					<stdlib.h>
# define					OP_OPEN_PARENT_IDX0
# define					OP_CLOSE_PARENT_IDX1
# define					OP_PLUS_IDX2
# define					OP_SUB_IDX3
# define					OP_NEG_IDX3
# define					OP_MULT_IDX4
# define					OP_DIV_IDX5
# define					OP_MOD_IDX6
# define					SYNTAXE_ERROR_MSG "syntax error\n"
# define COMPARE_MORE(a, b)                     ((a > b) ? (a) : (b))
# define COMPARE_LESS(a, b)                     ((a < b) ? (a) : (b))
# define COMPARE_NBR_MORE(nba, nbb)             ((my_strlen(nba) > my_strlen(nbb)) ? (nba) : (nbb))
# define COMPARE_NBR_LESS(nba, nbb)             ((my_strlen(nba) < my_strlen(nbb)) ? (nba) : (nbb))
# define CHIFFRE(str, a)                        str[a] >= 48 && str[a] <= 57


char		*eval_expr(char *str);
void		my_putstr(char *);
int		my_strlen(char *);
static void	check_base(char *base);
static void	check_ops(char *ops);
static char	*get_expr(unsigned size);

#endif /*!__BISTROMATIQUE_H_*/
