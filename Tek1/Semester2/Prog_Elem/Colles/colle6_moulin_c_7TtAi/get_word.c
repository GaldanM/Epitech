/*
** get_word.c for my_boogle in /home/sement_s/rendu/colle6_moulin_c_7TtAi
** 
** Made by Stephen SEMENT
** Login   <sement_s@epitech.net>
** 
** Started on  Mon Jun  2 21:45:31 2014 Stephen SEMENT
** Last update Mon Jun  2 21:53:58 2014 Stephen SEMENT
*/

#include	<unistd.h>
#include	<stdlib.h>

#define		BUFF_SIZE 4096

char		*buff_to_word(char *buff, char *word)
{
  int		i;

  i = my_strlen(buff);
  if ((word = malloc(sizeof(char) * i + 1)) == NULL)
    {
      my_putstr("Malloc error.\n");
      return (NULL);
    }
  i = 0;
  while (buff[i] != '\0')
    {
      word[i] = buff[i];
      i = i + 1;
    }
  word[i] = '\0';
  return (word);
}

char		*get_word()
{
  char		buff[BUFF_SIZE];
  char		*word;

  if (read(1, buff, BUFF_SIZE) < 0)
    {
      my_putstr("Read error, what happened?!\n");
      return (NULL);
    }
  if ((word = buff_to_word(buff, word)) == NULL)
    return (NULL);
  return (word);
}
