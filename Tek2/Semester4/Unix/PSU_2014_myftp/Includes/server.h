/*
** server.h for ftp in /home/moulin_c/rendu/PSU_2014_myftp
** 
** Made by Galdan Moulinneuf
** Login   <moulin_c@epitech.net>
** 
** Started on  Sun Mar 29 21:42:49 2015 Galdan Moulinneuf
** Last update Sun Mar 29 21:42:49 2015 Galdan Moulinneuf
*/

#ifndef SERVER_H_
# define SERVER_H_

# include		<netdb.h>

typedef struct          s_user
{
  char			*name;
  char			*pwd;
  char			*home;
  char			*root;
  int			fd;
  int			isUser;
  int			isPass;
}                       t_user;

typedef struct		s_cmd
{
  char			*cmd;
  void			(*func)();
}			t_cmd;

int			init_socket_s(int argc, struct protoent *pe, int *fd);
void			ls_s(char **p, t_user *u);
void			pwd_s(char **p, t_user *u);
void			quit_s(char **p, t_user *u);
void			cd_s(char **p, t_user *u);
void			get_s(char **p, t_user *u);
void			put_s(char **p, t_user *u);
void			user_s(char **p, t_user *u);
void			pass_s(char **p, t_user *u);
int			check_transf(char **p, t_user *u);
char			*get_fname(char *str);
void			my_send(int fd);
void			my_receive(int fd);
char			**my_strtotab(char *buf);
int			send_to_client(int client_fd, char *str);
int			check_file(char *str);
void			receive_from_client(t_user *u);
void			xclose(int fd);
void			init_sin(struct sockaddr_in *s_in, int port);
void			my_server(int fd, char root[1025]);
void			init_user(t_user *u, int client_fd);



#endif /* !SERVER_H_ */
