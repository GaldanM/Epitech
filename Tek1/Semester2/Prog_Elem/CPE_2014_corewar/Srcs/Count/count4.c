/*
** count4.c for asm in /home/moulin_c/rendu/Semester 2/Modules/C_Prog_Elem/Corewar/ASM/Count
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Sun Apr 13 18:29:28 2014 moulin_c
** Last update Sun Apr 13 20:49:58 2014 moulin_c
*/

int	my_lfork(char **tab, int *oct, int pos)
{
  my_fork(tab, oct, pos);
}

int	my_fork(char **tab, int *oct, int pos)
{
  check_type(tab, pos);
  *(oct) = 3;
}

int	my_nothing(char **tab, int *oct)
{
  return (0);
}
