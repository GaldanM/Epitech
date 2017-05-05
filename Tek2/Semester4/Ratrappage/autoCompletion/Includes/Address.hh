#ifndef ADDRESS_HH_
# define ADDRESS_HH_

# include	<iostream>
# include	<string>
# include	<vector>
# include	"MyError.hh"

class 		Address
{
private:
	std::string					_city;
	std::string					_number;
	std::string					_type;
	std::string					_street;
	std::string					_cityEpur;
	std::string					_streetEpur;
	bool						_cityFilled;
	bool						_streetFilled;
	std::vector<std::string> 	_cityVector;
	std::vector<std::string> 	_streetVector;
	std::vector<std::string> 	_cityEpurVector;
	std::vector<std::string> 	_streetEpurVector;

public:
	Address();
	~Address();

	void				build(std::string);

	bool				checkFormat(std::string);
	bool				isStreetType(const std::string);
	bool				isNumber(const std::string);
	bool				checkPush();
	std::size_t			getLess(std::string&);
	std::size_t			findNumeric(const std::string&);

	void				setCity(const std::string);
	void				setNumber(const std::string);
	void				setType(const std::string);
	void				setStreet(const std::string);
	void				epurCity();
	void				epurStreet();
	void				splitCity();
	void				splitStreet();
	void				splitCityEpur();
	void				splitStreetEpur();

	const std::string&	getCity() const;
	const std::string&	getNumber() const;
	const std::string&	getType() const;
	const std::string&	getStreet() const;
	const std::string&	getCityEpur() const;
	const std::string&	getStreetEpur() const;
	const std::vector<std::string>&	getCityVector() const;
	const std::vector<std::string>&	getStreetVector() const;
	const std::vector<std::string>&	getCityEpurVector() const;
	const std::vector<std::string>&	getStreetEpurVector() const;
};

#endif /* !ADDRESS_HH_ */