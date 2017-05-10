/*
** MyError.h for MyError in /home/doghri_f/Downloads/ClientQuiMarche
** 
** Made by Fares Doghri
** Login   <doghri_f@epitech.net>
** 
** Started on  Sun Jul  5 21:11:11 2015 Fares Doghri
** Last update Sun Jul  5 21:11:21 2015 Fares Doghri
*/

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
