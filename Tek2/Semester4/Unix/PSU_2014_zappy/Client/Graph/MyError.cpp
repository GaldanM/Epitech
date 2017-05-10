//
// MyError.cpp for MyError in /home/doghri_f/Downloads/Graph
// 
// Made by Fares Doghri
// Login   <doghri_f@epitech.net>
// 
// Started on  Sun Jul  5 21:16:21 2015 Fares Doghri
// Last update Sun Jul  5 21:16:27 2015 Fares Doghri
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
