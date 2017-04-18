#ifndef EX03_H_
# define EX03_H_

# include <iostream>

template<typename T>
void	foreach(T *tab, void (&aff)(const T&), int size)
{
	for (int i = 0; i < size; i++)
		aff(tab[i]);
}

template<typename U>
void	print(const U &aff)
{
	std::cout << aff << std::endl;
}

#endif