/*
** main_diag.c for bsq in /home/moulin_c/rendu/Modules/C_Prog_Elem/BSQ/CPE-2013-BSQ
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Sun Dec  8 10:44:03 2013 moulin_c
** Last update Sun Dec  8 18:30:10 2013 moulin_c
*/

#include "bsq.h"
#include "get_next_line.h"

char	**make_tab_lines(int nb_lines, int nb_column, int fd)
{
  int	i;
  char	**tab;

  if ((tab = malloc(sizeof(char *) * (nb_lines + 1))) == NULL)
    return (NULL);
  i = 1;
  while (i < nb_lines)
    if ((tab[i++] = malloc((nb_column + 1) * sizeof(char))) == NULL)
      return (NULL);
  i = 1;
  while (i < nb_lines)
    {
      tab[i] = get_next_line(fd);
      tab[i][nb_column] = '\n';
      tab[i++][nb_column + 1] = '\0';
    }
  tab[i] = 0;
  return (tab);
}

int		main(int argc, char **argv)
{
  int		nb_lines;
  int		nb_column;
  int		fd;
  char		**tab;
  char		*str;
  t_param	var;

  var.file = argv[1];
  if ((fd = open(var.file, O_RDONLY)) == -1)
    {
      my_putstr("Cannot open file");
      exit(2);
    }
  str = get_next_line(fd);
  nb_lines = my_getnbr(str);
  str = get_next_line(fd);
  nb_column = my_strlen(str);
  tab = make_tab_lines(nb_lines, nb_column, fd);
  tab[0] = str;
  tab[0][nb_column] = '\n';
  tab[0][nb_column + 1] = '\0';
  more_square(tab, nb_lines, nb_column, var);
  return (0);
}
