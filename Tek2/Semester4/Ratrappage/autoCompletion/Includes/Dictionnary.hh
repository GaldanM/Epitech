#ifndef DICTIONNARY_HH_
# define DICTIONNARY_HH_

# include	<iostream>
# include	<fstream>
# include	<algorithm>
# include	<string>
# include	<vector>
# include	<map>
# include	<string.h>
# include	"Address.hh"
# include	"MyError.hh"

typedef std::pair<char, std::size_t> Probabilitie;

class 		Dictionnary
{
private:
	int 						_cityPossibilities;
	int 						_streetPossibilities;
	bool						_abort;
	std::string					_cityFilled;
	std::string					_streetFilled;
	std::string					_input;
	std::ifstream				_dico;
	std::vector<std::string>	_choices;
	std::vector<std::string>	_choicesEpur;
	std::vector<Address *> 		_addresses;
	std::vector<Probabilitie>	_probabilities;


public:
	Dictionnary(const std::string &dico);
	~Dictionnary();
	
	void	searchAddress();
	bool	checkWordFinished();

	bool	oneCityPossible();
	void	fillCitiesChoices();
	void	dispCities();

	bool	oneStreetSeveralAddresses();
	void	choiceStreets();
	bool	manageChoiceStreets(const int);
	void	fillStreetsChoices();
	void	dispStreets();

	void	calcProba();
	void	incProba(const char);
	void	resetProba();
	void	sortProba();
	
	bool	completion();
	
	void	dispProba();
	size_t	getNbrProba();

	void	fillInput();
	void	manageNumber(const int);
	
	void	epurAddresses();
	void	epurCity();
	void	epurStreet();

	bool	isNumber(const std::string&);
	bool	notDoublon(const Address&);
	void	sortVectorCase(std::vector<std::string>&);
};

#endif /* !DICTIONNARY_HH_ */