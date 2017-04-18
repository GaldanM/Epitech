#ifndef PICTURE_H_
# define PICTURE_H_

# include <iostream>
# include <fstream>

class Picture
{
public:
	std::string			data;

	Picture(std::string const&data = "");
	~Picture();

	bool				getPictureFromFile(std::string const&);
	std::string const&	getData() const;
};

#endif