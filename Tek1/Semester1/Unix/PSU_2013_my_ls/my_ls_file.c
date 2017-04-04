/*
** my_ls_file.c for my_ls in /home/moulin_c/rendu/Modules/Unix/My_ls/PSU_2013_my_ls
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Sun Dec  1 12:21:03 2013 moulin_c
** Last update Sun Dec  1 19:22:09 2013 moulin_c
*/

#include "my_ls.h"

void	my_ls_file(char **name_file, int nb_files)
{
  struct dirent *ptr;
  struct stat	file;
  DIR		*dir;
  int		i;

  i = 1;
  while (i < nb_files)
    {
      lstat(name_file[i], &file);
      dir = opendir(name_file[i]);
      if (dir == NULL)
	my_printf("%s\n", name_file[i]);
      else if (S_ISDIR(file.st_mode))
	{
	  my_printf("%s:\n", name_file[i]);
	  dir = opendir(name_file[i]);
	  while (ptr = readdir(dir))
	    my_printf("%s\n", ptr->d_name);
	  my_printf("\n");
	}
      i++;
    }
}
