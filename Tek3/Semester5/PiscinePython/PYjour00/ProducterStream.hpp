#ifndef PRODUCTERSTREAM_HPP
# define PRODUCTERSTREAM_HPP

# include	<iostream>
# include	<fstream>

class ProducterStream
{
private:
	bool			_stdin;
	std::ifstream	*_file;

public:
	ProducterStream();
	~ProducterStream();

	std::string			nextString();
	bool				loadFile(char*);
	bool				loadStdin();
	bool				getStdin();
	std::ifstream*		getFile();
};

#endif /* PRODUCTERSTREAM_HPP */