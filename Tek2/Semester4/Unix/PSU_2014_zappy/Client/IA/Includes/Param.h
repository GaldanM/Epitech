/*
** Param.h for Param in /home/doghri_f/Downloads/ClientQuiMarche
** 
** Made by Fares Doghri
** Login   <doghri_f@epitech.net>
** 
** Started on  Sun Jul  5 21:10:39 2015 Fares Doghri
** Last update Sun Jul  5 21:11:02 2015 Fares Doghri
*/

#ifndef PARAM_H_
# define PARAM_H_

#include	<iostream>
#include	<vector>

class	Param
{
 private:
  std::string	_teamName;
  int		_port;
  std::string	_host;
  int		_op;

 public:
  Param();
  ~Param();

  bool		countOp(char **);

  bool		setAll(char **);
  bool		setTeamName(char *);
  bool		setPort(char *);
  bool		setHost(char *);

  std::string	getTeamName() const;
  int		getPort() const;
  std::string	getHost() const;
};

#endif
