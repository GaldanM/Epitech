//
// MyError.cpp for My_error in /home/doghri_f/Downloads/ClientQuiMarche
// 
// Made by Fares Doghri
// Login   <doghri_f@epitech.net>
// 
// Started on  Sun Jul  5 20:57:19 2015 Fares Doghri
// Last update Sun Jul  5 20:57:40 2015 Fares Doghri
//

#include	"MyError.h"

MyError::MyError(const std::string &msg) throw() : _error(msg)
{
}

MyError::MyError(const MyError &cpy) throw() : _error(cpy._error)
{
}

MyError::~MyError() throw()
{
}

MyError&	MyError::operator=(const MyError &cpy) throw()
{
_error = cpy._error;
return (*this);
}

const char*	MyError::what() const throw()
{
return _error.c_str();
}
