/*
** ls_count_files.c for my_ls in /home/moulin_c/rendu/Modules/Unix/My_ls/PSU_2013_my_ls
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Sun Dec  1 11:44:29 2013 moulin_c
** Last update Sun Dec  1 15:39:02 2013 moulin_c
*/

#include "my_ls.h"

int	count_files()
{
  struct dirent	*ptr;
  DIR		*dir;
  int		count;

  if ((dir = opendir(".")) == NULL)
    exit(1);
  ptr = readdir(dir);
  while (ptr != NULL)
    {
      count++;
      ptr = readdir(dir);
    }
  closedir(dir);
  return (count);
}
