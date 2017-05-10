//
// Client.cpp for CLient in /home/doghri_f/Downloads/ClientQuiMarche
// 
// Made by Fares Doghri
// Login   <doghri_f@epitech.net>
// 
// Started on  Sun Jul  5 21:09:17 2015 Fares Doghri
// Last update Sun Jul  5 21:09:25 2015 Fares Doghri
//

#include "Client.hh"

Client::Client(const std::string & ip, int port)
{
  this->_ip = ip;
  this->_port = port;
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
      throw MyError(" error : connect to server");
    }
  std::cout << "connected !!" << std::endl;
  return (true);
}

void		Client::receiveFromServer()
{
  int ret;

  if ((ret = read(_fd, _buf, 4096)) == -1)
    {
      close(_fd);
      throw MyError("IA DEAD");
    }
  _buf[ret] = 0;
  this->_cmd = _buf;
}

void		Client::sendToServer(const std::string &str)
{
  if (write(_fd, str.c_str(), str.size()) == -1)
    throw MyError("IA DEAD");
}
