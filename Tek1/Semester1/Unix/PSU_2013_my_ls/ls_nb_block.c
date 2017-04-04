/*
** ls_nb_block.c for my_ls in /home/moulin_c/rendu/Modules/Unix/My_ls/PSU_2013_my_ls
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Sun Dec  1 18:54:04 2013 moulin_c
** Last update Sun Dec  1 19:06:24 2013 moulin_c
*/

#include "my_ls.h"

int	nb_blocks()
{
  struct dirent		*ptr;
  struct stat		file;
  DIR			*dir;
  unsigned long		res;

  res = 0;
  dir = opendir(".");
  while ((ptr = readdir(dir)))
    {
      lstat(ptr->d_name, &file);
      if (ptr->d_name[0] == '.')
	ptr = readdir(dir);
      res = res + (file.st_blocks / 2);
    }
  my_printf("total %d\n", res);
}
