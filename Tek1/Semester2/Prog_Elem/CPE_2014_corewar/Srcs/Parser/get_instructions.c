/*
** get_instructions.c for asm in /home/moulin_c/rendu/Semester 2/Modules/C_Prog_Elem/Corewar/ASM
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Fri Apr  4 17:02:05 2014 moulin_c
** Last update Sun Apr 13 21:53:42 2014 moulin_c
*/

#include "../Includes/mylist.h"
#include "../Includes/asm.h"

int			check_new_label(char *str)
{
  int			i;

  i = 0;
  while (str[i] && str[i] != ':')
    i++;
  if (str[i] == ':' && str[i - 1] != '%')
    return (1);
  return (0);
}

int	fill_instr(t_instr **instr, t_save *save, t_str *str, int key)
{
  char		**tab;
  int		nb;

  if (str->cmds != NULL)
    {
      if ((tab = malloc(sizeof(char *) * (count_words(str->cmds) + 1))) == NULL)
	return (-1);
      my_str_to_inst_tab(str->cmds, tab);
      nb = count_octet_instr(tab, save->pos);
      add_instr(instr, tab, nb, save);
      key = 1;
    }
  return (key);
}

int	get_instr(t_instr **instr, t_save *save, t_str *strs, int key)
{
  char	**tab;

  strs->cmds = strs->line;
  if (check_new_label(strs->cmds) == 1 && key > 0)
    {
      save->name = strs->name;
      tab = split_line(strs->cmds, strs->name, strs->line);
      save->next_name = tab[0];
      save->next_cmds = tab[1];
      save->pos_label = save->pos;
      key = 2;
    }
  else
    {
      tab = split_line(strs->cmds, strs->name, strs->line);
      if (tab[0] != NULL)
	{
	  strs->name = tab[0];
	  save->pos_label = save->pos;
	  strs->cmds = tab[1];
	}
      key = fill_instr(instr, save, strs, key);
    }
  return (key);
}

int	if_save(t_instr **instr, t_save *save, t_str *strs, int key)
{
  strs->name = save->next_name;
  strs->cmds = save->next_cmds;
  key = fill_instr(instr, save, strs, key);
  save->next_name = NULL;
  return (key);
}

int	recup_instr(t_instr **instr, t_save *save, int fd)
{
  t_str	strs;
  int	key;

  key = 0;
  strs.name = my_strdup("\0");
  while (key < 2)
    {
      if (save->next_name != NULL)
	key = if_save(instr, save, &strs, key);
      else
	{
	  if ((strs.line = get_next_line(fd)) == NULL)
	    {
	      save->name = strs.name;
	      return (1);
	    }
	  strs.line = epur_str(strs.line);
	  if (check_line(strs.line) == 0)
	    key = get_instr(instr, save, &strs, key);
	  (save->pos)++;
	}
    }
  return (0);
}
