#include "ToyStory.h"

ToyStory::ToyStory()
{

}

ToyStory::~ToyStory()
{

}

bool		call_func(Toy &toy, funcs func, std::string const &line)
{

  if (!(toy.*func)(line))
    {
      Toy::Error e = toy.getLastError();
      std::cout << e.where() << ": " << e.what() << std::endl;
      return (false);
    }
  return (true);
}

bool		replace_pic(Toy &toy, std::string const &file)
{
  if (toy.setAscii(file) == false)
    {
      Toy::Error e = toy.getLastError();
      std::cout << e.where() << ": " << e.what() << std::endl;
      return (false);
    }
  std::cout << toy.getAscii() << std::endl;
  return (true);
}

bool		ToyStory::tellMeAStory(std::string const &file, Toy &toy1, funcs func1, Toy &toy2, funcs func2)
{
  int			pos;
  char			turn = 1;
  char			buff[1024];
  std::ifstream		fd;
  std::string		line;
  std::string		pic_replace;

  std::cout << toy1.getAscii() << std::endl;
  std::cout << toy2.getAscii() << std::endl;
  fd.open(file.c_str(), std::ifstream::in);
  if (fd)
    {
      while (fd.eof() == false)
	{
	  fd.getline(buff, 1024);
	  line = buff;
	  if ((pos = line.find("picture:")) == 0)
	    {
	      pic_replace = line.substr(pos + 8);
	      if (turn == 1)
		{
		  if (replace_pic(toy1, pic_replace) == false)
		    return (false);
		}
	      else
		{
		  if (replace_pic(toy2, pic_replace) == false)
		    return (false);
		}
	    }
	  else if (line != "")
	    {
	      if (turn == 1)
		{
		  if (call_func(toy1, func1, line) == false)
		    return (false);
		}
	      else
		{
		  if (call_func(toy2, func2, line) == false)
		    return (false);
		}
	      if (turn == 1)
		turn = 2;
	      else
		turn = 1;
	    }
	}
    }
  else
    {
      std::cout << "Bad Story" << std::endl;
      return (false);
    }
  return (true);
}
