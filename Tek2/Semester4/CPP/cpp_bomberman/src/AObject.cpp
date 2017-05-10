#include "AObject.hh"

AObject::AObject(float pos_y, float pos_x) : _position(pos_x, pos_y, 0), _rotation(0, 0, 0), _scale(1, 1, 1)
{

}

AObject::AObject(): _position(0, 0, 0), _rotation(0, 0, 0),_scale(1, 1, 1)
{}

AObject::~AObject()
{

}

float		AObject::isolate(float nb_f)
{
	int 	nb_i = nb_f;

	nb_f -= nb_i;
	return (nb_f);
}

float		AObject::limit(float tmp, float pos)
{
	float	isol;

	if (tmp < pos)
	{
		isol = isolate(pos);
		if (isol > 0 + HITBOX)
			pos = (pos - isol) + HITBOX;
	}
	else if (tmp > pos)
	{
	 	isol = isolate(pos);
		if (isol < 1 - HITBOX)
			pos = (pos - isol) + (1 - HITBOX);
	}
	return (pos);
}

void AObject::translate(glm::vec3 const &v)
{
   _position += v;
}

void		AObject::translate(glm::vec3 const &v, bool obstacle)
{
	float	tmp_x = _position.x;
	float	tmp_y = _position.y;

 	_position += v;
 	if (obstacle)
 	{
 		_position.x = limit(tmp_x, _position.x);
 		_position.y = limit(tmp_y, _position.y);
 	}
}

void		AObject::rotate(glm::vec3 const &axis, float angle)
{
	_rotation += axis * angle;
}

void		AObject::scale(glm::vec3 const &scale)
{
	_scale *= scale;
}

void		AObject::setPosition(float y, float x)
{
	_position.y = y;
	_position.x = x;
}

glm::mat4	AObject::getTransformation()
{
	glm::mat4	transf(1);

	transf = glm::translate(transf, _position);
	transf = glm::rotate(transf, _rotation.x, glm::vec3(1, 0, 0));
	transf = glm::rotate(transf, _rotation.y, glm::vec3(0, 1, 0));
	transf = glm::rotate(transf, _rotation.z, glm::vec3(0, 0, 1));
	transf = glm::scale(transf, _scale);
	return (transf);
}

AObject::Type		AObject::getType() const
{
	return _type;
}


glm::vec3			AObject::getPosition() const
{
	return _position;
}
