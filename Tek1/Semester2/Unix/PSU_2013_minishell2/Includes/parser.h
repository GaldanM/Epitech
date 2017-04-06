/*
** parser.h for shell in /home/moulin_c/rendu/Modules/Unix/Minishell/Minishell_1/PSU_2013_minishell1
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Thu Dec 19 14:16:33 2013 moulin_c
** Last update Sun Mar  9 16:37:34 2014 moulin_c
*/

#ifndef PARSER_H_
# define PARSER_H_

typedef struct	s_cmd
{
  char	**cmd;
  int	fdin;
  int	fdout;
}		t_cmd;

typedef struct	s_fd
{
  int	i;
  int	j;
  int	a;
  int	beg;
  int	end;
  int	save;
  int	pipefd[2];
  int	savepos;
  int	key;
}		t_fd;

int	my_tablen(char **tab);
char	**my_tabcpy(char **old, char **new, int name, int check);
char	**my_tab_realloc(char **old, int name, int check);

int	my_free_tab(char **tab);

int	my_show_trpl_tab(char ***tab_p);

int	my_show_wordtab(char **tab);

int	count_words_path(char *str);
void	pos_word_path(int *word_begin, int *word_end, char *str, int words_ask);
char	*get_word_path(int nb_words_ask, char *str);
char	**my_str_to_tabpaths(char *str);

int	count_words(char *str);
void	pos_word(int *word_begin, int *word_end, char *str, int nb_words_ask);
char	*get_word(int nb_words_ask, char *str);
char	**my_str_to_wordtab(char *str);

int	count_number(char **tab);
char	**my_put_word_int_tab(char **tab_p, char **tab, int beg, int end);

#endif /* !PARSER_H_ */
