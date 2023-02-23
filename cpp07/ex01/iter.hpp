#ifndef ITER_HPP
# define ITER_HPP

template<typename T>
void	iter(T* array, int len, void (*func)(T &))
{
	if (!func)
		return ;
	for (int i = 0; i < len; i++)
		(*func)(array[i]);
}

template<typename T>
void	iter(T* array, unsigned int len, void (*func)(T const &))
{
	if (!func)
		return ;
	for (unsigned int i = 0; i < len; i++)
		(*func)(array[i]);
}

template<typename T>
void printArr(T& a)
{
	std::cout << a << std::endl;
}

template<typename T>
void printArr(T const& a)
{
	std::cout << a << std::endl;
}

#endif