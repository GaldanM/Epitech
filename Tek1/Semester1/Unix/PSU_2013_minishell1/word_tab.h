/*
** word_tab.h for word_tab in /home/moulin_c/rendu/Modules/Unix/Minishell/Minishell_1/PSU_2013_minishell1
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Thu Dec 19 14:16:33 2013 moulin_c
** Last update Sat Dec 21 02:13:21 2013 moulin_c
*/

#ifndef WORD_TAB_H_
# define WORD_TAB_H_

int	count_words(char *str);
void	pos_word(int *word_begin, int *word_end, char *str, int nb_words_ask);
char	*get_word(int nb_words_ask, char *str);
char	**tab_words(int nb_words, char *str);
char	**my_str_to_wordtab(char *str);
int	my_show_wordtab(char **tab);
int	my_free_tab(char **tab);

#endif /* !WORD_TAB_H_ */
