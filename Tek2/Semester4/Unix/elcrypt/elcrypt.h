#ifndef _ELCRYPT_H_
# define _ELCRYPT_H_

typedef struct		s_param
{
  char		d;
  char		e;
  int		f;
  int		o;
  unsigned long	k;
}			t_param;

typedef struct		s_crypt
{
  int		count;
  unsigned char	buffer_l[4];
  unsigned char	buffer_r[4];
  unsigned long	key_p;
  unsigned int	key_s;
  unsigned int	block_l;
  unsigned int	block_r;
  unsigned int	block_save;
}			t_crypt;

void		init_param(t_param *);
int		open_file(char *, char);
int		check_param(t_param *);

void		encrypt(t_param *);

void		decrypt(t_param *);

void		func_crypt(t_crypt *);
void		set_blocks(t_crypt *, unsigned char *);
void		write_blocks(unsigned int, unsigned int, int);

unsigned long	my_primary_key(unsigned long);
unsigned long	my_secondary_key(unsigned long, int);

int		set_fds(char **, int, char);
int		set_param_pointers(char **, t_param *, int *);
int		set_param(char **, t_param *);

#endif /* !_ELCRYPT_H_ */
