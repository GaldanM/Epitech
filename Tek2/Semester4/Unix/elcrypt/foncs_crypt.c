#include	<unistd.h>
#include	<stdlib.h>
#include	"elcrypt.h"

void		func_crypt(t_crypt *crpt)
{
  crpt->key_s = my_secondary_key(crpt->key_p, crpt->count);
  crpt->block_save = crpt->block_l;
  crpt->block_l = crpt->block_r;
  crpt->block_r = crpt->block_save ^ (crpt->block_r ^ crpt->key_s);
  ++(crpt->count);
}

void		set_blocks(t_crypt *crpt, unsigned char *buffer)
{
  crpt->buffer_l[0] = buffer[0];
  crpt->buffer_l[1] = buffer[1];
  crpt->buffer_l[2] = buffer[2];
  crpt->buffer_l[3] = buffer[3];
  crpt->buffer_r[0] = buffer[4];
  crpt->buffer_r[1] = buffer[5];
  crpt->buffer_r[2] = buffer[6];
  crpt->buffer_r[3] = buffer[7];
  crpt->block_l = strtoul(((char*)crpt->buffer_l), NULL, 10);
  crpt->block_r = strtoul(((char*)crpt->buffer_r), NULL, 10);
}

void		write_blocks(unsigned int block_L, unsigned int block_R, int fd)
{
  int		i;
  unsigned int	block_save;
  unsigned char	buffer[4];

  i = 0;
  while (i < 4)
    {
      block_save = block_L >> i * 8;
      block_save = block_save & 255;
      buffer[i] = block_save;
      ++i;
    }
  write(fd, buffer, 4);
  i = 0;
  while (i < 4)
    {
      block_save = block_R >> i * 8;
      block_save = block_save & 255;
      buffer[i] = block_save;
      ++i;
    }
  write(fd, buffer, 4);
}
