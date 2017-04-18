#ifndef TOY_H_
# define TOY_H_

# include "Picture.h"

class Toy
{
public:
	typedef enum 	ToyType
	{
		BASIC_TOY,
		ALIEN,
		BUZZ,
		WOODY
	}				ToyType;

protected:
	ToyType 	_type;
	std::string _name;
	Picture		*_picture;

public:
	Toy();
	Toy(ToyType, std::string const&, std::string const&);
	Toy(Toy const&);
	~Toy();
	Toy&	operator=(Toy const&);

	ToyType				getType() const;
	std::string	const&	getName() const;
	std::string	const&	getAscii() const;

	void				setName(std::string const&);
	bool				setAscii(std::string const&);
};

#endif