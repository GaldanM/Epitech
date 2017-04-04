/*
** my_strcapitalize.c for my_strcapitalize in /home/moulin_c/rendu/Piscine-C-Jour_06/ex_09
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Tue Oct  8 16:25:59 2013 moulin_c
** Last update Tue Oct  8 20:38:39 2013 moulin_c
*/

char    *min(char *str, int count)
{
  if(str[count] >= 97 && str[count] <= 122)
    {
      if (str[count - 1] >= 48 && str[count - 1] <= 57)
        str[count] = str[count];
      else if (str[count - 1] >= 65 && str[count - 1] <= 90)
        str[count] = str[count];
      else if (str[count - 1] >= 97 && str[count - 1] <= 122)
        str[count] = str[count];
      else if (count == 0)
        str[count] = str[count] - 32;
      else
        str[count] = str[count] - 32;
    }
  return (str);
}

char    *maj(char *str, int count)
{
  if(str[count] >= 65 && str[count] <= 90)
    {
      if (str[count - 1] >= 48 && str[count - 1] <= 57)
        str[count] = str[count] + 32;
      else if (str[count - 1] >= 65 && str[count - 1] <= 90)
        str[count] = str[count] + 32;
      else if (str[count - 1] >= 97 && str[count - 1] <= 122)
        str[count] = str[count] + 32;
      else if (count == 0)
        str[count] = str[count];
      else
        str[count] = str[count];
    }
  return (str);
}

char    *others(char *str, int count)
{
  if (str[count] >= 32 && str[count] <= 64)
    str[count] = str[count];
  else if (str[count] >= 91 && str[count] <= 96)
    str[count] = str[count];
  else if (str[count] > 123)
    str[count] = str[count];
  return (str);
}

char    *my_strcapitalize(char *str)
{
  int   count;

  count = 0;
  while (str[count] != '\0')
    {
      str =  min(str, count);
      str = maj(str, count);
      str = others(str, count);
      count = count + 1;
    }
  return (str);
}
