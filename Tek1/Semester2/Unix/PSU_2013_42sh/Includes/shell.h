/*
** shell.h for 42 in /home/moulin_c/rendu/Semester 2/Modules/Unix/42sh/Minishell1
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Wed May  7 12:54:37 2014 moulin_c
** Last update Sun Jun  1 18:29:30 2014 doghri_f
*/

#ifndef SHELL_H_
# define SHELL_H_

# include	<stdio.h>
# include	"lists.h"
# include	"my.h"

#define		END(car, i)	(car[i] == ';')
#define		SPACES(car)	(car == ' ' || car == '\t')
#define		SEP(car, i)	((SEP1(car, i)) || (SEP2(car, i)))
#define		SP(car, i)	(car[i] == '|' || car[i] == '&')
#define		SR(car, i)	(car[i] == '<' || car[i] == '>')
#define		NB(car, i)	((car[i] == '1' || car[i] == '2'))
#define		ND(car, i)	((NB(car, i) && car[i + 1] == '>'))
#define		NA(car, i)	((NB(car, i) && car[i - 1] == '&'))
#define		DA(car, i)	((car[i] == '&' && car[i + 1] == '&'))
#define		DP(car, i)	((car[i] == '|' && car[i + 1] == '|'))
#define		NR(car, i)	(ND(car, i) && car[i + 2] == '&' && NB(car, i + 3))
#define		SEP1(car, i)	(SP(car, i) || SR(car, i) || DA(car, i) || DP(car, i))
#define		SEP2(car, i)	(ND(car, i) || NA(car, i) || NR(car, i))

/*
** Parser
*/
void		disp_cmds(t_cmds *);

char		*concat_syntax(t_syntax *);
char		*check_syntax(char *);

int		str_to_syntaxlist(t_syntax *, char *);

t_cmds		*my_pipe(t_cmds *);
t_cmds		*my_redir_left(t_cmds *);
t_cmds		*my_redir_right(t_cmds *);
t_cmds		*my_dbl_redir_left(t_cmds *);
t_cmds		*my_dbl_redir_right(t_cmds *);

t_cmds		*find_next_cmd(t_cmds *);
t_cmds		*find_next_cmd_exec(t_cmds *);
t_cmds		*my_exec_func(int, t_cmds *);
void		tab_point(char *[15]);
int		get_fds(t_cmds *);

int		malloc_carg(char *, int, int);
int		recup_cmd(t_cmds *, char *, int);
int		recup_args(t_cmds *, char *, int);
int		recup_separ(t_cmds *, char *, int);
int		get_cmds(t_cmds *, t_env *);

char		*change_var(char *, t_env *);
void		replace_arg(t_args *, t_env *);
void		replace_env(t_cmds *, t_env *);
int		check_pipe(char *);
char		*complete_pipe(char *);
int		str_to_wordlist(t_cmds *, char *, t_env *);

char		*get_name_env(char *);
char		*get_var_env(char *);
int		get_env(t_env *, char **);

t_cmds		*my_redir_err(t_cmds *);
t_cmds		*my_redir_both(t_cmds *);

t_cmds		*my_pipe(t_cmds *);
int		check_bad(char *);
t_cmds		*redir_error(t_cmds *);

t_syntax	*find_good_redir(t_syntax *);
t_syntax	*swap_redir(t_syntax *);
t_syntax	*swap_both(t_syntax *);
void		sort_syntax(t_syntax *);

t_env		*my_init_env(char **);
/*
** End Parser
*/

/*
** Shell
*/
int		count_args(t_cmds *);
char		**cmd_to_tab(t_cmds *);
int		count_env(t_env *);
char		**env_to_tab(t_env *);

int		get_var_bin(char **);
char		*malloc_bin_path(char *, int, int *, int *);
int		str_to_pathslist(t_bin *, char *);
char		*path_bin(char *, t_bin *);
char		*get_bin_path(char *, char **);

int		my_execve(char **, char **);
int		my_exec(t_cmds *, t_env *);
int		exec_loop(t_cmds *, t_env *);

void		do_builts_child(t_cmds *, t_env **);
t_cmds		*do_builts_father(t_cmds *, t_env **);
int		my_check_builts(t_cmds *);

int		check_exec(t_cmds *);
int		gere_sig_shell(int);

void		my_child(t_cmds *, t_env *);
void		my_ret_exec(t_cmds *, char *);
int		my_closes(t_cmds *);
int		my_dups(t_cmds *);
int		my_execve(char **, char **);
/*
** End Shell
*/

/*
** Builts
*/
int		put_backslash_char(t_cmds *, char *, int, char *);
int		noption(t_cmds *);
int		eoption(t_cmds *);
int		beoption(t_cmds *);
int		check_echo_option(t_cmds *);
int		check_echo_args(t_cmds *);
int		check_echo_args_space(t_cmds *);
int		my_echo(t_cmds *);

int		my_unsetenv(t_env **, t_cmds *);

char		*get_pwd(t_env **);
char		*get_oldpwd(t_env **);
void		my_cd_m(t_env **, char *);
char		*concat_pwd(int, char *, char *);
char		*erase_dots(char *, int);
char		*epur_dots(char *);
int		strcat_pwd(t_env **, t_cmds *);
int		set_env(t_env **, t_cmds *);
char		*get_home(t_env *);
int		mcd(t_env **, t_cmds *);
int		my_cd(t_env **, t_cmds *);

int		ooption(t_env **);
int		nooption(t_env **);
int		check_option(t_cmds *);
int		my_env(t_env **, t_cmds *);

int		check_env(char *, t_env **);
int		my_setenv(t_env **, t_cmds *);

/*
** End Builts
*/
#endif /* !SHELL_H_ */
