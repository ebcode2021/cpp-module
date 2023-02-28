#include "Span.hpp"

Span::Span()
{
	this->_maxSize = 0;
}

Span::Span(const Span& span)
{
	this->_maxSize = span._maxSize;
	this->_spanVector = span._spanVector;
}

Span& Span::operator=(const Span& span)
{
	if (this != &span)
	{
		this->_maxSize = span._maxSize;
		this->_spanVector = span._spanVector;
	}
	return (*this);
}

Span::~Span(){}

Span::Span(unsigned int n)
{
	this->_maxSize = n;
}

void	Span::addNumber(unsigned int n)
{
	if (this->_spanVector.size() == this->_maxSize)
		throw std::range_error("ERROR::FULL!");
	this->_spanVector.push_back(n);
}

int	Span::longestSpan() const
{
	if (this->_spanVector.size() < 2)
		throw std::range_error("ERROR::NEED AT LEAST 2 ELEMENTS");
	return ((*std::max_element(this->_spanVector.begin(), this->_spanVector.end())) -
			*(std::min_element(this->_spanVector.begin(), this->_spanVector.end())));
}

int	Span::shortestSpan() const
{
	if (this->_spanVector.size() < 2)
		throw std::range_error("ERROR::NEED AT LEAST 2 ELEMENTS");
	std::vector<int> tmp = this->_spanVector;
	std::sort(tmp.begin(), tmp.end());
	
	int	min = INT_MAX;

	for (std::vector<int>::iterator it = tmp.begin(); it < tmp.end() - 1; it++)
	{
		long long check = *(it + 1) - *(it);
		if (check < INT_MIN || check > INT_MAX)
			throw std::range_error("ERROR::OVERFLOW");
		min = std::min(*(it + 1) - *(it), min);
	}
	return (min);
}

int Span::getSize() const
{
	return (this->_spanVector.size());
}

void	Span::addTwice()
{
	if (this->_spanVector.size() * 2 > this->_maxSize)
		throw std::range_error("ERROR::TOO MANY SIZE");
	this->_spanVector.insert(this->_spanVector.end(), this->_spanVector.begin(), this->_spanVector.end());
}