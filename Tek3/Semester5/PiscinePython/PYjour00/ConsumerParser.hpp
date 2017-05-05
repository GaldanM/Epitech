#ifndef CONSUMERPARSER_HPP
# define CONSUMERPARSER_HPP

# include 	<map>
# include	"ProducterStream.hpp"

class ConsumerParser
{
private:
	int 			_pos;
	std::string		_stream;
	ProducterStream	*_st;
	std::map<std::string, int>		_map;

public:
	ConsumerParser(ProducterStream &st);
	~ConsumerParser();
	
	bool		fillStream();
	bool		readText(char*);
	bool		readEOF();
	bool		readUntil(char);
	bool		readUntilEOF();
	bool		readInteger();
	bool		readIdentifier();
	inline bool	flush()
	{
		_stream.clear();
		return (true);
	}
	inline bool	peekChar(char c)
	{
		if (c == _stream[_pos])
			return (true);
		return (false);
	}

	inline bool readChar(char c)
	{
		if (!fillStream())
			return (false);
		if (peekChar(c))
		{
			++_pos;
			return (true);
		}
		return (false);
	}

	inline bool	readRange(char begin, char end)
	{
		if (end < begin)
			return (false);
		if (!fillStream())
			return (false);
		if (_stream[_pos] >= begin && _stream[_pos] <= end)
		{
			++_pos;
			return (true);
		}
		return (false);
	}

	inline bool	beginCapture(std::string tag)
	{
		if (_stream.empty())
			return (false);
		_map[tag] = _pos;
		return (true);
	}

	inline bool	endCapture(std::string tag, std::string& out)
	{
		if (_map.empty() || _stream.empty())
			return (false);
		out = _stream.substr(_map[tag], _pos);
		return (true);
	}
};

#endif /* CONSUMERPARSER_HPP */