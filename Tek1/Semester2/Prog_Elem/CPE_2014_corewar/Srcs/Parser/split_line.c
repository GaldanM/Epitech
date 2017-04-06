/*
** split_line.c for asm in /home/moulin_c/rendu/Semester 2/Modules/C_Prog_Elem/Corewar/ASM
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Fri Apr  4 17:01:37 2014 moulin_c
** Last update Sun Apr 13 23:36:04 2014 moulin_c
*/

#include <stdlib.h>

#define ALPHA(car)	(car >= 'a' && car <= 'z')

char	*if_cmds(char *line, char *cmds, int i, int end)
{
  int	beg;

  if (line[i + 1] != '\0' && line[i + 2] != ' ')
    {
      while (line[i] && !ALPHA(line[i]))
	i++;
      if (line[i] != '\0')
	{
	  if ((cmds = malloc(sizeof(char) * (end - i + 1))) == NULL)
	    exit(25);
	  beg = 0;
	  while (i <= end)
	    {
	      cmds[beg] = line[i];
	      beg++;
	      i++;
	    }
	}
    }
  else
    cmds = NULL;
  return (cmds);
}

char		*if_label(char *name, char *line, char **tab, int *end)
{
  int	beg;

  beg = 0;
  if ((name = malloc(sizeof(char) * (*end - beg + 1))) == NULL)
    exit(30);
  while (beg < *end)
    {
      name[beg] = line[beg];
      beg++;
    }
  name[beg] = '\0';
  return (name);
}

char		**split_line(char *cmds, char *name, char *line)
{
  int	end;
  int	i;
  char	**tab;

  if ((tab = malloc(sizeof(char *) * 3)) == NULL)
    exit(20);
  tab[2] = NULL;
  i = 0;
  while (line[i] && line[i] != ':')
    i++;
  end = i;
  if ((!line[i]) || (line[i - 1] == '%'))
    {
      tab[0] = NULL;
      return (tab);
    }
  name = if_label(name, line, tab, &end);
  end++;
  while (line[end])
    end++;
  cmds = if_cmds(line, cmds, i, end);
  tab[0] = name;
  tab[1] = cmds;
  return (tab);
}
