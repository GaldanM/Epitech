/*
** ls_rights.c for my_ls in /home/moulin_c/rendu/Modules/Unix/My_ls/PSU_2013_my_ls
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Sat Nov 30 17:01:41 2013 moulin_c
** Last update Sun Dec  1 10:41:42 2013 moulin_c
*/

#include "my_ls.h"

void	my_rights(char *name)
{
  struct stat	file;

  lstat(name, &file);
  my_printf((S_ISDIR(file.st_mode)) ? ("d") : (""));
  my_printf((S_ISLNK(file.st_mode)) ? ("l") : (""));
  my_printf((S_ISREG(file.st_mode)) ? ("-") : (""));
  my_printf((S_ISCHR(file.st_mode)) ? ("c") : (""));
  my_printf((S_ISBLK(file.st_mode)) ? ("b") : (""));
  my_printf((S_ISFIFO(file.st_mode)) ? ("p") : (""));
  my_printf((S_ISSOCK(file.st_mode)) ? ("s") : (""));
  my_printf((S_IRUSR & file.st_mode) ? ("r") : ("-"));
  my_printf((S_IWUSR & file.st_mode) ? ("w") : ("-"));
  my_printf((S_IXUSR & file.st_mode) ? ("x") : ("-"));
  my_printf((S_IRGRP & file.st_mode) ? ("r") : ("-"));
  my_printf((S_IWGRP & file.st_mode) ? ("w") : ("-"));
  my_printf((S_IXGRP & file.st_mode) ? ("x") : ("-"));
  my_printf((S_IROTH & file.st_mode) ? ("r") : ("-"));
  my_printf((S_IWOTH & file.st_mode) ? ("w") : ("-"));
  my_printf((S_IXOTH & file.st_mode) ? ("x") : ("-"));
}
