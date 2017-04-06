/*
** my_putstr.c for alum in /home/moulin_c/rendu/Semester 2/Modules/C_Prog_Elem/Alum_1/Allum1
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Tue Feb  4 19:58:01 2014 moulin_c
** Last update Wed Feb  5 18:36:04 2014 moulin_c
*/

void	my_putchar(char d)
{
  write(1, &d, 1);
}

void	my_putstr(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    {
      write(1, &str[i], 1);
      i++;
    }
}
