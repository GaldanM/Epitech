/*
** check_line.c for asm in /home/moulin_c/rendu/Semester 2/Modules/C_Prog_Elem/Corewar/ASM
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Thu Apr 10 19:28:35 2014 moulin_c
** Last update Sun Apr 13 21:51:23 2014 moulin_c
*/

int	check_line(char *epur)
{
  if (epur[0] == '\0')
    return (1);
  else if (!my_strncmp(epur, ".name", 5) != 0 ||
	   !my_strncmp(epur, ".comment", 8))
    return (1);
  else if (epur[0] == '#')
    return (1);
  else
    return (0);
}
