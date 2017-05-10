#ifndef MASTER_HH
# define MASTER_HH_

# include	"Menu.hh"
# include	"GameEngine.hh"

class Master
{
protected:
  gdl::SdlContext				_context;
  gdl::Clock					_clock;
  gdl::Input					_input;
  gdl::BasicShader			_shader;
  std::vector<IObject*>		_obj;

public:
  Master();
  ~Master();

  int 									run();
  const std::vector<std::vector<int > >	getVect(int,  int,  int,  int,  int,  int,  int,  int,  int);
};

#endif /* MASTER_HH_ */
