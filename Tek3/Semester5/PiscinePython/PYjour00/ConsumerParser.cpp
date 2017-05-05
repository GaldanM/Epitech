#include "ConsumerParser.hpp"

ConsumerParser::ConsumerParser(ProducterStream &st) : _pos(0), _stream(""), _st(&st)
{}

ConsumerParser::~ConsumerParser()
{}

bool		ConsumerParser::fillStream()
{
	if (_pos == _stream.size())
	{
		try
		{
			_stream += _st->nextString();	
		}
		catch (std::exception const &e)
		{
			throw std::exception();
		}
	}
	if (_stream.empty())
		return (false);
	return (true);
}

bool		ConsumerParser::readText(char *text)
{
	int 		i = 0;
	std::string str(text);
	int 		len = str.size();

	if (!fillStream())
		return (false);
	while (i < len)
	{
		if (text[i] != _stream[i])
			return (false);
		++i;
	}
	_pos += i;
	return (true);
}

bool		ConsumerParser::readEOF()
{
	return (_stream.empty());
}

bool		ConsumerParser::readUntil(char c)
{
	int 	i = 0;

	if (!fillStream())
		return (false);
	while (_stream[i])
	{
		++i;
		if (_stream[_pos] == c)
		{
			_pos += i;
			return (true);
		}
	}
	return (false);
}

bool		ConsumerParser::readUntilEOF()
{
	if (!fillStream())
		return (false);
	_pos = _stream.size();
	return (true);
}

bool		ConsumerParser::readInteger()
{
	int 	i = 0;

	if (!fillStream())
		return (false);
	while (_stream[i])
	{
		if (_stream[i] < '0' || _stream[i] > '9')
			return (false);
		++i;
	}
	_pos += i;
	return (true);
}

bool		ConsumerParser::readIdentifier()
{
	std::size_t 	i = 1;

	if (!fillStream())
		return (false);
	if (_stream[_pos] <= '0' || _stream[_pos] >= '9')
	{
		while ((_stream[i] >= '0' && _stream[i] <= '9')
			|| (_stream[i] >= 'a' && _stream[i] <= 'z')
			|| (_stream[i] >= 'A' && _stream[i] <= 'Z')
			|| (_stream[i] == '_'))
			++i;
		if (i < _stream.size())
			return (false);
		_pos += i;
		return (true);
	}
	return (false);
}