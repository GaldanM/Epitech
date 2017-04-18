#ifndef EX05_HPP_
#define EX05_HPP_

#include <string>
#include <exception>
#include <iostream>

template <typename T>
class array
{
	T   			*_tab;
	unsigned int	_size;
public:
		array()
		{
			this->_tab = NULL;
			_size = 0;
		}

		virtual ~array()
		{

		}

		array(const array& var)
		{
			this->tocopy(var);
		}

		array(unsigned int n)
		{
			this->_tab = new T[n];
			this->_size = n;
		}


		array<T>& tocopy(const array<T>& var)
		{

			this->_tab = var._tab;
			this->_size = var._size;
			return (*this);
		}


		array<T>& operator=(const array<T>& var)
		{
			this->tocopy(var);
			return (*this);
		}

		T& operator[](unsigned int i)
		{
			unsigned int j = 0;
			
			if (i > _size)
			{
				T *nouv = new T[i + 1];
				while (j < _size)
				{
					nouv[j] = this->_tab[j];
					j++;
				}
				this->_size = 1 + i;
				delete this->_tab;
				this->_tab = nouv;
			}
			return (this->_tab[i]);
		}

		const T operator[](unsigned int i) const
		{
			if (i > this->_size)
				throw std::exception();
			return (this->_tab[i]);
		}

		void 	dump() const
		{
			unsigned int 	i = 0;

			std::cout << "[";
			while (_size && i < this->_size)
			{
				std::cout << this->_tab[i];
				
				if (i != this->_size - 1)
					std::cout << ", ";
			i++;	
			}
			std::cout << "]" << std::endl;
		}

		template <typename U>
		array<U> 	 convertTo(U(*toConv)(const T &)) const
		{
			array<U>  nouv(this->_size);
			unsigned int 	i = 0;

			while (i <= _size)
			{
			 nouv[i] = (*toConv)(this->_tab[i]);
				i++;
			}
			return  (nouv);
		}

		unsigned int size() const
		{
			return _size;
		}
};

template<>
void 	array<bool>::dump() const
{
	unsigned int 	i = 0;

	std::cout << "[";
	while (_size && i < this->_size)
	{
		if (_tab[i] == 1)
			std::cout << "true";
		else if (_tab[i] == 0)
			std::cout << "false";
		
		if (i != this->_size - 1)
			std::cout << ", ";
	i++;	
	}
	std::cout << "]" << std::endl;
}

#endif