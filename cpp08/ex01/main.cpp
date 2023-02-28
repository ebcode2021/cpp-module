#include <iostream>
#include "Span.hpp"

int	main()
{
	// subject
	{
		std::cout << "[subject test]" << std::endl;

		Span sp = Span(5);

		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}

	// test
	{
		Span sp = Span(12290);

		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;

		try
		{
			sp.addNumber(235);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}

	try
	{
		for (int i = 0; i < 11; i++)
		{
			sp.addTwice();
			std::cout << "현재 span의 개수는 " << sp.getSize() << std::endl;
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	return (0);
}
}