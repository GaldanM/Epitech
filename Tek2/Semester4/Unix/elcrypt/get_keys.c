#include	"elcrypt.h"

unsigned long	my_primary_key(unsigned long key)
{
  unsigned long	tab[8];
  int		i;

  i = 0;
  while (i < 8)
    {
      tab[i] = key >> i * 8;
      tab[i] = tab[i] & 0xFF;
      ++i;
    }
  i = 0;
  key = 0;
  while (i < 8)
    {
      tab[i] = tab[i] >> 1;
      tab[i] = tab[i] << i * 8;
      key = key + tab[i];
      ++i;
    }
  return (key);
}

unsigned long	my_secondary_key(unsigned long key, int turn)
{
  int		i;

  i = 0;
  while (i < turn)
    {
      key = key << 4;
      i++;
    }
  key =  key & 0xFFFFFFFF;
  return (key);
}
