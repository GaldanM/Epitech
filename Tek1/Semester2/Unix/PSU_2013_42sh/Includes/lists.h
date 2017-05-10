/*
** lists.h for 42 in /home/moulin_c/rendu/Semester 2/Modules/Unix/42sh/Minishell1
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Wed May  7 13:35:24 2014 moulin_c
** Last update Sun May 25 02:18:22 2014 moulin_c
*/

#ifndef LISTS_H_
# define LISTS_H_

typedef struct	s_cmds
{
  struct s_cmds		*prev;
  char			*cmd;
  struct s_args		*args;
  char			*separator;
  int			fdin;
  int			fdout;
  int			fderr;
  int			ret_exec;
  int			is_built;
  int			root;
  struct s_cmds		*next;
}		t_cmds;

typedef struct	s_args
{
  struct s_args		*prev;
  char			*arg;
  int			root;
  struct s_args		*next;
}		t_args;

typedef struct	s_env
{
  struct s_env		*prev;
  char			*name;
  char			*var;
  int			root;
  struct s_env		*next;
}		t_env;

typedef struct	s_bin
{
  struct s_bin		*prev;
  char			*path;
  int			root;
  struct s_bin		*next;
}		t_bin;

typedef struct	s_syntax
{
  struct s_syntax	*prev;
  char			*str;
  int			root;
  struct s_syntax	*next;
}		t_syntax;

/*
** Make
*/
t_cmds		*make_cmds(void);
t_args		*make_args(void);
t_env		*make_env(void);
t_bin		*make_bin(void);
t_syntax	*make_syntax(void);
/*
** Make
*/

/*
** Add
*/
int		add_cmd(t_cmds **, char *);
int		add_arg(t_args **, char *);
int		add_env(t_env **, char *, char *);
int		add_bin(t_bin **, char *);
int		add_syntax(t_syntax **, char *);
/*
** End Add
*/

/*
** Del
*/
void		del_env(t_env *);
void		del_cmd(t_cmds *);
void		del_arg(t_args *);
void		del_syntax(t_syntax *);
/*
** Del
*/

/*
** Swap
*/
/* void		swap_syntax(char *, char *); */
/*
** End Swap
*/

#endif /* !LISTS_H_ */
