#ifndef FIND_HPP_
# define FIND_HPP_

# include <algorithm>

template<typename T>
typename T::iterator	do_find(T &tab, int to_find)
{
	typename T::iterator ite;

	ite = std::find(tab.begin(), tab.end(), to_find);
	return (ite);
}

#endif