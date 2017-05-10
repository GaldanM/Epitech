//
// Client.cpp for Client in /home/doghri_f/Downloads/Graph
// 
// Made by Fares Doghri
// Login   <doghri_f@epitech.net>
// 
// Started on  Sun Jul  5 21:16:34 2015 Fares Doghri
// Last update Sun Jul  5 21:16:47 2015 Fares Doghri
//

#include "Client.hh"

Client::Client(const std::string & ip, int port) : _ip(ip), _port(port)
{

}

Client::~Client()
{
  close(_fd);
}

void 		Client::initialize()
{
  std::cout << "Connecting to " << _ip << " :: " << _port << std::endl;
  _pe = NULL;
  if ((_pe = getprotobyname("TCP")) == 0)
    throw MyError("Error TCP");
  if ((_fd = socket(AF_INET, SOCK_STREAM, _pe->p_proto)) == -1)
    throw MyError("Error socket");
  _s_in.sin_family = AF_INET;
  _s_in.sin_port = htons(_port);
  _s_in.sin_addr.s_addr = inet_addr(_ip.c_str());
}

bool 		Client::connectToServer()
{
  initialize();
  if (connect(_fd, (struct sockaddr *)&_s_in, sizeof(_s_in)) == -1)
    {
      std::cerr << "Failed to connect to port " << _port << std::endl;
      close(_fd);
      throw MyError("error : connect to server");
    }
  std::cout << "connected !!" << std::endl;
  return (true);
}

void		Client::receiveFromServer()
{
  int ret;

  if ((ret = read(_fd, _buf, BUFF_SIZE)) == -1)
    close(_fd);
  _buf[ret] = 0;
}

void		Client::sendToServer(const std::string &str)
{
  write(_fd, str.c_str(), str.size());
}

bool 		Client::handleSelect()
{
  struct timeval tv;

  tv.tv_usec = 0;
  tv.tv_sec = 0;
  FD_ZERO(&_readfds);
  FD_SET(_fd, &_readfds);
  if (select(_fd +  1, &_readfds, NULL, NULL, &tv) == -1)
    throw MyError ("disconnected");
  else
    {
      if (FD_ISSET(_fd, &_readfds))
    	{
	  receiveFromServer();
	  return (true);
    	}
    }
  return (false);
}
