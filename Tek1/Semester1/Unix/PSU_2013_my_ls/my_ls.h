/*
** my_ls.h for my_ls in /home/moulin_c/rendu/Modules/Unix/My_ls/PSU_2013_my_ls
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Fri Nov 29 16:19:43 2013 moulin_c
** Last update Sun Dec  1 19:29:05 2013 moulin_c
*/

#ifndef MY_LS_H_
# define MY_LS_H_

#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <stdlib.h>
#include <time.h>
#include <pwd.h>
#include <grp.h>

int	main(int argc, char **argv);
int	ls_match(char *str, int i);
void	tab_flag_ls(char *str, int i);
char	**tab_name();
char	**tab_name_rev();
void	aff_data_l(char **tab, int i);
void	my_ls();
void	my_ls_l();
void	my_ls_a();
void	my_ls_big_r();
void	my_ls_d();
void	my_ls_r();
void	my_ls_t();
void	my_ls_other();
void	my_ls_file(char **name_file, int nb_files);
char	*my_strcpy(char *dest, char *src);
int	my_strcmp(char *s1, char *s2);
void	my_manage_cmp(char *str1, char *str2, int *i);
char	*mod_date(char *str);
int	nb_blocks();
void	my_rights(char *name);
int	count_files();
char	**my_sort_alpha(int nb_files, char **name_file);
char	**my_sort_alpha_rev(int nb_files, char **name_file);

#endif /* !MY_LS_H_ */
