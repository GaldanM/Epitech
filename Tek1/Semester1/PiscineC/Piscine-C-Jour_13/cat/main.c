/*
** main.c for cat in /home/moulin_c/rendu/Piscine-C-Jour_13/cat
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Thu Oct 24 18:49:55 2013 moulin_c
** Last update Thu Oct 24 18:50:07 2013 moulin_c
*/

int     main(int argc, char **argv)
{
  char buffer[30720];

  if (argc == 1)
    no_arg(buffer);
  else
    arg(buffer, argv, argc);
  my_putchar('\n');
}
