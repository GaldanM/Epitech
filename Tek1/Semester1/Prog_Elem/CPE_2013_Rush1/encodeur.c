/*
** main.c for Morse in /home/moulin_c/rendu/CPE_2013_Rush1
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Fri Dec 13 20:04:20 2013 moulin_c
** Last update Sun Dec 15 21:35:44 2013 moulin_c
*/

#include "morse.h"

t_encode	g_encode[36] = 
  {
    {'a', "-._"},
    {'b', "_.-.-.-"},
    {'c', "_.-._.-"},
    {'d', "_.-.-"},
    {'e', "-"},
    {'f', "-.-._.-"},
    {'g', "_._.-"},
    {'h', "-.-.-.-"},
    {'i', "-.-"},
    {'j', "-._._._"},
    {'k', "_.-._"},
    {'l', "-._.-.-"},
    {'m', "_._"},
    {'n', "_.-"},
    {'o', "_._._"},
    {'p', "-._._.-"},
    {'q', "_._.-._"},
    {'r', "-._.-"},
    {'s', "-.-.-"},
    {'t', "_"},
    {'u', "-.-._"},
    {'v', "-.-.-._"},
    {'w', "-._._"},
    {'x', "_.-.-._"},
    {'y', "_.-._._"},
    {'z', "_._.-.-"},
    {'.', "-._.-._.-._"},
    {'1', "-._._._._"},
    {'2', "-.-._._._"},
    {'3', "-.-.-._._"},
    {'4', "-.-.-.-._"},
    {'5', "-.-.-.-.-"},
    {'6', "_.-.-.-.-"},
    {'7', "_._.-.-.-"},
    {'8', "_._._.-.-"},
    {'9', "_._._._.-"},
  };

t_param_e	init_encod(t_param_e var)
{
  if (var.ret_read == -1)
    exit(1);
  if (var.buffer[var.ret_read - 1] == '\n')
    {
      var.is_read = 1;
      var.key = 0;
    }
  else
    var.ret_read++;
  if ((var.str = malloc(sizeof(char) * var.ret_read)) == NULL)
    {
      var.check_malloc = NULL;
      return (var);
    }
  var.str = my_strcpy(var.str, var.buffer);
  var.str[var.ret_read - 1] = '\0';
  var.i = 0;
  if (var.key == 1)
    write(1, "...", 3);
  if (check_encode(var.str) == -1)
    exit(1);
  return (var);
}

int		check_encode(char *str)
{
  int		i;
  int		j;

  i = 0;
  j = 0;
  while (str[i])
    {
      while (str[i] != g_encode[j].letter && j < 36)
	j++;
      if (str[i] == g_encode[j].letter)
	{
	  i++;
	  j = 0;
	}
      else
	{
	  my_putstr("Only 'a-z' or '1-9' or '.'\n");
	  return (-1);
	}
    }
  return (0);
}

t_param_e	write_morse(t_param_e var)
{
  int		j;

  j = 0;
  while (var.str[var.i] != g_encode[j].letter)
    j++;
  my_putstr(g_encode[j].code);
  return (var);
}

int		main()
{
  t_param_e	var;

  var.key = 0;
  while ((var.ret_read = read(0, var.buffer, SIZE)))
    {
      var = init_encod(var);
      if (var.check_malloc == NULL)
	{
	  my_putstr("Malloc failed");
	  exit(2);
	}
      while (var.str[var.i] != '\0')
	{
	  var = write_morse(var);
	  if (var.str[var.i + 1] != '\0')
	    write(1, "...", 3);
	  var.i++;
	}
      if (var.is_read && var.ret_read < SIZE)
	write(1, "\n", 1);
      var.key = 1;
      free(var.str);
    }
  return (0);
}
