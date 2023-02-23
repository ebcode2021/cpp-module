#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>

template<typename T>
class	Array
{
	private :
		unsigned int	_size;
		T*				_array;

	public :
		// OCCF
		Array()
		{
			this->_size = 0;
			this->_array = new T;
		};

		Array(unsigned int n)
		{
			this->_size = n;
			this->_array = new T[n];
		};

		Array(const Array& a)
		{
			this->_size = a._size;
			this->_array = new T[a._size];
			for (unsigned int i= 0; i < a._size; i++)
					this->_array[i] = a._array[i];
		};

		Array& operator=(const Array& a)
		{
			if (this != &a)
			{
				delete[] this->_array;
				this->_size = a._size;
				this->_array = new T[a._size];
				for (unsigned int i= 0; i < a._size; i++)
					this->_array[i] = a._array[i];
			}
			return (*this);
		};

		~Array()
		{
			delete[] this->_array;
		};

		// method
		unsigned int size()
		{
			return (this->_size);
		};

		T& operator [](unsigned int n)
		{
			if (this->_size <= n)
				throw OutOfIndexException();
			return (this->_array[n]);
		};

		//exception
		class	OutOfIndexException : public std::exception
		{
			const char* what() const throw()
			{
				return "out ot index!!\n";
			};
		};
};

template<typename T>
std::ostream& operator<<(std::ostream &out, Array<T> &array)
{
	unsigned int n = array.size();

	out << "[size]" << std::endl;
	out << n << std::endl;
	out << "\n[인자]" << std::endl;
	if (n == 0)
		out << "*** nothing! ***";
	else
	{
		for (unsigned int i = 0; i < n; i++)
			out << array[i] << " ";
	}
	out << "\n" << std::endl;
	return out;
}

#endif