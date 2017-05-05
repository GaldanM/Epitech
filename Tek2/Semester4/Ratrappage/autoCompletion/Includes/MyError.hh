#ifndef MYERROR_HH
# define MYERROR_HH

# include		<stdexcept>

class MyError : public std::exception
{
protected :
  std::string		_error;

public:

  MyError(const std::string&) throw();
  MyError(const MyError&) throw();
  virtual ~MyError() throw();
  MyError&		operator=(const MyError&) throw();

  virtual const char*	what() const throw();
};

#endif /* !MYERROR_HH */
