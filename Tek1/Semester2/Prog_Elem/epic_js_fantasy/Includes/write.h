/*
** file.h for  in /home/medec_o/rendu/corewar/str_to_inst_tab/test
** 
** Made by medec_o
** Login   <medec_o@epitech.net>
** 
** Started on  Thu Apr  3 22:04:15 2014 medec_o
** Last update Thu Apr  3 22:07:24 2014 medec_o
*/

#ifndef FILE_H_
# define FILE_H_

union u_int
{
  unsigned int  bin;
  unsigned char nbr[32];
};

typedef struct	s_file
{
  union u_int	p;
}		t_file;

#endif /* !FILE_H_ */
