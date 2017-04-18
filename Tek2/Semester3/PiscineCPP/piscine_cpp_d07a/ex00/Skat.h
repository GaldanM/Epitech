/*
** Skat.h for skat in /home/moulin_c/rendu/piscine_cpp_d07a/ex00
** 
** Made by Galdan MOULINNEUF
** Login   <moulin_c@epitech.net>
** 
** Started on  Tue Jan 13 19:16:58 2015 Galdan MOULINNEUF
** Last update Tue Jan 13 21:23:12 2015 Galdan MOULINNEUF
*/

#ifndef SKAT_H_
# define SKAT_H_

# include <iostream>
# include <string>

class Skat
{
 private:
  int			_stimPaks;
  std::string		_name;

 public:
  Skat(std::string const &name = "bob", int stimPaks = 15);
  const std::string	&name();
  int			&stimPaks();
  void			shareStimPaks(int number, int &stock);
  void			addStimPaks(unsigned int number);
  void			useStimPaks();
  void			status();
  ~Skat();

};

#endif /* !SKAT_H_ */
