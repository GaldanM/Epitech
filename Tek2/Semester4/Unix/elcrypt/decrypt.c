#include	<unistd.h>
#include	"elcrypt.h"

void		decrypt(t_param *p)
{
  int		ret;
  t_crypt	crpt;
  unsigned char	buffer[8 + 1];

  crpt.key_p = my_primary_key(p->k);
  while ((ret = read(p->f, buffer, 8)) == 8)
    {
      buffer[ret] = 0;
      crpt.count = 8;
      set_blocks(&crpt, buffer);
      while (crpt.count > 0)
	func_crypt(&crpt);
      write_blocks(crpt.block_l, crpt.block_r, p->o);
    }
}
