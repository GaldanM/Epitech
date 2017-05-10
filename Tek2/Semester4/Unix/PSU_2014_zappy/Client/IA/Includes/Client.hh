//
// Client.hh for Client in /home/doghri_f/Downloads/IA/Includes
// 
// Made by Fares Doghri
// Login   <doghri_f@epitech.net>
// 
// Started on  Sun Jul  5 21:31:28 2015 Fares Doghri
// Last update Sun Jul  5 21:32:22 2015 Fares Doghri
//

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

class Client
{
protected:
	struct 		protoent*			_pe;
	struct 		sockaddr_in			_s_in;
	int 						_fd;
	int 						_port;

	char						_buf[4096];
	std::string					_cmd;
	std::string					_ip;

public:
	Client(const std::string &, int);
	~Client();

	void 			initialize();
	bool 			connectToServer();
	void			receiveFromServer();
	void			sendToServer(const std::string &);
};

#endif /* !CLIENT_HH_ */
