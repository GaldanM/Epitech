/*
** disp_files.c for TP in /home/moulin_c/rendu/Modules/Unix/My_ls/TP/Step1-2
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Wed Nov 27 16:36:05 2013 moulin_c
** Last update Sun Dec  1 19:19:49 2013 moulin_c
*/

#include "my_ls.h"

int	main(int argc, char **argv)
{
  if (argc >= 2)
    {
      if (argv[1][0] == '-')
	tab_flag_ls(argv[1], 1);
      else
	my_ls_file(argv, argc);
    }
  else if (argc == 1)
    my_ls();
  else
    my_printf("Usage : ./my_ls [flag] [file]\n");
  return (0);
}
