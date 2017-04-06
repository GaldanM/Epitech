/*
** my_putchar.c for asm in /home/moulin_c/rendu/Semester 2/Modules/C_Prog_Elem/Corewar/ASM
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Tue Apr  8 21:26:39 2014 moulin_c
** Last update Tue Apr  8 21:26:42 2014 moulin_c
*/

void	my_putchar(char d)
{
  write(1, &d, 1);
}
