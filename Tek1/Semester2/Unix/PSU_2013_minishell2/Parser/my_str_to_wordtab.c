/*
** my_str_to_wordtab.c for strtowordtab in /home/moulin_c/rendu/Piscine C/Piscine-C-Jour_08/ex_04
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Mon Nov 25 11:56:29 2013 moulin_c
** Last update Sun Mar  9 16:56:34 2014 moulin_c
*/

#include <stdlib.h>
#include "../Includes/parser.h"
#include "../Includes/my.h"

int	count_words(char *str)
{
  int	i;
  int	nb_words;

  nb_words = 0;
  i = 0;
  while (str[i] == ' ' || str[i] == '\t')
    i++;
  while (str[i])
    {
      if (str[i] == ' ' || str[i] == '\t')
	{
	  while (str[i] == ' ' || str[i] == '\t')
	    i++;
	  if (str[i] != '\0')
	    nb_words++;
	}
      else
	i++;
    }
  return (nb_words + 1);
}

void	pos_word(int *word_begin, int *word_end, char *str, int nb_words_ask)
{
  int	count;
  int	count_words;

  count = 0;
  count_words = 0;
  while (count_words != nb_words_ask)
    {
      while (str[count] == ' ' || str[count] == '\t')
	count++;
      *word_begin = count;
      while (str[count] != ' ' && str[count])
	count++;
      count_words++;
      *word_end = count - 1;
    }
}

char	*get_word(int nb_words_ask, char *str)
{
  int	word_begin;
  int	word_end;
  int	count;
  char	*wrd;

  pos_word(&word_begin, &word_end, str, nb_words_ask);
  count = 0;
  word_begin--;
  if ((wrd = malloc(sizeof(char) * (word_end - word_begin + 1))) == NULL)
    return (NULL);
  while (word_begin < word_end)
    wrd[count++] = str[++word_begin];
  wrd[count] = '\0';
  return (wrd);
}

char	**my_str_to_wordtab(char *str)
{
  int	nb_words;
  int	i;
  char	*word;
  char	**tab;

  nb_words = count_words(str);
  if ((tab = malloc(sizeof(*tab) * (nb_words + 1))) == NULL)
    return (NULL);
  i = 0;
  while (i < nb_words)
    {
      word = get_word((i + 1), str);
      tab[i] = my_strcpy(tab[i], word);
      free(word);
      i++;
    }
  tab[i] = 0;
  return (tab);
}
