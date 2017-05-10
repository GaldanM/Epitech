#ifndef CLIENT_HH_
# define CLIENT_HH_

# include		<sys/types.h>
# include		<sys/socket.h>
# include		<netdb.h>
# include		<stdlib.h>
# include		<netinet/in.h>
# include		<arpa/inet.h>
# include		<sys/stat.h>
# include		<fcntl.h>
# include 		<iostream>
# include		<unistd.h>
# include 		<string.h>
# include 		"MyError.h"

# define BUFF_SIZE 4096

class Client
{
protected:
	struct 		protoent*									_pe;
	struct 		sockaddr_in									_s_in;
		
	std::string												_ip;
	int 													_port;

	int 													_fd;

	char													_buf[4096];

	fd_set 													_readfds;
public:
	Client(const std::string &, int);
	~Client();

	void 			initialize();
	bool 			connectToServer();
	void			receiveFromServer();
	void			sendToServer(const std::string &);
	bool			handleSelect();
};

#endif /* !CLIENT_HH_ */