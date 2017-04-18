/*
** String.c for String in /home/moulin_c/rendu/piscine_cpp_d03/ex00
** 
** Made by Galdan MOULINNEUF
** Login   <moulin_c@epitech.net>
** 
** Started on  Fri Jan  9 11:21:37 2015 Galdan MOULINNEUF
** Last update Sat Jan 10 00:41:23 2015 Galdan MOULINNEUF
*/

#include	<unistd.h>
#include	"String.h"

static void		assign_s(String *this, String const *str);
static void		assign_c(String *this, char const *s);

static void		append_s(String *this, String const *op);
static void		append_c(String *this, char const *ap);

static char		at(String *this, size_t pos);

static void		clear(String *this);

static int		size(String *this);

static int		compare_s(String *this, const String *str);
static int		compare_c(String *this, char const *str);

static size_t		copy(String* this, char* s, size_t n, size_t pos);

static char const	*c_str(String *this);

static int		empty(String* this);

static int		to_int(String* this);

static void		aff(String* this);

void		StringInit(String *this, char const *s)
{
  this->assign_s = &assign_s;
  this->assign_c = &assign_c;
  this->append_s = &append_s;
  this->append_c = &append_c;
  this->at = &at;
  this->clear = &clear;
  this->size = &size;
  this->compare_s = &compare_s;
  this->compare_c = &compare_c;
  this->copy = &copy;
  this->c_str = &c_str;
  this->empty = &empty;
  this->to_int = &to_int;
  this->aff = &aff;
  this->str = strdup(s);
}

void		StringDestroy(String *this)
{
  if (this != NULL && this->str != NULL)
    free(this->str);
  this->str = NULL;
}

static void	assign_s(String *this, String const *str)
{
  if (this != NULL && str != NULL && str->str)
    {
      StringDestroy(this);
      StringInit(this, str->str);
    }
}

static void	assign_c(String *this, char const *s)
{
  if (this != NULL && s != NULL)
    {
      StringDestroy(this);
      StringInit(this, s);
    }
}

static void	append_s(String *this, String const *ap)
{
  if (this == NULL || this->str == NULL)
    return;
  this->str = realloc(this->str, strlen(this->str) + strlen(ap->str) + 1);
  this->str = strcat(this->str, ap->str);
}

static void	append_c(String *this, char const *ap)
{
  if (this == NULL || ap == NULL)
    return;
  this->str = realloc(this->str, strlen(this->str) + strlen(ap) + 1);
  this->str = strcat(this->str, ap);
}

static char	at(String *this, size_t pos)
{
  if (this == NULL || pos >= strlen(this->str))
    return (-1);
  return (this->str[pos]);
}

static void	clear(String *this)
{
  if (this != NULL && this->str != NULL)
    memset(this->str, 0, strlen(this->str));
}

static int	size(String *this)
{
  if (this && this->str)
    return(strlen(this->str));
  return (-1);
}

static int	compare_s(String *this, const String *str)
{
  int		cmp;

  if (this && this->str && str && str->str)
    {
      cmp = strcmp(this->str, str->str);
      return (cmp);
    }
  return (-1);
}

static int	compare_c(String *this, char const *str)
{
  int		cmp;

  if (this && this->str && str)
    {
      cmp = strcmp(this->str, str);
      return (cmp);
    }
  return (-1);
}

static size_t	copy(String* this, char* s, size_t n, size_t pos)
{
  char		*ptr = this->str;

  if (this && this->str && pos < strlen(this->str))
    {
      ptr = ptr + pos;
      s = malloc(sizeof(char) * n + 1);
      strncpy(s, ptr, n);
      s[n] = 0;
      return (strlen(s));
    }
  return (-1);
}

static char const	*c_str(String *this)
{
  if (this && this->str)
    return (strdup(this->str));
  return (NULL);
}

static int	empty(String *this)
{
  if (this && this->str)
    return (-1);
  return (1);
}

static int	to_int(String *this)
{
  if (this && this->str)
    return (atoi(this->str));
  return (-1);
}

static void	aff(String *this)
{
  if (this && this->str)
    write(1, this->str, strlen(this->str));
  return;
}
