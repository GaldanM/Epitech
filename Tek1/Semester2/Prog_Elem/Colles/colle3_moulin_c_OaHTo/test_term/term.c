/*
** term.c for lol in /home/moulin_c/rendu/colle3_moulin_c_OaHTo/test_term
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Mon May 12 19:11:10 2014 moulin_c
** Last update Mon May 12 19:38:02 2014 moulin_c
*/

#include		<termios.h>
#include		<unistd.h>

int			main()
{
  struct termios	term;
  struct termios	save;
  char			buffer[4096];
  int			i;
  int			ret;

  i = 0;
  tcgetattr(0, &term);
  save = term;
  while (i < 4)
    {
      term.c_lflag &= ~ECHO;
      term.c_lflag &= ~ICANON;
      tcsetattr(0, TCSANOW, &term);
      ret = read(0, buffer, 4096);
      buffer[ret] = '\0';
      ret = 0;
      while (buffer[ret])
	{
	  printf("buffer[%d] = '%d'\n", ret, buffer[ret]);
	  ret++;
	}
      putchar('\n');
      i++;
    }
  tcsetattr(0, TCSANOW, &save);
}
