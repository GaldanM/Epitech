#ifndef TRADER_HH_
# define TRADER_HH_

# include	<iostream>
# include	<string>
# include	<list>
# include	<cmath>
# include	<cstdlib>

class Trader
{
private:
	double				_capital;
	double				_nbDays;
	double				_actualMarket;

	double				_actualDay;
	double				_nbActions;
	std::list<double>	_actionPrices;

public:
	Trader();
	~Trader();
	
	void	buy(double);
	void	sell(double);
	void	wait();
	void	choice();
	void	run();
};

#endif /* TRADER_HH_ */