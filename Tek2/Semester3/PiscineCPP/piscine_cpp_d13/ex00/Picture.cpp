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

Picture::~Picture()
{

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