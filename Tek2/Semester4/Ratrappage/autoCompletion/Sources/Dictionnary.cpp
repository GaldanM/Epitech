#include "Dictionnary.hh"

Dictionnary::Dictionnary(const std::string &dico) : _cityPossibilities(0), _streetPossibilities(0), _abort(false), _cityFilled(""), _streetFilled(""), _input("")
{
	char 			c = 'a';
	std::string 	eof;
	std::string		line;
	Address			*address;

	_dico.open(dico.c_str(), std::ifstream::in);
	if (!_dico.is_open())
		throw MyError("Argument invalide");
	if ((eof[0] = _dico.peek()) == std::ifstream::traits_type::eof())
		throw MyError("Argument invalide");
	while (getline(_dico, line))
	{
		if (eof[0] != 0)
			line.insert(0, eof);
		eof[0] = 0;
		address = new Address();
		if (!address->checkFormat(line))
			std::cerr << line << std::endl;
		address->build(line);
		if (notDoublon(*address) && address->checkPush())
			_addresses.push_back(address);
	}
	while (c <= 'z')
		_probabilities.push_back(std::make_pair(c++, 0));
}

Dictionnary::~Dictionnary()
{
	for (std::vector<Address *>::iterator it = _addresses.begin(); it != _addresses.end();)
		it = _addresses.erase(it);
}

void	Dictionnary::searchAddress()
{
	Address 	*address;

	while (_addresses.size() > 1 && !_abort)
	{
		if (!checkWordFinished())
		{
			calcProba();
			while (completion())
				calcProba();
			if (!checkWordFinished())
			{
				dispProba();
				fillInput();
				if (!_abort)
					epurAddresses();
			}
		}
		else if (_cityFilled.empty())
		{
			if (oneCityPossible())
			{
				_cityFilled = _input;
				_input.clear();
				_choices.clear();
			}
			else
			{
				fillCitiesChoices();
				dispCities();
				fillInput();
				if (_cityFilled.empty())
				{
					epurAddresses();
					_choices.clear();
				}
			}
		}
		else
		{
			fillStreetsChoices();
			dispStreets();
			if (oneStreetSeveralAddresses())
			{
				choiceStreets();
			}
			else
			{
				fillInput();
				if (_streetFilled.empty())
				{
					epurAddresses();
					_choices.clear();
				}
			}
		}
	}
	if (_abort)
		return;
	if (_addresses.size() == 0)
		throw MyError("Adresse inexistante");
	address = _addresses[0];
	std::cout << "=> " << address->getCity() << ", " << address->getNumber()
	<< " " << address->getType() << " " << address->getStreet() << std::endl;
}

bool	Dictionnary::oneCityPossible()
{
	std::string			tmp = _addresses[0]->getCityEpur();
	std::size_t 		nb = 0;

	for (std::size_t i = 0; i < _addresses.size(); ++i)
	{
		for (std::size_t j = 0; j < _addresses[i]->getCityEpurVector().size(); ++j)
		{
			if (!strcasecmp(_addresses[i]->getCityEpurVector()[j].c_str(), _input.c_str()))
			{
				if (!strcasecmp(_addresses[i]->getCityEpur().c_str(), tmp.c_str()))
					++nb;
				j = _addresses[i]->getCityEpurVector().size() - 1;
			}
		}
	}
	if (nb == _addresses.size())
		return (true);
	return (false);
}

void	Dictionnary::fillCitiesChoices()
{
	bool		flag;
	std::size_t pos = 0;
	std::string	tmp = "";
	std::string	tmpEpur = "";

	for (std::size_t i = 0; i < _addresses.size(); ++i)
	{
		flag = false;
		for (std::size_t j = 0; j < _addresses[i]->getCityEpurVector().size(); ++j)
		{
			if (!strcasecmp(_addresses[i]->getCityEpurVector()[j].c_str(), _input.c_str()))
			{
				pos = j;
				flag = true;
			}
		}
		for (std::size_t k = 0; k < _choices.size(); ++k)
		{
			if (!strcasecmp(_addresses[i]->getCityEpur().c_str(), _choices[k].c_str()))
				flag = false;
		}
		if (flag)
		{
			for (std::size_t j = 0; j < _addresses[i]->getCityEpurVector().size(); ++j)
			{
				if (j == pos)
				{
					tmp += _input;
					tmpEpur += _input;
				}
				else
				{
					tmp += _addresses[i]->getCityVector()[j];
					tmpEpur += _addresses[i]->getCityEpurVector()[j];
				}
				if (j + 1 < _addresses[i]->getCityVector().size())
				{
					tmp += " ";
					tmpEpur += " ";
				}
			}
			_choices.push_back(tmp);
			_choicesEpur.push_back(tmpEpur);
			tmp.clear();
			tmpEpur.clear();
		}
	}
}

void	Dictionnary::dispCities()
{
	sortVectorCase(_choices);
	sortVectorCase(_choicesEpur);
	for (std::size_t i = 0; i < _choices.size(); ++i)
	{
		std::cout << "{" << i + 1 << " : " << _choices[i] << "}";
		if (i + 1 < _choices.size())
			std::cout << " ";
		else
			std::cout << std::endl;
	}

}

bool	Dictionnary::oneStreetSeveralAddresses()
{
	std::string	tmp = _addresses[0]->getStreetEpur();
	std::size_t 		nb = 0;

	for (std::size_t i = 0; i < _addresses.size(); ++i)
	{
		for (std::size_t j = 0; j < _addresses[i]->getStreetEpurVector().size(); ++j)
		{
			if (!strcasecmp(_addresses[i]->getStreetEpurVector()[j].c_str(), _input.c_str()))
			{
				if (!strcasecmp(_addresses[i]->getStreetEpur().c_str(), tmp.c_str()))
					++nb;
				j = _addresses[i]->getStreetEpurVector().size() - 1;
			}
		}
	}
	if (nb == _addresses.size())
		return (true);
	return (false);
}

void	Dictionnary::choiceStreets()
{
	bool		flag = false;
	std::string	read;

	while (!flag)
	{
		getline(std::cin, read);
		if (!strcasecmp(read.c_str(), "ABORT"))
		{
			_abort = true;
			return;
		}
		if (isNumber(read))
		{
			flag = manageChoiceStreets(atoi(read.c_str()));
		}
		if (!flag)
			dispStreets();
	}
}

bool	Dictionnary::manageChoiceStreets(const int choice)
{
	bool	flag = false;
	std::size_t i = 0;

	while(i < _choices.size() && static_cast<unsigned int>(choice) != i + 1)
		++i;
	if (i != _choices.size())
	{
		_streetFilled = _choicesEpur[i];
		epurStreet();
		flag = true;
		_input.clear();
		_choices.clear();
	}
	return (flag);
}

void	Dictionnary::fillStreetsChoices()
{
	bool		flag;
	std::size_t pos = 0;
	std::string	tmp = "";
	std::string	tmpEpur = "";

	for (std::size_t i = 0; i < _addresses.size(); ++i)
	{
		flag = false;
		for (std::size_t j = 0; j < _addresses[i]->getStreetEpurVector().size(); ++j)
		{
			if (!strcasecmp(_addresses[i]->getStreetEpurVector()[j].c_str(), _input.c_str()))
			{
				pos = j;
				flag = true;
			}
		}
		for (std::size_t k = 0; k < _choices.size(); ++k)
		{
			if (!strcasecmp(_addresses[i]->getStreetEpur().c_str(), _choices[k].c_str()))
				flag = false;
		}
		if (flag)
		{
			tmp += _addresses[i]->getNumber() + " " + _addresses[i]->getType() + " ";
			tmpEpur = tmp;
			for (std::size_t j = 0; j < _addresses[i]->getStreetEpurVector().size(); ++j)
			{
				if (j == pos)
				{
					tmp += _input;
					tmpEpur += _input;
				}
				else
				{
					tmp += _addresses[i]->getStreetVector()[j];
					tmpEpur += _addresses[i]->getStreetEpurVector()[j];
				}
				if (j + 1 < _addresses[i]->getStreetVector().size())
				{
					tmp += " ";
					tmpEpur += " ";
				}
			}
			_choices.push_back(tmp);
			_choicesEpur.push_back(tmpEpur);
			tmp.clear();
			tmpEpur.clear();
		}
	}
}

void	Dictionnary::dispStreets()
{
	sortVectorCase(_choices);
	sortVectorCase(_choicesEpur);
	for (std::size_t i = 0; i < _choices.size(); ++i)
	{
		std::cout << "{" << i + 1 << " : " << _cityFilled << ", " << _choices[i] << "}";
		if (i + 1 < _choices.size())
			std::cout << " ";
		else
			std::cout << std::endl;
	}
}

bool	Dictionnary::checkWordFinished()
{
	for (std::size_t i = 0; i < _addresses.size(); ++i)
	{
		if (_cityFilled.empty())
		{
			for(std::size_t j = 0; j < _addresses[i]->getCityEpurVector().size(); ++j)
			{
				if (!strcasecmp(_addresses[i]->getCityEpurVector()[j].c_str(), _input.c_str()))
					return (true);
			}
		}
		else
		{
			for(std::size_t j = 0; j < _addresses[i]->getStreetEpurVector().size(); ++j)
			{
				if (!strcasecmp(_addresses[i]->getStreetEpurVector()[j].c_str(), _input.c_str()))
					return (true);
			}
		}
	}
	return (false);
}

void	Dictionnary::calcProba()
{
	char 	c;

	resetProba();
	for (std::size_t i = 0; i < _addresses.size(); ++i)
		if (_cityFilled.empty())
		{
			for(std::size_t j = 0; j < _addresses[i]->getCityEpurVector().size(); ++j)
				if (!strcasecmp(_addresses[i]->getCityEpurVector()[j].substr(0, _input.length()).c_str(), _input.c_str()))
				{
					c = _addresses[i]->getCityEpurVector()[j][_input.length()];
					if (c >= 'A' && c <= 'Z')
						c += 32;
					incProba(c);
				}
		}
		else
		{
			for(std::size_t j = 0; j < _addresses[i]->getStreetEpurVector().size(); ++j)
				if (!strcasecmp(_addresses[i]->getStreetEpurVector()[j].substr(0, _input.length()).c_str(), _input.c_str()))
				{
					c = _addresses[i]->getStreetEpurVector()[j][_input.length()];
					if (c >= 'A' && c <= 'Z')
						c += 32;
					incProba(c);
				}
		}
	sortProba();
}

void	Dictionnary::incProba(const char c)
{
	for (std::size_t i = 0; i < _probabilities.size(); ++i)
	{
		if (_probabilities[i].first == c)
			_probabilities[i].second += 1;
	}
}

void	Dictionnary::resetProba()
{
	for (std::size_t i = 0; i < _probabilities.size(); ++i)
			_probabilities[i].second = 0;
}

void	Dictionnary::sortProba()
{
	std::pair<char, std::size_t> 	tmp;

	for (std::size_t i = 0; i < _probabilities.size(); ++i)
	{
		for (std::size_t j = i + 1; j < _probabilities.size(); ++j)
		{
			if (_probabilities[j].second > _probabilities[i].second)
				_probabilities[i].swap(_probabilities[j]);
			else if (_probabilities[i].second == _probabilities[j].second)
			{
				if (_probabilities[j].first < _probabilities[i].first)
					_probabilities[i].swap(_probabilities[j]);
			}
		}
	}
}

bool	Dictionnary::completion()
{
	int 	nb = 0;

	for (std::size_t i = 0; i < _probabilities.size(); ++i)
	{
		if (_probabilities[i].second > 0)
			++nb;
	}
	if (nb > 1)
		return (false);
	for (std::size_t i = 0; i < _probabilities.size(); ++i)
	{
		if (_probabilities[i].second == _addresses.size())
		{
			_input += _probabilities[i].first - 32;
			return (true);
		}
	}
	return (false);
}

void	Dictionnary::dispProba()
{
	for (std::size_t i = 0; i < getNbrProba() && i < 5; ++i)
	{
		std::cout << "{";
		if (_cityFilled.empty())
			std::cout << _input << _probabilities[i].first;
		else
			std::cout << _cityFilled << ", " << _input << _probabilities[i].first;
		if (i + 1 < 5 && i + 1 < getNbrProba())
			std::cout << "} ";
		else
			std::cout << "}";
	}
	std::cout << std::endl;
}

size_t	Dictionnary::getNbrProba()
{
	std::size_t	nb = 0;

	for (std::size_t i = 0; i < _probabilities.size(); ++i)
	{
		if (_probabilities[i].second > 0)
			++nb;
	}
	return (nb);
}

void	Dictionnary::fillInput()
{
	std::string	read;

	getline(std::cin, read);
	if (!strcasecmp(read.c_str(), "ABORT"))
	{
		_abort = true;
		return;
	}
	if (read[0] >= 'a' && read[0] <= 'z')
		read[0] -= 32;
	if (isNumber(read))
		manageNumber(atoi(read.c_str()));
	else
		_input += read[0];
}

void	Dictionnary::manageNumber(const int nb)
{
	std::size_t i = 0;

	while(i < _choices.size() && static_cast<unsigned int>(nb) != i + 1)
		++i;
	if (i == _choices.size())
		_input += nb;
	else
	{
		if (_cityFilled.empty())
		{
			_cityFilled = _choicesEpur[i];
			epurCity();
		}
		else
		{
			_streetFilled = _choicesEpur[i];
			epurStreet();
		}
		_input.clear();
		_choices.clear();
	}

}

void	Dictionnary::epurAddresses()
{
	bool	flag;

	for (std::size_t i = 0; i < _addresses.size();)
	{
		flag = false;
		if (_cityFilled.empty())
		{
			for(std::size_t j = 0; j < _addresses[i]->getCityEpurVector().size(); ++j)
			{
				if (_addresses[i]->getCityEpurVector()[j].size() >= _input.size())
				{
					if (!strcasecmp(_addresses[i]->getCityEpurVector()[j].substr(0, _input.length()).c_str(), _input.c_str()))
						flag = true;
				}
			}
			if (!flag)
				_addresses.erase(_addresses.begin() + i);
			else
				++i;
		}
		else
		{
			for(std::size_t j = 0; j < _addresses[i]->getStreetEpurVector().size(); ++j)
			{
				if (_addresses[i]->getStreetEpurVector()[j].size() >= _input.size())
				{
					if (!strcasecmp(_addresses[i]->getStreetEpurVector()[j].substr(0, _input.length()).c_str(), _input.c_str()))
						flag = true;
				}
			}
			if (!flag)
				_addresses.erase(_addresses.begin() + i);
			else
				++i;
		}
	}
}

void	Dictionnary::epurCity()
{
	for (std::size_t i = 0; i < _addresses.size();)
	{
		if (strcasecmp(_addresses[i]->getCityEpur().c_str(), _cityFilled.c_str()))
			_addresses.erase(_addresses.begin() + i);
		else
			++i;
	}
}

void	Dictionnary::epurStreet()
{
	std::string	streetFull;

	for (std::size_t i = 0; i < _addresses.size();)
	{
		streetFull = _addresses[i]->getNumber() + " " + _addresses[i]->getType() + " " + _addresses[i]->getStreetEpur();
		if (strcasecmp(streetFull.c_str(), _streetFilled.c_str()))
			_addresses.erase(_addresses.begin() + i);
		else
			++i;
	}
}

bool	Dictionnary::isNumber(const std::string &nb)
{
	int 	i = 0;

	while (nb[i])
	{
		if (nb[i] <= '0' || nb[i] >= '9')
			return (false);
		++i;
	}
	return (true);
}

bool	Dictionnary::notDoublon(const Address &address)
{
	for (std::size_t i = 0; i < _addresses.size(); ++i)
	{
		if (address.getCity() == _addresses[i]->getCity()
			&& address.getNumber() == _addresses[i]->getNumber()
			&& address.getType() == _addresses[i]->getType()
			&& address.getStreet() == _addresses[i]->getStreet())
			return (false);
	}
	return (true);
}

void	Dictionnary::sortVectorCase(std::vector<std::string> &sort)
{
	for (std::size_t i = 0; i < sort.size(); ++i)
	{
		for (std::size_t j = i + 1; j < sort.size(); ++j)
		{
			if (strcasecmp(sort[i].c_str(), sort[j].c_str()) > 0)
				sort[i].swap(sort[j]);
		}
	}
}