/*
** client.h for ftp in /home/moulin_c/rendu/PSU_2014_myftp
** 
** Made by Galdan Moulinneuf
** Login   <moulin_c@epitech.net>
** 
** Started on  Sun Mar 29 21:42:24 2015 Galdan Moulinneuf
** Last update Sun Mar 29 21:42:25 2015 Galdan Moulinneuf
*/

#ifndef CLIENT_H_
# define CLIENT_H_

# include		<netdb.h>

typedef struct		s_cmd
{
  char			*cmd;
  void			(*func)();
}			t_cmd;

void			receive_from_server(int fd, int *isLog);
void			send_to_server(int fd);
int			init_socket_c(int argc, struct protoent *pe, int *fd);
char			**my_strtotab(char *buf);
void			my_send(int fd);
void			my_receive(int fd);
char			*get_fname(char *str);
int			check_file(char *str);
void			cd_c(char **p, int fd);
void			quit_c(char **p, int fd);
void			pwd_c(char **p, int fd);
void			ls_c(char **p, int fd);
void			user_c(char **p, int fd);
void			pass_c(char **p, int fd);
void			get_c(char **p, int fd);
void			put_c(char **p, int fd);
void			xread(int fd, char buf[4096]);

#endif /* !CLIENT_H_ */
