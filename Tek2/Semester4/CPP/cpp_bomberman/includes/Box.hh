#ifndef BOMBERMAN_Box_H
# define BOMBERMAN_Box_H

# include <iostream>
# include <string>
# include <Texture.hh>
# include <Geometry.hh>
# include "AObject.hh"

class Box : public AObject
{
private:
	gdl::Texture	_texture;
	gdl::Geometry	_geometry;
	float			_speed;

public:
	Box(const float, const float);
	virtual ~Box();
	
	virtual void	draw(gdl::AShader &, gdl::Clock const&);
};

#endif /* BOMBERMAN_Box_H */
