/*
** String.h for String in /home/moulin_c/rendu/piscine_cpp_d03/ex00
** 
** Made by Galdan MOULINNEUF
** Login   <moulin_c@epitech.net>
** 
** Started on  Fri Jan  9 11:16:27 2015 Galdan MOULINNEUF
** Last update Sat Jan 10 00:30:59 2015 Galdan MOULINNEUF
*/

#ifndef STRING_H_
# define STRING_H_

# include <stdlib.h>
# include <string.h>

typedef struct	String
{
  char	*str;
  void (*assign_s)(struct String *this, struct String const *str);
  void (*assign_c)(struct String *this, char const *s);
  void (*append_s)(struct String *this, struct String const *ap);
  void (*append_c)(struct String *this, char const *ap);
  char (*at)(struct String *this, size_t pos);
  void (*clear)(struct String *this);
  int (*size)(struct String *this);
  int (*compare_s)(struct String *this, const struct String *str);
  int (*compare_c)(struct String *this, char const *str);
  size_t (*copy)(struct String *this, char *s, size_t n, size_t pos);
  char const *(*c_str)(struct String *this);
  int (*empty)(struct String *this);
  int (*to_int)(struct String *this);
  void (*aff)(struct String *this);
}		String;

void	StringInit(struct String *this, char const *s);
void	StringDestroy(struct String *this);

#endif /* !STRING_H_ */
