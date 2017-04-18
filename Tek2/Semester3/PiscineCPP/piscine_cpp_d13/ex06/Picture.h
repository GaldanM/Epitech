#ifndef PICTURE_H_
# define PICTURE_H_

# include <iostream>
# include <fstream>

class Picture
{
public:
	std::string			data;

	Picture(std::string const&data = "");
	Picture(Picture const&);
	~Picture();
	Picture&			operator=(Picture const&);

	Picture				*copy();
	bool				getPictureFromFile(std::string const&);
	std::string const&	getData() const;
};

#endif