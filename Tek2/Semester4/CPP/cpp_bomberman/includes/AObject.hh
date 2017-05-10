#ifndef BOMBERMAN_AOBJECT_H
# define BOMBERMAN_AOBJECT_H

#include <fstream>
#include <sstream>
#include <unistd.h>
#include <Game.hh>
#include <Clock.hh>
#include <Input.hh>
#include <SdlContext.hh>
#include <Geometry.hh>
#include <Texture.hh>
#include <BasicShader.hh>
#include <Model.hh>
#include <SdlContext.hh>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <iostream>
#include <vector>
#include <map>
#include <utility>
#include "MyError.h"

# define CASE_SIZE 0.5f
# define FLOOR_SIZE 0.1f
# define HITBOX 0.25f

class AObject
{
public:
	enum Type
	{
		FLOOR,
		WALL,
		BOX,
		BOMB,
		PLAYER1,
		PLAYER2,
		IA,
		FIRE,
		ASSET,
		ASSETBOMB,
		ASSETSPEED,
		ASSETRANGE
		
	};
protected:
	glm::vec3	_position;
	glm::vec3	_rotation;
	glm::vec3	_scale;
	Type 		_type;

public:
	AObject();
	AObject(const float, const float);
	virtual ~AObject();

	virtual void	draw(gdl::AShader&, gdl::Clock const&) = 0;

	void 			translate(glm::vec3 const&);
	float			isolate(float nb_f);
	float			limit(float, float);
	void			translate(glm::vec3 const&, bool);
	void			rotate(glm::vec3 const&, float);
	void			scale(glm::vec3 const&);

	void			setPosition(const float, const float);
	void			setIsBox();
	void			setIsAsset();

	Type 			getType() const;
	glm::vec3		getPosition() const;
	bool			getIsBox() const;
	bool			getIsAsset() const;
	glm::mat4		getTransformation();
};

#endif /* BOMBERMAN_AOBJECT_H */
