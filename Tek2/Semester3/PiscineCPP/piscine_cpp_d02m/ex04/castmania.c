/*
** castmania.c for castmania in /home/moulin_c/rendu/piscine_cpp_d02m/ex04
** 
** Made by Galdan MOULINNEUF
** Login   <moulin_c@epitech.net>
** 
** Started on  Thu Jan  8 15:12:41 2015 Galdan MOULINNEUF
** Last update Thu Jan  8 17:51:42 2015 Galdan MOULINNEUF
*/

#include	<stdio.h>
#include	"castmania.h"

void print_int(t_instruction_type instruction_type, int *data)
{
  int		i = 0;

  if (instruction_type)
    i++;
  printf("%d\n", *data);
}

void print_float(t_instruction_type instruction_type, float *data)
{
  int		i = 0;

  if (instruction_type)
    i++;
  printf("%f\n", *data);
}

void exec_operation(t_instruction_type instruction_type, void *data)
{
  t_add		*add;
  t_div		*div;
  t_integer_op	*inte;
  t_decimale_op	*deci;

  if (instruction_type == ADD_OPERATION)
    {
      add = ((t_add *)((t_instruction *)data)->operation);
      exec_add(add);
      if (((t_instruction *)data)->output_type == VERBOSE)
	printf("%d\n", add->add_op.res);
    }
  else if (instruction_type == DIV_OPERATION)
    {
      div = ((t_div *)((t_instruction *)data)->operation);
      exec_div(div);
      if (((t_instruction *)data)->output_type == VERBOSE)
	{
	  inte = ((t_integer_op *)div->div_op);
	  deci = ((t_decimale_op *)div->div_op);
	  if (div->div_type == INTEGER)
	    printf("%d\n", inte->res);
	  else if (div->div_type == DECIMALE)
	    printf("%f\n", deci->res);
	}
    }
}

void exec_instruction(t_instruction_type instruction_type, void *data)
{
  void(*tab[4])();

  tab[PRINT_INT] = &print_int;
  tab[PRINT_FLOAT] = &print_float;
  tab[DIV_OPERATION] = &exec_operation;
  tab[ADD_OPERATION] = &exec_operation;
  (*tab[instruction_type])(instruction_type, data);
}
