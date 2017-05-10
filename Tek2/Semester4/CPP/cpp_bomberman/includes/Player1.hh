#ifndef BOMBERMAN_Player1_H
# define BOMBERMAN_Player1_H

# include "ACharacter.hh"

class Player1 : public ACharacter
{
protected:
	bool	_flag;
	
public:
	Player1(const float, const float);
	virtual ~Player1();

	virtual void update(const gdl::Clock&, gdl::Input&, Map *map);
	void		moveUpDown(gdl::Input &input);
	void		moveLeftRight(gdl::Input &input);
};

#endif /* BOMBERMAN_Player1_H */
