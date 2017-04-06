/*
** builts.h for shell in /home/moulin_c/rendu/Semester 2/Modules/Unix/Minishell/Minishell_2/PSU_2013_minishell2/Includes
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Fri Feb 28 16:54:33 2014 moulin_c
** Last update Sun Mar  9 12:45:16 2014 moulin_c
*/

#ifndef BUILTS_H_
# define BUILTS_H_

void	my_exit(char **tab);
int	my_env(char **envp);
int	my_unsetenv(char **tab, char ***env);

char	*choose_dir(char **tab, char **envp);
int	my_cd(char **tab, char ***envp);

int	check_setenv(char **tab);
void	set_exist(char **tab, char ***envp, int ovrwrt, int i);
char	*set_no_exist(char **tab, char ***envp, int i);
int	my_setenv(char **tab, char ***envp);

#endif	/* !BUILTS_H_ */
