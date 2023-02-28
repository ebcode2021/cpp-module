#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <iostream>

/* sequence container*/
#include <deque>
#include <vector>
#include <list>

template<typename T>
typename T::iterator easyfind(T& container, int n)
{
	typename T::iterator find;

	find = std::find(container.begin(), container.end(), n);
	if (find == container.end())
		throw std::range_error("ERROR::NOT FOUND!");
	else
		return find;
}

#endif