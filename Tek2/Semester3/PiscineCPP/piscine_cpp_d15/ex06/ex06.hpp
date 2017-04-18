

#ifndef EX06_HPP_
# define EX06_HPP_

# include <iostream>
# include <sstream>

template<typename T>
std::string	disp(T a)
{
	std::string var("???");

	if (a == a)
		return (var);
	return (var);
}

template<>
std::string	disp<int>(int a)
{
	std::string var("int:");
	std::ostringstream oss;
	oss << a;
	return (var + oss.str());
}

template<>
std::string	disp<float>(float a)
{
	std::string var("float :");
	std::ostringstream oss;
	oss << a;
	return (var + oss.str() + "f");
}

template<>
std::string	disp<std::string>(std::string a)
{
	std::string var("string:\"");
	var += a;
	var += "\"";
	return (var);
}

template <typename T, typename U = int>
struct 	Tuple
{
 	T 	a;
 	U 	b;


 	std::string	toString()
 	{
		std::string var("[TUPLE [");
		var += disp(a);
		var += "] [";
		var += disp(b);
		var += "]]";
		return (var);
 	}

};

#endif