/*
** asm.h for asm in /home/moulin_c/rendu/Semester 2/Modules/C_Prog_Elem/Corewar/ASM
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Fri Apr  4 18:46:57 2014 moulin_c
** Last update Sun Apr 13 20:35:32 2014 moulin_c
*/

#ifndef ASM_H_
# define ASM_H_

#include "mylist.h"
#include "op.h"

typedef struct	s_param
{
  int	i;
  int	j;
  int	k;
  int	lbl;
}		t_param;

typedef struct	s_save
{
  char			*name;
  int			pos;
  int			pos_label;
  char			*next_name;
  char			*next_cmds;
}		t_save;

typedef struct	s_file
{
  char			name[PROG_NAME_LENGTH + 1];
  char			comment[COMMENT_LENGTH + 1];
  t_lab			*tab;
}		t_file;

typedef struct	s_str
{
  char	*line;
  char	*cmds;
  char	*name;
}		t_str;
//COUNT
int	my_add(char **tab, int *oct, int pos);
int	my_aff(char **tab, int *oct, int pos);
int	my_and(char **tab, int *oct, int pos);
int	my_lfork(char **tab, int *oct, int pos);
int	my_fork(char **tab, int *oct, int pos);
int	my_lldi(char **tab, int *oct, int pos);
int	my_ldi(char **tab, int *oct, int pos);
int	my_lld(char **tab, int *oct, int pos);
int	my_ld(char **tab, int *oct, int pos);
int	my_live(char **tab, int *oct, int pos);
int	my_nothing(char **tab, int *oct, int pos);
int	my_or(char **tab, int *oct, int pos);
int	my_sti(char **tab, int *oct, int pos);
int	my_st(char **tab, int *oct, int pos);
int	my_sub(char **tab, int *oct, int pos);
int	my_xor(char **tab, int *oct, int pos);
int	my_zjmp(char **tab, int *oct, int pos);
//CHECKS
int	check_tab(char *tab, int pos);
int	check_error(char **tab);
int	check_string(char *str, int pos);
//CHECK_TYPE
char	*check_param(char *str);
int	is_overflow(char **tab, int pos, int i);
int	is_bad_arg(char **tab, int pos, int i);
int	check_type(char **tab, char *line, int pos);
//COUNT_OCT
int	fonct_tab(char **tab, int *oct, int *param);
int	count_octet_instr(char **instr, int pos);
//FONCS_OCT
int	label_size(t_instr *instr);
int	direct_char_err(char *tab, int pos, int i);
int	label_char_err(char *tab, int pos, int i);
int	count_octet_param(char *param);
int	show_error(char *str, int pos, char *msg);



int	calc_getnbr(char *str, int b);
int	my_getnbr(char *str);

void	my_putchar(char d);


int	add_instr(t_instr **instr, char **tab, int nb, t_save *save);


int	add_label(t_labels **label, t_instr *inst, t_save save, int nb);

int	check_mnemo(char **tab, int pos, t_param *param);
int	check_instr(t_lab *tab);

int	check_line(char *epur);

int	second_malloc_epur(char *str);
char	*second_epur_str(char *str);
int	first_malloc_epur(char *str);
char	*epur_str(char *str);

int	check_new_label(char *str);
int	fill_instr(t_instr **instr, t_save *save, t_str *strs, int key);
int	get_instr(t_instr **instr, t_save *save, t_str *strs, int key);
int	if_save(t_instr **instr, t_save *save, t_str *strs, int key);
int	recup_instr(t_instr **instr, t_save *save, int fd);

char	*strcpy_getnextline(char *dest, char *src);
char	*my_realloc(char *str);
int	buff_read(const int *fd, char *buffer, int *ret_read, int *i);
char	*get_next_line(const int fd);

void	aff_tab(t_lab *tab);
int	nb_labels(t_labels *list);
int	nb_instr(t_instr *list);
t_lab	*list_to_tab(t_labels *list);

t_instr	*make_instr(void);

t_labels	*make_labels(void);

int	browse_up(t_lab *tab, t_param *param, char *name);
int	browse_down(t_lab *tab, t_param *param, char *name);
int	find_labels(t_lab *tab, t_param *param, char *name);
void	my_calc_labels(t_lab *tab);

int	nbr_size(int nbr);
char	*my_malloc_nbr(int size);
char	*my_concat_str(char *nb, int size, int flag);
char	*my_getstr(int nbr);

int	count_words(char *str);
void	my_show_tab(char **tab);
int	browse_str(char *str, int i, int *beg, int *end);
int	my_str_to_inst_tab(char *str, char **tab);

int	check_char_label(char *str, int pos);
int	check_labels(t_lab *tab);
int	my_recup_labels(t_labels **labels, char *file);
int	main(int argc, char **argv);

void	my_recup_header(t_file *header, char *file);

char	**split_line(char *cmds, char *name, char *line);

int	my_put_header(t_file *file, int fd);
char	*get_name(char *name);
int	create_bin(t_file *file, char *name);

int	my_putnbr_param(int nb, int oct, int fd);

void	my_putchar_file(int d, int fd);
int	my_putstr_file(char *str, int fd, int oct);

int	my_putstr_mnemo(char *str, int fd);

char	*rev_str(char *str);

char	*my_strcat(char *dest, char *src);
int	my_strcmp(char *s1, char *s2);
char	*my_strdup(char *src);

#endif	/* !MYLIST_H_ */
