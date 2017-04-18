#ifndef EX01_HPP_
# define EX01_HPP_

template<typename T>
int		compare(T const &a, T const &b)
{
	if (a == b)
		return (0);
	if (a < b)
		return (-1);
	return (1);
}

template<>
int		compare<const char *>(const char * const &a, const char * const &b)
{
	int	ret;
	std::string s1(a);
	std::string s2(b);

	ret = s1.compare(s2);
	if (ret == 0)
		return (ret);
	if (ret < 0)
		return (-1);
	return (1);
}

#endif