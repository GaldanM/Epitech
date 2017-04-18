#ifndef AENEMY_H_
# define AENEMY_H_

# include <iostream>

class AEnemy
{
protected:
int				_hp;
std::string		_type;

public:
	AEnemy(int, std::string const &);
	virtual ~AEnemy();

	std::string const&	getType() const;
	int					getHP() const;

	virtual void		takeDamage(int);
};

#endif