#include	<stdio.h>
#include	<unistd.h>
#include	"elcrypt.h"

int		main(int argc, char **argv)
{
  t_param	p;

  if (argc > 1)
    {
      init_param(&p);
      if (set_param(argv, &p) == -1)
	return (-1);
      if (p.e)
	encrypt(&p);
      close(p.f);
      if (p.o != 1)
	close(p.o);
    }
  else
    printf("Usage : -d|-e -f \"source_file\" -k \"key\" -o \"dest file\"\n");
  return (0);
}
