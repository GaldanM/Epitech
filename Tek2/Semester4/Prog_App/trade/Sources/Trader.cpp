#include "Trader.hh"

Trader::Trader() : _actualDay(0), _nbActions(0)
{}

Trader::~Trader()
{}

void	Trader::buy(double nb)
{
	double	toPay;
	double	commition;
	double	nb_d = nb;

	toPay = nb_d * _actualMarket;
	commition = ceil((toPay / 100.0f) * 0.15f);
	toPay += commition;
	if (_capital > toPay)
	{
		_capital -= toPay;
		_nbActions += nb;
		std::cout << "buy " << nb << std::endl;
	}
	else
		wait();
}

void	Trader::sell(double nb)
{
	double	toGain;
	double	commition;
	double	nb_d = nb;

	toGain = nb_d * _actualMarket;
	commition = ceil((toGain / 100.0f) * 0.15f);
	toGain -= commition;
	if (_nbActions >= nb)
	{
		_capital += toGain;
		_nbActions -= nb;
		std::cout << "sell " << nb << std::endl;
	}
	else
		wait();
}

void	Trader::wait()
{
	std::cout << "wait" << std::endl;
}

void	Trader::choice()
{
	if (_actualDay == _nbDays)
		sell(_nbActions);
	else if (_actionPrices.empty())
		wait();
	else if (_actualMarket > _actionPrices.front())
		sell(1);
	else if (_actualMarket < _actionPrices.front())
		buy(1);
	else
		wait();
	_actionPrices.push_front(_actualMarket);
}

void	Trader::run()
{
	std::string		read;

	std::cin >> read;
	_capital = atof(read.c_str());

	std::cin >> read;
	_nbDays = atof(read.c_str());

	std::cin >> read;
	while (read != "--end--" && _actualDay < _nbDays)
	{
		_actualDay += 1.0f;
		_actualMarket = atof(read.c_str());
		choice();
		std::cin >> read;
	}
}