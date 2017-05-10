#ifndef IOBJECT_HPP
#define IOBJECT_HPP

#include "AObject.hh"

class IObject : public AObject
{
public:
	IObject() {}
	virtual ~IObject() {}

  virtual bool  initialize() = 0;
  virtual void  update(gdl::Clock const &clock, gdl::Input &input) = 0;
  virtual int   getPage() const = 0;
  virtual int   getCurrentPage() const = 0;
  virtual int   getNbBot() const = 0;
  virtual int   getSave() const = 0;
  virtual int   getScreenSize() const = 0;
  virtual int   getMap() const = 0;
  virtual int   getNbPlayer() const = 0;
  virtual int   getWidth() const = 0;
  virtual int   getHeight() const = 0;
};

#endif /* !IOBJECT_HPP */
