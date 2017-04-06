/*
** parser.c for asm in /home/moulin_c/rendu/Semester 2/Modules/C_Prog_Elem/Corewar/ASM
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Fri Mar 28 18:33:49 2014 moulin_c
** Last update Sun Apr 13 23:37:45 2014 moulin_c
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include "../Includes/mylist.h"
#include "../Includes/asm.h"
#include "../Includes/get_next_line.h"
#include "../Includes/op.h"

int			check_char_label(char *str, int pos)
{
  int	i;
  int	j;

  i = 0;
  while (str[i])
    {
      j = 0;
      while (LABEL_CHARS[j] && LABEL_CHARS[j] != str[i])
	j++;
      if (LABEL_CHARS[j] != str[i])
	{
	  my_printf("Error at line #%d : label '%s' is not valid\n", pos, str);
	  my_printf("Only '%s' are allowed\n", LABEL_CHARS);
	  return (-1);
	}
      i++;
    }
  return (0);
}

int			check_labels(t_lab *tab)
{
  int	i;
  int	j;
  int	k;

  i = 0;
  while (tab[i].inst != NULL)
    {
      j = i + 1;
      while (tab[j].inst != NULL)
	{
	  if (!my_strcmp(tab[i].name, tab[j].name))
	    {
	      my_printf("Error : Multiple definition of label '%s'\n", tab[i].name);
	      return (-1);
	    }
	  j++;
	}
      if (check_char_label(tab[i].name, tab[i].pos) == -1)
	return (-1);
      i++;
    }
  return (0);
}

int			my_recup_labels(t_labels **labels, char *file)
{
  t_instr		*instr;
  t_save		save;
  int			fd;
  int			nb;
  int			key;

  if ((fd = open(file, O_RDONLY)) == -1)
    exit(1);
  key = 0;
  save.pos = 1;
  save.name = NULL;
  save.next_name = NULL;
  save.next_cmds = NULL;
  while (key == 0)
    {
      instr = make_instr();
      key = recup_instr(&instr, &save, fd);
      if (save.name != NULL)
	{
	  nb = label_size(instr);
	  add_label(labels, instr, save, nb);
	}
    }
  if (close(fd) == -1)
    exit(21);
}

void	aff_end_comp(t_file *file)
{
  if (file->name[0])
    my_printf("      %s\n", file->name);
  if (file->comment[0])
    my_printf("\t%s\n", file->comment);
  my_printf("Compilation Done !\n");
}

int			main(int argc, char **argv)
{
  t_file		file;
  t_labels		*labels;
  t_lab			*tab;

  if (argc > 1)
    {
      my_extension(argv[1]);
      my_recup_header(&file, argv[1]);
      labels = make_labels();
      my_recup_labels(&labels, argv[1]);
      tab = list_to_tab(labels);
      if (check_labels(tab) == -1)
	return (-1);
      if (check_instr(tab) == -1)
	return (-1);
      my_calc_labels(tab);
      file.tab = tab;
      make_cor(&file, argv[1]);
      aff_end_comp(&file);
    }
  else
    my_printf("Usage : ./asm 'YOUR_FILE.s'\n");
  return (0);
}
