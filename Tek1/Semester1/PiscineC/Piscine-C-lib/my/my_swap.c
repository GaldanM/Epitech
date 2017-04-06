/*
** my_swap.c for my_swap in /home/moulin_c/rendu/Piscine-C-Jour_04
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Thu Oct  3 12:02:51 2013 moulin_c
** Last update Fri Oct  4 20:02:19 2013 moulin_c
*/

int     my_swap(int *a, int *b)
{
  int	stock;

  stock = *a;
  *a = *b;
  *b = stock;
}
