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
	
	class Error
	{
	public:
		typedef enum 	ErrorType
		{
			UNKNOWN,
			PICTURE,
			SPEAK
		}				ErrorType;
	
		ErrorType	type;

		Error();
		~Error();

		virtual std::string 	what() const;
		virtual std::string		where() const;
	};

protected:
	/* ATTRIB */
	ToyType 	_type;
	std::string _name;
	Picture		*_picture;
	Error 		_error;

public:
	
	/* INIT */
	Toy();
	Toy(ToyType, std::string const&, std::string const&);
	Toy(Toy const&);
	virtual ~Toy();
	Toy&	operator=(Toy const&);

	/* GETTERS */
	ToyType				getType() const;
	std::string	const&	getName() const;
	std::string	const&	getAscii() const;

	/* SETTERS */
	void				setName(std::string const&);
	bool				setAscii(std::string const&);

	/* OTHERS */
	virtual void		speak(std::string const&);
	virtual bool		speak_es(std::string const&) = 0;
	Error				getLastError();

	/* OPERATORS */
	Toy&				operator<<(std::string const &);
};

std::ostream&	operator<<(std::ostream& os, Toy const &dildo);

#endif