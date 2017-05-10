/*
** MyError.h for MyError in /home/doghri_f/rendu/Bomberman
** 
** Made by Fares Doghri
** Login   <doghri_f@epitech.net>
** 
** Started on  Sun Jun 14 22:16:28 2015 Fares Doghri
** Last update Sun Jun 14 22:16:29 2015 Fares Doghri
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
