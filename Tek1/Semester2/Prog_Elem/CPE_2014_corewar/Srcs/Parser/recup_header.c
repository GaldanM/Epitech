/*
** recup_header.c for asm in /home/moulin_c/rendu/Semester 2/Modules/C_Prog_Elem/Corewar/ASM
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Mon Apr  7 15:49:13 2014 moulin_c
** Last update Sun Apr 13 23:39:16 2014 moulin_c
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "../Includes/asm.h"

void	if_name(t_file *header, char *str)
{
  int	i;
  int	j;

  j = 0;
  i = 5;
  while (str[i] && (str[i] == ' ' || str[i] == '\t'))
    i++;
  if (str[i] && str[i] == 34)
    i++;
  while (str[i] && str[i] != 34)
    {
      header->name[j] = str[i];
      i++;
      j++;
    }
  header->name[j] = '\0';

}

void	if_comment(t_file *header, char *str)
{
  int	i;
  int	j;

  j = 0;
  i = 8;
  while (str[i] && (str[i] == ' ' || str[i] == '\t'))
    i++;
  if (str[i] && str[i] == 34)
    i++;
  while (str[i] && str[i] != 34)
    {
      header->comment[j] = str[i];
      i++;
      j++;
    }
  header->comment[j] = '\0';
}

void	my_recup_header(t_file *header, char *file)
{
  int	fd;
  int	i;
  int	j;
  int	nb;
  char	*str;

  if ((fd = open(file, O_RDONLY)) == -1)
    exit(15);
  header->name[0] = '\0';
  header->comment[0] = '\0';
  while ((str = get_next_line(fd)) != NULL)
    {
      epur_str(str);
      if (my_strncmp(str, ".name", 5) == 0)
	if_name(header, str);
      else if (my_strncmp(str, ".comment", 8) == 0)
	if_comment(header, str);
    }
  if (close(fd) == -1)
    exit(23);
}
