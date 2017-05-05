#include "Address.hh"

Address::Address() : _city(""), _type(""), _street(""), _cityFilled(false), _streetFilled(false)
{}

Address::~Address()
{}

void	Address::build(std::string line)
{
	std::size_t	pos;

	while (!line.empty())
	{
		pos = line.find(" ");
		if (isNumber(line.substr(0, pos)) == true)
			setNumber(line.substr(0, pos));
		else if (isStreetType(line.substr(0, pos)) == true)
			setType(line.substr(0, pos));
		else
		{
			if (_cityFilled)
			{
				pos = line.length();
				setStreet(line);
			}
			else
			{
				if (!_type.empty() && !_streetFilled)
				{
					pos = line.find(",");
					if (pos == std::string::npos)
						pos = line.length();
					line.erase(pos, 1);
					_streetFilled = true;
					setStreet(line.substr(0, pos));
				}
				else
				{
					if (_streetFilled)
					{
						pos = line.length();
						setCity(line);
					}
					else
					{
						pos = getLess(line);
						setCity(line.substr(0, pos));
					}
				}
			}
		}
		line.erase(0, pos + 1);
	}
	splitCity();
	splitStreet();
	epurCity();
	epurStreet();
	splitCityEpur();
	splitStreetEpur();
}

bool	Address::isStreetType(const std::string str)
{
	bool						flag = false;
	std::vector<std::string>	types;

	types.push_back("allée");
	types.push_back("avenue");
	types.push_back("boulevard");
	types.push_back("chemin");
	types.push_back("impasse");
	types.push_back("place");
	types.push_back("quai");
	types.push_back("rue");
	types.push_back("square");

	for (std::size_t i = 0; i < types.size(); ++i)
	{
		if (types[i] == str)
			flag = true;
	}
	return (flag);
}

bool	Address::isNumber(const std::string str)
{
	bool	flag = true;

	for (int i = 0; str[i]; ++i)
	{
		if (str[i] < 48 || str[i] > 57)
			flag = false;
	}
	return (flag);
}

std::size_t		Address::getLess(std::string &line)
{
	std::size_t	pos1;
	std::size_t	pos2;

	pos1 = line.find(",");
	if (pos1 == std::string::npos)
		pos1 = line.length();
	else
		line.erase(pos1, 1);
	pos2 = findNumeric(line) - 1;
	pos1 = (pos1 < pos2) ? pos1 : pos2;
	return (pos1);
}

std::size_t		Address::findNumeric(const std::string &line)
{
	int	i = 0;

	while (line[i] && (line[i] < 48 || line[i] > 57))
		++i;
	return (i);
}

void	Address::setCity(const std::string str)
{
	if (_city == "")
		_city = str;
	else
		_city += " " + str;
}

void	Address::setNumber(const std::string str)
{
	if (!_city.empty())
		_cityFilled = true;
	if (!_street.empty())
		_streetFilled = true;
	_number = str;
}

void	Address::setType(const std::string str)
{
	if (!_city.empty())
		_cityFilled = true;
	if (!_street.empty())
		_streetFilled = true;
	_type = str;
}

void	Address::setStreet(const std::string str)
{
	if (_street == "")
		_street = str;
	else
		_street += " " + str;
}

void	Address::epurCity()
{
	std::size_t	pos = 0;
	_cityEpur = _city;

	while ((pos = _cityEpur.find("\'")) != std::string::npos)
		_cityEpur.erase(pos, 1);
	while ((pos = _cityEpur.find("-")) != std::string::npos)
		_cityEpur.erase(pos, 1);
}

void	Address::epurStreet()
{
	std::size_t	pos = 0;
	_streetEpur = _street;

	while ((pos = _streetEpur.find("\'")) != std::string::npos)
		_streetEpur.erase(pos, 1);
	while ((pos = _streetEpur.find("-")) != std::string::npos)
		_streetEpur.erase(pos, 1);
}

void	Address::splitCity()
{
	std::size_t	pos = 0;
	std::string	city = _city;

	while (!city.empty())
	{
		if ((pos = city.find(" ")) == std::string::npos)
			pos = city.length();
		_cityVector.push_back(city.substr(0, pos));
		if (city[pos] == ' ')
			city.erase(0, pos + 1);
		else
			city.erase(0, pos);
	}
}

void	Address::splitStreet()
{
	std::size_t	pos = 0;
	std::string	street = _street;

	while (!street.empty())
	{
		if ((pos = street.find(" ")) == std::string::npos)
			pos = street.length();
		_streetVector.push_back(street.substr(0, pos));
		if (street[pos] == ' ')
			street.erase(0, pos + 1);
		else
			street.erase(0, pos);
	}
}


void	Address::splitCityEpur()
{
	std::size_t	pos = 0;
	std::string	city = _cityEpur;

	while (!city.empty())
	{
		if ((pos = city.find(" ")) == std::string::npos)
			pos = city.length();
		_cityEpurVector.push_back(city.substr(0, pos));
		if (city[pos] == ' ')
			city.erase(0, pos + 1);
		else
			city.erase(0, pos);
	}
}

void	Address::splitStreetEpur()
{
	std::size_t	pos = 0;
	std::string	street = _streetEpur;

	while (!street.empty())
	{
		if ((pos = street.find(" ")) == std::string::npos)
			pos = street.length();
		_streetEpurVector.push_back(street.substr(0, pos));
		if (street[pos] == ' ')
			street.erase(0, pos + 1);
		else
			street.erase(0, pos);
	}
}

bool	Address::checkFormat(std::string line)
{
	std::size_t	pos;

	if ((pos = line.find(",")) == std::string::npos)
		return (false);
	line.erase(0, pos + 2);
	if ((pos = line.find(" ")) == std::string::npos)
		return (false);
	if (!isNumber(line.substr(0, pos)))
		return (false);
	line.erase(0, pos + 1);
	if ((pos = line.find(" ")) == std::string::npos)
		return (false);
	if (!isStreetType(line.substr(0, pos)))
		return (false);
	line.erase(0, pos + 1);
	if (line.empty())
		return(false);
	return(true);
}

bool		Address::checkPush()
{
	if (_city.empty() || _number.empty() || _type.empty() || _street.empty())
		return (false);
	return (true);
}

const std::string&	Address::getCity() const
{
	return _city;
}

const std::string&	Address::getNumber() const
{
	return _number;
}

const std::string&	Address::getType() const
{
	return _type;
}

const std::string&	Address::getStreet() const
{
	return _street;
}

const std::string&	Address::getCityEpur() const
{
	return _cityEpur;
}

const std::string&	Address::getStreetEpur() const
{
	return _streetEpur;
}

const std::vector<std::string>&	Address::getCityVector() const
{
	return _cityVector;
}

const std::vector<std::string>&	Address::getStreetVector() const
{
	return _streetVector;
}

const std::vector<std::string>&	Address::getCityEpurVector() const
{
	return _cityEpurVector;
}

const std::vector<std::string>&	Address::getStreetEpurVector() const
{
	return _streetEpurVector;
}