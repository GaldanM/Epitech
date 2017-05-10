#ifndef BOMBERMAN_Bomb_H
# define BOMBERMAN_Bomb_H

# include <iostream>
# include <string>
# include <Texture.hh>
# include <Geometry.hh>
# include "AObject.hh"

class Bomb : public AObject
{
private:
	gdl::Texture	_texture;
	gdl::Geometry	_geometry;
	float			_speed;
	double			_timer;
	double			_timerFire;
	int				_id;
	bool			_explosed;
	
	int				_top;
	int				_bottom;
	int				_left;
	int				_right;

public:
	Bomb(const float, const float, int);
	virtual ~Bomb();
	
	bool			update(gdl::Clock const &clock);
	bool			updateFire(gdl::Clock const &clock);
	virtual void	draw(gdl::AShader &, gdl::Clock const&);
	int				getId() const;
	void			explose();
	bool			getExplosed() const;
	void			setExplosed();

	void			setTop(int);
	void			setBottom(int);
	void			setLeft(int);
	void			setRight(int);

	int				getTop() const;
	int				getBottom() const;
	int				getLeft() const;
	int				getRight() const;


};

#endif /* BOMBERMAN_Bomb_H */
