/*
** asm.h for asm in /home/moulin_c/rendu/Semester 2/Modules/C_Prog_Elem/Corewar/ASM
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Fri Apr  4 18:46:57 2014 moulin_c
** Last update Sun Apr 13 10:54:34 2014 moulin_c
*/

#ifndef ASM_H_
# define ASM_H_

#include "mylist.h"
#include "op.h"

typedef struct	s_param
{
  int	i;
  int	j;
  int	k;
  int	lbl;
}		t_param;

typedef struct	s_save
{
  char			*name;
  int			pos;
  char			*next_name;
  char			*next_cmds;
}		t_save;

typedef struct	s_file
{
  char			name[PROG_NAME_LENGTH + 1];
  char			comment[COMMENT_LENGTH + 1];
  t_lab			*tab;
}		t_file;

typedef struct	s_str
{
  char	*line;
  char	*cmds;
  char	*name;
}		t_str;

#endif /* !MYLIST_H_ */
