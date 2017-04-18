#ifndef LIME_H_
# define LIME_H_

# include "Lemon.h"

class Lime : public Lemon
{
public:
	Lime();
	~Lime();

	virtual std::string const&		getName() const;
};

#endif