/*
** minishell1.h for minishell1 in /home/moulin_c/rendu/Modules/Unix/Minishell/Minishell_1/PSU_2013_minishell1
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Thu Dec 19 14:21:58 2013 moulin_c
** Last update Sun Mar  9 16:19:32 2014 moulin_c
*/

#ifndef SHELL_H_
# define SHELL_H_

# define REDIRECT_EG(tab)	(tab == 124 || tab == 60 || tab == 62 || tab == 59)
# define REDIRECT_DIFF(tab)	(tab != 124 && tab != 60 && tab != 62 && tab != 59)

# define CMP_EG1(str)		(!my_strcmp(str, ">"))
# define CMP_EG2(str)		(!my_strcmp(str, "<") || !my_strcmp(str, ">>"))
# define CMP_REDIR_EG(str)	(CMP_EG1(str) || CMP_EG2(str))

# define CMP_DIF1(str)		(my_strcmp(str, "<") && my_strcmp(str, ">>"))
# define CMP_DIF2(str)		(my_strcmp(str, "|") && my_strcmp(str, ">"))
# define CMP_DIF3(str)		(my_strcmp(str, ";"))
# define CMP_REDIR_DIF(str)	(CMP_DIF1(str) && CMP_DIF2(str) && CMP_DIF3(str))

#include <unistd.h>
#include "parser.h"

int	check_builts(char **tab, char ***envp);
int	check_redirect(char **tab, char ***envp);
char	*browse_paths(char *str, char **tab_paths, int i);
char	*check_locate(char *str, char **envp);

char	**del_redir(char **tab_p);
int	find_redir(char **tab_p);

int	get_path_home(char **envp);
char	*get_path(char **envp);

void	get_signal(pid_t pid);
int	my_shell(char ***envp);
int	main(int argc, char **argv, char **envp);

int	my_fork(char **tab, char ***envp);
int	my_exec(t_cmd *tab_p, int j, char ***envp);

#endif /* !SHELL_H_ */
