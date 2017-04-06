/*
** my_ls_l.c for my_ls in /home/moulin_c/rendu/Modules/Unix/My_ls/PSU_2013_my_ls
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Sat Nov 30 16:58:23 2013 moulin_c
** Last update Sun Dec  1 19:03:43 2013 moulin_c
*/

#include "my_ls.h"

void	aff_data_l(char **tab, int j)
{
  struct stat	file;
  struct passwd	*info;
  struct group	*info_2;
  char		*lst_md;
  
  my_rights(tab[j]);
  lstat(tab[j], &file);
  info = getpwuid(file.st_uid);
  info_2 = getgrgid(file.st_gid);
  lst_md = ctime(&file.st_mtime);
  lst_md = mod_date(lst_md);
  my_printf(" %d %s %s %d\t", file.st_nlink, info->pw_name, info_2->gr_name, file.st_size);
  my_printf("%s %s\n", lst_md, tab[j]);
  free(lst_md);
}

void	my_ls_l()
{
  char		**tab;
  int		j;

  tab = tab_name();
  j = 0;
  nb_blocks();
  while (tab[j] != 0)
    {
      if (tab[j][0] == '.')
	j++;
      else
	{
	  aff_data_l(tab, j);
	  j++;
	}
    }
  free(tab);
}
