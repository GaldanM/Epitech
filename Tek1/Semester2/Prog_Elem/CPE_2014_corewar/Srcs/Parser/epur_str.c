/*
** epur_str.c for asm in /home/moulin_c/rendu/Semester 2/Modules/C_Prog_Elem/Corewar/ASM/Parser
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Tue Apr  8 19:21:36 2014 moulin_c
** Last update Wed Apr  9 16:29:25 2014 moulin_c
*/

#include <stdlib.h>

int	second_malloc_epur(char *str)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  while (str[i])
    {
      if (str[i] == ',' && str[i - 1] == ' ')
	i++;
      i++;
      j++;
    }
  return (j);
}

char	*second_epur_str(char *str)
{
  char	*new;
  int	i;
  int	j;

  i = 0;
  j = 0;
  if ((new = malloc(sizeof(char) * (second_malloc_epur(str) + 1))) == NULL)
    return (NULL);
  while (str[i])
    {
      if (str[i] == ',' && str[i - 1] == ' ')
	{
	  new[j - 1] = ',';
	  i++;
	}
      new[j] = str[i];
      i++;
      j++;
    }
  new[j] = '\0';
  free(str);
  return (new);
}

int	first_malloc_epur(char *str)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  while (str[i])
    {
      while (str[i] && (str[i] == ' ' || str[i] == '\t'))
	i++;
      while (str[i] && str[i] != ' ' && str[i] != '\t' && str[i] != ',')
	{
	  i++;
	  j++;
	}
      if (str[i])
	{
	  i++;
	  j++;
	}
    }
  return (j);
}

char	*first_epur_str(char *str, int i, int j)
{
  char	*new;

  if ((new = malloc(sizeof(char) * (first_malloc_epur(str) + 1))) == NULL)
    return (NULL);
  while (str[i])
    {
      while (str[i] && (str[i] == ' ' || str[i] == '\t'))
	i++;
      while (str[i] && str[i] != ' ' && str[i] != '\t' && str[i] != ',')
	new[j++] = str[i++];
      if (str[i] && str[i] == ',')
	{
	  new[j++] = ',';
	  i++;
	}
      else if (str[i])
	{
	  new[j++] = ' ';
	  i++;
	}
    }
  new[j] = '\0';
  if (new[j - 1] == ' ' || new[j - 1] == '\t')
    new[j - 1] = '\0';
  return (new);
}

char	*epur_str(char *str)
{
  char	*new;
  int	i;
  int	j;

  i = 0;
  j = 0;
  new = first_epur_str(str, i, j);
  new = second_epur_str(new);
  return (new);
}
