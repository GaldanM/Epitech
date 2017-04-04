/*
** minishell1.h for minishell1 in /home/moulin_c/rendu/Modules/Unix/Minishell/Minishell_1/PSU_2013_minishell1
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Thu Dec 19 14:21:58 2013 moulin_c
** Last update Fri Jan  3 17:05:35 2014 moulin_c
*/

#ifndef MINISHELL1_H_
# define MINISHELL1_H_
# include <unistd.h>

void	get_signal(pid_t pid);
void	cmd_not_found(char *str, char **tab);
int	my_shell(char ***envp);
int	main(int argc, char **argv, char **envp);
int	my_cd(char **tab, char **envp);
int	my_env(char **envp);
void	my_exit(char **tab);
int	my_unsetenv(char **tab, char ***envp);
int	check_builts(char **tab, char ***envp);
char	*check_locate(char *str, char **envp);
int	get_path_home(char **envp);
int	get_old_path(char **envp);
char	*get_path(char **envp);
int	count_words_path(char *str);
void	pos_word_path(int *word_begin, int *word_end, char *str, int words_ask);
char	*get_word_path(int nb_words_ask, char *str);
char	**my_str_to_tabpaths(char *str);
int	my_tablen(char **tab);
char	**my_tabcpy(char **old, char **new, int name, int check);
char	**my_tab_realloc(char **old, int name, int check);
int	my_setenv(char **tab, char ***envp);
int	check_setenv(char **tab);
void	set_exist(char **tab, char ***envp, int ovrwrt, int i);
int	*set_no_exist(char **tab, char ***envp, int i);

#endif /* !MINISHELL1_H_ */
