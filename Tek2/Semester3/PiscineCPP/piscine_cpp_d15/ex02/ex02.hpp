#ifndef EX02_HPP_
# define EX02_HPP_

template<typename T>
T 		min(T const &a, T const &b)
{
	std::cout << "template min" << std::endl;
	if (a == b)
		return (a);
	if (a < b)
		return (a);
	return (b);
}

int 		min(int const &a, int const &b)
{
	std::cout << "non-template min" << std::endl;
	if (a == b)
		return (a);
	if (a < b)
		return (a);
	return (b);
}

template<typename T>
T 		templateMin(T *tab, int const &size)
{
	int i = 1;
	T	mini = tab[0];

	while (i < size)
	{
		mini = min<T>(mini, tab[i]);
		i++;
	}
	return (mini);
}

int 		nonTemplateMin(int * const &tab, int const &size)
{
	int		i = 1;
	int		mini = tab[0];

	while (i < size)
	{
		mini = min(mini, tab[i]);
		i++;
	}
	return (mini);
}

#endif