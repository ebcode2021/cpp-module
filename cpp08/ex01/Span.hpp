#ifndef SPAN_HPP
# define SPAN_HPP

#include <vector>
#include <algorithm>

class	Span
{
	private :
		unsigned int 		_maxSize;
		std::vector<int>	_spanVector;


	public :
		// OCCF
		Span();
		Span(const Span&);
		Span& operator=(const Span&);
		~Span();
		Span(unsigned int);

		// member function
		void	addNumber(unsigned int);
		void	addTwice();
		int		shortestSpan() const;
		int		longestSpan() const;
		int		getSize() const;
};

#endif