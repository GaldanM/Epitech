/*
** operations.c for operations in /home/moulin_c/rendu/Piscine-C-Jour_11/do-op
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Mon Oct 21 18:28:51 2013 moulin_c
** Last update Tue Oct 22 11:16:33 2013 moulin_c
*/

int	add(char *argv1, char *argv3)
{
  int	result_add;

  result_add = my_getnbr(argv1) + my_getnbr(argv3);
  my_put_nbr(result_add);
  my_putchar('\n');
}

int     sub(char *argv1, char *argv3)
{
  int   result_sub;

  result_sub = my_getnbr(argv1) - my_getnbr(argv3);
  my_put_nbr(result_sub);
  my_putchar('\n');
}

int     multiple(char *argv1, char *argv3)
{
  int   result_mult;

  result_mult = my_getnbr(argv1) * my_getnbr(argv3);
  my_put_nbr(result_mult);
  my_putchar('\n');
}

int     divide(char *argv1, char *argv3)
{
  int   result_div;

  if (my_getnbr(argv3) == 0)
    {
      my_putstr("Stop : division by zero\n");
      return (0);
    }
  result_div = my_getnbr(argv1) / my_getnbr(argv3);
  my_put_nbr(result_div);
}

int     modulo(char *argv1, char *argv3)
{
  int   result_modu;

  if (my_getnbr(argv3) == 0)
    {
      my_putstr("Stop : modulo by zero\n");
      return (0);
    }
  result_modu = my_getnbr(argv1) % my_getnbr(argv3);
  my_put_nbr(result_modu);
}
