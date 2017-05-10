#ifndef BOMBERMAN_AssetBomb_H
# define BOMBERMAN_AssetBomb_H

# include <iostream>
# include <string>
# include <Texture.hh>
# include <Geometry.hh>
# include "AObject.hh"

class AssetBomb : public AObject
{
private:
	gdl::Texture	_texture;
	gdl::Geometry	_geometry;
	float			_speed;

public:
	AssetBomb(const float, const float);
	virtual ~AssetBomb();
	
	virtual void	draw(gdl::AShader &, gdl::Clock const&);
};

#endif /* BOMBERMAN_AssetBomb_H */
