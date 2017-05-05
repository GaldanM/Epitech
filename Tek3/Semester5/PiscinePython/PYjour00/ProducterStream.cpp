#include "ProducterStream.hpp"

ProducterStream::ProducterStream() : _stdin(false), _file(NULL)
{}

ProducterStream::~ProducterStream()
{
	if (_file != NULL)
	{
		_file->close();
		delete _file;
	}
}

std::string		ProducterStream::nextString()
{
	char		c;
	std::string line;

	if (_stdin)
	{
		std::cin >> line;
	}
	else
	{
		if (_file == NULL)
		{
			throw std::exception();
		}
		while (_file->get(c) && c != '\n')
			line += c;
	}
	return (line);
}

bool			ProducterStream::loadFile(char *path)
{
	_file = new std::ifstream();

	_file->open(path);
	if (_file->is_open())
		_stdin = false;
	else
	{
		delete _file;
		_file = NULL;
	}
	return (stdin);
}

bool			ProducterStream::loadStdin()
{
	_stdin = true;
	return (true);
}

bool			ProducterStream::getStdin()
{
	return (_stdin);
}

std::ifstream*	ProducterStream::getFile()
{
	return (_file);
}