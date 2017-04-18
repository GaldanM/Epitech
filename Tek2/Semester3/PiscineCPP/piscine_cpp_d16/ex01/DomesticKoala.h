#ifndef DOMESTIC_H_
# define DOMESTIC_H_

#include <iostream>
#include <vector>
#include "KoalaAction.h"

typedef void (KoalaAction::*methodPointer_t)(std::string const&);

class DomesticKoala
{
private:
	std::vector<char> 				_tabChar;
	std::vector<methodPointer_t> 	_tabActions;
	KoalaAction 					_koala;

public:

	/* INIT */
	DomesticKoala(KoalaAction &);
	DomesticKoala(DomesticKoala const&);
	~DomesticKoala();
	DomesticKoala& operator=(DomesticKoala const&);

	/* GETTERS */
	std::vector<methodPointer_t> const *getAction(void) const;

	/* SETTERS */
	void		learnAction(unsigned char, methodPointer_t);
	void		unlearnAction(unsigned char);
	void		setKoalaAction(KoalaAction &);

	/* OTHERS */
	void		doAction(unsigned char, std::string const&);

};
#endif