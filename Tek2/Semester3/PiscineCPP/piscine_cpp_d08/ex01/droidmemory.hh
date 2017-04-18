//
// droidmemory.hh for memory in /home/moulin_c/rendu/piscine_cpp_d08/ex01
// 
// Made by Galdan MOULINNEUF
// Login   <moulin_c@epitech.net>
// 
// Started on  Wed Jan 14 18:35:40 2015 Galdan MOULINNEUF
// Last update Wed Jan 14 21:33:08 2015 Galdan MOULINNEUF
//

#ifndef DROIDMEMORY_H_
# define DROIDMEMORY_H_

# include	<cstddef>

class	DroidMemory
{
private:
  size_t	_Exp;
  size_t	_FingerPrint;

public:
  /* INIT */
  DroidMemory();
  DroidMemory(DroidMemory const &);
  ~DroidMemory();

  /* GETTERS */
  size_t	getFingerPrint() const;
  size_t	getExp() const;

  /* SETTERS */
  void		setFingerPrint(size_t);
  void		setExp(size_t);

  /* OPERATORS */
  DroidMemory&	operator=(DroidMemory const &);
  DroidMemory&	operator<<(DroidMemory const &);
  DroidMemory&	operator>>(DroidMemory&);
  DroidMemory&	operator+=(DroidMemory const &);
  DroidMemory&	operator+=(size_t);
  DroidMemory&	operator+(DroidMemory const &);
  DroidMemory&	operator+(size_t);
};

std::ostream&	operator<<(std::ostream& os, DroidMemory const &);

#endif /* DROIDMEMORY_H_ */
