#include "DomesticKoala.h"

DomesticKoala::DomesticKoala(KoalaAction &action) : _koala(action)
{

}

DomesticKoala::DomesticKoala(DomesticKoala const &cpy)
{
	_tabActions = cpy._tabActions;
	_tabChar = cpy._tabChar;
	_koala = cpy._koala;
}

DomesticKoala::~DomesticKoala()
{

}

DomesticKoala&		DomesticKoala::operator=(DomesticKoala const &cpy)
{
	if (&cpy && &cpy != this)
	{
		_tabActions = cpy._tabActions;
		_tabChar = cpy._tabChar;
		_koala = cpy._koala;
	}
	return (*this);
}

std::vector<methodPointer_t> const	*DomesticKoala::getAction() const
{
	return &_tabActions;
}

void			DomesticKoala::learnAction(unsigned char c, methodPointer_t method)
{
	_tabChar.push_back(c);
	_tabActions.push_back(method);
}

void			DomesticKoala::unlearnAction(unsigned char c)
{
	int			i = 0;

	while (_tabChar[i] && _tabChar[i] != c)
		i++;
	if (_tabChar[i])
	{
		_tabChar.erase(_tabChar.begin() + i);
		_tabActions.erase(_tabActions.begin() + i);
	}
}

void			DomesticKoala::doAction(unsigned char c, std::string const &param)
{
	int i = 0;
	while (_tabChar[i] && _tabChar[i] != c)
		i++;
	if (_tabChar[i])
		(_koala.*_tabActions[i])(param);
}

void			DomesticKoala::setKoalaAction(KoalaAction &new_koala)
{
	_koala = new_koala;
	_tabActions.erase(_tabActions.begin(), _tabActions.end());
	_tabChar.erase(_tabChar.begin(), _tabChar.end());
}
