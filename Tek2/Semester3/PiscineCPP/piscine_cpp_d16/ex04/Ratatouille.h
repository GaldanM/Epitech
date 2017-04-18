#ifndef RATATOUILLE_H_
# define RATATOUILLE_H_

# include <iostream>
# include <string>
# include <sstream>

class Ratatouille
{
 protected:
  std::ostringstream _string;

 public:
  Ratatouille();
  Ratatouille(Ratatouille const&);
  ~Ratatouille();
  Ratatouille &operator=(Ratatouille const&);

  Ratatouille &addVegetable(unsigned char);
  Ratatouille &addCondiment(unsigned int);
  Ratatouille &addSpice(double);
  Ratatouille &addSauce(std::string const&);

  std::string kooc(void);
};

#endif
