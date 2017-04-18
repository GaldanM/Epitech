#ifndef TOYSTORY_H_
# define TOYSTORY_H_

# include "Toy.h"

typedef bool(Toy::*funcs)(std::string const&);

class ToyStory
{
public:
	ToyStory();
	~ToyStory();

	static bool	tellMeAStory(std::string const&, Toy &, funcs func1, Toy &, funcs func2);
};

bool			call_func(Toy&, funcs, std::string const&);
bool			replace_pic(Toy&, std::string const&);

#endif
