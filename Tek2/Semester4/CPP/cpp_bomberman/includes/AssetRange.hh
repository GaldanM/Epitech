#ifndef BOMBERMAN_AssetRange_H
# define BOMBERMAN_AssetRange_H

# include <iostream>
# include <string>
# include <Texture.hh>
# include <Geometry.hh>
# include "AObject.hh"

class AssetRange : public AObject
{
private:
	gdl::Texture	_texture;
	gdl::Geometry	_geometry;
	float			_speed;

public:
	AssetRange(const float, const float);
	virtual ~AssetRange();
	
	virtual void	draw(gdl::AShader &, gdl::Clock const&);
};

#endif /* BOMBERMAN_AssetRange_H */
