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
