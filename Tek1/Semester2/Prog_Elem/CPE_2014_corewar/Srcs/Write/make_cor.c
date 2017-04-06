/*
** create_bin.c for asm in /home/moulin_c/rendu/Semester 2/Modules/C_Prog_Elem/Corewar/ASM/Write
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Wed Apr  9 16:48:38 2014 moulin_c
** Last update Sun Apr 13 23:38:30 2014 moulin_c
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include "../Includes/asm.h"
#include "../Includes/op.h"
#include "../Includes/mylist.h"

int		make_headers(t_file *file, int fd)
{
  int		len;

  len = 0;
  putnbr_file(COREWAR_EXEC_MAGIC, 4, fd);
  write(fd, file->name, my_strlen(file->name));
  len = PROG_NAME_LENGTH - 4 - len;
  while (len > 0)
    {
      putnbr_file(0, 1, fd);
      len--;
    }
  len = my_strlen(file->comment);
  write(fd, file->comment, len);
  len = COMMENT_LENGTH - len + PROG_NAME_LENGTH;
  while (len > 0)
    {
      putnbr_file(0, 1, fd);
      len--;
    }
}

char		*catch_name(char *name)
{
  char		*new;
  int		i;

  if ((new = malloc(sizeof(char) * (my_strlen(name) + 3))) == NULL)
    return (NULL);
  i = 0;
  while (name[i])
    {
      new[i] = name[i];
      i++;
    }
  new[i - 1] = 'c';
  new[i] = 'o';
  new[i + 1] = 'r';
  new[i + 2] = '\0';
  return (new);
}

int		make_cor(t_file *file, char *name)
{
  t_param	param;
  int		fd;
  int		open_flags;

  param.i = 0;
  open_flags = S_IWUSR | S_IRGRP | S_IRUSR | S_IROTH;
  name = catch_name(name);
  if ((fd = open(name, O_CREAT | O_RDWR | O_TRUNC, open_flags)) == -1)
    exit(15);
  make_headers(file, fd);
  while (file->tab[param.i].inst != NULL)
    {
      param.j = 0;
      while (file->tab[param.i].inst[param.j].instr != NULL)
	{
	  write_instr(file->tab[param.i].inst[param.j].instr, fd);
	  (param.j)++;
	}
      (param.i)++;
    }
  if (close(fd) == -1)
    exit(56);
}
