/*
** my_str_to_pathtab.c for str_to_path in /home/moulin_c/rendu/Modules/Unix/Minishell/Minishell_1/PSU_2013_minishell1
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Thu Dec 19 17:13:57 2013 moulin_c
** Last update Mon Dec 30 13:10:42 2013 moulin_c
*/

#include <stdlib.h>
#include "word_tab.h"
#include "my.h"

int	count_words_path(char *str)
{
  int	i;
  int	nb_words;

  nb_words = 0;
  i = 0;
  while (str[i] == ':' && str[i])
    i++;
  while (str[i])
    {
      if (str[i] == ':' && str[i])
	{
	  while (str[i] == ':' && str[i])
	    i++;
	  if (str[i])
	    nb_words++;
	}
      else
	i++;
    }
  nb_words++;
  return (nb_words);
}

void	pos_word_path(int *word_begin, int *word_end, char *str, int words_ask)
{
  int	count;
  int	count_words;

  count = 0;
  count_words = 0;
  while (count_words != words_ask && str[count])
    {
      while (str[count] == ':' && str[count])
	count++;
      *word_begin = count;
      while (str[count] != ':' && str[count])
	count++;
      count_words++;
      *word_end = count - 1;
    }
}

char	*get_word_path(int nb_words_ask, char *str)
{
  int   word_begin;
  int   word_end;
  int	count;
  char	*wrd;

  pos_word_path(&word_begin, &word_end, str, nb_words_ask);
  count = 0;
  word_begin--;
  if ((wrd = malloc(sizeof(char) * (word_end - word_begin + 1))) == NULL)
    return (NULL);
  while (word_end != word_begin)
    wrd[count++] = str[++word_begin];
  wrd[count] = '\0';
  return (wrd);
}

char	**my_str_to_tabpaths(char *str)
{
  int	nb_words;
  int	i;
  char	*word;
  char	**tab;

  nb_words = count_words_path(str);
  if ((tab = malloc(sizeof(*tab) * (nb_words + 1))) == NULL)
    return (NULL);
  i = 0;
  while (i < nb_words)
    {
      word = get_word_path((i + 1), str);
      tab[i] = my_strcpy(tab[i], word);
      free(word);
      i++;
    }
  tab[i] = 0;
  return (tab);
}
