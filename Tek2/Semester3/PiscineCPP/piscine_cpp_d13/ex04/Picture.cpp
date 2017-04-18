#include "Toy.h"

Picture::Picture(std::string const &file)
{
	char			lee;
	std::ifstream	fd;

	fd.open(file.c_str(), std::ifstream::in);
	if (fd)
	{
		while (fd.get(lee))
			data += lee;
		fd.close();
	}
	else
		data = "ERROR";
}

Picture::Picture(Picture const &cpy)
{
	data = cpy.data;
}

Picture::~Picture()
{

}

Picture&			Picture::operator=(Picture const &cpy)
{
	data = cpy.data;
	return (*this);
}

Picture				*Picture::copy()
{
	Picture *nouv = new Picture(*this);
	return (nouv);
}

bool				Picture::getPictureFromFile(std::string const &file)
{
	char			lee;
	std::ifstream	fd;

	data.clear();
	fd.open(file.c_str(), std::ifstream::in);
	if (fd)
	{
		while (fd.get(lee))
			data += lee;
		fd.close();
	}
	else
	{
		data = "ERROR";
		return (false);
	}
	return (true);
}

std::string const&	Picture::getData() const
{
	return (data);
}